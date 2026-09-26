
void _mmu_flushpagectx(uint param_1)

{
                    /* WARNING: Could not recover jumptable at 0xf00956f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushpagectx)(param_1 & 0xfffff000);
  return;
}

