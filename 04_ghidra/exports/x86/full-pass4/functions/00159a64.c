/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159a64 */

undefined4 _mach_reply_port(void)

{
  int iVar1;
  undefined4 *local_c;
  undefined4 local_8;
  
  iVar1 = _ipc_port_alloc(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),&local_8,&local_c)
  ;
  if (iVar1 == 0) {
    LOCK();
    *local_c = 0;
    UNLOCK();
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

