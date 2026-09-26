
void _memerr_disable(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009715c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_memerr_disable)();
  return;
}
