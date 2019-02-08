/*--Task_Blinky.c
 *
 *  Author:         Gary J. Minden
 *  Organization:   KU/EECS/EECS 388
 *  Date:           February 22, 2016
 *
 *  Description:    Blinks LED D1 on Tiva TMC41294 Evaluation board
 *
 */

#include    "inc/hw_ints.h"
#include    "inc/hw_memmap.h"
#include    "inc/hw_types.h"
#include    "inc/hw_uart.h"

#include    <stddef.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <stdarg.h>

#include    "driverlib/sysctl.h"
#include    "driverlib/pin_map.h"
#include    "driverlib/gpio.h"

#include    "FreeRTOS.h"
#include    "task.h"

#include    "Drivers/EECS388_DAC.h"

extern bool makesound;
enum ButtonState {idle,debounce, pressed};
#define BUTTONS (GPIO_PIN_1|GPIO_PIN_0)
static enum ButtonState current_button;
static uint32_t Previous_Button_Data;
static uint32_t Task_Buttons_DeltaExecute=0;

extern void Task_ButtonState( void *pvParameters ) {
uint32_t Button_Data=0;

SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);

GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE,BUTTONS);

GPIOPadConfigSet(GPIO_PORTJ_BASE,BUTTONS,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

current_button= idle;
Button_Data=GPIOPinRead(GPIO_PORTJ_BASE, BUTTONS);
Previous_Button_Data=Button_Data;

UARTStdio_Initialization();

while(1){
        Button_Data= GPIOPinRead(GPIO_PORTJ_BASE,BUTTONS);
        switch(current_button){
        case idle:{
        makesound=false;
        if(Button_Data != BUTTONS)
             {
                current_button= debounce;
                Task_Buttons_DeltaExecute =10;
             }
           Task_Buttons_DeltaExecute=1;
        } break;


        case debounce:{
         if(Button_Data != BUTTONS && Previous_Button_Data == Button_Data)
             {
                current_button=idle;
             }
         else
             {
                 current_button= pressed;
             }
        }break;

        case pressed:{

            if(current_button=1){
                current_button=idle;
            }
        } break;

            }

        }
}





/*extern int Select = 0;

static long bSignal;

static long keepButtons;

enum buttonStates {

    idle, pressed, debounce

};

enum buttonStates bState = idle;

uint32_t delay=1;


extern void Task_Button(void *pvParameters) {



    //

    // Enable the GPIO Port G.

    //

    SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOG);



    //

    // Configure GPIO_G to drive the Status LED.

    //

    GPIOPinTypeGPIOInput( GPIO_PORTG_BASE, SELECT);

    GPIOPadConfigSet( GPIO_PORTG_BASE,

    SELECT, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    while(1)

    {

        //UARTStdio_Initialization();

        bSignal = GPIOPinRead(GPIO_PORTG_BASE, SELECT);

        keepButtons = bSignal;

        switch (bState) {

        case idle:

            if (bSignal != 0b10000000) {

                bState = debounce;

                 delay=10;

            }

            break;

        case debounce:

            if (bSignal != 0b10000000 && bSignal == keepButtons) {

                    bState = pressed;

            } else {

                bState = idle;
            }

            delay=1;
        break;



        case pressed:

        if (bSignal == 0x80) {

            Select = 1;
            bState = idle;

        }

        break;
    }

        vTaskDelay( (delay*100) );


    }

}*/



