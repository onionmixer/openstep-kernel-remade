
void _thread_exception_return(void)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    uVar1 = _thread_user_state(_active_threads);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  _check_for_ast(uVar1);
  __return_with_state(uVar1);
  return;
}

