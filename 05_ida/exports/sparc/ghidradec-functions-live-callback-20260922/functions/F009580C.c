
void _vac_usrflush(void)

{
  if (_vac != 0) {
    DAT_f0134070._0_4_ = DAT_f0134070._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009583c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_usrflush)();
    return;
  }
  return;
}

