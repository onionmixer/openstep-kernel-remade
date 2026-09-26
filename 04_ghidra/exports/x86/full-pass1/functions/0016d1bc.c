/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d1bc */

int _kern_serv_kernel_task_port(void)

{
  int local_8;
  
  _task_reference(_kernel_task);
  local_8 = _convert_task_to_port(_kernel_task);
  if (local_8 != 0) {
    _object_copyout(*(undefined4 *)(_active_threads + 0xc),local_8,6,&local_8);
    return local_8;
  }
  return 0;
}

