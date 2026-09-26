
void _mmu_flushrgn(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushrgn)(param_1 & 0xff000000);
  return;
}
