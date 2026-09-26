
int _issig(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = *_active_u;
  if (_master_cpu != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIssigNotOnMast);
  }
  if ((*(int *)(iVar1 + 0x72) != 0) || (*(int *)(iVar1 + 0x76) != 0)) {
    do {
      if (*(int *)(iVar1 + 0x76) == 0) goto loc_40093A0;
      while( true ) {
        if (_active_threads == *(int *)(iVar1 + 0x76)) {
          return 0;
        }
        _thread_hold(_active_threads);
loc_40093A0:
        _thread_block();
        if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
          return 1;
        }
        if (*(int *)(iVar1 + 0x72) != 0) break;
        if (*(int *)(iVar1 + 0x76) == 0) goto loc_40093C2;
      }
    } while( true );
  }
loc_40093C2:
  do {
    if (*(char *)(dword_40B57D4 + 0x70) != '\0') {
      *(uint *)(dword_40B57D4 + 0x72) =
           1 << ((int)*(char *)(dword_40B57D4 + 0x70) - 1U & 0x3f) | *(uint *)(dword_40B57D4 + 0x72)
      ;
      *(undefined *)(dword_40B57D4 + 0x70) = 0;
    }
    iVar2 = dword_40B57D4;
    uVar5 = ~*(uint *)(iVar1 + 0x1c) & (*(uint *)(iVar1 + 0x18) | *(uint *)(dword_40B57D4 + 0x72));
    uVar6 = *(uint *)(iVar1 + 0x28) & 0x10;
    if (uVar6 == 0) {
      uVar5 = ~*(uint *)(iVar1 + 0x20) & uVar5;
    }
    if ((*(uint *)(iVar1 + 0x28) & 0x1000) != 0) {
      uVar5 = uVar5 & 0xffccffff;
    }
    if (uVar5 == 0) {
      *(undefined *)(iVar1 + 0x17) = 0;
      *(undefined *)(dword_40B57D4 + 0x70) = 0;
      return 0;
    }
    if ((param_1 != 0) && (uVar6 != 0)) {
      return 1;
    }
    iVar4 = _ffs(uVar5);
    uVar6 = 1 << (iVar4 - 1U & 0x3f);
    if ((uVar6 & 0x1ef8) != 0) {
      *(char *)(iVar2 + 0x70) = (char)iVar4;
      *(uint *)(dword_40B57D4 + 0x72) = ~uVar6 & *(uint *)(dword_40B57D4 + 0x72);
    }
    *(uint *)(iVar1 + 0x18) = ~uVar6 & *(uint *)(iVar1 + 0x18);
    *(char *)(iVar1 + 0x17) = (char)iVar4;
    if ((*(uint *)(iVar1 + 0x28) & 0x1010) == 0x10) {
      _psignal(*(undefined4 *)(iVar1 + 0x42),0x14);
      *(int *)(iVar1 + 0x6a) = _active_threads;
      iVar2 = *(int *)(iVar1 + 0x66);
      iVar4 = *(int *)(iVar2 + 0x3c);
      *(int *)(iVar2 + 0x3c) = iVar4 + 1;
      if (iVar4 == 0) {
        _task_hold(iVar2);
        *(undefined4 *)(iVar1 + 0x72) = 1;
        _task_dowait(iVar2,1);
        _thread_hold(_active_threads);
      }
      else {
        *(undefined4 *)(iVar1 + 0x72) = 1;
      }
      *(undefined *)(iVar1 + 0x13) = 6;
      *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xffffffdf;
      _wakeup(*(undefined4 *)(iVar1 + 0x42));
      _thread_block();
      *(undefined4 *)(iVar1 + 0x72) = 0;
      cVar3 = *(char *)(iVar1 + 0x17);
      if (' ' < cVar3) {
        _clear_wait(_active_threads,2,0);
        *(int *)(iVar1 + 0x76) = _active_threads;
        _task_hold(*(undefined4 *)(_active_threads + 0xc));
        _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
                    /* WARNING: Subroutine does not return */
        _exit(cVar3 + -0x20);
      }
      if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
        return 1;
      }
      if ((*(byte *)(iVar1 + 0x2b) & 0x10) != 0) {
        iVar4 = (int)cVar3;
        if (iVar4 == 0) goto loc_40093C2;
        uVar6 = 1 << (iVar4 - 1U & 0x3f);
        if ((uVar6 & *(uint *)(iVar1 + 0x1c)) == 0) goto loc_400960E;
      }
      if ((uVar6 & 0x1ef8) == 0) {
        *(uint *)(iVar1 + 0x18) = uVar6 | *(uint *)(iVar1 + 0x18);
      }
      else {
        *(uint *)(dword_40B57D4 + 0x72) = uVar6 | *(uint *)(dword_40B57D4 + 0x72);
      }
      goto loc_40093C2;
    }
loc_400960E:
    iVar2 = *(int *)((int)_active_u + iVar4 * 4 + 0x2a);
    if (iVar2 != 1) {
      if (1 < iVar2) {
        if (iVar2 != 3) {
          return iVar4;
        }
        goto loc_400970C;
      }
      if (iVar2 != 0) {
        return iVar4;
      }
      if (*(sword *)(iVar1 + 0x32) == 0) {
        *(undefined *)(dword_40B57D4 + 0x70) = 0;
        *(uint *)(dword_40B57D4 + 0x72) = ~uVar6 & *(uint *)(dword_40B57D4 + 0x72);
        goto loc_40093C2;
      }
      switch(iVar4) {
      case :
      case :
      case :
      case :
      case :
        goto loc_40093C2;
      case :
      case :
      case :
        if (*(int *)(iVar1 + 0x42) == _init_proc) {
          _psignal(iVar1,9);
          goto loc_40093C2;
        }
      case :
        if ((*(byte *)(iVar1 + 0x2b) & 0x10) == 0) {
          _psignal(*(undefined4 *)(iVar1 + 0x42),0x14);
          _stop(iVar1);
          *(undefined4 *)(iVar1 + 0x72) = 1;
          _thread_block();
          *(undefined4 *)(iVar1 + 0x72) = 0;
          if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            return 1;
          }
        }
        goto loc_40093C2;
      :
        return iVar4;
      }
    }
loc_400970C:
    if ((*(byte *)(iVar1 + 0x2b) & 0x10) == 0) {
      _printf(&aIssig);
    }
  } while( true );
}

