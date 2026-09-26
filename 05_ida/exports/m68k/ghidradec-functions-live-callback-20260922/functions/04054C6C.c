
void _thread_read_times(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  
  do {
    uVar1 = *(uint *)(param_1 + 0xd8);
  } while (*(int *)(param_1 + 0xdc) != *(int *)(param_1 + 0xe0));
  *param_2 = uVar1 / 1000000 + *(int *)(param_1 + 0xdc);
  param_2[1] = uVar1 % 1000000;
  do {
    uVar1 = *(uint *)(param_1 + 0xe8);
  } while (*(int *)(param_1 + 0xec) != *(int *)(param_1 + 0xf0));
  *param_3 = uVar1 / 1000000 + *(int *)(param_1 + 0xec);
  param_3[1] = uVar1 % 1000000;
  return;
}

