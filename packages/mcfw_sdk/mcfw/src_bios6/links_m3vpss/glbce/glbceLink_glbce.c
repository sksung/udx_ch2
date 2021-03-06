/** ==================================================================
 *  @file   glbceLink_glbce.c                                                  
 *                                                                    
 *  @path    ipnc_mcfw/mcfw/src_bios6/links_m3vpss/glbce/                                                 
 *                                                                    
 *  @desc   This  File contains.                                      
 * ===================================================================
 *  Copyright (c) Texas Instruments Inc 2011, 2012                    
 *                                                                    
 *  Use of this software is controlled by the terms and conditions found
 *  in the license agreement under which this software has been supplied
 * ===================================================================*/

#include <xdc/std.h> 

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/hal/Cache.h>
#include <mcfw/src_bios6/utils/utils_mem.h>
#include <mcfw/interfaces/link_api/glbceSupportLink.h>

#include <ti/psp/iss/alg/jpeg_enc/inc/msp.h>
#include <ti/psp/iss/alg/ip_run/inc/ip_run.h>
#include <ti/psp/iss/alg/glbce/msp_glbce.h>
#include <ti/psp/vps/fvid2.h>

#include <ti/psp/iss/drivers/alg/2A/inc/issdrv_alg2APriv.h>
#include <ti/psp/iss/drivers/alg/2A/inc/issdrv_algTIaewb.h>

#include "glbceLink_glbce.h"
#include "glbceLink_priv.h"

#define GLBCE_USE_DEFAULT_PARAMS
#define GLBCE_EXTERNAL_RESOURCES_HANDLE

#ifndef IMX_BASED_SWOSD_ENABLED  
#define RESET_TO_BE_USED 
#endif


#define MAX_DEPTH_OF_BUFFERS  (6)

#ifdef USE_A8_FOR_TC_CALC
GlbceSupportLink_processPrm  processPrm[MAX_DEPTH_OF_BUFFERS];
unsigned char *BoxCarBuffers[MAX_DEPTH_OF_BUFFERS];
unsigned char *tonalCurveBuffers[MAX_DEPTH_OF_BUFFERS];

static int writeIndex = 0;
static int readIndex = 0;
int totalNumberOfTcRcvd = 0;
#endif

extern Uint32 glbceFlag;

extern ti2a_output ti2a_output_params; 
static int hasSomeOtherAlgoUsedSIMCOP = 0;


Iss_CaptDccPrm ggDccPrm;
static int isBoxCarAndToneCurveCalled = 0;
#ifdef RESET_TO_BE_USED
static int isCPIS_glbceCalled = 0;
#endif
	static int printCnt = 0;

/* Cache write back */
void cacheWb(void * ptr, Uint32 size, Uint16 wait){
    Cache_wb(ptr, size, Cache_Type_ALL, wait);
    return;
}

unsigned int GLBCE_Exec_Time;
unsigned int CPIS_glbce_Time;
unsigned int CPIS_reset_Time;
unsigned int BoxcarToneCurve_Time;
unsigned int CPIS_Boxcar_Time;


//Histogram memory
Int32 histogramMemory[256];

Int16 rgb2rgbMat[9]={
  434, -191, 13, 
 -112, 358,  10, 
  -138, -451,845
};
// ##################################################################################################
// ######
// ##################################################################################################

/* ===================================================================
 *  @func     MSP_GLBCE_Engine_Init                                               
 *                                                                    
 *  @desc     Function does the following                             
 *                                                                    
 *  @modif    This function modifies the following structures         
 *                                                                    
 *  @inputs   This function takes the following inputs                
 *            <argument name>                                         
 *            Description of usage                                    
 *            <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @outputs  <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @return   Return value of this function if any                    
 *  ==================================================================
 */                                                                   
