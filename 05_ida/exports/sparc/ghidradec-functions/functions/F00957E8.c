
void _vac_flushall(void)

{
  if (_vac != 0) {
                    /* WARNING: Could not recover jumptable at 0xf0095804. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_flushall)();
    return;
  }
  return;
}
