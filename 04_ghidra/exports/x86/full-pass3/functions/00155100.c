/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155100 */

kern_return_t
_mach_port_rename(ipc_space_t task,mach_port_name_t old_name,mach_port_name_t new_name)

{
  kern_return_t kVar1;
  
  if (task == 0) {
    return 0x10;
  }
  if ((new_name != 0) && (new_name != 0xffffffff)) {
    kVar1 = _ipc_object_rename(task,old_name,new_name);
    return kVar1;
  }
  return 0x12;
}

