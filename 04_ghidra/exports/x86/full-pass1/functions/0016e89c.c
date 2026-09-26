/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e89c */

void FUN_0016e89c(int *param_1,uint *param_2)

{
  task_t task;
  uint uVar1;
  processor_set_name_t local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    task = _convert_port_to_task(param_1[2]);
    uVar1 = _task_get_assignment(task,&local_8);
    param_2[7] = uVar1;
    _task_deallocate(task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0158;
      uVar1 = _convert_pset_name_to_port(local_8);
      param_2[9] = uVar1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