Int32 MSP_GLBCE_Engine_Init(GlbceLink_Obj * pObj)
{
    int status = 0;
    System_LinkChInfo *inChInfo;
	
#ifdef USE_A8_FOR_TC_CALC
	int i;
	writeIndex = 0;
	readIndex = 0;
	totalNumberOfTcRcvd = 0;
#endif
    hasSomeOtherAlgoUsedSIMCOP = 0;
	isBoxCarAndToneCurveCalled = 0;
#ifdef RESET_TO_BE_USED
    isCPIS_glbceCalled = 0;
#endif
	inChInfo = &pObj->inQueInfo.chInfo[0];
	
	pObj->frameNum = 0;
	pObj->WIDTH = inChInfo->width;
	pObj->HEIGHT = (inChInfo->height + 8) & 0xFFFFFFF0;
	
	pObj->memSizeForBoxCarData = (2*pObj->WIDTH*pObj->HEIGHT)/256;
	
	pObj->BOXCAR = Utils_memAlloc(pObj->memSizeForBoxCarData, 16);
	UTILS_assert(pObj->BOXCAR != 0);
	
#ifdef USE_A8_FOR_TC_CALC
	for(i = 0; i < MAX_DEPTH_OF_BUFFERS; i++)
	{
	    BoxCarBuffers[i] = Utils_memAlloc_cached(pObj->memSizeForBoxCarData, 4*1024);
	    UTILS_assert(BoxCarBuffers[i] != 0);
		
		
	    tonalCurveBuffers[i] = Utils_memAlloc_cached(sizeof(unsigned char)*MAX_NUM_BLOCKS*NUM_OF_BINS*2, 4*1024);
	    UTILS_assert(tonalCurveBuffers[i] != 0);
	}
#endif
	
	pObj->memSizeForWeightData = 2*pObj->WIDTH*pObj->HEIGHT;
	
    pObj->WEIGHT = Utils_memAlloc_cached(2*pObj->WIDTH*pObj->HEIGHT, 16);
	 UTILS_assert(pObj->WEIGHT != 0);


	
    pObj->glbceCIP = &(pObj->glbceHandle.creationInputParams);
	pObj->glbceIIP = &(pObj->glbceHandle.imageInputParams);
    pObj->glbce = (GLBCEstruct*)pObj->glbceHandle.glbceHandle;
	
	
  
	 
	 pObj->glbceCIP->externalScratchMemorySize = MAX_NUM_BLOCKS*1024*sizeof(Word16);
	 pObj->glbceCIP->PersistentMemorySize = 1210*sizeof(Word16);
     pObj->glbceCIP->externalScratchMemory = (Byte*)Utils_memAlloc(pObj->glbceCIP->externalScratchMemorySize, 16);
	 UTILS_assert(pObj->glbceCIP->externalScratchMemory != 0);
	 pObj->glbceCIP->PersistentMemory = (Byte*)Utils_memAlloc(pObj->glbceCIP->PersistentMemorySize, 16);
	 UTILS_assert(pObj->glbceCIP->PersistentMemory != 0);
	 pObj->glbceIIP->boxcarMemory = (Uint16*)pObj->BOXCAR;

    /* The function CPIS_getBestDim just needs the members downsampleRatio, tonesCurvesDownsampleRatio
    numHorzCurveTables, numVertCurveTables, externalGamma to function */
    pObj->boxcarDownsampleRatio= 16;//32;
    pObj->params.boxcarDownsampleRatio= pObj->boxcarDownsampleRatio;
    pObj->params.downsampleRatio= 1;
    pObj->params.tonesCurvesDownsampleRatio= 1;
    pObj->params.numHorzCurveTables= 0;
    pObj->params.numVertCurveTables= 0;
    pObj->params.localBlockWidth= 0;
    pObj->params.localBlockHeight= 0; 
    pObj->params.externalGamma= 0;
    pObj->base.roiSize.width= pObj->WIDTH  ;
    pObj->base.roiSize.height= pObj->HEIGHT ;
    CPIS_setBestRoiAndProcBlockDim(&pObj->base, &pObj->params);	

    if (pObj->WIDTH!= pObj->base.roiSize.width || pObj->HEIGHT!= pObj->base.roiSize.height) {
     Vps_printf("ROI dimensions of %d x %d not optimal for performance. Optimal dimension is %d x %d with processsing block= %d x %d. Num horz table= %d, vert table= %d, localBlockWidth= %d.\n", \
     pObj->WIDTH, pObj->HEIGHT, pObj->base.roiSize.width, pObj->base.roiSize.height, pObj->base.procBlockSize.width, pObj->base.procBlockSize.height, pObj->params.numHorzCurveTables, pObj->params.numVertCurveTables, pObj->params.localBlockWidth);
    }
	else
	{
     Vps_printf("ROI dimensions of %d x %d are optimal for performance. Optimal dimension is %d x %d with processsing block= %d x %d. Num horz table= %d, vert table= %d, localBlockWidth= %d.\n", \
     pObj->WIDTH, pObj->HEIGHT, pObj->base.roiSize.width, pObj->base.roiSize.height, pObj->base.procBlockSize.width, pObj->base.procBlockSize.height, pObj->params.numHorzCurveTables, pObj->params.numVertCurveTables, pObj->params.localBlockWidth);
	}	

	 
	 
    {
         RM_SIMCOP_CLIENT_PARAMS stRMClientParams;
         RM_SIMCOP_STATUS eRMStatus = RM_SIMCOP_STATUS_SUCCESS;

         stRMClientParams.nSize = sizeof(RM_SIMCOP_CLIENT_PARAMS);
         stRMClientParams.pClientHandle = (RM_SIMCOP_CLIENT_HANDLE)pObj;
         /* Get Resource Manager Handle independent of resources And register Client */
         eRMStatus = RM_SIMCOP_RegisterClient(stRMClientParams, (RM_SIMCOP_CLIENT_HANDLE *) &pObj->pRMHandle);
         UTILS_assert(eRMStatus==RM_SIMCOP_STATUS_SUCCESS);

    }	
	
	{
	  Semaphore_Params semParams;
	
        Semaphore_Params_init(&semParams);

        Semaphore_construct(&pObj->semMem, MAX_DEPTH_OF_BUFFERS, &semParams);

        pObj->sem = Semaphore_handle(&pObj->semMem);

        UTILS_assert(pObj->sem != NULL);	
    }
	
    return status;
}

