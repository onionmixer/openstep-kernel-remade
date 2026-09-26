
undefined4 _kdbg_connect(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (dword_40C9474 == 0) {
    _kdb_net._0_4_ = 0;
    _kdb_net._4_4_ = 0;
    _en_bufalloc(param_1);
    _dbg_connect_pkt = sub_40963BC(1);
    if (_dbg_connect_pkt == 0) {
      uVar1 = 0;
    }
    else if (*(int *)(_dbg_connect_pkt + 0x2e) == 8) {
      dword_40C9474 = 1;
      if (dword_40B5628 != 0) {
                    /* WARNING: Subroutine does not return */
        _dbg_dispatch();
      }
      __m68k_trap(0xf);
      uVar1 = 1;
    }
    else {
      _nmi_prf(aOldDebuggingIn,*(undefined4 *)(_dbg_connect_pkt + 0x2e));
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
