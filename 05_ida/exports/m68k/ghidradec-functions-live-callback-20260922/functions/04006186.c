
void _fork1(undefined4 param_1)

{
  sword sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = _alloc_posix_proc();
  iVar5 = 0;
  sVar1 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
  iVar3 = _allproc;
  if (sVar1 != 0) {
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      if (sVar1 == *(sword *)(iVar3 + 0x2c)) {
        iVar5 = iVar5 + 1;
      }
    }
    if (_zombproc != 0) {
      iVar3 = _zombproc;
      do {
        if (*(sword *)(*(int *)((int)_active_u + 0x1a) + 2) == *(sword *)(iVar3 + 0x2c)) {
          iVar5 = iVar5 + 1;
        }
        iVar3 = *(int *)(iVar3 + 8);
      } while (iVar3 != 0);
    }
  }
  if (_freeproc == 0) {
    iVar3 = _getproc();
    if (iVar3 != 0) {
      *(int *)(iVar3 + 8) = _freeproc;
      _freeproc = iVar3;
      goto loc_4006222;
    }
    _tablefull(&aProc);
  }
  else {
loc_4006222:
    iVar3 = _freeproc;
    if ((*(sword *)(*(int *)((int)_active_u + 0x1a) + 2) == 0) || (iVar5 < 0x65)) {
      iVar5 = *_active_u;
      iVar4 = _cloneproc(iVar5,param_1,uVar2);
      _thread_dup(_active_threads,iVar4);
      *(int *)(*(int *)(iVar4 + 0x80) + 0x5c) = (int)*(sword *)(iVar5 + 0x30);
      *(undefined4 *)(*(int *)(iVar4 + 0x80) + 0x60) = 1;
      _microtime(*(int *)(*(int *)(iVar4 + 0xc) + 0x30) + 0x232);
      *(undefined2 *)(*(int *)(*(int *)(iVar4 + 0xc) + 0x30) + 0x23a) = 1;
      *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar3 + 0x30);
      _thread_resume(iVar4);
      goto loc_40062C2;
    }
  }
  _free_posix_proc(uVar2);
  *(undefined *)(dword_40B57D4 + 100) = 0xb;
loc_40062C2:
  *(undefined4 *)(dword_40B57D4 + 0x60) = 0;
  return;
}

