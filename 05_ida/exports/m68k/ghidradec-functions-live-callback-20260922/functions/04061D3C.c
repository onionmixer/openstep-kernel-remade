
undefined4 _suiword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _copyoutmsg(&stack0x00000008,param_1,4);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

