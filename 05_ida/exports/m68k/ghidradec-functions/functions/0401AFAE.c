
undefined4 _getvnodefp(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _getf(param_1);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else if (*(sword *)(iVar1 + 0xc) == 1) {
    *param_2 = iVar1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
