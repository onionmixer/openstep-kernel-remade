/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e3ec */

undefined4 __io_task_get_port(undefined4 param_1)

{
  undefined4 local_8;
  
  _port_reference(param_1);
  _object_copyout(_IOTask_kern,param_1,6,&local_8);
  return local_8;
}

