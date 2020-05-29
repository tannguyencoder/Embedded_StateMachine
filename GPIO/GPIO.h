/*
 * GPIO.h
 *
 *  Created on: May 29, 2020
 *      Author: Tan
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#define LED_PORT_R GPIO_PORTF_BASE
#define LED_PORT_G GPIO_PORTE_BASE
#define LED_R GPIO_PIN_1
#define LED_G GPIO_PIN_3
#define SW_PORT GPIO_PORTF_BASE
#define SW_1 GPIO_PIN_4

void Config_LED_R(void);
void Config_SWITCH(void);
void Config_LED_G(void);


#endif /* GPIO_GPIO_H_ */
