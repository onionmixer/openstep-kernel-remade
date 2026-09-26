
void _exception_raise_continue_fast(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _active_threads;
  param_1[7] = param_1[7] + -1;
  *param_1 = *param_1 + -2;
  iVar2 = _exception_parse_reply(param_2);
  if (iVar2 == 0) {
    if (*(int *)(iVar1 + 0x34) != 0) {
      _call_continuation(*(int *)(iVar1 + 0x34));
    }
    _thread_exception_return();
  }
  else {
    if (*(int *)(iVar1 + 0xc0) != 0) {
      _exception_try_task(*(int *)(iVar1 + 0xc0),*(undefined4 *)(iVar1 + 0xc4),
                          *(undefined4 *)(iVar1 + 200));
    }
    _exception_no_server();
  }
  return;
}
