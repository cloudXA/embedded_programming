int counter = 0;

int main()
{
  int *pointer;
  pointer = &counter;
  while(*pointer < 21) {
      ++*pointer;
  }
  pointer = (int*)0x20000002U;
  
  *pointer =    0xABC;
  
  return 0;
}
