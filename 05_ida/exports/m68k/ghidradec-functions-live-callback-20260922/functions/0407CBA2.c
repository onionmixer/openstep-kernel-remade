
void sub_407CBA2(int *param_1,undefined4 param_2)

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
  uStack_46 = *(undefined4 *)(iVar1 + 0xb2);
  uStack_56 = 0x12;
  uVar2 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar2 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*(int *)(iVar1 + 8) + 0x1d) << 0x1d) >> 8),0x42);
  uStack_42 = 0x42;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}

