
void _srmmu_mmu_setctx(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = segment(4);
  *(undefined4 *)(iVar1 + 0x200) = param_1;
  return;
}

