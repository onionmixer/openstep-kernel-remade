
void _srmmu_mmu_flushall(void)

{
  int iVar1;
  
  iVar1 = segment(3);
  *(undefined4 *)(iVar1 + 0x400) = 0;
  return;
}
