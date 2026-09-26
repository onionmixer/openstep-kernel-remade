/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170370 */

void FUN_00170370(int *param_1,uint *param_2)

{
  task_t task;
  uint uVar1;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e044c)) {
    task = _convert_port_to_task(param_1[2]);
    uVar1 = _task_get_special_port(task,param_1[7],param_2 + 9);
    param_2[7] = uVar1;
    _task_deallocate(task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0450;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

