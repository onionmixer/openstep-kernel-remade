
void _mmu_log_module_err(void)

{
                    /* WARNING: Could not recover jumptable at 0xf0095730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_mmu_log_module_err)();
  return;
}

