
void _fioctl(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*(int *)(param_1 + 0x12) + 4))(param_1,param_2,param_3);
  return;
}
