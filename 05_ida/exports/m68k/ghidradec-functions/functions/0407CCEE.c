
undefined4 sub_407CCEE(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined uStack_56;
  uint uStack_55;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  int iStack_3a;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0;
  uStack_55 = uStack_55 & 0x1fffffff | (uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d;
  uStack_46 = 0;
  uStack_42 = 0;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  iVar1 = sub_407E678(param_1,&uStack_56,param_2);
  if ((iVar1 == 0) && (iStack_3a == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
