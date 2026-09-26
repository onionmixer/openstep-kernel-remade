
void _rtinit(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined2 param_4)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  
  _bzero(auStack_34,0x30);
  uStack_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  uStack_10 = param_4;
  _rtrequest(param_3,auStack_34);
  return;
}
