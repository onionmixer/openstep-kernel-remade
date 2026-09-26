
void _unix_syscall_return(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _active_threads;
  iVar2 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar2 == 0) {
    iVar2 = _thread_user_state(_active_threads);
  }
  else {
    iVar2 = iVar2 + 0x84;
  }
  iVar1 = *(int *)(iVar1 + 0x84);
  if ((((param_1 != 0) && (param_1 != 0x17)) && (0x17 < param_1)) && (param_1 == 0x1c)) {
    iVar3 = _fspause(0);
    if (iVar3 != 0) {
      *(undefined1 *)(DAT_001e875c + 0x69) = 2;
    }
    param_1 = (int)*(char *)(iVar1 + 0x68);
  }
  if (*(char *)(iVar1 + 0x69) == '\x03') {
    if (param_1 == 0) {
      *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar1 + 0x60);
      *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 100);
      *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xfffffffe;
    }
    else {
      *(int *)(iVar2 + 0x2c) = param_1;
      *(byte *)(iVar2 + 0x40) = *(byte *)(iVar2 + 0x40) | 1;
    }
  }
  else if (*(char *)(iVar1 + 0x69) == '\x02') {
    *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + -7;
  }
  *(char *)(iVar1 + 0x68) = (char)param_1;
  _thread_exception_return();
  return;
}

