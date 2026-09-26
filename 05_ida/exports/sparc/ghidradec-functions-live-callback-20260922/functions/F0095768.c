
void _mmu_wo(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_wo)();
  return;
}

