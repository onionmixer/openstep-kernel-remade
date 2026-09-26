
void _mmu_writepte(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_writepte)();
  return;
}
