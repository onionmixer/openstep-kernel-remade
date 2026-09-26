/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015513c */

kern_return_t
_mach_port_allocate_name(ipc_space_t task,mach_port_right_t right,mach_port_name_t name)

{
  kern_return_t kVar1;
  int iVar2;
  undefined4 *local_c;
  undefined4 *local_8;
  
  if (task == 0) {
    return 0x10;
  }
  if ((name == 0) || (name == 0xffffffff)) {
    return 0x12;
  }
  if (right == 3) {
    iVar2 = _ipc_pset_alloc_name(task,name,&local_c);
joined_r0x001551ab:
    if (iVar2 == 0) {
      LOCK();
      *local_c = 0;
      UNLOCK();
    }
  }
  else {
    if (right < 4) {
      if (right == 1) {
        iVar2 = _ipc_port_alloc_name(task,name,&local_8);
        local_c = local_8;
        goto joined_r0x001551ab;
      }
    }
    else if (right == 4) {
      kVar1 = _ipc_object_alloc_dead_name(task,name);
      return kVar1;
    }
    iVar2 = 0x12;
  }
  return iVar2;
}

