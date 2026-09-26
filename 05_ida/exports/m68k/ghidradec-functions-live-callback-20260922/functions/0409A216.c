
void _unix_syscall_return(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = _active_threads;
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    piVar3 = (int *)_thread_user_state(_active_threads);
  }
  else {
    piVar3 = *(int **)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  iVar1 = *(int *)(iVar2 + 0x80);
  if ((((param_1 != 0) && (param_1 != 0x17)) && (0x17 < param_1)) && (param_1 == 0x1c)) {
    iVar4 = _fspause(0);
    if (iVar4 != 0) {
      *(undefined *)(iVar1 + 0x65) = 2;
    }
    param_1 = (int)*(char *)(iVar1 + 100);
  }
  if (*(char *)(iVar1 + 0x65) == '\x03') {
    if (param_1 == 0) {
      *piVar3 = *(int *)(iVar1 + 0x5c);
      piVar3[1] = *(int *)(iVar1 + 0x60);
      *(word *)(piVar3 + 0x10) = *(word *)(piVar3 + 0x10) & 0xfffe;
    }
    else {
      *piVar3 = param_1;
      *(word *)(piVar3 + 0x10) = *(word *)(piVar3 + 0x10) | 1;
    }
  }
  else if (*(char *)(iVar1 + 0x65) == '\x02') {
    *(int *)((int)piVar3 + 0x42) = *(int *)((int)piVar3 + 0x42) + -2;
  }
  *(char *)(iVar1 + 100) = (char)param_1;
  if ((*(byte *)(*(int *)(iVar2 + 0x24) + 0x54) & 8) != 0) {
    _do_trace(piVar3);
  }
  _check_for_ast(piVar3);
  __return_with_state(piVar3);
  return;
}

