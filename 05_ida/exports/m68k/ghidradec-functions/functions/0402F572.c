
void _svcerr_noprog(int param_1)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 1;
  uStack_2c = 0;
  uStack_28 = *(undefined4 *)(param_1 + 0x1e);
  uStack_24 = *(undefined4 *)(param_1 + 0x22);
  uStack_20 = *(undefined4 *)(param_1 + 0x26);
  uStack_1c = 1;
  (**(code **)(*(int *)(param_1 + 6) + 0xc))(param_1,auStack_34);
  return;
}
