/*---------------------------------------------------------------getInt.c--------------------------------------------------------------*/


/*******************************************************************************
 * Include
 ******************************************************************************/
#include<stdio.h>
#include<stdint.h>
#include"getInt.h"


/*--------------------get uint8----------------------------------------
@para var: pointer receive your address of variable
*/
int getInt8(uint8_t *var,)
{
    uint8_t retVal = 0;                                                         /*variable to return you enter value is ok or not*/
    uint32_t newVar;                                                            /* variable to receive your value*/
    fflush(stdin);
    scanf("%d", &newVar);
    if (newVar > 255)
    {
        printf("\n Your value is out of range!!!");
        retVal = 1;
    }
    else
    {
        *var = (uint8_t)newVar;
    }
    return retVal;
}


/*--------------------get uint16----------------------------------------
@para var: pointer receive your address of variable
*/
int getInt16(uint16_t *var)
{
    uint8_t retVal = 0;
    uint32_t newVar;
    fflush(stdin);
    scanf("%d", &newVar);
    if (newVar > 65535)
    {
        printf("\n Your value is out of range!!!");
        retVal = 1;
    }
    else
    {
        *var = (uint16_t)newVar;
    }
    return retVal;
}


/*-------------------------------------------------------------------END---------------------------------------------------------------------------------*/
