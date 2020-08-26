/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_util.c
 * @brief	application utility functions
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>		//# fork...
#include <sys/wait.h>	//# waitpid

#include "app_comm.h"
#include "app_util.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    util mem_alloc/free function
* @section  [desc]
*****************************************************************************/
void *util_mem_alloc(unsigned int msize)
{
	void *ptr;

	//--- memory alloc ------------------------------------
	ptr = malloc (msize);

	return ptr;
}

void util_mem_free(void *ptr)
{
	//--- memory free ------------------------------------
	free (ptr);
}

/*****************************************************************************
* @brief    util memory copy function
* @section  [desc]
*****************************************************************************/
int util_mem_copy(void *pDes, void *pSrc, int size)
{
    if (pDes == NULL || pSrc == NULL){
        return -1;
    }

	memcpy(pDes, pSrc, size);

    return 0;
}

/*****************************************************************************
* @brief    system exec function
* @section  [desc]
*****************************************************************************/
int util_sys_exec(char *arg)
{
    int numArg, i, j, k;
    int len, status;

    char exArg[10][64];
	pid_t chId;

    if (arg[0] == '\0')
        return 0;

    j = 0; 	k = 0;
	len = strlen(arg);

    for (i = 0; i < len; i++) {
        if (arg[i] == ' ') {
		    exArg[j][k] = '\0';
		    j ++; k = 0;
		} else {
		    exArg[j][k] = arg[i];
		    k ++;
		}
	}

    if (exArg[j][k - 1] == '\n') {
	    exArg[j][k - 1] = '\0';
	} else {
	    exArg[j][k] = '\0';
	}

	numArg = j + 1;

	if (numArg > 10) {
	    dprintf("The no of arguments are greater than 10" \
	    		"calling standard system function...\n");
	    return (util_sys_exec(arg));
	}

    chId = fork();
	if (chId == 0) {
	    // child process
	    switch (numArg) {
	    case 1:
	        execlp(exArg[0],exArg[0],NULL);
	        break;
	    case 2:
	        execlp(exArg[0],exArg[0],exArg[1],NULL);
	        break;
	    case 3:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],NULL);
	        break;
	    case 4:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],NULL);
	        break;
	    case 5:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               NULL);
	        break;
	    case 6:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],NULL);
	        break;
	    case 7:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],NULL);
	        break;
	    case 8:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],NULL);
	        break;
	    case 9:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],exArg[8],NULL);
	        break;
	    case 10:
	        execlp(exArg[0],exArg[0],exArg[1],exArg[2],exArg[3],exArg[4],
	               exArg[5],exArg[6],exArg[7],exArg[8],exArg[9],NULL);
	        break;
		}
        eprintf("execlp failed...\n");
	    exit(0);
	} else if(chId < 0) {
		eprintf("Failed to create child process\n");
		return -1;
	} else {
		/* parent process */
		/* wait for the completion of the child process */
		/* 3th option WNOHANG->non-block 0->block */
		waitpid(chId, &status, 0);
		#if 0
		if (WIFEXITED(status))
			dprintf("Chiled exited with the code %d\n", WEXITSTATUS(status));
		else
			eprintf("Child terminated abnormally..\n");
		#endif
	}

    return 0;
}

/*****************************************************************************
* @brief    console menu function
* @section  [desc]
*****************************************************************************/
static int is_number(char *str)
{
	int i, len;

	len = strlen(str) - 1;		//# skip '\n'
	if(len <= 0) {
		return 0;
	}

	for(i=0;i<len;i++)
		if( ! ( (str[i] >= '0') && (str[i]<= '9') ) )
			return 0;

	return 1;
}

int menu_get_data(void)
{
	char buf[32];

	fgets(buf, 32, stdin);

	if(is_number(buf))
		return (int)atoi(buf);
	else
		return -1;
}

char menu_get_cmd(void)
{
	char buf[32];

	fgets(buf, 32, stdin);

	return (buf[0]);
}

/*****************************************************************************
* @brief    time trace function
* @section  [act] 1 : start time trace
*                 0 : end time trace and print elapsed time
*****************************************************************************/
static unsigned long btime=0;
void __time_trace(int act)
{
	unsigned long elapsed_time;

	if(act) {
		btime = app_get_time();
	}
	else {
		elapsed_time = app_get_time() - btime;
		printf("--- %ld ms\n", elapsed_time);
		btime += elapsed_time;
	}
}
