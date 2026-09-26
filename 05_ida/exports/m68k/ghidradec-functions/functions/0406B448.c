
void _fc_start_timer(int param_1,int param_2)

{
  int iStack_c;
  int iStack_8;
  
  if (_fd_polling_mode == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x10;
    if (param_2 < 1000000) {
      iStack_c = 0;
    }
    else {
      iStack_c = param_2 / 1000000;
      param_2 = param_2 % 1000000;
    }
    iStack_8 = param_2;
    _us_timeout(_fc_timeout,param_1,&iStack_c,0);
  }
  return;
}
