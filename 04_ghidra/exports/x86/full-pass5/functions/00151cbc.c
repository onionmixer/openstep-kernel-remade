/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151cbc */

kern_return_t
_mach_port_get_srights(ipc_space_t task,mach_port_name_t name,mach_port_rights_t *srights)

{
  kern_return_t kVar1;
  undefined4 *local_8;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else {
    kVar1 = _ipc_object_translate(task,name,1,&local_8);
    if (kVar1 == 0) {
      LOCK();
      *local_8 = 0;
      UNLOCK();
      *srights = local_8[7];
      kVar1 = 0;
    }
  }
  return kVar1;
}

