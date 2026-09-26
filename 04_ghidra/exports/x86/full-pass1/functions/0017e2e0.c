/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e2e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0017e2e0(void)

{
  int iVar1;
  kern_return_t kVar2;
  boolean_t unaff_EBP;
  task_t *unaff_retaddr;
  
  DAT_001f7494 = &_dmaBufQueue;
  _dmaBufQueue = &_dmaBufQueue;
  kVar2 = _task_create(_kernel_task,(ledger_array_t)0x0,0x1f748c,unaff_EBP,unaff_retaddr);
  if (kVar2 != 0) {
    _IOLog(s_IOLibIOInit_task_create_returned_001e0f49,kVar2);
    return;
  }
  _task_deallocate(_IOTask_kern);
  _vm_map_deallocate(*(undefined4 *)(_IOTask_kern + 0xc));
  iVar1 = _IOTask_kern;
  *(undefined4 *)(_IOTask_kern + 0xc) = _kernel_map;
  *(undefined4 *)(iVar1 + 0x3c) = _kernel_proc;
  *(undefined4 *)(iVar1 + 0x50) = 1;
  _lock_init(*(int *)(iVar1 + 0x38) + 0x20,1);
  iVar1 = _IOTask_kern;
  *(undefined4 *)(*(int *)(_IOTask_kern + 0x38) + 0x1c) = _rootcred;
  **(undefined4 **)(iVar1 + 0x38) = _kernel_proc;
  _processor_set_policy_enable(0x1e9610,2);
  __IOTask = _IOTaskGetPort(*(undefined4 *)(_IOTask_kern + 0x6c));
  return;
}

