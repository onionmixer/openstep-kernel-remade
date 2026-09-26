
void _srmmu_mmu_getasyncflt(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = segment(4);
  param_1[1] = *(undefined4 *)(iVar1 + 0x600);
  iVar1 = segment(4);
  *param_1 = *(undefined4 *)(iVar1 + 0x500);
  param_1[2] = 0xffffffff;
  return;
}

