
void _as_tune(int param_1)

{
  if ((0x3b < *(sword *)(_mon_global + 0x30c)) && (*(int *)(_mon_global + 0x3aa) != 0)) {
    (**(code **)(_mon_global + 0x3aa))();
  }
  if (param_1 + 1 < _astune_calls) {
    _timeout(_as_tune,param_1 + 1,_hz * _astune_rate);
  }
  return;
}

