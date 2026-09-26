/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001554ac */

kern_return_t
_mach_port_set_mscount(ipc_space_t task,mach_port_name_t name,mach_port_mscount_t mscount)

{
  kern_return_t kVar1;
  undefined4 *local_8;
  
  if (task == 0) {
    return 0x10;
  }
  kVar1 = _ipc_object_translate(task,name,1,&local_8);
  if (kVar1 == 0) {
    local_8[6] = mscount;
    LOCK();
    *local_8 = 0;
    UNLOCK();
    return 0;
  }
  return kVar1;
}

