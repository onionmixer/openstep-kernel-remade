
void _vac_segflush(undefined4 param_1,undefined4 param_2)

{
  if (_vac != 0) {
    DAT_f0134064._0_4_ = DAT_f0134064._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009591c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_segflush)(param_1,param_2,param_2);
    return;
  }
  return;
}
