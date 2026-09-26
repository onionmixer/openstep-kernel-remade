
undefined4 _fuiword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  iVar1 = _copyinmsg(param_1,&uStack_8,4);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = uStack_8;
  }
  return uVar2;
}

