
undefined4 _subyte(undefined4 param_1,undefined param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar1 = _copyoutmsg(&uStack_5,param_1,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

