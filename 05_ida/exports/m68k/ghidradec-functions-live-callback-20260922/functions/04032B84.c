
void sub_4032B84(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  if (*(uint *)(*param_1 + 0x14) < (uint)(param_3 + param_4)) {
    *(int *)(*param_1 + 0x14) = param_3 + param_4;
  }
  (**(code **)(param_1[7] + 0x78))(param_1,param_2,param_3,param_4);
  return;
}

