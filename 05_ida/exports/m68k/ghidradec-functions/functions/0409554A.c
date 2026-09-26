
undefined4 _dbg_trap(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  _adb_watchdog(0);
  _get_vbr();
  if (_client_running == 0) {
    dword_40B5630 = 5;
  }
  else {
    if ((*(word *)(param_1 + 0x46) & 0x2000) == 0) {
      iVar1 = (*(int *)(param_1 + 0x4c) << 4) >> 0x16;
      if (iVar1 == 9) {
        _adb_watchdog(1);
        uVar2 = dword_40B561C;
      }
      else {
        if (iVar1 != 0x2f) {
          _nmi_prf(aDbgTrapReturni,(*(int *)(param_1 + 0x4c) << 4) >> 0x14);
                    /* WARNING: Subroutine does not return */
          _dbg_panic(aDbgTrapBadUser);
        }
        _adb_watchdog(1);
        uVar2 = dword_40B5620;
      }
      return uVar2;
    }
    _client_running = 0;
    _bcopy(param_1,&_client_pcb,0xa2);
    dword_40B5634 = 0;
    dword_40B5638 = (*(int *)(param_1 + 0x4c) << 4) >> 0x14;
    switch(*(int *)(param_1 + 0x4c) >> 0x1c) {
    case :
    case :
      dword_40C9714 = dword_40C9714 + 8;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0xc;
      break;
    :
                    /* WARNING: Subroutine does not return */
      _dbg_panic(aStackFrameScre);
    case :
      dword_40C9714 = dword_40C9714 + 0x3c;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x14;
      dword_40B5634 = CONCAT22(dword_40C9722._0_2_,dword_40C9722._2_2_);
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x20;
      dword_40B5634 = dword_40C972A;
      break;
    case :
      dword_40C9714 = dword_40C9714 + 0x5c;
      dword_40B5634 = dword_40C972A;
    }
    switch((CONCAT22(word_40C9720,dword_40C9722._0_2_) << 4) >> 0x16) {
    case :
    case :
      dword_40B5630 = 1;
      break;
    case :
      dword_40B5630 = 2;
      break;
    :
      dword_40B5630 = 5;
      break;
    case :
      if ((dword_40B5610 != 0) && (dword_40B5624 != 0)) {
        iVar1 = _get_vbr();
        *(undefined4 *)(iVar1 + 0x24) = dword_40B561C;
        word_40C971A = word_40C971A & 0x7fff;
        dword_40B5624 = 0;
      }
    case :
      dword_40B5630 = 6;
    }
  }
  _adb_watchdog(1);
                    /* WARNING: Subroutine does not return */
  _dbg_dispatch();
}
