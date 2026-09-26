
void _mmu_flushpage(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushpage)(param_1 & 0xfffff000);
  return;
}
