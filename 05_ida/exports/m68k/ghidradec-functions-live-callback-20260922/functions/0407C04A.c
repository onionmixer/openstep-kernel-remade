
void sub_407C04A(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x18);
  *(undefined *)(param_1 + 0x5a) = 2;
  (**(code **)(*(int *)(iVar1 + 0x14) + 0x12))(iVar1);
  return;
}

