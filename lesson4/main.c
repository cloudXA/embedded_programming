int counter = 0;

int main()
{
  *((unsigned int *)0x400FE608U) = 0x20U;
  *((unsigned int *)0x40025400U) = 0x02U;
  *((unsigned int *)0x4002551cU) = 0x02U;
  
  while(1) {
    *((unsigned int *)0x40025008U) = 0x02U;
    
    int counter = 0;
    while(counter < 1000000) {
      ++counter;
    }
    
    *((unsigned int *)0x40025008U) = 0x00U;
    counter = 0;
    
    
    while(counter < 1000000) {
      ++counter;
    }
  }
  
  return 0;
}
