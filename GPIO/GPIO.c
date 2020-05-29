/*
 * GPIO.c
 *
 *  Created on: May 29, 2020
 *      Author: Tan
 */

#include "../includes.h"
#include "GPIO.h"

void Config_LED_R(void){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(LED_PORT_R,LED_R);
	GPIOPinTypeGPIOOutput(LED_PORT_R,LED_G);
	GPIOPinWrite(LED_PORT_R,LED_R,0);
	GPIOPinWrite(LED_PORT_R,LED_G,0);

}
void Config_LED_G(void){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinTypeGPIOOutput(LED_PORT_G,LED_G);
	GPIOPinWrite(LED_PORT_G,LED_R,0);
}
void Config_SWITCH(void){
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOInput(SW_PORT,SW_1);
	GPIOPadConfigSet(SW_PORT,SW_1,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD_WPU);

}
