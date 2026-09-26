
void _fc_timeout(int param_1)

{
  _fc_flags_bset(param_1,8);
  _fc_flags_bclr(param_1,0x10);
  _thread_wakeup_prim(param_1 + 0x18,0,0);
  return;
}

