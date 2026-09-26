/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d158 */

int FUN_0015d158(int param_1,int param_2)

{
  kern_return_t kVar1;
  int iVar2;
  int iVar3;
  thread_act_t local_8;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    local_8 = _active_threads;
  }
  else {
    kVar1 = _thread_create(*(task_t *)(_active_threads + 0xc),&local_8);
    if (kVar1 != 0) {
      return 7;
    }
    _thread_deallocate(local_8);
  }
  iVar3 = param_1 + 8;
  iVar2 = FUN_0015d21c(local_8,iVar3,*(int *)(param_1 + 4) + -8);
  if (iVar2 == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar2 = FUN_0015d270(_active_threads,iVar3,*(int *)(param_1 + 4) + -8,param_2 + 8);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar3 = FUN_0015d2d4(_active_threads,iVar3,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    else {
      _thread_resume(local_8);
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    iVar2 = 0;
  }
  return iVar2;
}

