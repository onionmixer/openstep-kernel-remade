
void _thread_syscall_return(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    puVar1 = (undefined4 *)_thread_user_state(_active_threads);
  }
  else {
    puVar1 = *(undefined4 **)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  *puVar1 = param_1;
  _check_for_ast(puVar1);
  __return_with_state(puVar1);
  return;
}

