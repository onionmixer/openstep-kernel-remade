
void _compute_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x5c) == 2) {
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (-1 < *(int *)(param_1 + 0x60)) {
      *(int *)(param_1 + 0x60) = iVar1;
      return;
    }
  }
  _set_pri(param_1,iVar1,param_2);
  return;
}
