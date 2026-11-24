/* Board Support Package */
#ifndef __RESTRICT
#define __RESTRICT
#endif

#include "bsp.h"

#include "tm4c_cmsis.h"


__stackless void assert_failed(char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}

__stackless void SysTick_Handler(void ) {
    GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
}