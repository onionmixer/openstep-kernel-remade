
void _fc_stop_timer(undefined4 param_1)

{
  if (_fd_polling_mode == 0) {
    _us_untimeout(_fc_timeout,param_1);
    _fc_flags_bclr(param_1,0x18);
  }
  return;
}

