
undefined4 _srmmu_mmu_getcr(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)segment(4);
  return *puVar1;
}
