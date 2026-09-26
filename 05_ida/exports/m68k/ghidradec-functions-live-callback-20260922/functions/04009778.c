
int _psig(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar4 = *_active_u;
  if (_master_cpu != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aPsigNotOnMaste);
  }
  if ((*(int *)(iVar4 + 0x72) != 0) || (*(int *)(iVar4 + 0x76) != 0)) {
    do {
      if (*(int *)(iVar4 + 0x76) == 0) goto loc_40097C8;
      while( true ) {
        if (_active_threads == *(int *)(iVar4 + 0x76)) {
          return _active_threads;
        }
        _thread_hold(_active_threads);
loc_40097C8:
        iVar2 = _thread_block();
        if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
          return iVar2;
        }
        if (*(int *)(iVar4 + 0x72) != 0) break;
        if (*(int *)(iVar4 + 0x76) == 0) goto loc_40097EA;
      }
    } while( true );
  }
loc_40097EA:
  iVar2 = (int)*(char *)(iVar4 + 0x17);
  iVar3 = 1;
  uVar5 = 1 << (iVar2 - 1U & 0x3f);
  if ((iVar2 != 0) &&
     ((iVar3 = 0, (uVar5 & 0x1ef8) == 0 ||
      (iVar3 = (int)*(char *)(dword_40B57D4 + 0x70), iVar3 == iVar2)))) {
    if (*(char *)(dword_40B57D4 + 0x6a) < '\0') {
      iVar3 = _rpcont();
    }
    iVar1 = *(int *)((int)_active_u + iVar2 * 4 + 0x2a);
    if (iVar1 == 0) {
      *(word *)((int)_active_u + 0x23a) = *(word *)((int)_active_u + 0x23a) | 0x10;
      switch(iVar2) {
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      case :
        *(int *)(dword_40B57D4 + 4) = iVar2;
        *(int *)(iVar4 + 0x76) = _active_threads;
        _task_hold(*(undefined4 *)(_active_threads + 0xc));
        _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
        iVar4 = _core();
        if (iVar4 != 0) {
          iVar2 = iVar2 + 0x80;
        }
        break;
      :
        *(int *)(iVar4 + 0x76) = _active_threads;
        _task_hold(*(undefined4 *)(_active_threads + 0xc));
        _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
        break;
      case :
      case :
      case :
      case :
        goto loc_40099F6;
      }
                    /* WARNING: Subroutine does not return */
      _exit(iVar2);
    }
    if ((iVar1 == 1) || ((uVar5 & *(uint *)(iVar4 + 0x1c)) != 0)) {
      _log(4,aPsigProcessing);
    }
    *(undefined *)(dword_40B57D4 + 100) = 0;
    if ((*(byte *)(iVar4 + 0x29) & 0x10) != 0) {
      if (1 < iVar2 - 4U) {
        *(undefined4 *)((int)_active_u + iVar2 * 4 + 0x2a) = 0;
        *(uint *)(iVar4 + 0x24) = ~uVar5 & *(uint *)(iVar4 + 0x24);
      }
      uVar5 = 0;
    }
    if ((*(uint *)(iVar4 + 0x28) & 0x200) == 0) {
      uVar6 = *(undefined4 *)(iVar4 + 0x1c);
    }
    else {
      uVar6 = *(undefined4 *)((int)_active_u + 0x13a);
      *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfffffdff;
    }
    *(uint *)(iVar4 + 0x1c) =
         uVar5 | *(uint *)((int)_active_u + iVar2 * 4 + 0xae) | *(uint *)(iVar4 + 0x1c);
    *(undefined *)(iVar4 + 0x17) = 0;
    if (0x1ef8 << 0x20 - iVar2 < 0) {
      *(undefined *)(dword_40B57D4 + 0x70) = 0;
    }
    *(int *)((int)_active_u + 0x1a2) = *(int *)((int)_active_u + 0x1a2) + 1;
    iVar3 = _sendsig(iVar1,iVar2,uVar6);
  }
loc_40099F6:
  return iVar3;
}

