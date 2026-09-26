
void _fc_thread_timer(void)

{
  int iVar1;
  int iVar2;
  
  if ((_kernel_task == 0) || (_fc_thread_init != 0)) {
    _timeout(_fc_thread_timer,0,_hz);
  }
  else {
    _kernel_thread_noblock(_kernel_task,_volume_check);
    iVar2 = 0;
    iVar1 = 0;
    do {
      if ((*(uint *)(DAT_40c3784 + iVar1) & 2) == 0) {
        _kernel_thread_noblock(_kernel_task,_fc_thread);
      }
      iVar1 = iVar1 + 0x262;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
    _fc_thread_init = 1;
  }
  return;
}

