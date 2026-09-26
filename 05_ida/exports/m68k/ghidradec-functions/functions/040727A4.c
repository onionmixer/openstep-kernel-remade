
void _np_gpinwait(int param_1,int param_2)

{
  if (param_2 != 0) {
    _timeout(_np_gpiwait_timeout,param_1,param_2);
  }
  _assert_wait(param_1 + 0x11b,0);
  _thread_block();
  _untimeout(_np_gpiwait_timeout,param_1);
  return;
}
