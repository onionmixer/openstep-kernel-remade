
char sub_4068ECC(undefined4 *param_1,int param_2)

{
  char cVar1;
  
  if (0 < param_2) {
    *param_1 = 1;
    param_1[1] = 0;
    param_1[2] = 1;
    param_1[3] = (uint)_mon_rev;
  }
  cVar1 = 0 < param_2;
  if (1 < param_2) {
    param_1[4] = 1;
    param_1[5] = 1;
    param_1[6] = 2;
    param_1[7] = (uint)_mon_rev;
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}

