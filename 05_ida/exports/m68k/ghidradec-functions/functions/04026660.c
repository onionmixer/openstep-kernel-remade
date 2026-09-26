
void _vattr_to_nattr(int *param_1,int *param_2)

{
  sword sVar1;
  
  *param_2 = *param_1;
  sVar1 = *(sword *)(param_1 + 1);
  if (sVar1 == -1) {
    param_2[1] = -1;
  }
  else {
    *(undefined2 *)(param_2 + 1) = 0;
    *(sword *)((int)param_2 + 6) = sVar1;
  }
  if (*(sword *)((int)param_1 + 6) == -1) {
    param_2[3] = -1;
  }
  else {
    param_2[3] = (int)*(sword *)((int)param_1 + 6);
  }
  if (*(sword *)(param_1 + 2) == -1) {
    param_2[4] = -1;
  }
  else {
    param_2[4] = (int)*(sword *)(param_1 + 2);
  }
  param_2[9] = *(int *)((int)param_1 + 10);
  param_2[10] = *(int *)((int)param_1 + 0xe);
  param_2[2] = (int)*(sword *)((int)param_1 + 0x12);
  param_2[5] = param_1[5];
  param_2[0xb] = param_1[7];
  param_2[0xc] = param_1[8];
  param_2[0xd] = param_1[9];
  param_2[0xe] = param_1[10];
  param_2[0xf] = param_1[0xb];
  param_2[0x10] = param_1[0xc];
  param_2[7] = (int)*(sword *)(param_1 + 0xd);
  param_2[8] = *(int *)((int)param_1 + 0x36);
  param_2[6] = param_1[6];
  if (*param_1 == 8) {
    *param_2 = 4;
    param_2[7] = -1;
    param_2[1] = param_2[1] & 0xffff0fffU | 0x2000;
  }
  return;
}

