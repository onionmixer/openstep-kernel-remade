
undefined4
_getsectdatafromheader(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _getsectbynamefromheader(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_4 = 0;
    uVar2 = 0;
  }
  else {
    *param_4 = *(undefined4 *)(iVar1 + 0x24);
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
  }
  return uVar2;
}
