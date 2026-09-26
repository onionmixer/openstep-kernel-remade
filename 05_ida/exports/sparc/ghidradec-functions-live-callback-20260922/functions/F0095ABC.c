
void _srmmu_mmu_setcr(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)segment(4);
  *puVar1 = param_1;
  return;
}

