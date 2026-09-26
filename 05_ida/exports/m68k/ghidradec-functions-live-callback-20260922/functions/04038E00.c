
void sub_4038E00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    _wakeup(iVar1);
    iVar1 = iVar2;
  }
  return;
}

