/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001331cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _async_daemon(void)

{
  byte *pbVar1;
  int iVar2;
  
  *(undefined4 *)(_active_threads + 0x78) = 1;
  _stack_privilege(_active_threads);
  DAT_001e59ec = DAT_001e59ec + 1;
  iVar2 = _set_label((int *)(DAT_001e875c + 0x28));
  if (iVar2 == 0) {
    do {
      _DAT_001e59e8 = _DAT_001e59e8 + 1;
      while (_async_bufhead == (byte *)0x0) {
        _sleep(0x1ef174);
      }
      _DAT_001e59e8 = _DAT_001e59e8 + -1;
      pbVar1 = _async_bufhead;
      _async_bufhead = *(byte **)(_async_bufhead + 0xc);
      FUN_001332c8(pbVar1);
    } while( true );
  }
  if (DAT_001e59ec == 0) {
    iVar2 = DAT_001e59ec;
    if (_async_bufhead != (byte *)0x0) {
      do {
        *_async_bufhead = *_async_bufhead | 4;
        pbVar1 = _async_bufhead;
        _async_bufhead = *(byte **)(_async_bufhead + 0xc);
        _biodone(pbVar1);
      } while (_async_bufhead != (byte *)0x0);
      return;
    }
  }
  else {
    iVar2 = DAT_001e59ec + -1;
    _DAT_001e59e8 = _DAT_001e59e8 + -1;
    if ((iVar2 == 0) && (DAT_001e59ec = 0, _async_bufhead != (byte *)0x0)) {
      do {
        pbVar1 = _async_bufhead;
        _async_bufhead = *(byte **)(_async_bufhead + 0xc);
        FUN_001332c8(pbVar1);
      } while (_async_bufhead != (byte *)0x0);
      return;
    }
  }
  DAT_001e59ec = iVar2;
  return;
}