/* ===================================================================
 *  @func     MSP_GLBCE_Engine_Open                                               
 *                                                                    
 *  @desc     Function does the following                             
 *                                                                    
 *  @modif    This function modifies the following structures         
 *                                                                    
 *  @inputs   This function takes the following inputs                
 *            <argument name>                                         
 *            Description of usage                                    
 *            <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @outputs  <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @return   Return value of this function if any                    
 *  ==================================================================
 */                                                                   
Int32 MSP_GLBCE_Engine_Open(GlbceLink_Obj * pObj)
{
    int status = 0;
	RM_SIMCOP_STATUS eRMStatus = RM_SIMCOP_STATUS_SUCCESS;
	unsigned int bitFieldOfResources;
    RM_SIMCOP_RESOURCE_STATUS resStatus;

    bitFieldOfResources = RM_SIMCOP_RESOURCE_BFIELD_SIMCOP_HWSEQ | RM_SIMCOP_RESOURCE_BFIELD_SIMCOP_DMA ;
	resStatus.bitFieldDirtyResources = 0;
    eRMStatus = RM_SIMCOP_AcquireMultiResources((RM_SIMCOP_CLIENT_HANDLE) pObj->pRMHandle,
          bitFieldOfResources,
          RM_SIMCOP_ACQUIRE_WAIT,
          &resStatus);
    UTILS_assert(eRMStatus==RM_SIMCOP_STATUS_SUCCESS);

	if(resStatus.bitFieldDirtyResources) 
	  hasSomeOtherAlgoUsedSIMCOP = 1;
	else
	  hasSomeOtherAlgoUsedSIMCOP = 0;
	
    return status;
}

/* ===================================================================
 *  @func     MSP_GLBCE_Engine_Close                                               
 *                                                                    
 *  @desc     Function does the following                             
 *                                                                    
 *  @modif    This function modifies the following structures         
 *                                                                    
 *  @inputs   This function takes the following inputs                
 *            <argument name>                                         
 *            Description of usage                                    
 *            <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @outputs  <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @return   Return value of this function if any                    
 *  ==================================================================
 */                                                                   
