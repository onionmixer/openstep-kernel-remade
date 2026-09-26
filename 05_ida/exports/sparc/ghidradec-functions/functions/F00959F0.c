
void _vac_parity_chk_dis(void)

{
  if (_vac != 0) {
                    /* WARNING: Could not recover jumptable at 0xf0095a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_v_vac_parity_chk_dis)();
    return;
  }
  return;
}
