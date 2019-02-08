/*--Task_Blinky.c
 *
 *  Author:			Gary J. Minden
 *	Organization:	KU/EECS/EECS 388
 *  Date:			February 22, 2016
 *
 *  Description:	Blinks LED D1 on Tiva TMC41294 Evaluation board
 *
 */

#include	"inc/hw_ints.h"
#include	"inc/hw_memmap.h"
#include	"inc/hw_types.h"
#include	"inc/hw_uart.h"

#include	<stddef.h>
#include	<stdbool.h>
#include	<stdint.h>
#include	<stdarg.h>

#include	"driverlib/sysctl.h"
#include	"driverlib/pin_map.h"
#include	"driverlib/gpio.h"

#include	"FreeRTOS.h"
#include	"task.h"

#include    "Drivers/EECS388_DAC.h"
extern void Task_Speakerbuzz( void *pvParameters ) {
    //DAC_State= DAC_State ^ DAC_Toggle;
	uint32_t	DAC_State=0X0000;

    //
    // Enable the GPIO Port N.
    //
	//DAC_State= DAC_State ^ DAC_Toggle;
    EECS388_DAC_Initialization();
    bool high = false;



	while ( 1 ) {
       if(high){
           EECS388_WriteDAC(0X3FFF);
           high =false;
       }
       else{
           EECS388_WriteDAC(0X0000);
           high=true;
       }

	               vTaskDelay(pdMS_TO_TICKS(2) );
	}
}



