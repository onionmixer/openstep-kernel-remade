
uint _vik_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(4);
  return *(uint *)(iVar1 + 0x300) & 0x20000;
}

