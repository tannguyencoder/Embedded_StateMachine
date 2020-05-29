/*
 * main.c
 */
#include "includes.h"


int main(void) {
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
	Config_LED_R(); //doorCtrlIninit
	Config_LED_G();
	Config_SWITCH(); //Sensor init
	SysTickPeriodSet(SysCtlClockGet()/1000);
	IntMasterEnable();
	SysTickEnable();
	SysTickIntEnable();

	initDoorState();
	initLedState();
	initmotionState();

	while(1)
	{
		motionStateMachineUpdate();
		doorStateMachineUpdate();
		ledStateMachineUpdate();
	}
}
