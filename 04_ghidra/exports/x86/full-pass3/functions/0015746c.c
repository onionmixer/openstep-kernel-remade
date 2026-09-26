/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015746c */

void _exception_raise_continue(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = _ipc_mqueue_receive(*(int *)(_active_threads + 0xc4) + 0x40,0,0xffffffff,0,1,
                              _exception_raise_continue,&local_8,&local_c);
  _exception_raise_continue_slow(uVar1,local_8,local_c);
  return;
}