Int32 MSP_GLBCE_Engine_Close(GlbceLink_Obj * pObj)
{
    int status = 0;
	RM_SIMCOP_STATUS eRMStatus = RM_SIMCOP_STATUS_SUCCESS;
	unsigned int bitFieldOfResources;
    //RM_SIMCOP_RESOURCE_STATUS resStatus;

    bitFieldOfResources = RM_SIMCOP_RESOURCE_BFIELD_SIMCOP_HWSEQ | RM_SIMCOP_RESOURCE_BFIELD_SIMCOP_DMA ;
	eRMStatus = RM_SIMCOP_ReleaseMultiResources((RM_SIMCOP_CLIENT_HANDLE) pObj->pRMHandle,
      bitFieldOfResources);
    UTILS_assert(eRMStatus==RM_SIMCOP_STATUS_SUCCESS);

    return status;
}

/* ===================================================================
 *  @func     MSP_GLBCE_Engine_DeInit                                               
 *                                                                    
 *  @desc     Function does the following                             
 *                                                                    
 *  @modif    This function modifies the following structures         
 *                                                                    
 *  @inputs   This function takes the following inputs                
 *            <argument name>                                         
 *            Description of usage                                    
 *            <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @outputs  <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @return   Return value of this function if any                    
 *  ==================================================================
 */                                                                   
Int32 MSP_GLBCE_Engine_DeInit(GlbceLink_Obj * pObj)
{
    int status = 0;
#ifdef USE_A8_FOR_TC_CALC	
	int i;
#endif	
	RM_SIMCOP_DeRegisterClient(pObj->pRMHandle);
	
	Utils_memFree_cached(pObj->WEIGHT, pObj->memSizeForWeightData);
	Utils_memFree(pObj->glbceCIP->PersistentMemory, pObj->glbceCIP->PersistentMemorySize); 
	Utils_memFree(pObj->glbceCIP->externalScratchMemory, pObj->glbceCIP->externalScratchMemorySize);
	Utils_memFree(pObj->BOXCAR, pObj->memSizeForBoxCarData);

#ifdef USE_A8_FOR_TC_CALC
	
	for(i = 0; i < MAX_DEPTH_OF_BUFFERS; i++)
	{
	    Utils_memFree_cached(BoxCarBuffers[i], pObj->memSizeForBoxCarData);
		Utils_memFree_cached(tonalCurveBuffers[i], sizeof(unsigned char)*MAX_NUM_BLOCKS*NUM_OF_BINS*2);
	}
#endif
	Semaphore_destruct(&pObj->semMem);

    pObj->sem = NULL;
	
	

	
    return status;
}


