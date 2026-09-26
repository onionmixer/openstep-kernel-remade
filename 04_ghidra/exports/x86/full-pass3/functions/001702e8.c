/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001702e8 */

void FUN_001702e8(int *param_1,int param_2)

{
  task_t target_task;
  kern_return_t kVar1;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    target_task = _convert_port_to_task(param_1[2]);
    kVar1 = _task_suspend(target_task);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _task_deallocate(target_task);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

