/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e66c */

void FUN_0016e66c(int *param_1,int param_2)

{
  int iVar1;
  thread_act_t thread;
  processor_set_t new_set;
  kern_return_t kVar2;
  
  if (((param_1[1] == 0x20) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) {
    thread = _convert_port_to_thread(param_1[2]);
    new_set = _convert_port_to_pset(param_1[7]);
    kVar2 = _thread_assign(thread,new_set);
    *(kern_return_t *)(param_2 + 0x1c) = kVar2;
    _pset_deallocate(new_set);
    _thread_deallocate(thread);
    if (((*(int *)(param_2 + 0x1c) == 0) && (iVar1 = param_1[7], iVar1 != 0)) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

