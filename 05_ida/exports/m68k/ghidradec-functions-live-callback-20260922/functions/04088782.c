
void sub_4088782(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  int iStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  iStack_46 = param_1[1];
  uStack_56 = 0x12;
  uVar1 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar1 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 8),0x42);
  uStack_42 = 0x42;
  uStack_4a = 0;
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,param_2);
  return;
}

