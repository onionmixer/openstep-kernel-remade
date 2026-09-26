/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001559ec */

kern_return_t
_mach_port_insert_right
          (ipc_space_t task,mach_port_name_t name,mach_port_t poly,mach_msg_type_name_t polyPoly)

{
  kern_return_t kVar1;
  
  if (task == 0) {
    kVar1 = 0x10;
  }
  else if (((name == 0) || (name == 0xffffffff)) || (2 < polyPoly - 0x10)) {
    kVar1 = 0x12;
  }
  else if ((poly == 0) || (poly == 0xffffffff)) {
    kVar1 = 0x14;
  }
  else {
    kVar1 = _ipc_object_copyout_name(task,poly,polyPoly,0,name);
  }
  return kVar1;
}

