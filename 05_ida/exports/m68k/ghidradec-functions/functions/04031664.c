
void _set_blocksize(int param_1,word param_2)

{
  int iVar1;
  int iVar2;
  
  if (((_nblkdev <= (int)(uint)(param_2 >> 8)) ||
      ((&off_40B088C)[(uint)(param_2 >> 8) * 6] == (code *)0x0)) ||
     (iVar2 = (*(&off_40B088C)[(uint)(param_2 >> 8) * 6])((int)(sword)param_2), iVar2 == -1)) {
    *(undefined4 *)(param_1 + 0x46) = 0;
    return;
  }
  *(int *)(param_1 + 0x46) = iVar2;
  if (*(int *)(param_1 + 0x3a) == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x3a) + 0x2e);
  if (*(int *)(iVar1 + 0x46) != 0) {
    return;
  }
  *(int *)(iVar1 + 0x46) = iVar2;
  return;
}
