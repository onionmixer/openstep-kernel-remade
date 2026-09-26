
void sub_407CC0E(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  iVar1 = *param_1;
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x1a;
  uVar2 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar2 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*(int *)(iVar1 + 8) + 0x1d) << 0x1d) >> 8),
                        (char)param_4);
  uStack_46 = param_3;
  uStack_42 = param_4;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}
