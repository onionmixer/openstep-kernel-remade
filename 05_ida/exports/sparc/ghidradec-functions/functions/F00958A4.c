
void _vac_rgnflush(uint param_1,undefined4 param_2)

{
  if (_vac != 0) {
    DAT_f0134074._0_4_ = DAT_f0134074._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf00958e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_rgnflush)(param_1 & 0xff000000,param_2,param_2);
    return;
  }
  return;
}
