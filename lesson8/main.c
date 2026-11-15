#include "tm4c.h"
#define EnableClock 1U << 5
#define PF1 1U << 1
#define PF2 1U << 2
#define PF3 1U << 3
/* white on off */

void delay(void) {
  int volatile counter = 0;
  while(counter < 1000000) {
      ++counter;
  }
}

int main()
{
  SYSCTL_RCGCGPIO_R = EnableClock;
  SYSCTL_GPIOHBCTL_R |= (1U << 5);    // enable AHB for gpiof
  GPIO_PORTF_AHB_DIR_R = PF1 | PF2 | PF3;  // config output
  GPIO_PORTF_AHB_DEN_R = PF1 | PF2 | PF3; // digtal function
  
  
  while(1) {
    GPIO_PORTF_AHB_DATA_BITS_R[PF1] = PF1;
    // *(GPIO_PORTF_DATA_BITS_R + PF1) = PF1;
    
    delay();
    
    GPIO_PORTF_AHB_DATA_BITS_R[PF1 | PF2 | PF3] = 0x00U;
    
    delay();
  }
  
  return 0;
}
