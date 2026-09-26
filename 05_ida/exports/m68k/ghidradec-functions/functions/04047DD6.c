
void _exception_raise_continue_slow(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _active_threads;
  iVar3 = *(int *)(_active_threads + 0xbc);
  iVar4 = iVar3 + 0x3c;
  while (param_1 == 0x10004005) {
    while ((*(uint *)(iVar1 + 0x177) & 0x3ffffff) >> 0x18 != 0) {
      if ((iVar3 != 0) && (iVar3 != -1)) {
        _ipc_object_release(iVar3);
      }
      *(undefined4 *)(iVar1 + 0xbc) = 0;
      iVar4 = 0;
      _thread_halt_self_with_continuation(0);
      iVar3 = *(int *)(iVar1 + 0xb8);
      *(int *)(iVar1 + 0xbc) = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        _ipc_object_reference(iVar3);
        iVar4 = iVar3 + 0x3c;
      }
    }
    if (((iVar3 == 0) || (iVar3 == -1)) || (-1 < *(int *)(iVar3 + 4))) {
      param_1 = 0x10004009;
      break;
    }
    pcVar2 = (code *)0x0;
    if (*(int *)(iVar1 + 0x34) != 0) {
      pcVar2 = _exception_raise_continue;
    }
    param_1 = _ipc_mqueue_receive(iVar4,0,0xffffffff,0,0,pcVar2,&param_2,&stack0x0000000c);
  }
  if ((iVar3 != 0) && (iVar3 != -1)) {
    _ipc_object_release(iVar3);
  }
  if (param_1 == 0) {
    _ipc_port_release_sonce(iVar3);
    param_1 = _exception_parse_reply(param_2);
    if (param_1 != 0) goto loc_4047EC8;
  }
  else {
loc_4047EC8:
    if (param_1 != 0x10004009) goto loc_4047EE0;
  }
  if (*(int *)(iVar1 + 0x34) == 0) {
    return;
  }
  _call_continuation(*(int *)(iVar1 + 0x34));
loc_4047EE0:
  if (*(int *)(iVar1 + 0xc0) == 0) {
    _exception_no_server();
  }
  else {
    _exception_try_task(*(int *)(iVar1 + 0xc0),*(undefined4 *)(iVar1 + 0xc4),
                        *(undefined4 *)(iVar1 + 200));
  }
  return;
}
