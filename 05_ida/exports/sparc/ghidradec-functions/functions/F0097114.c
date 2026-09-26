
void _disable_dvma(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009711c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_disable_dvma)();
  return;
}
