
undefined4
_processor_info(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else if ((param_2 == 1) && (4 < *param_5)) {
    iVar1 = *(int *)(param_1 + 0x13c);
    *param_4 = (&dword_40B5DCC)[iVar1 * 8];
    param_4[1] = (&dword_40B5DD0)[iVar1 * 8];
    if ((*(int *)(param_1 + 0x110) == 5) || (*(int *)(param_1 + 0x110) == 0)) {
      param_4[2] = 0;
    }
    else {
      param_4[2] = 1;
    }
    param_4[3] = iVar1;
    if (param_1 == _master_processor) {
      param_4[4] = 1;
    }
    else {
      param_4[4] = 0;
    }
    *param_5 = 5;
    *param_3 = &_realhost;
    uVar2 = 0;
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

