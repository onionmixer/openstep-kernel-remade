
undefined4 _srmmu_mmu_getctp(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(undefined4 *)(iVar1 + 0x100);
}

