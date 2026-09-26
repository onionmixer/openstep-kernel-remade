
undefined4 sub_40895AC(undefined4 param_1,undefined *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_4089628(param_1,param_2,param_3);
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    if (param_3 == 0) {
      _printf(aStCmd0xXSrIoSt,*param_2,*(int *)(param_2 + 0x1c));
      if (*(int *)(param_2 + 0x1c) == 2) {
        _printf(aSenseKey0xXSen,param_2[0x24] & 0xf,param_2[0x2e]);
      }
    }
    uVar2 = 5;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
