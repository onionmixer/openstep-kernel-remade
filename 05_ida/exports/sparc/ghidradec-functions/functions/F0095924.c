
void _vac_pageflush(uint param_1)

{
  if (_vac != 0) {
    DAT_f0134068._0_4_ = DAT_f0134068._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009595c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_pageflush)(param_1 & 0xfffff000);
    return;
  }
  return;
}
