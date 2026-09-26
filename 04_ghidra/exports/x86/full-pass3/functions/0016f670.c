/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f670 */

void FUN_0016f670(int *param_1,uint *param_2)

{
  ipc_space_t task;
  uint uVar1;
  mach_port_t *previous;
  
  if ((((param_1[1] == 0x38) && (*param_1 < 0)) && (param_1[6] == DAT_001e0304)) &&
     (((param_1[8] == DAT_001e0308 && (param_1[10] == DAT_001e030c)) &&
      ((param_1[0xc] & 0x3fffffffU) == 0x10012012)))) {
    previous = (mach_port_t *)param_1[2];
    task = _convert_port_to_space();
    uVar1 = _mach_port_request_notification
                      (task,param_1[7],param_1[9],param_1[0xb],param_1[0xd],
                       (mach_msg_type_name_t)(param_2 + 9),previous);
    param_2[7] = uVar1;
    _space_deallocate(task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0310;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