unsigned char * GLBCE_findBoxcarAndTonalCurves(GlbceLink_Obj * pObj, Uint8 * INPUT, Uint8 * BOXCAR_ISS)
{
	int i;
#ifdef USE_A8_FOR_TC_CALC	
    GlbceSupportLink_processPrm  *processPrmPost;	
#endif	
	   UInt32 startTime1 , elaspedTime1;
    static GlbceRunTimeParams GlbceParam;
    static int firstFrame = 1;
    static int frameCnt = 1;
    if(firstFrame)
    {
      GlbceParam.glbce_dcc_params_exist = 0;
      firstFrame = 0;
    }
	  if(frameCnt == 30)
    {
	    GlbceLink_drvUpdateDCC(&GlbceParam);//For now later need to read from DCC file
      frameCnt = 0;
    }
    frameCnt++;
	
	 //Calculate the Boxcar and the Tonal Curve
	/* Initialize the library */
	
     if(1)//(GlbceParam.glbce_dcc_params_exist == 0)
     {
	     //GBCE
	     pObj->glbceIIP->GBEStrength = 32;
	     pObj->glbceIIP->GCEStrength = 32;
	     //LBCE
	     pObj->glbceIIP->LBEStrength = 1<<12;
	     pObj->glbceIIP->LCEStrength = 1<<12;
     }
     else
     {
	     //GBCE
	     pObj->glbceIIP->GBEStrength = GlbceParam.gbe_strength;
	     pObj->glbceIIP->GCEStrength = GlbceParam.gce_strength;
	     //LBCE
	     pObj->glbceIIP->LBEStrength = GlbceParam.lbe_strength;
	     pObj->glbceIIP->LCEStrength = GlbceParam.lce_strength;
     }

	 {
      pObj->glbceIIP->WB_RGain =  ti2a_output_params.ipipe_awb_gain.rGain;
      pObj->glbceIIP->WB_GrGain = ti2a_output_params.ipipe_awb_gain.grGain;
      pObj->glbceIIP->WB_GbGain = ti2a_output_params.ipipe_awb_gain.gbGain;
      pObj->glbceIIP->WB_BGain =  ti2a_output_params.ipipe_awb_gain.bGain;
	  }

	   pObj->glbceIIP->SensorType = pObj->sensorType = 2;

     pObj->gGain= (pObj->glbceIIP->WB_GrGain + pObj->glbceIIP->WB_GbGain + 1)>>1;
     pObj->glbceIIP->RRCoef =  rgb2rgbMat[0]; 
	   pObj->glbceIIP->RGCoef =  rgb2rgbMat[1];
	   pObj->glbceIIP->RBCoef =  rgb2rgbMat[2];
	   pObj->glbceIIP->GRCoef =  rgb2rgbMat[3]; 
	   pObj->glbceIIP->GGCoef =  rgb2rgbMat[4];
	   pObj->glbceIIP->GBCoef =  rgb2rgbMat[5];
	   pObj->glbceIIP->BRCoef =  rgb2rgbMat[6];
	   pObj->glbceIIP->BGCoef =  rgb2rgbMat[7];
	   pObj->glbceIIP->BBCoef =  rgb2rgbMat[8];
     pObj->paramsBoxCar.dwn_sample_factor= pObj->boxcarDownsampleRatio;
     pObj->paramsBoxCar.boxcarPattern= pObj->sensorType;
     pObj->paramsBoxCar.numInBits= 12;
     pObj->paramsBoxCar.numOutBits= 8;
     pObj->paramsBoxCar.dirtyBit = 1;
     
     for (i=0;i<9;i++)
       pObj->paramsBoxCar.rgb2rgbMat[i]= rgb2rgbMat[i];
    
     /* We actually modify the rgb2rgb matrix with white balance gains */
     pObj->paramsBoxCar.rgb2rgbMat[0]= (pObj->paramsBoxCar.rgb2rgbMat[0]*pObj->glbceIIP->WB_RGain + 256)>>9;  
     pObj->paramsBoxCar.rgb2rgbMat[1]= (pObj->paramsBoxCar.rgb2rgbMat[1]*pObj->gGain + 256)>>9;  
     pObj->paramsBoxCar.rgb2rgbMat[2]= (pObj->paramsBoxCar.rgb2rgbMat[2]*pObj->glbceIIP->WB_BGain + 256)>>9;   
     pObj->paramsBoxCar.rgb2rgbMat[3]= (pObj->paramsBoxCar.rgb2rgbMat[3]*pObj->glbceIIP->WB_RGain + 256)>>9;  
     pObj->paramsBoxCar.rgb2rgbMat[4]= (pObj->paramsBoxCar.rgb2rgbMat[4]*pObj->gGain + 256)>>9;   
     pObj->paramsBoxCar.rgb2rgbMat[5]= (pObj->paramsBoxCar.rgb2rgbMat[5]*pObj->glbceIIP->WB_BGain + 256)>>9;   
     pObj->paramsBoxCar.rgb2rgbMat[6]= (pObj->paramsBoxCar.rgb2rgbMat[6]*pObj->glbceIIP->WB_RGain + 256)>>9;   
     pObj->paramsBoxCar.rgb2rgbMat[7]= (pObj->paramsBoxCar.rgb2rgbMat[7]*pObj->gGain + 256)>>9;   
     pObj->paramsBoxCar.rgb2rgbMat[8]= (pObj->paramsBoxCar.rgb2rgbMat[8]*pObj->glbceIIP->WB_BGain + 256)>>9;   
     pObj->glbceIIP->toneCurveIndex= 0;
	 pObj->glbceCIP->imgVertSize= pObj->HEIGHT;
	 pObj->glbceCIP->imgHorzSize= pObj->WIDTH;
	 pObj->glbceCIP->downsampleRatio= pObj->boxcarDownsampleRatio;
     pObj->glbceCIP->temporalAverWeightLog= 3;
	 

		 
     pObj->base.srcBuf[0].ptr= (Uint8*)INPUT;
     pObj->base.srcBuf[0].stride= pObj->WIDTH;
     pObj->base.srcFormat[0]= CPIS_BAYER;
        
     pObj->base.dstBuf[0].ptr= (Uint8*)pObj->BOXCAR;
#ifdef USE_A8_FOR_TC_CALC
     pObj->base.dstBuf[0].ptr= BoxCarBuffers[writeIndex];
	 pObj->glbceIIP->boxcarMemory = (uWord16 *) BoxCarBuffers[writeIndex];
#endif
     pObj->base.dstBuf[0].stride= 0;
     pObj->base.dstFormat[0]= CPIS_U16BIT;
                  
     pObj->base.roiSize.width= pObj->WIDTH;
     pObj->base.roiSize.height= pObj->HEIGHT;
     pObj->base.procBlockSize.width= 0;
     pObj->base.procBlockSize.height= 0;		
	 
	 
		//Prepare the process Params
		{
#ifdef USE_A8_FOR_TC_CALC
		   Semaphore_pend(pObj->sem, BIOS_WAIT_FOREVER);
		   
		   processPrmPost = &processPrm[writeIndex];
#ifdef USE_ISS_BOXCAR
           //Vps_rprintf("M3 sending buffer address 0x%x\n", BOXCAR_ISS);
		   processPrm[writeIndex].boxCarPtr = BOXCAR_ISS;//BoxCarBuffers[writeIndex];
		   processPrm[writeIndex].rgbMatPtr = (Int16 *) BoxCarBuffers[writeIndex];
		   processPrm[writeIndex].rgbMatSize = 32;
		   memcpy((void*)BoxCarBuffers[writeIndex], (void*)pObj->paramsBoxCar.rgb2rgbMat, processPrm[writeIndex].rgbMatSize);
		   cacheWb((void*)BoxCarBuffers[writeIndex], processPrm[writeIndex].rgbMatSize, NULL);
#else		
		   processPrm[writeIndex].boxCarPtr = BoxCarBuffers[writeIndex];
#endif		   
		   processPrm[writeIndex].tonalCurvePtr = tonalCurveBuffers[writeIndex];
		   processPrm[writeIndex].boxCarSize = pObj->memSizeForBoxCarData;
		   processPrm[writeIndex].tonalCurveSize = sizeof(unsigned char)*MAX_NUM_BLOCKS*NUM_OF_BINS*2;
		   processPrm[writeIndex].index = writeIndex;
		   processPrm[writeIndex].GBEStrength = pObj->glbceIIP->GBEStrength;
		   processPrm[writeIndex].LBEStrength = pObj->glbceIIP->LBEStrength;
		   processPrm[writeIndex].GCEStrength = pObj->glbceIIP->GCEStrength;
		   processPrm[writeIndex].LCEStrength = pObj->glbceIIP->LCEStrength;
		   processPrm[writeIndex].WB_RGain = pObj->glbceIIP->WB_RGain;
		   processPrm[writeIndex].WB_GrGain = pObj->glbceIIP->WB_GrGain;
		   processPrm[writeIndex].WB_GbGain = pObj->glbceIIP->WB_GbGain;
		   processPrm[writeIndex].WB_BGain = pObj->glbceIIP->WB_BGain;
		   processPrm[writeIndex].sensorType = 2;
		   
		   processPrm[writeIndex].toneCurveIndex = 0;
		   processPrm[writeIndex].imgVertSize = pObj->HEIGHT;
		   processPrm[writeIndex].imgHorzSize = pObj->WIDTH;
		   processPrm[writeIndex].downsampleRatio = pObj->boxcarDownsampleRatio;
		   processPrm[writeIndex].temporalAverWeightLog = 3;
		   
           
		
   		   writeIndex++;
           if(writeIndex == MAX_DEPTH_OF_BUFFERS)
               writeIndex = 0;		   
#endif
		}
	 
	   startTime1 = Utils_getCurTimeInMsec();


	 
#ifdef USE_ISS_BOXCAR
         //DO NOTHING LIKE BOXCAR COMPUTATION

#else
#ifdef RESET_TO_BE_USED

	if(isCPIS_glbceCalled)
	{
        CPIS_delete(pObj->handle);	
        isCPIS_glbceCalled = 0;		
	}
#endif	                 
		if (CPIS_boxcar(
            &pObj->boxcar_handle,
            &pObj->base,
            &pObj->paramsBoxCar,
            CPIS_SYNC
            )== -1) {
            Vps_printf("\nCPIS_boxcar() error %d frameNum %d\n", CPIS_errno, pObj->frameNum);
            
        };
#endif		
	   elaspedTime1 = Utils_getCurTimeInMsec();
	   CPIS_Boxcar_Time =  elaspedTime1 - startTime1;
		
//#ifdef SYSTEM_DEBUG_GLBCE
		if(printCnt / 32)
		{
		printCnt = 0;
		Vps_printf("----------------------------------------------\n");
		//Vps_printf("BoxcarToneCurve_Time is %d msec \n", BoxcarToneCurve_Time);
		Vps_printf("CPIS_glbce_Time is %d msec \n", CPIS_glbce_Time);
		Vps_printf("CPIS_reset_Time is %d msec \n", CPIS_reset_Time);
		Vps_printf("GLBCE_Exec_Time is %d msec \n", GLBCE_Exec_Time);
		Vps_printf("CPIS_Boxcar_Time is %d msec \n", CPIS_Boxcar_Time);
		
		Vps_printf("----------------------------------------------\n");
		}
//#endif		
		
		
		
		
		
#ifdef USE_A8_FOR_TC_CALC
	          System_linkControl(pObj->createArgs.glbceSupportID,
                             SYSTEM_CMD_NEW_DATA,
                             processPrmPost,
                             sizeof(GlbceSupportLink_processPrm),FALSE);
							 
		//totalNumberOfTcRcvd++;
#endif

#ifdef USE_A8_FOR_TC_CALC
      if(pObj->frameNum == 0)
#endif
      GLBCE_algConfig(&pObj->glbceHandle);

#ifdef USE_A8_FOR_TC_CALC
     if(pObj->frameNum == 0)
#endif
	   GLBCE_init(&pObj->glbceHandle);
	 
#ifdef USE_A8_FOR_TC_CALC
	 //Read the tonal curve
	 if(totalNumberOfTcRcvd)
	 {
         pObj->glbce->toneCurves[0] = tonalCurveBuffers[readIndex];
         pObj->glbce->toneCurves[1] = tonalCurveBuffers[readIndex]+sizeof(unsigned char)*MAX_NUM_BLOCKS*NUM_OF_BINS;
	  
         readIndex++;
         if(readIndex == MAX_DEPTH_OF_BUFFERS)
           readIndex = 0;		 
         totalNumberOfTcRcvd--;
         Semaphore_post(pObj->sem);		   
     }
     /* Benchmark the actual processing */
     if(pObj->frameNum == 0)
#endif
	 GLBCE_run(&pObj->glbceHandle);
	 
	 printCnt++;
	 
	 return (unsigned char *) pObj->glbce->toneCurves[0];
}



