#ifndef __PRIVATE_H_
#define __PRIVATE_H_

#include <intrinsics.h>

void hal_rcc_init();
void hal_gpio_init();
void hal_uart_init();
void hal_nvic_init();

#endif  // __PRIVATE_H_