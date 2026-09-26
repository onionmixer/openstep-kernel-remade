
void _vac_flush(void)

{
  if (_vac != 0) {
    DAT_f013406c._0_4_ = DAT_f013406c._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf00959d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_flush)();
    return;
  }
  return;
}
