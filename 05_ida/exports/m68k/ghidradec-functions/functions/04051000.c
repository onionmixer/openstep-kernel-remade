
void _compute_my_priority(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x54) = iVar1;
  return;
}
