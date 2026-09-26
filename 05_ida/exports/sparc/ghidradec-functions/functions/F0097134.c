
void _ebe_handler(void)

{
                    /* WARNING: Could not recover jumptable at 0xf009713c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_v_ebe_handler)();
  return;
}

