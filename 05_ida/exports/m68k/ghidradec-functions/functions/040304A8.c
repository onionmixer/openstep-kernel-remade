
undefined4 _xdrmbuf_putlong(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 != -4) {
      _printf(aXdrMbufPutlong);
    }
    if (*(int **)(param_1 + 0x10) != (int *)0x0) {
      iVar1 = **(int **)(param_1 + 0x10);
      *(int *)(param_1 + 0x10) = iVar1;
      if (iVar1 != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
        *(int *)(param_1 + 0x14) = *(sword *)(iVar1 + 8) + -4;
        goto loc_40304FE;
      }
    }
    uVar2 = 0;
  }
  else {
loc_40304FE:
    **(undefined4 **)(param_1 + 0xc) = *param_2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
    uVar2 = 1;
  }
  return uVar2;
}
