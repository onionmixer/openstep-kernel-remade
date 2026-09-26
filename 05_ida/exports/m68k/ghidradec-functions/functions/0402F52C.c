
void _svcerr_auth(int param_1,undefined4 param_2)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_30 = 1;
  uStack_2c = 1;
  uStack_28 = 1;
  uStack_24 = param_2;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
