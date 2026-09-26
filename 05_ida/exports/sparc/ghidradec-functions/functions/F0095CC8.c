
void _srmmu_mmu_wo(void)

{
  uint *puVar1;
  uint uVar2;
  
  segment(4);
  puVar1 = (uint *)segment(4);
  uVar2 = *puVar1;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 | 2;
  puVar1 = (uint *)segment(4);
  *puVar1 = uVar2 & 0xfffffffd;
  segment(4);
  segment(4);
  wo_chk_flt();
  return;
}
