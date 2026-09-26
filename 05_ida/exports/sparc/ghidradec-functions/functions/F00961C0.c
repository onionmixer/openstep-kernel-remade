
uint _swift_mmu_chk_wdreset(void)

{
  int iVar1;
  
  iVar1 = segment(0x20);
  return *(uint *)(iVar1 + 0x71f00000) & 0x10;
}
