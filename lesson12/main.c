#include <stdint.h>

#ifndef __RESTRICT
#define __RESTRICT
#endif

#include "tm4c_cmsis.h"
#include "tm4c.h"
#include "delay.h"
#define EnableClock 1U << 5
#define PF1 1U << 1
#define PF2 1U << 2
#define PF3 1U << 3

typedef struct {
    uint8_t y;
    uint16_t x;
} Point;

Point p1, p2;

typedef struct {
  Point top_left;
  Point bottom_right;
} Window;

typedef struct {
  Point corners[3];
} Triangle;

Window w, w2;
Triangle t;


int main()
{
  
  Point *pp;
  Window *wp;
  
  p1.x = sizeof(Point);
  p1.y = 0xAAU;
  
  w.top_left.x = 1U;
  w.bottom_right.y = 2U;
  
  t.corners[0].x = 1U;
  t.corners[2].y = 3U;
  
  p2 = p1;
  w2 = w;
  
  pp = &p1;
  wp = &w2;
  
  (*pp).x = 1U;
  (*wp).bottom_right = *pp;
  
  pp->x = 8U;
  wp->top_left = *pp;
  
  
  
  
  // SYSCTL_RCGCGPIO_R = EnableClock;
  SYSCTL->RCGC2 = EnableClock;
  
  // SYSCTL_GPIOHBCTL_R |= (1U << 5);    // enable AHB for gpiof
  SYSCTL->GPIOHSCTL |= (1U << 5);

  
  
  // GPIO_PORTF_AHB_DIR_R = PF1 | PF2 | PF3;  // config output
  GPIOF_AHB->DIR = PF1 | PF2 | PF3;
  
  // GPIO_PORTF_AHB_DEN_R = PF1 | PF2 | PF3; // digtal function
  GPIOF_AHB->DEN = PF1 | PF2 | PF3;
  
  while(1) {
    
    
    // GPIO_PORTF_AHB_DATA_BITS_R[PF1] = PF1;
    // *(GPIO_PORTF_DATA_BITS_R + PF1) = PF1;
    GPIOF_AHB->DATA_Bits[PF1] = PF1;
  
    delay(500000);  
    // GPIO_PORTF_AHB_DATA_BITS_R[PF1 | PF2 | PF3] = 0x00U;
    GPIOF_AHB->DATA_Bits[PF1 | PF2 | PF3] = 0x00U;
    delay(500000);
  }
  // return 0;
}

