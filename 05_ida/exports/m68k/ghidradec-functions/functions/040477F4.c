
void _exception_no_server(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _active_threads;
  uVar1 = *(uint *)(_active_threads + 0x177);
  while ((uVar1 & 0x3ffffff) >> 0x18 != 0) {
    _thread_halt_self();
    uVar1 = *(uint *)(iVar2 + 0x177);
  }
  _task_terminate(*(undefined4 *)(iVar2 + 0xc));
  _thread_halt_self();
  return;
}
