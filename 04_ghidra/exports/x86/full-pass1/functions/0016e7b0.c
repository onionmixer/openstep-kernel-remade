/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e7b0 */

void FUN_0016e7b0(int *param_1,int param_2)

{
  int iVar1;
  task_t task;
  processor_set_t new_set;
  kern_return_t kVar2;
  
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) &&
     (param_1[8] == DAT_001e0150)) {
    task = _convert_port_to_task(param_1[2]);
    new_set = _convert_port_to_pset(param_1[7]);
    kVar2 = _task_assign(task,new_set,param_1[9]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar2;
    _pset_deallocate(new_set);
    _task_deallocate(task);
    if (((*(int *)(param_2 + 0x1c) == 0) && (iVar1 = param_1[7], iVar1 != 0)) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

