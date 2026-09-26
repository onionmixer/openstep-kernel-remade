
byte _thread_will_wait(int param_1)

{
  int unaff_D2;
  char in_XF;
  
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  return in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2;
}

