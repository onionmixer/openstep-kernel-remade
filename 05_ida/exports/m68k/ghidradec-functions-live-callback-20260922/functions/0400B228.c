
void sub_400B228(void)

{
  int iVar1;
  
  iVar1 = dword_40B67E8;
  if (_log_open != 0) {
    dword_40B67E8 = 0;
    if (iVar1 != 0) {
      _selwakeup(iVar1,0);
      _thread_deallocate_interrupt(iVar1);
    }
    if ((_logsoftc & 4) != 0) {
      _gsignal(dword_40B67EC,0x17);
    }
    if ((_logsoftc & 8) != 0) {
      _wakeup(_pmsgbuf);
      _logsoftc = _logsoftc & 0xfffffff7;
    }
  }
  return;
}

