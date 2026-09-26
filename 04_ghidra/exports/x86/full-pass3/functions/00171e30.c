/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171e30 */

undefined4 _ux_handler_init(void)

{
  undefined4 uVar1;
  
  DAT_001e7280 = 0;
  _ux_exception_port = 0;
  uVar1 = _kernel_task_create(_kernel_task,0);
  _kernel_thread(uVar1,FUN_00171cb4,0);
  do {
  } while (DAT_001e7280 != 0);
  LOCK();
  DAT_001e7280 = 1;
  UNLOCK();
  if (_ux_exception_port != 0) {
    LOCK();
    DAT_001e7280 = 0;
    UNLOCK();
    return 1;
  }
  uVar1 = _thread_sleep(&_ux_exception_port,&DAT_001e7280,0);
  return uVar1;
}

