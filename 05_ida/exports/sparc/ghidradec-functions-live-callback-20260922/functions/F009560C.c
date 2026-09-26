
void _mmu_probe(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095614. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_probe)();
  return;
}

