
undefined8 _thread_bind(int param_1,int param_2)

{
  char in_XF;
  
  *(int *)(param_1 + 0x17c) = param_2;
  return CONCAT44((int)(sword)(word)(byte)(in_XF << 4 | (param_2 < 0) << 3 | (param_2 == 0) << 2),
                  CONCAT22((sword)((uint)param_2 >> 0x10),
                           (word)(byte)((param_2 < 0) << 3 | (param_2 == 0) << 2)));
}

