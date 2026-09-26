/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017be44 */

thread_act_t _procdup(int param_1,int param_2)

{
  kern_return_t kVar1;
  boolean_t unaff_EBX;
  task_t *unaff_ESI;
  thread_act_t local_c;
  task_t local_8;
  
  kVar1 = _task_create(*(task_t *)(param_2 + 0x68),
                       (ledger_array_t)(uint)(_kernel_task != *(task_t *)(param_2 + 0x68)),
                       (mach_msg_type_number_t)&local_8,unaff_EBX,unaff_ESI);
  if (kVar1 != 0) {
    _printf(s_fork_procdup__task_create_failed_001e0db4,kVar1);
  }
  *(task_t *)(param_1 + 0x68) = local_8;
  _task_deallocate(local_8);
  *(int *)(local_8 + 0x3c) = param_1;
  kVar1 = _thread_create(local_8,&local_c);
  if (kVar1 != 0) {
    _printf(s_fork_procdup__thread_create_fail_001e0de2,kVar1);
  }
  _thread_deallocate(local_c);
  _compute_priority(local_c,0);
  _bcopy(*(void **)(*(int *)(param_2 + 0x68) + 0x38),*(void **)(local_8 + 0x38),0x298);
  _bzero((void *)(*(int *)(local_8 + 0x38) + 0x248),0x18);
  *(undefined4 *)(*(int *)(local_8 + 0x38) + 0x15c) = 0;
  _expand_fdlist(*(int *)(local_8 + 0x38),*(undefined4 *)(*(int *)(local_8 + 0x38) + 0x158));
  _bcopy(*(void **)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x150),
         *(void **)(*(int *)(local_8 + 0x38) + 0x150),
         (*(int *)(*(int *)(local_8 + 0x38) + 0x158) + 1) * 4);
  _bcopy(*(void **)(*(int *)(*(int *)(param_2 + 0x68) + 0x38) + 0x154),
         *(void **)(*(int *)(local_8 + 0x38) + 0x154),*(int *)(*(int *)(local_8 + 0x38) + 0x158) + 1
        );
  **(int **)(*(int *)(local_c + 0xc) + 0x38) = param_1;
  _bzero((void *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x170),0x48);
  _bzero((void *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x1b8),0x48);
  *(undefined4 *)(*(int *)(*(int *)(local_c + 0xc) + 0x38) + 0x2c) = 0;
  return local_c;
}

