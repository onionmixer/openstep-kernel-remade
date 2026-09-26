
undefined4 _fc_start(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = dword_40C3704;
  if (*(int *)(param_1 + 4) == 0) {
    if ((_fd_polling_mode == 0) && ((*(uint *)(dword_40C3704 + 0x18) & 2) == 0)) {
      _fd_thread_block(dword_40C3704 + 0x18,2,dword_40C3704 + 0x14);
    }
    piVar1 = *(int **)(iVar2 + 0x10);
    if (piVar1 == (int *)(iVar2 + 0xc)) {
      *piVar1 = param_1;
    }
    else {
      *(int *)((int)piVar1 + 0x12a) = param_1;
    }
    *(int **)(param_1 + 0x12e) = piVar1;
    *(int *)(param_1 + 0x12a) = iVar2 + 0xc;
    *(int *)(iVar2 + 0x10) = param_1;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 1;
    if (_fd_polling_mode != 0) {
      _fc_thread();
      return *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x3e);
    }
    _thread_wakeup_prim(iVar2 + 0x18,0,0);
  }
  else if (*(int *)(param_1 + 0x66) == 2) {
    _fd_intr(param_1);
  }
  else {
    _v2d_map(param_1);
  }
  return 0;
}

