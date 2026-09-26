/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001550a4 */

kern_return_t _mach_port_type(ipc_space_t task,mach_port_name_t name,mach_port_type_t *ptype)

{
  kern_return_t kVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else {
    kVar1 = _ipc_right_lookup_write(task,name,&local_8);
    if ((kVar1 == 0) && (kVar1 = _ipc_right_info(task,name,local_8,ptype,local_c), kVar1 == 0)) {
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
    }
  }
  return kVar1;
}

