
int _pty_alloc(byte param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (sword)(word)param_1 * 0xe;
  if (*(int *)((int)&dword_40B318A + iVar1) == 0) {
    _lock_write(&_pty_alloc_lock);
    if (*(int *)((int)&dword_40B318A + iVar1) == 0) {
      uVar2 = _kalloc(0x86);
      *(undefined4 *)((int)&dword_40B318A + iVar1) = uVar2;
      _bzero(uVar2,0x86);
      uVar2 = _kalloc(0xe);
      *(undefined4 *)((int)&dword_40B318E + iVar1) = uVar2;
      _bzero(uVar2,0xe);
    }
    _lock_done(&_pty_alloc_lock);
  }
  return (int)&unk_40B3184 + iVar1;
}

