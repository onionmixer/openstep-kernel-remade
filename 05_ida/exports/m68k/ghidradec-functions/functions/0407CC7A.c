
void sub_407CC7A(int *param_1,undefined4 param_2)

{
  uint uStack_56;
  undefined uStack_52;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = CONCAT13(0x1b,(int3)(((uint)*(byte *)(*(int *)(*param_1 + 8) + 0x1d) << 0x1d) >> 8));
  uStack_52 = 1;
  uStack_56 = uStack_56 | 0x10000;
  uStack_46 = 0;
  uStack_42 = 0;
  uStack_4a = 0;
  uStack_3e = 0x3c;
  sub_407E678(param_1,&uStack_56,param_2);
  return;
}
