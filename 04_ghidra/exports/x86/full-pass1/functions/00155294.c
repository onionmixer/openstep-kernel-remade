/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155294 */

kern_return_t _mach_port_deallocate(ipc_space_t task,mach_port_name_t name)

{
  kern_return_t kVar1;
  undefined4 local_8;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else {
    kVar1 = _ipc_right_lookup_write(task,name,&local_8);
    if (kVar1 == 0) {
      kVar1 = _ipc_right_dealloc(task,name,local_8);
    }
  }
  return kVar1;
}

