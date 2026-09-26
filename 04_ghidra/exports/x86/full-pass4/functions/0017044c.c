/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017044c */

void FUN_0017044c(int *param_1,int param_2)

{
  task_name_t target_task;
  kern_return_t kVar1;
  mach_msg_type_number_t local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0458)) {
    target_task = _convert_port_to_task(param_1[2]);
    local_8 = 0x400;
    kVar1 = _task_info(target_task,param_1[7],(task_info_t)(param_2 + 0x2c),&local_8);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _task_deallocate(target_task);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e045c;
      *(undefined **)(param_2 + 0x24) = PTR_s__62I__001e0460;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e0464;
      *(mach_msg_type_number_t *)(param_2 + 0x28) = local_8;
      *(mach_msg_type_number_t *)(param_2 + 4) = local_8 * 4 + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

