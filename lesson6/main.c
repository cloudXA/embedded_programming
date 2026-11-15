#include "tm4c.h"
#define EnableClock 1U << 5
#define PF1 1U << 1
#define PF2 1U << 2
#define PF3 1U << 3
/* white on off */

int main()
{       
  SYSCTL_RCGCGPIO_R = EnableClock;
  GPIO_PORTF_DIR_R = PF1 | PF2 | PF3;  // config output
  GPIO_PORTF_DEN_R = PF1 | PF2 | PF3; // digtal function
  
  
  GPIO_PORTF_DATA_BITS_R[PF1 | PF2 | PF3] = PF1;
  
  while(1) {

    GPIO_PORTF_DATA_BITS_R[PF1 | PF2 | PF3] = PF1;
    
    int volatile counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
    
    GPIO_PORTF_DATA_BITS_R[PF1 | PF2 | PF3] = 0x00U;
    counter = 0;
    
    
    while(counter < 1000000) {
      ++counter;
    }
  }
  
  return 0;
}
