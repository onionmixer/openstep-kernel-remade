
void _enable_dvma(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009710c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_enable_dvma)();
  return;
}
