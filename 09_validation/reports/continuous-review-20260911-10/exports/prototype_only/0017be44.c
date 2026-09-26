
thread_act_t _procdup(int param_1,int param_2)

{
  int iVar1;
  kern_return_t kVar2;
  thread_act_t local_c;
  void *local_8;
  
  iVar1 = _task_create(*(void **)(param_2 + 0x68),(uint)(_kernel_task != *(void **)(param_2 + 0x68))
                       ,&local_8);
  if (iVar1 != 0) {
    _printf(s_fork_procdup__task_create_failed_001e0db4,iVar1);
  }
  *(void **)(param_1 + 0x68) = local_8;
  _task_deallocate(local_8);
  *(int *)((int)local_8 + 0x3c) = param_1;
  kVar2 = _thread_create((task_t)local_8,&local_c);
  if (kVar2 != 0) {
    _printf(s_fork_procdup__thread_create_fail_001e0de2,kVar2);
  }
  _thread_deallocate(local_c);
  _compute_priority(local_c,0);
  _bcopy(*(void **)(*(int *)(param_2 + 0x68) + 0x38),*(void **)((int)local_8 + 0x38),0x298);
  _bzero((void *)(*(int *)((int)local_8 + 0x38) + 0x248),0x18);
  *(undefined4 *)(*(int *)((int)local_8 + 0x38) + 0x15c) = 0;
  _expand_fdlist(*(int *)((int)local_8 + 0x38),
                 *(undefined4 *)(*(int *)((int)local_8 + 0x38) + 0x158));
  _bcopy(*(void **)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x150),
         *(void **)(*(int *)((int)local_8 + 0x38) + 0x150),
         (*(int *)(*(int *)((int)local_8 + 0x38) + 0x158) + 1) * 4);
  _bcopy(*(void **)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x154),
         *(void **)(*(int *)((int)local_8 + 0x38) + 0x154),
         *(int *)(*(int *)((int)local_8 + 0x38) + 0x158) + 1);
  **(int **)(*(int *)(local_c + 0xc) + 0x38) = param_1;
  _bzero((void *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x170),0x48);
  _bzero((void *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x1b8),0x48);
  *(undefined4 *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x2c) = 0;
  return local_c;
}

