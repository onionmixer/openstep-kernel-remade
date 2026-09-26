
undefined8 __udivdi3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_2c [8];
  undefined8 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = param_1;
  uStack_8 = param_2;
  uStack_1c = param_3;
  uStack_18 = param_4;
  __bdiv(&uStack_14,&uStack_1c,&uStack_24,auStack_2c,0x10,8);
  return uStack_24;
}
