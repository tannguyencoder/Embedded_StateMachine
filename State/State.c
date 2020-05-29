/*
 * State.c
 *
 *  Created on: May 29, 2020
 *      Author: Tan
 */
#include "state.h"
#include "../includes.h"
#include "state.h"

static motionDetector_t mnt;
static ledState_t ledState;
static doorState_t doorState;
static motionState_t motionState;
static unsigned int ledTimerCount;
static unsigned int doorTimerCount;
static unsigned int motionTimerCount;

motionSensor_t motionSensor(void){
    if(GPIOPinRead(SW_PORT,SW_1)==0){
        return MOTION;
    }
    else return NOMOTION;
}
void motionStateMachineUpdate(void){
    switch(motionState){
        case S_NOMOTION:
            if(motionSensor()==MOTION){
                motionTimerCount=50;
                motionState=S_WAIT_MOTION;
            }
            break;
        case S_WAIT_MOTION:
            if(motionSensor()==NOMOTION){
                motionState=S_NOMOTION;
            }
            else if(motionTimerCount==0){
                motionState=S_MOTION;
            }
            break;
        case S_MOTION:
            if(motionSensor()==NOMOTION){
                motionState=S_WAIT_NOMOTION;
                motionTimerCount=50;
            }
            break;
        case S_WAIT_NOMOTION:
            if(motionSensor()==MOTION){
                motionState=S_MOTION;
            }
            else if(motionTimerCount==0){
                motionState=S_NOMOTION;
            }
            break;
    }
    switch (motionState)
    {
        case S_NOMOTION:
        case S_WAIT_MOTION:
            mnt =D_NOMOTION;
            break;
        case S_MOTION:
        case S_WAIT_NOMOTION:
            mnt = D_MOTION;
            break;
    }

}

void doorStateMachineUpdate(void){
    switch(doorState){
        case S_DOOR_CLOSE:
            if(mnt ==D_MOTION){
                doorState=S_DOOR_OPEN;
            }
            break;
        case S_DOOR_OPEN:
            if(mnt==D_NOMOTION){
                doorTimerCount=10000;
                doorState=S_DOOR_WAIT_CLOSE;
            }
            break;
        case S_DOOR_WAIT_CLOSE:
            if(mnt==D_MOTION){
                doorState=S_DOOR_OPEN;
            }
            else if(doorTimerCount==0){
                doorState=S_DOOR_CLOSE;
            }
            break;
    }
    switch(doorState){
        case S_DOOR_CLOSE:
            doorCtrl(DOORCLOSE);
            break;
        case S_DOOR_OPEN:
        case S_DOOR_WAIT_CLOSE:
            doorCtrl(DOOROPEN);
            break;
    }
}

void ledStateMachineUpdate(void){
    switch(ledState){
        case S_LEDOFF:
            if((mnt==D_MOTION)&&(ledTimerCount==0)){
                ledState=S_LEDON;
                ledTimerCount=500;
            }
            break;
        case S_LEDON:
            if(ledTimerCount==0){
                ledState=S_LEDOFF;
                ledTimerCount=500;
            }
            break;
    }
    switch(ledState){
        case S_LEDOFF:
            LEDOFF;
            break;
        case S_LEDON:
            LEDON;
            break;
    }
}

void initmotionState(void){
	motionState = S_NOMOTION;
}
void initDoorState(void){
	doorState= S_DOOR_CLOSE;
}
void initLedState(void){
	ledState=S_LEDOFF;
}
void doorCtrl(int State){
    GPIOPinWrite(LED_PORT_G,LED_G,State);
}
void SysTickIntHandler(void){
    if(motionTimerCount !=0){
        motionTimerCount--;
    }
    if(ledTimerCount !=0){
        ledTimerCount --;
    }
    if(doorTimerCount !=0){
        doorTimerCount --;
    }
}
