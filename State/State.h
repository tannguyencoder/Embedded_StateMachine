/*
 * State.h
 *
 *  Created on: May 29, 2020
 *      Author: Tan
 */

#ifndef STATE_STATE_H_
#define STATE_STATE_H_

//Tín hiệu điều khiển cửa
#define DOOROPEN 1<<3
#define DOORCLOSE 0

//CHương trình điều khiển LED
#define LEDON   GPIOPinWrite(LED_PORT_R,LED_R,1<<1);
#define LEDOFF  GPIOPinWrite(LED_PORT_R,LED_R,0);

//
typedef enum{
    S_NOMOTION,
    S_WAIT_MOTION,
    S_MOTION,
    S_WAIT_NOMOTION
}motionState_t;
typedef enum{
    MOTION,
    NOMOTION
}motionSensor_t;
typedef enum{
    D_MOTION,
    D_NOMOTION
}motionDetector_t;
typedef enum{
    S_LEDON,
    S_LEDOFF
}ledState_t;
typedef enum{
    S_DOOR_CLOSE,
    S_DOOR_OPEN,
    S_DOOR_WAIT_CLOSE
}doorState_t;


motionSensor_t motionSensor(void);

void doorCtrl(int State);
void ledinit(void);
//Đặt trạng thái ban đầu là không chuyển động
void initmotionState(void);
//Đặt trạng thái bạn đầu là đóng
void initDoorState(void);
//Đặt trạng ban của LED là tắt
void initLedState(void);

//Cập nhật trạng thái của chuyển động
void motionStateMachineUpdate(void);
//Cập nhật trạng thái của DOOR
void doorStateMachineUpdate(void);
//Cập nhật trạng thái của LED
void ledStateMachineUpdate(void);

#endif /* STATE_STATE_H_ */
