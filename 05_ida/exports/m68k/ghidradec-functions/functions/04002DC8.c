
void _init_task(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  _task_name(&aInit);
  puVar1 = dword_40B57D4;
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    uVar2 = _thread_user_state(_active_threads);
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  *puVar1 = uVar2;
  _load_init_program();
  _thread_exception_return();
  return;
}
