/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001553a4 */

kern_return_t
_mach_port_mod_refs(ipc_space_t task,mach_port_name_t name,mach_port_right_t right,
                   mach_port_delta_t delta)

{
  kern_return_t kVar1;
  undefined4 local_8;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else if (right < 5) {
    kVar1 = _ipc_right_lookup_write(task,name,&local_8);
    if (kVar1 == 0) {
      kVar1 = _ipc_right_delta(task,name,local_8,right,delta);
    }
  }
  else {
    kVar1 = 0x12;
  }
  return kVar1;
}

