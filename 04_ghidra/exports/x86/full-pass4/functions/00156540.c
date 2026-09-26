/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156540 */

kern_return_t
_port_set_status(ipc_space_t param_1,mach_port_name_t param_2,mach_port_name_array_t *param_3,
                mach_msg_type_number_t *param_4)

{
  kern_return_t kVar1;
  
  kVar1 = _mach_port_get_set_status(param_1,param_2,param_3,param_4);
  if ((kVar1 != 0) && (kVar1 != 6)) {
    kVar1 = 4;
  }
  return kVar1;
}

