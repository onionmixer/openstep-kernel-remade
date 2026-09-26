
void sub_4088840(int *param_1)

{
  undefined uStack_56;
  undefined4 uStack_55;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x10;
  uStack_55._0_1_ =
       uStack_55._0_1_ & 0x1f | (byte)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 0x18);
  uStack_55 = (uint)uStack_55._0_1_ << 0x18;
  uStack_55 = CONCAT31(uStack_55._0_3_,1);
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,0);
  return;
}
