
void sub_40887EA(int *param_1,undefined4 param_2)

{
  undefined uStack_56;
  uint uStack_55;
  undefined4 uStack_46;
  undefined4 uStack_3e;
  undefined4 uStack_1a;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0;
  uStack_55 = uStack_55 & 0x1fffffff | (uint)*(byte *)(*param_1 + 0x1d) << 0x1d;
  uStack_3e = 0x78;
  uStack_46 = 0;
  uStack_1a = 0;
  sub_40895AC(param_1,&uStack_56,param_2);
  return;
}
