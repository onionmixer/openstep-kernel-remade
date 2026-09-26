
int _ip_rtaddr(int param_1)

{
  int iVar1;
  
  if (_ipforward_rt != 0) {
    if (param_1 == dword_40B7D94) goto loc_4021514;
    if (*(sword *)(_ipforward_rt + 0x26) == 1) {
      _rtfree(_ipforward_rt);
    }
    else {
      *(sword *)(_ipforward_rt + 0x26) = *(sword *)(_ipforward_rt + 0x26) + -1;
    }
    _ipforward_rt = 0;
  }
  unk_40B7D90._0_2_ = 2;
  dword_40B7D94 = param_1;
  _rtalloc(&_ipforward_rt);
loc_4021514:
  if ((_ipforward_rt != 0) && (_in_ifaddr != 0)) {
    iVar1 = _in_ifaddr;
    do {
      if (*(int *)(_ipforward_rt + 0x2c) == *(int *)(iVar1 + 0x20)) {
        return iVar1;
      }
      iVar1 = *(int *)(iVar1 + 0x40);
    } while (iVar1 != 0);
  }
  return 0;
}

