/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155a44 */

kern_return_t
_mach_port_extract_right
          (ipc_space_t task,mach_port_name_t name,mach_msg_type_name_t msgt_name,mach_port_t *poly,
          mach_msg_type_name_t *polyPoly)

{
  kern_return_t kVar1;
  mach_msg_type_name_t mVar2;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else if (msgt_name - 0x10 < 6) {
    kVar1 = _ipc_object_copyin(task,name,msgt_name,poly);
    if (kVar1 == 0) {
      mVar2 = _ipc_object_copyin_type(msgt_name);
      *polyPoly = mVar2;
    }
  }
  else {
    kVar1 = 0x12;
  }
  return kVar1;
}

