#include "tm4c.h"
#define PF1 1U << 1
#define PF2 1U << 2
#define PF3 1U << 3




int main()
{
  SYSCTL_RCGCGPIO_R = 0x20U;
  GPIO_PORTF_DIR_R = 0x02U;
  GPIO_PORTF_DEN_R = 0x02U;
  
  while(1) {
    GPIO_PORTF_DATA_BITS_R[PF3] = PF3; 
    
    int volatile counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
    
    GPIO_PORTF_DATA_BITS_R[PF3] = 0x00U;
    counter = 0;
    
    
    while(counter < 1000000) {
      ++counter;
    }
  }
  
  return 0;
}
