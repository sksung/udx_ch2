/*
 * Copyright (C) 2009, Texas Instruments, Incorporated
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* 1-4 */		BIT(0), BIT(0), BIT(0), BIT(0), //# 1[W30]->MMC1_CLK,           	2[Y29]->MMC1_CMD,        		3[W31]->MMC1_DAT0,         		4[AA30]->MMC1_DAT1
/* 5-8 */		BIT(0), BIT(0), BIT(0), BIT(7), //# 5[U29]->MMC1_DAT2,          	6[Y27]->MMC1_DAT3,       		7[U28]->NC,                		8[AB30]->B_REV_GP0[1]
/* 9-12 */		BIT(7), BIT(7), BIT(7), BIT(0),	//# 9[AA29]->B_REV_GP0[2],      	10[AA28]->B_REV_GP0[3],  		11[AA26]-B_REV_GP0[4],     		12[Y31]->NC
/* 13-16 */		BIT(0), BIT(7), BIT(2), BIT(0), //# 13[Y30]-NC,                 	14[AF31]->USB1_VBUS[1],  			 		15[AF27]->B_AIC_MCLK,      		16[AG30]->NC
/* 17-20 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 17[AD28]->NC,               	18[AE29]->NC,            		19[AD30]->NC,              		20[AF30]->NC
/* 21-24 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 21[AF29]->NC,               	22[AE31]->NC,            		23[AE30]->NC,              		24[AC31]->NC
/* 25-28 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 25[AD26]->NC,               	26[AD27]->NC,            		27->RESERVED,              		28->RESERVED,
/* 29-32 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 29->RESERVED,               	30->RESERVED,            		31[AC23]->B_AIC_BCLK,      		32[AB22]->B_AIC_WCLK
/* 33-36 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 33[AD29]->NC,               	34[AC24]->NC,            		35[Y22]->B_AIC_DIN,        		36[Y21]->B_AIC_DOUT
/* 37-40 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 37->RESERVED,               	38->RESERVED,            		39->RESERVED,              		40->RESERVED
/* 41-44 */		BIT(1), BIT(1), BIT(0), BIT(0),	//# 41[AB31]->NC,               	42[AC30]->NC,            		43->RESERVED,              		44->RESERVED
/* 45-48 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 45->RESERVED,               	46->RESERVED,            		47->RESERVED,              		48->RESERVED
/* 49-52 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 49->RESERVED,               	50->RESERVED,            		51->RESERVED,              		52->RESERVED
/* 53-56 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 53->RESERVED,               	54->RESERVED,            		55->RESERVED,              		56->RESERVED
/* 57-60 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 57->RESERVED,               	58->RESERVED,            		59->RESERVED,              		60->RESERVED
/* 61-64 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 61->RESERVED,               	62->RESERVED,            		63->RESERVED,              		64->RESERVED
/* 65-68 */		BIT(0), BIT(0), BIT(0), BIT(1),	//# 65->RESERVED,               	66->RESERVED,            		67->RESERVED,              		68[M21]->UART[2]_TXD
/* 69-72 */		BIT(1), BIT(0), BIT(0), BIT(0),	//# 69[L22]->UART[2]_RXD,       	70[J26]->UART[0]_RXD,    		71[E28]->UART[0]_TXD,      		72[D30]->NC
/* 73-76 */		BIT(0), BIT(5), BIT(5), BIT(2),	//# 73[D31]->NC,                	74[E31]->I2C2_SCL,       		75[E29]->I2C2_SDA,         		76[E30]->UART1_TXD
/* 77-80 */		BIT(2), BIT(0), BIT(0), BIT(7),	//# 77[N26]->UART1_RXD,         	78[D2]->I2C1_SCL,        		79[D1]->I2C1_SDA,          		80[G28]->MMC1_SD_CD_GP1[6]
/* 81-84 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 81[G29]->NC,                	82[N24]->NC,             		83[J27]->NC,               		84[J28]->NC
/* 85-88 */		BIT(0), BIT(0), BIT(0), BIT(0), //# 85[J29]->NC,                	86[M29]->NC,             		87[M27]->NC,               		88[N23]->NC
/* 89-92 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 89[W6]->GPMC_D[0],          	90[W4]->GPMC_D[1],       		91[W3]->GPMC_D[2],         		92[U2]->GPMC_D[3]
/* 93-96 */		BIT(0), BIT(0), BIT(0), BIT(0),	//# 93[W9]->GPMC_D[4],          	94[T5]->GPMC_D[5],       		95[T3]->GPMC_D[6],         		96[T2]->GPMC_D[7]
/* 97-100 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 97[T1]->BTMODE[8],          	98[T8]->BTMODE[9],       		99[R6]->BTMODE[10],        		100[R4]->BTMODE[11]
/* 101-104 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 101[R3]->BTMODE[12],        	102[R2]->BTMODE[13],     		103[R1]->BTMODE[14],       		104[P2]->BTMODE[15]
/* 105-108 */	BIT(0), BIT(0), BIT(0), BIT(7),	//# 105[M1]->NC,                	106[M2]->NC,             		107[M3]->NC,               		108[M5]->RSTOUTn_GP1[14]
/* 109-112 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 109[N9]->NC,                	110[N1]->NC,             		111[N2]->NC,               		112[R8]->NC
/* 113-116 */	BIT(7), BIT(7), BIT(7), BIT(0),	//# 113[AE3]->MCU_DEF_GPIO, 		114[AE2]->MCU_DEF_GPIO,  		115[AE1]->3101_RST_GP1[21],		116[AD2]->NC
/* 117-120 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 117[AD1]->NC,               	118[AC8]->NC,            		119[AC5]->NC,              		120[AC4]->NC
/* 121-124 */	BIT(0), BIT(0), BIT(0), BIT(7),	//# 121[AC6]->NC,               	122[AC9]->GPMC_NCS0,     		123[AA12]->NC,             		124[AC3]->GPMC_WP_GP1[25]
/* 125-128 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 125[AF2]->NC,               	126[AG6]->NC,            		127[AB9]->NC,              		128[AA10]->GPMC_NADV_ALE
/* 129-132 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 129[Y8]->GPMC_OEN_REN,      	130[Y5]->GPMC_WEN,       		131[Y3]->GPMC_NBE0_CLE,    		132[Y11]->NC
/* 133-136 */	BIT(0), BIT(0), BIT(4), BIT(4),	//# 133[W8]->GPMC_WAIT0,        	134[H12]->VIN[0]B_CLK,   		135[C12]->VIN[0]B_HSYNC,   		136[J13]->VIN[0]B_VSYNC
/* 137-140 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 137[C9]->VIN[0]A_CLK,       	138[D13]->VIN[0]A_HSYNC, 		139[C13]->VIN[0]A_VSYNC,   		140[B18]->VIN0_D0
/* 141-144 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 141[A17]->VIN0_D1,          	142[B17]->VIN0_D2,       		143[C17]->VIN0_D3,         		144[D17]->VIN0_D4
/* 145-148 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 145[F17]->VIN0_D5,          	146[L20]->VIN0_D6,       		147[H20]->VIN0_D7,         		148[B16]->VIN0B_D0
/* 149-152 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 149[C16]->VIN0B_D1,         	150[E16]->VIN0B_D2,      		151[H17]->VIN0B_D3,        		152[J16]->VIN0B_D4
/* 153-156 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 153[H16]->VIN0B_D5,         	154[F13]->VIN0B_D6,      		155[H13]->VIN0B_D7,        		156[K11]->NC
/* 157-160 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 157[E12]->NC,               	158[K10]->NC,            		159[D7]->NC,               		160[F9]->NC
/* 161-164 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 161[C7]->NC,                	162[A6]->NC,             		163[A5]->NC,               		164[B5]->NC
/* 165-168 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 165[C5]->NC,            		166[B4]->NC,         	 		167[A3]->NC,               		168[A2]->NC
/* 169-172 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 169[B2]->NC,            		170[C1]->NC,         	 		171[C2]->NC,           			172[D5]->NC
/* 173-176 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 173[H9]->NC,         			174[J10]->NC, 			 		175[B3]->NC,       				176[K22]->NC
/* 177-180 */	BIT(0), BIT(0), BIT(7), BIT(0),	//# 177[F21]->NC,               	178[E20]->NC,            		179[C20]->BSL_RTS_GP2[21], 		180[F24]->NC
/* 181-184 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 181[D21]->NC,               	182[J23]->NC,            		183[H23]->NC,              		184[J24]->NC
/* 185-188 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 185[E24]->NC,               	186[D24]->NC,            		187[C24]->NC,              		188[C25]->NC
/* 189-192 */	BIT(0), BIT(0), BIT(0), BIT(0), //# 189[C26]->NC, 					190[E26]->NC, 			 		191[B26]->NC, 					192[A26]->NC
/* 193-196 */	BIT(0), BIT(0), BIT(0), BIT(7), //# 193[B25]->NC, 					194[B27]->NC, 			 		195[A27]->NC, 					196[C28]->MICOM_HOLD_GP2[26]
/* 197-200 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 197[B28]->NC, 					198[B29]->NC, 			 		199[A29]->NC, 					200[C30]->NC
/* 201-204 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 201[B30]->NC, 					202[A30]->NC, 			 		203[B31]->NC, 					204[D3]->NC
/* 205-208 */	BIT(7), BIT(7), BIT(7), BIT(7), //# 205[E2]->VIN[0]B_PWR_GP2[29],	206[F5]->TV_OUT_DET_GP2[30],	207[F1]->VIN[0]A_LED_GP2[31], 	208[F2]->VIN[0]B_PDN_GP3[0]
/* 209-212 */	BIT(7), BIT(7), BIT(7), BIT(7), //# 209[F3]->LED1_GP3[1], 			210[G1]->LED2_GP3[2], 			211[G2]->LED3_GP3[3], 			212[H3]->VIN[0]B_LOCKN_GP3[4]
/* 213-216 */	BIT(0), BIT(0), BIT(7), BIT(7),	//# 213[G3]->NC, 					214[H5]->NC, 					215[H6]->REC_KEY_GP3[7], 		216[J8]-VIN[0]A_PDN_GP3[8]
/* 217-220 */	BIT(7), BIT(7), BIT(7), BIT(7),	//# 217[J1]->MICOM_GP3[9], 			218[H4]->MICOM_GP3[10], 		219[J9]->VIN[0]B_LED_GP3[11], 	220[L3]->G_INT_GP3[12]
/* 221-224 */	BIT(7), BIT(7), BIT(0), BIT(7),	//# 221[K1]->MICOM_GP3[13], 		222[H2]->VIN[0]B_LED_GP3[14], 	223[M11]->NC, 					224[L12]->VIN[0]A_PWR_EN_GP3[16]
/* 225-228 */	BIT(7), BIT(7), BIT(7), BIT(0),	//# 225[M10]->VIN[0]A_LED_GP3[17], 	226[J2]->VIN[0]A_LOCKN_GP3[18], 227[K2]->ETH_INT_GP3[19], 		228[L2]->NC
/* 229-232 */	BIT(7), BIT(0), BIT(0), BIT(0),	//# 229[L4]->GPS_PWR_EN_GP3[21], 	230[L6]->NC, 					231[M8]->NC, 					232[AG1]->EMAC_RMREFCLK
/* 233-236 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 233[AG2]->MDIO_MDCLK, 			234[AG3]->MDIO_MDIO, 			235[AG4]->NC, 					236[AH1]->NC
/* 237-240 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 237[AH1]->NC, 					238[AJ2]->NC, 					239[AK1]->NC, 					240[AK2]->NC
/* 241-244 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 241[AL2]->NC, 					242[AL3]->NC, 					243[AK3]->NC, 					244[AK4]->NC
/* 245-248 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 245[AJ4]->NC, 					246[AL5]->NC, 					247->RESERVED, 					248[AJ6]->NC
/* 249-252 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 249[AL6]->NC, 					250[AK6]->NC, 					251[AJ7]->NC, 					252[AK7]->EMAC1_RMRXD0
/* 253-256 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 253[AE4]->EMAC1_RMRXD1, 		254[AK8]->EMAC1_RMRXER, 		255[AJ8]->EMAC1_RMCRSDV, 		256[AH8]->EMAC1_RMTDX0
/* 257-260 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 257[AG8]->EMAC1_RMTDX1, 		258[AF8]->EMAC1_RMTXEN, 		259[AJ31]->NC, 					260[AH29]->RESET
/* 261-264 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 261[AH31]->NMI 					262[AJ30]->RSTOUT_WD_OUT,		263[T27]->I2C[0]_SCL,			264[T24]->I2C[0]SDA
/* 265-268 */	BIT(0), BIT(0), BIT(0), BIT(0),	//# 265->RESERVED, 					266->RESERVED, 					267->RESERVED, 					268->RESERVED
/* 270 usb0_drvvbus, fn1, pulldn enable */
/* 269-271 */	BIT(0), BIT(1), BIT(0),			//# 269->RESERVED, 					270[K23]->USB0_VBUS_GP0[7], 	271->RESERVED
