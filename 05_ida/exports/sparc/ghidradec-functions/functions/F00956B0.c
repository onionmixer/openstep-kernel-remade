
void _mmu_flushseg(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushseg)(param_1 & 0xfffc0000);
  return;
}
