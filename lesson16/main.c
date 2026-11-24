#include <stdint.h>

#ifndef __RESTRICT
#define __RESTRICT
#endif

#include "tm4c_cmsis.h"
#include "tm4c.h"
#include "bsp.h"

#define EnableClock (1U << 5)




int main()
{
  
  
  // SYSCTL_RCGCGPIO_R = EnableClock;
  SYSCTL->RCGC2 = EnableClock;
  // SYSCTL_GPIOHBCTL_R |= EnableClock;    // enable AHB for gpiof
  SYSCTL->GPIOHSCTL |= EnableClock;
  // GPIO_PORTF_AHB_DIR_R = LED_RED | LED_BLUE | LED_GREEN;  // config output
  GPIOF_AHB->DIR = LED_RED | LED_BLUE | LED_GREEN;
  // GPIO_PORTF_AHB_DEN_R = LED_RED | LED_BLUE | LED_GREEN; // digtal function
  GPIOF_AHB->DEN = LED_RED | LED_BLUE | LED_GREEN;
  
  
  SysTick->LOAD = SYS_CLOCK_HZ/2U - 1;
  SysTick->VAL = 0;
  SysTick->CTRL = 1U << 2 | 1U << 1 | 1U;

  __enable_interrupt();
  while(1) {


  }
  // return 0;
}

