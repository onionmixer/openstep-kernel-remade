/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156c90 */

void _exception_no_server(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = _active_threads;
  bVar1 = *(byte *)(_active_threads + 0x17c);
  while ((bVar1 & 3) != 0) {
    _thread_halt_self();
    bVar1 = *(byte *)(iVar2 + 0x17c);
  }
  _task_terminate(*(task_t *)(iVar2 + 0xc));
  _thread_halt_self();
  return;
}

