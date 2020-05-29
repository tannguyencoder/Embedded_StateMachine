/*
 * includes.h
 *
 *  Created on: May 29, 2020
 *      Author: Tan
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

//thu vien ho tro ve bool, int, string va toan hoc math
#include <stdbool.h>
#include <stdint.h> //tạo ra các kiểu dữ liệu mới
#include <string.h> //Hàm về chuỗi
#include <math.h> //Cung cấp hàm về toán

//thu vien driver API
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"
#include "driverlib/systick.h"

//thu vien ho tro phan cung
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

//Thư viện tự định nghĩa 
#include "GPIO/GPIO.h" //Cấu hình 2 LED với 1 SW
#include "State/State.h"



#endif /* INCLUDES_H_ */
