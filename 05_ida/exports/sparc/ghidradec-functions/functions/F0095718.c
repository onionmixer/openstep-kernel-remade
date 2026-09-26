
void _mmu_chk_wdreset(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_chk_wdreset)();
  return;
}
