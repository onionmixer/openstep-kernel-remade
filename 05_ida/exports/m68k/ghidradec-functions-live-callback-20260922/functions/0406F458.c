
void _kmstart(int param_1)

{
  if (((*(uint *)(param_1 + 0x3e) & 0x121) == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x20;
    if ((int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2) <
        *(int *)(param_1 + 0x18)) {
      _callout_dispatch(0,_kmoutput,param_1);
    }
    else {
      _timeout(_kmoutput,param_1,_hz / 0x1e);
    }
  }
  else if (*(int *)(param_1 + 0x18) <=
           (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
    if ((*(uint *)(param_1 + 0x3e) & 0x40) != 0) {
      *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xffffffbf;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x3e) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xefff;
    }
  }
  return;
}

