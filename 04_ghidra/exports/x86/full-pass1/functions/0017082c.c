/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017082c */

void FUN_0017082c(int *param_1,int param_2)

{
  thread_act_t target_act;
  kern_return_t kVar1;
  mach_msg_type_number_t local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e048c)) {
    target_act = _convert_port_to_thread(param_1[2]);
    local_8 = 0x400;
    kVar1 = _thread_info(target_act,param_1[7],(thread_info_t)(param_2 + 0x2c),&local_8);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _thread_deallocate(target_act);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e0490;
      *(undefined **)(param_2 + 0x24) = PTR_s__62I__001e0494;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e0498;
      *(mach_msg_type_number_t *)(param_2 + 0x28) = local_8;
      *(mach_msg_type_number_t *)(param_2 + 4) = local_8 * 4 + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

