
void _vac_ctxflush(int param_1)

{
  if ((_vac != 0) && ((*(uint *)(_contexts + param_1 * 4) & 3) == 1)) {
    _flush_cnt._0_4_ = _flush_cnt._0_4_ + 1;
                    /* WARNING: Could not recover jumptable at 0xf009589c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_ctxflush)(param_1,1,param_1);
    return;
  }
  return;
}

