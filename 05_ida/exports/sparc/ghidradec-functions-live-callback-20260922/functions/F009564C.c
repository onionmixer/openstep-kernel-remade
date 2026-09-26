
void _mmu_flushall(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095654. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_flushall)();
  return;
}

