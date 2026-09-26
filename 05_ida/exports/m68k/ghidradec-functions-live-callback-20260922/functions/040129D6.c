
int _solisten(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,3,0,0,0);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x1a) == 0) {
      *(int *)(param_1 + 0x1a) = param_1;
      *(int *)(param_1 + 0x14) = param_1;
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 2;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (0x80 < param_2) {
      param_2 = 0x80;
    }
    *(sword *)(param_1 + 0x20) = (sword)param_2;
    iVar1 = 0;
  }
  return iVar1;
}

