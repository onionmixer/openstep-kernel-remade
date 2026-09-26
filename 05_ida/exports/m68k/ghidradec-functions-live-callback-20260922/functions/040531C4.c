
byte _thread_hold(int param_1)

{
  int unaff_D2;
  char in_XF;
  
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
  return in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2;
}

