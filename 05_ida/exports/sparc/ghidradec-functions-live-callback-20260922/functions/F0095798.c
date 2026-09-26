
void _mmu_writeptp(void)

{
                    /* WARNING: Could not recover jumptable at 0xf00957a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_writeptp)();
  return;
}

