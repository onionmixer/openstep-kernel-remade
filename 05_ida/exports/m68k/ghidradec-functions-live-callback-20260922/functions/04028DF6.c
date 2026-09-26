
void _vattr_to_sattr(int param_1,undefined4 *param_2)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 4);
  if (sVar1 == -1) {
    *param_2 = 0xffffffff;
  }
  else {
    *(undefined2 *)param_2 = 0;
    *(sword *)((int)param_2 + 2) = sVar1;
  }
  if (*(sword *)(param_1 + 6) == -1) {
    param_2[1] = 0xffffffff;
  }
  else {
    param_2[1] = (int)*(sword *)(param_1 + 6);
  }
  if (*(sword *)(param_1 + 8) == -1) {
    param_2[2] = 0xffffffff;
  }
  else {
    param_2[2] = (int)*(sword *)(param_1 + 8);
  }
  param_2[3] = *(undefined4 *)(param_1 + 0x14);
  param_2[4] = *(undefined4 *)(param_1 + 0x1c);
  param_2[5] = *(undefined4 *)(param_1 + 0x20);
  param_2[6] = *(undefined4 *)(param_1 + 0x24);
  param_2[7] = *(undefined4 *)(param_1 + 0x28);
  return;
}

