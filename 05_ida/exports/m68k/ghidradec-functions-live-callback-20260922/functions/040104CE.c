
undefined4 _ptswrite(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  if (*(int *)(iVar1 + 0x24) == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = (**(code **)(DAT_40ae4b8 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1,param_2);
  }
  return uVar2;
}

