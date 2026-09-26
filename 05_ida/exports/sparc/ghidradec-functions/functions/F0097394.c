
void _p4m35_sys_setfunc(void)

{
  _v_get_sysctl = _p4m35_get_sysctl;
  _v_set_sysctl = _p4m35_set_sysctl;
  _v_get_diagmesg = _p4m35_stub;
  _v_set_diagmesg = _p4m35_stub;
  _v_set_diagled = _p4m35_stub;
  _v_enable_dvma = _p4m35_enable_dvma;
  _v_disable_dvma = _p4m35_disable_dvma;
  _v_l15_async_fault = _p4m35_l15_async_fault;
  _v_memerr_init = _p4m35_memerr_init;
  _v_memerr_disable = _p4m35_memerr_disable;
  _v_ebe_handler = _p4m35_ebe_handler;
  _v_flush_writebuffers = _p4m35_stub;
  _v_flush_poke_writebuffers = _p4m35_stub;
  _v_init_all_fsr = _p4m35_init_all_fsr;
  return;
}
