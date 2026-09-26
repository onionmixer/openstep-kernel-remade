
void _srmmu_mmu_flushpage(int param_1)

{
  int iVar1;
  
  iVar1 = segment(3);
  *(undefined4 *)(param_1 + iVar1) = 0;
  return;
}
