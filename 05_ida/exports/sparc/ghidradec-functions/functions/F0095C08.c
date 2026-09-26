
uint _srmmu_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(uint *)(iVar1 + 0x700) & 4;
}
