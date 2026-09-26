/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00126c9c */

int _ip_rtaddr(int param_1)

{
  int iVar1;
  
  if (_ipforward_rt != 0) {
    if (DAT_001eacf8 == param_1) goto LAB_00126cf2;
    if (*(short *)(_ipforward_rt + 0x26) == 1) {
      _rtfree(_ipforward_rt);
    }
    else {
      *(short *)(_ipforward_rt + 0x26) = *(short *)(_ipforward_rt + 0x26) + -1;
    }
    _ipforward_rt = 0;
  }
  DAT_001eacf4 = 2;
  DAT_001eacf8 = param_1;
  _rtalloc(&_ipforward_rt);
LAB_00126cf2:
  if ((_ipforward_rt != 0) && (_in_ifaddr != 0)) {
    iVar1 = _in_ifaddr;
    do {
      if (*(int *)(iVar1 + 0x20) == *(int *)(_ipforward_rt + 0x2c)) {
        return iVar1;
      }
      iVar1 = *(int *)(iVar1 + 0x40);
    } while (iVar1 != 0);
  }
  return 0;
}

