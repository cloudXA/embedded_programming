#include "tm4c.h"
#include "delay.h"
#define EnableClock 1U << 5
#define PF1 1U << 1
#define PF2 1U << 2
#define PF3 1U << 3


/* white on off */
unsigned fact(unsigned n);
int main()
{
  unsigned volatile x;
  x = fact(0U);
  x = 2U + 3U * fact(1U);
  (void)fact(5U);
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
unsigned fact(unsigned n) {
  // 0! = 1;
  // n! = n*(n-1)! for n > 0
  if(n == 0U) {
    return 1U;
  } else {
    return n * fact(n - 1U);
  }
}
