/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010bf90 */

void FUN_0010bf90(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (_log_open != 0) {
    uVar2 = _splhigh();
    iVar1 = DAT_001e97c4;
    DAT_001e97c4 = 0;
    _splx(uVar2);
    if (iVar1 != 0) {
      _selwakeup(iVar1,0);
      _thread_deallocate_interrupt(iVar1);
    }
    if ((_logsoftc & 4) != 0) {
      _gsignal(DAT_001e97c8,0x17);
    }
    if ((_logsoftc & 8) != 0) {
      _wakeup(_pmsgbuf);
      _logsoftc = _logsoftc & 0xfffffff7;
    }
  }
  return;
}