/* ===================================================================
 *  @func     MSP_GLBCE_ProcessFrame                                               
 *                                                                    
 *  @desc     Function does the following                             
 *                                                                    
 *  @modif    This function modifies the following structures         
 *                                                                    
 *  @inputs   This function takes the following inputs                
 *            <argument name>                                         
 *            Description of usage                                    
 *            <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @outputs  <argument name>                                         
 *            Description of usage                                    
 *                                                                    
 *  @return   Return value of this function if any                    
 *  ==================================================================
 */                                                                   
Int32 MSP_GLBCE_ProcessFrame(GlbceLink_Obj * pObj,
                           
                           FVID2_Frame * currentImageBuffer,
                           FVID2_Frame * outputImageBuffer)
{
	int status = 0;
static Uint8 *tonecurvePtr;	
	

   Uint8 * INPUT = currentImageBuffer->addr[0][0];
   Uint8 * OUTPUT = outputImageBuffer->addr[0][0];
   Uint8 * BOXCAR_ISS = currentImageBuffer->blankData;
   UInt32 startTime , elaspedTime;

    if (  (pObj->frameNum%pObj->frequencyTonalCurve == 0) && glbceFlag)
	{
	   startTime = Utils_getCurTimeInMsec();
	   tonecurvePtr = GLBCE_findBoxcarAndTonalCurves(pObj, INPUT, BOXCAR_ISS);
	   elaspedTime = Utils_getCurTimeInMsec();
	   BoxcarToneCurve_Time =  elaspedTime - startTime;
       isBoxCarAndToneCurveCalled = 1;
    }
	
	{
	
	pObj->params.weightPtr= (CPIS_GlbceWeightStruct*)pObj->WEIGHT;
     pObj->params.boxcarDownsampleRatio= pObj->boxcarDownsampleRatio;
     pObj->params.generateWeight= pObj->frameNum? 0 : 1;
		pObj->params.downsampleRatio= 1;
		pObj->params.toneCurvesPtr= tonecurvePtr;
		pObj->params.numHorzCurveTables= pObj->glbce->numHorzBlocks;
		pObj->params.numVertCurveTables= pObj->glbce->numVertBlocks;
     pObj->params.localBlockWidth= pObj->glbce->localBlockWidth;
     pObj->params.localBlockHeight= pObj->glbce->localBlockHeight;
     pObj->params.tonesCurvesDownsampleRatio= 1;
		pObj->params.qFormat= 8;
		pObj->params.sensorType= pObj->sensorType;
		pObj->params.externalGamma= 0;
		pObj->params.numBits= 12;	 
		pObj->params.dirtyBit = hasSomeOtherAlgoUsedSIMCOP;	 
	
	
     pObj->base.srcBuf[0].ptr= (Uint8*)INPUT;
     pObj->base.srcBuf[0].stride= pObj->WIDTH;
     pObj->base.srcFormat[0]= CPIS_BAYER;
	 
	 pObj->base.srcBuf[1].ptr= (Uint8*) pObj->params.weightPtr;

     pObj->base.dstBuf[0].ptr= (Uint8*)OUTPUT;
     pObj->base.dstBuf[0].stride= pObj->WIDTH;
     pObj->base.dstFormat[0]= CPIS_BAYER;
		 
	 pObj->base.roiSize.width= pObj->WIDTH;
     pObj->base.roiSize.height= pObj->HEIGHT;//(HEIGHT/BLOCK_HEIGHT)*BLOCK_HEIGHT;
     pObj->base.procBlockSize.width= 0;//20;//0;//BLOCK_WIDTH; // se to 0 to let API pick the optimum settings
     pObj->base.procBlockSize.height= 0;//20;//0;//BLOCK_HEIGHT;

#ifdef RESET_TO_BE_USED
    if(isBoxCarAndToneCurveCalled || hasSomeOtherAlgoUsedSIMCOP  )
#else
    if(1 || isBoxCarAndToneCurveCalled || hasSomeOtherAlgoUsedSIMCOP)
#endif
	 {
#ifdef RESET_TO_BE_USED
	   if(isCPIS_glbceCalled)
       {	   
	      CPIS_delete(pObj->handle);
	  	  isCPIS_glbceCalled = 0;
	   }
#endif	   
	   startTime = Utils_getCurTimeInMsec();
		 if (CPIS_glbce(
			 &pObj->handle,
			 &pObj->base,
			 &pObj->params,
			 CPIS_ASYNC
			 )== -1) {
			  Vps_printf("\nCPIS_glbce() error %d frameNum %d\n", CPIS_errno, pObj->frameNum);

		 }
#ifdef RESET_TO_BE_USED
		 else
		    isCPIS_glbceCalled = 1;
#endif			
	   elaspedTime = Utils_getCurTimeInMsec();
	   CPIS_glbce_Time=  elaspedTime - startTime;
	   isBoxCarAndToneCurveCalled = 0;
     }
	 else
	 {
	   startTime = Utils_getCurTimeInMsec();

       CPIS_updateSrcDstPtr(pObj->handle, &pObj->base);
       CPIS_reset(pObj->handle);

       elaspedTime = Utils_getCurTimeInMsec();
	   CPIS_reset_Time =  elaspedTime - startTime;
	 }
	   startTime = Utils_getCurTimeInMsec();
       CPIS_start(pObj->handle);
       CPIS_wait(pObj->handle);
	   elaspedTime = Utils_getCurTimeInMsec();
	   GLBCE_Exec_Time =  elaspedTime - startTime;
	   
#ifndef RESET_TO_BE_USED
	   CPIS_delete(pObj->handle);
#endif	      
	 }


    pObj->frameNum++;
    return status;
}
