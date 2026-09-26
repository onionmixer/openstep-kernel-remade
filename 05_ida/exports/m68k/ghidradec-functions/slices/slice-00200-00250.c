/* GHIDRADEC_FUNCTION index=200 start=0x4008b68 */

undefined4 _sigblock(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  *(undefined4 *)(dword_40B57D4 + 0x5c) = *(undefined4 *)(iVar1 + 0x1c);
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar3 = *(uint *)*puVar2 & 0xfffafeff;
  }
  else {
    uVar3 = *(uint *)*puVar2 & 0xfffefeff;
  }
  uVar3 = *(uint *)(iVar1 + 0x1c) | uVar3;
  *(uint *)(iVar1 + 0x1c) = uVar3;
  return CONCAT22((sword)(uVar3 >> 0x10),(word)(byte)(((int)uVar3 < 0) << 3 | (uVar3 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=201 start=0x4008bca */

undefined4 _sigsetmask(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  *(undefined4 *)(dword_40B57D4 + 0x5c) = *(undefined4 *)(iVar1 + 0x1c);
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar3 = *(uint *)*puVar2 & 0xfffafeff;
  }
  else {
    uVar3 = *(uint *)*puVar2 & 0xfffefeff;
  }
  *(uint *)(iVar1 + 0x1c) = uVar3;
  return CONCAT22((sword)(uVar3 >> 0x10),(word)(byte)(((int)uVar3 < 0) << 3 | (uVar3 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=202 start=0x4008c26 */

void _sigcont(void)

{
  _unix_syscall_return(4);
  return;
}
/* GHIDRADEC_FUNCTION index=203 start=0x4008c38 */

void _sigpause(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  *(undefined4 *)((int)_active_u + 0x13a) = *(undefined4 *)(iVar1 + 0x1c);
  *(word *)(iVar1 + 0x2a) = *(word *)(iVar1 + 0x2a) | 0x200;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar3 = *puVar2 & 0xfffafeff;
  }
  else {
    uVar3 = *puVar2 & 0xfffefeff;
  }
  *(uint *)(iVar1 + 0x1c) = uVar3;
  _sleep_with_continuation(&_active_u,0x28,_sigcont);
  return;
}
/* GHIDRADEC_FUNCTION index=204 start=0x4008c9e */

void _sigstack(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = piVar1[1];
  if (iVar2 != 0) {
    uVar3 = _copyoutmsg(_active_u + 0x13e,iVar2,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
  }
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    uVar3 = _copyinmsg(iVar2,&uStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    iVar2 = _active_u;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined4 *)(_active_u + 0x13e) = uStack_c;
      *(undefined4 *)(iVar2 + 0x142) = uStack_8;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=205 start=0x4008d36 */

void _kill(void)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  uVar7 = piVar1[1];
  if (0x20 < uVar7) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return;
  }
  iVar3 = *piVar1;
  if (iVar3 < 1) {
    if (iVar3 == -1) {
      uVar8 = 1;
      iVar3 = 0;
    }
    else if (iVar3 == 0) {
      uVar8 = 0;
      iVar3 = 0;
    }
    else {
      uVar8 = 0;
      iVar3 = -*piVar1;
      uVar7 = piVar1[1];
    }
    uVar6 = _killpg1(uVar7,iVar3,uVar8);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    return;
  }
  iVar3 = _pfind(iVar3);
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
    return;
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
    if ((sVar2 != 0) && (sVar2 != *(sword *)(iVar3 + 0x2c))) goto loc_4008E34;
  }
  else {
    iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    iVar5 = _suser();
    if (iVar5 == 0) {
      sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
      if ((((sVar2 != *(sword *)(iVar4 + 4)) && (sVar2 != *(sword *)(iVar4 + 6))) &&
          (sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6), sVar2 != *(sword *)(iVar4 + 4)))
         && (sVar2 != *(sword *)(iVar4 + 6))) {
        if (piVar1[1] != 0x13) {
loc_4008E34:
          *(undefined *)(dword_40B57D4 + 100) = 1;
          return;
        }
        iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
        iVar4 = *(int *)(iVar4 + 0xe);
        iVar5 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
        if (*(int *)(iVar4 + 8) != *(int *)(*(int *)(iVar5 + 0xe) + 8)) goto loc_4008E34;
      }
    }
    *(undefined *)(dword_40B57D4 + 100) = 0;
  }
  if (piVar1[1] != 0) {
    _psignal(iVar3,piVar1[1]);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=206 start=0x4008e98 */

void _killpg(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = (*(undefined4 **)(dword_40B57D4 + 0x24))[1];
  if (uVar1 < 0x21) {
    uVar2 = _killpg1(uVar1,**(undefined4 **)(dword_40B57D4 + 0x24),0);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=207 start=0x4008ed2 */

int _killpg1(int param_1,int param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (((param_3 != 0) || (param_2 != 0)) ||
     (param_2 = (int)*(sword *)(*_active_u + 0x2e), param_2 != 0)) {
    iVar4 = 0;
    for (iVar1 = _allproc; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((((param_2 == *(sword *)(iVar1 + 0x2e)) || (param_3 != 0)) &&
          ((*(sword *)(iVar1 + 0x32) != 0 && ((*(byte *)(iVar1 + 0x2b) & 2) == 0)))) &&
         ((param_3 == 0 || (iVar1 != *_active_u)))) {
        sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
        if ((sVar2 == 0) ||
           ((sVar2 == *(sword *)(iVar1 + 0x2c) ||
            ((param_1 == 0x13 && (iVar3 = _inferior(iVar1), iVar3 != 0)))))) {
          iVar4 = iVar4 + 1;
          if (param_1 != 0) {
            _psignal(iVar1,param_1);
          }
        }
        else if (param_3 == 0) {
          iVar5 = 1;
        }
      }
    }
    if (iVar5 != 0) {
      return iVar5;
    }
    if (iVar4 != 0) {
      return 0;
    }
  }
  return 3;
}
/* GHIDRADEC_FUNCTION index=208 start=0x4008f96 */

void _gsignal(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = _pgfind(param_1);
    if (iVar1 != 0) {
      _pgsignal(iVar1,param_2,0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=209 start=0x4008fc0 */

void _pgsignal(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 10)) {
      if ((param_3 == 0) || ((*(byte *)(iVar1 + 0x28) & 0x40) != 0)) {
        _psignal(iVar1,param_2);
      }
      iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=210 start=0x400901a */

void _psignal(int param_1,uint param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (0x20 < param_2) {
    return;
  }
  uVar3 = 1 << (param_2 - 1 & 0x3f);
  iVar1 = *(int *)(param_1 + 0x66);
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0x48) != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x2b) & 0x10) == 0) {
    if ((((*(byte *)(param_1 + 0x16) & 0x40) == 0) || (uVar3 != 0x40000)) &&
       ((uVar3 & *(uint *)(param_1 + 0x20)) != 0)) {
      return;
    }
    if ((((*(byte *)(param_1 + 0x16) & 0x40) == 0) || (uVar3 != 0x40000)) &&
       ((uVar3 & *(uint *)(param_1 + 0x1c)) != 0)) {
      iVar5 = 3;
    }
    else {
      iVar5 = 0;
      if ((uVar3 & *(uint *)(param_1 + 0x24)) != 0) {
        iVar5 = 2;
      }
    }
  }
  else {
    iVar5 = 0;
  }
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x18) = uVar3 | *(uint *)(param_1 + 0x18);
    switch(param_2) {
    case :
      if (((*(byte *)(param_1 + 0x2b) & 0x10) == 0) && (iVar5 == 0)) goto loc_40090e8;
      break;
    case :
    case :
    case :
    case :
      *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xfb;
      break;
    case :
loc_40090e8:
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffccffff;
    }
  }
  iVar4 = _active_threads;
  if (iVar5 == 3) {
    return;
  }
  piVar6 = (int *)_active_threads;
  if (iVar1 != *(int *)(_active_threads + 0xc)) {
    piVar6 = *(int **)(iVar1 + 0x18);
    if (piVar6 == (int *)(iVar1 + 0x18)) {
      return;
    }
    _thread_reference(piVar6);
  }
  if ((param_2 == 9) && ('\0' < *(char *)(param_1 + 0x15))) {
    *(undefined *)(param_1 + 0x15) = 0;
    _thread_max_priority(piVar6,*(undefined4 *)((int)piVar6 + 0x178),10);
    _thread_priority(piVar6,10,0);
  }
  if ((*(byte *)(param_1 + 0x2b) & 0x10) == 0) {
    if (iVar5 == 0) {
      switch(param_2) {
      case :
        while (0 < *(int *)(iVar1 + 0x3c)) {
          _task_resume(iVar1);
        }
        *(undefined *)(param_1 + 0x13) = 3;
        iVar1 = *(int *)((int)piVar6 + 0x88);
        while (0 < iVar1) {
          _thread_resume(piVar6);
          iVar1 = *(int *)((int)piVar6 + 0x88);
        }
        _clear_wait(piVar6,3,0);
        if ((int *)iVar4 == piVar6) {
          return;
        }
        _mach_msg_abort_rpc(piVar6);
        _thread_deallocate(piVar6);
        return;
      :
        goto loc_400931E;
      case :
      case :
      case :
      case :
        *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
        break;
      case :
      case :
      case :
      case :
        if ((param_2 == 0x11) || (*(int *)(param_1 + 0x42) != _init_proc)) {
          if ((*(byte *)((int)piVar6 + 0x4b) & 4) == 0) {
            *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
            if (*(int *)(iVar1 + 0x3c) == 0) {
              *(uint *)(param_1 + 0x3a) = param_2;
              _psignal(*(undefined4 *)(param_1 + 0x42),0x14);
              _stop(param_1);
            }
          }
          else if (((param_1 == *_active_u) && (*(char *)(param_1 + 0x13) != '\x05')) &&
                  (_need_ast = _need_ast | 0x20, _need_ast != 0)) {
            pbVar2 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
            *pbVar2 = *pbVar2 | 0x10;
          }
        }
        else {
          _psignal(param_1,9);
          *(uint *)(param_1 + 0x18) = ~uVar3 & *(uint *)(param_1 + 0x18);
        }
        break;
      case :
        _task_resume(iVar1);
        *(undefined *)(param_1 + 0x13) = 3;
      }
      goto loc_4009332;
    }
    if (param_2 == 0x13) {
      _task_resume(iVar1);
      *(undefined *)(param_1 + 0x13) = 3;
    }
  }
  else if (*(char *)(param_1 + 0x13) == '\x06') goto loc_4009332;
loc_400931E:
  _clear_wait(piVar6,2,1);
loc_4009332:
  if ((int *)iVar4 != piVar6) {
    _thread_deallocate_interrupt(piVar6);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=211 start=0x400934c */

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
/* GHIDRADEC_FUNCTION index=212 start=0x4009746 */

void _stop(int param_1)

{
  _task_suspend_nowait(*(undefined4 *)(param_1 + 0x66));
  *(undefined *)(param_1 + 0x13) = 6;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;
  _wakeup(*(undefined4 *)(param_1 + 0x42));
  return;
}
/* GHIDRADEC_FUNCTION index=213 start=0x4009778 */

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
/* GHIDRADEC_FUNCTION index=214 start=0x4009a00 */

void _sigpending(void)

{
  undefined uVar1;
  
  uVar1 = _copyoutmsg(*_active_u + 0x18,**(undefined4 **)(dword_40B57D4 + 0x24),4);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=215 start=0x4009a34 */

int _uiomove(int param_1,uint param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  do {
    while( true ) {
      if (((int)param_2 < 1) || (*(int *)((int)param_4 + 0x12) == 0)) {
        return iVar2;
      }
      piVar1 = (int *)*param_4;
      uVar3 = piVar1[1];
      if (uVar3 != 0) break;
      *param_4 = (int)(piVar1 + 2);
      param_4[1] = param_4[1] + -1;
    }
    if (param_2 < uVar3) {
      uVar3 = param_2;
    }
    iVar4 = param_4[3];
    if (iVar4 == 1) {
      if (param_3 == 0) {
        iVar2 = param_1;
        iVar4 = *piVar1;
      }
      else {
        iVar2 = *piVar1;
        iVar4 = param_1;
      }
      iVar2 = _copywithin(iVar2,iVar4,uVar3);
    }
    else if (iVar4 < 2) {
      if (iVar4 == 0) {
loc_4009A8C:
        if (param_3 == 0) {
          iVar2 = _copyoutmsg(param_1,*piVar1,uVar3);
        }
        else {
          iVar2 = _copyinmsg(*piVar1,param_1,uVar3);
        }
        if (iVar2 != 0) {
          return iVar2;
        }
      }
    }
    else if (iVar4 == 2) goto loc_4009A8C;
    *piVar1 = uVar3 + *piVar1;
    piVar1[1] = piVar1[1] - uVar3;
    *(int *)((int)param_4 + 0x12) = *(int *)((int)param_4 + 0x12) - uVar3;
    param_4[2] = uVar3 + param_4[2];
    param_1 = uVar3 + param_1;
    param_2 = param_2 - uVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=216 start=0x4009af0 */

undefined4 _ureadc(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    if (param_2[1] == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aUreadc);
    }
    piVar1 = (int *)*param_2;
    if ((0 < piVar1[1]) && (0 < *(int *)((int)param_2 + 0x12))) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  iVar2 = param_2[3];
  if (iVar2 == 1) {
    *(char *)*piVar1 = (char)param_1;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto loc_4009B68;
      iVar2 = _subyte(*piVar1,param_1);
    }
    else {
      if (iVar2 != 2) goto loc_4009B68;
      iVar2 = _suibyte(*piVar1,param_1);
    }
    if (iVar2 < 0) {
      return 0xe;
    }
  }
loc_4009B68:
  *piVar1 = *piVar1 + 1;
  piVar1[1] = piVar1[1] + -1;
  *(int *)((int)param_2 + 0x12) = *(int *)((int)param_2 + 0x12) + -1;
  param_2[2] = param_2[2] + 1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=217 start=0x4009b82 */

uint _uwritec(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (0 < *(int *)((int)param_1 + 0x12)) {
    do {
      if (param_1[1] < 1) {
                    /* WARNING: Subroutine does not return */
        _panic(&aUwritec);
      }
      piVar1 = (int *)*param_1;
      if (piVar1[1] != 0) {
        iVar2 = param_1[3];
        if (iVar2 == 1) {
          uVar3 = (uint)*(byte *)*piVar1;
        }
        else if (iVar2 < 2) {
          if (iVar2 != 0) {
loc_4009C04:
                    /* WARNING: Subroutine does not return */
            _panic(aUwritecBogusUi);
          }
          uVar3 = _fubyte(*piVar1);
        }
        else {
          if (iVar2 != 2) goto loc_4009C04;
          uVar3 = _fuibyte(*piVar1);
        }
        if ((int)uVar3 < 0) {
          return 0xffffffff;
        }
        *piVar1 = *piVar1 + 1;
        piVar1[1] = piVar1[1] + -1;
        *(int *)((int)param_1 + 0x12) = *(int *)((int)param_1 + 0x12) + -1;
        param_1[2] = param_1[2] + 1;
        return uVar3 & 0xff;
      }
      *param_1 = (int)(piVar1 + 2);
      iVar2 = param_1[1];
      param_1[1] = iVar2 + -1;
    } while (iVar2 != 1);
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=218 start=0x4009c36 */

undefined4 _sleep(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *_active_u;
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,-(int)-(0x19 < (int)param_2));
  if ((int)param_2 < 0x1a) {
    *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
    if (_master_cpu != 0) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(0);
loc_4009D8E:
    uVar4 = 0;
  }
  else {
    if ((iVar3 == 0) ||
       (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
        ((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
         uVar1 == 0 ||
         ((((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
           ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
      if (_master_cpu != 0) {
        _printf(aUnixSleepOnSla);
      }
      _thread_block_with_continuation(0);
      if ((iVar3 == 0) ||
         (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
          (((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
            uVar1 == 0 ||
            (((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
             ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)))) ||
           (iVar3 = _issig(1), iVar3 == 0)))))) goto loc_4009D8E;
    }
    else {
      _clear_wait(_active_threads,2,1);
    }
    if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
      _longjmp(dword_40B57D4 + 0x28);
    }
    uVar4 = 1;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=219 start=0x4009dba */

undefined4 _sleep_with_continuation(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *_active_u;
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,-(int)-(0x19 < (int)param_2));
  if ((int)param_2 < 0x1a) {
    *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
    if (_master_cpu != 0) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(param_3);
loc_4009F16:
    uVar4 = 0;
  }
  else {
    if ((iVar3 == 0) ||
       (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
        ((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
         uVar1 == 0 ||
         ((((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
           ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
      if (_master_cpu != 0) {
        _printf(aUnixSleepOnSla);
      }
      _thread_block_with_continuation(param_3);
      if ((iVar3 == 0) ||
         (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
          (((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
            uVar1 == 0 ||
            (((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
             ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)))) ||
           (iVar3 = _issig(1), iVar3 == 0)))))) goto loc_4009F16;
    }
    else {
      _clear_wait(_active_threads,2,1);
    }
    if (param_3 != 0) {
      _call_continuation(param_3);
    }
    if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
      _longjmp(dword_40B57D4 + 0x28);
    }
    uVar4 = 1;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=220 start=0x4009f50 */

undefined4
_sleep_with_continuation_and_deadline(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *_active_u;
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,-(int)-(0x19 < (int)param_2));
  if ((int)param_2 < 0x1a) {
    if (param_4 != 0) {
      uVar4 = _hzto(param_4);
      _thread_set_timeout(uVar4);
    }
    *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
    if (_master_cpu != 0) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(param_3);
loc_400A0E0:
    uVar4 = 0;
  }
  else {
    if ((iVar3 == 0) ||
       (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
        ((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
         uVar1 == 0 ||
         ((((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
           ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      if (param_4 != 0) {
        uVar4 = _hzto(param_4);
        _thread_set_timeout(uVar4);
      }
      *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
      if (_master_cpu != 0) {
        _printf(aUnixSleepOnSla);
      }
      _thread_block_with_continuation(param_3);
      if ((iVar3 == 0) ||
         (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
          (((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
            uVar1 == 0 ||
            (((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
             ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)))) ||
           (iVar3 = _issig(1), iVar3 == 0)))))) goto loc_400A0E0;
    }
    else {
      _clear_wait(_active_threads,2,1);
    }
    if (param_3 != 0) {
      _call_continuation(param_3);
    }
    if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
      _longjmp(dword_40B57D4 + 0x28);
    }
    uVar4 = 1;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=221 start=0x400a11a */

bool _rpsleep(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  undefined auStack_38 [52];
  
  if (-1 < (char)*(byte *)(dword_40B57D4 + 0x6a)) {
    *(byte *)(dword_40B57D4 + 0x6a) = *(byte *)(dword_40B57D4 + 0x6a) | 0x80;
    _uprintf(aSSSPausing,_active_u + 8,param_4,param_5);
  }
  _bcopy(dword_40B57D4 + 0x28,auStack_38,0x34);
  iVar1 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar1 == 0) {
    (*param_1)(param_2,param_3);
  }
  _bcopy(auStack_38,dword_40B57D4 + 0x28,0x34);
  if (-1 < *(char *)(dword_40B57D4 + 0x6a)) {
    _rpcont();
  }
  return iVar1 == 0;
}
/* GHIDRADEC_FUNCTION index=222 start=0x400a1da */

void _rpcont(void)

{
  *(undefined *)(dword_40B57D4 + 0x6a) = 0;
  _uprintf(aSContinuing,_active_u + 8);
  return;
}
/* GHIDRADEC_FUNCTION index=223 start=0x400a202 */

byte _wakeup(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _thread_wakeup_prim(param_1,0,0);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=224 start=0x400a22c */

byte _wakeup_one(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _thread_wakeup_prim(param_1,1,0);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=225 start=0x400a258 */

void _rqinit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &_qs;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return;
}
/* GHIDRADEC_FUNCTION index=226 start=0x400a278 */

void _gettimeofday(void)

{
  int *piVar1;
  undefined uVar2;
  undefined auStack_c [8];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 != 0) {
    _microtime(auStack_c);
    uVar2 = _copyoutmsg(auStack_c,*piVar1,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=227 start=0x400a2be */

void _settimeofday(void)

{
  undefined uVar1;
  undefined auStack_c [8];
  
  if (**(int **)(dword_40B57D4 + 0x24) != 0) {
    uVar1 = _copyinmsg(**(int **)(dword_40B57D4 + 0x24),auStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar1;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _setthetime(auStack_c);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=228 start=0x400a30e */

void _setthetime(int *param_1)

{
  int iVar1;
  int aiStack_c [2];
  
  iVar1 = _suser();
  if (iVar1 != 0) {
    _getthetime(aiStack_c);
    _boottime = (*param_1 - aiStack_c[0]) + _boottime;
    dword_40B67D4 = 0;
    _host_set_time(dword_40B67DC,*param_1,param_1[1]);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=229 start=0x400a360 */

void _getthetime(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = _mtime[1];
  } while (_mtime[2] != *_mtime);
  *param_1 = _mtime[2];
  param_1[1] = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=230 start=0x400a396 */

void _adjtime(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    uVar3 = _copyinmsg(*puVar1,&uStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _host_adjust_time(dword_40B67DC,uStack_c,uStack_8,&uStack_14);
      if (puVar1[1] != 0) {
        uStack_1c = uStack_14;
        uStack_18 = uStack_10;
        _copyoutmsg(&uStack_1c,puVar1[1],8);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=231 start=0x400a42a */

void _inittodr(uint param_1)

{
  uint uVar1;
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((param_1 < 0x1ff46b80) || ((int)param_1 < 0)) {
    _printf(aWarningPrepost);
  }
  else {
    _microtime(&uStack_c);
    _boottime = uStack_c;
    dword_40B67D4 = 0;
    uVar1 = uStack_c - param_1;
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
    }
    if ((uVar1 < 0x2a300) && ((int)param_1 < (int)uStack_c)) {
      dword_40B67D4 = 0;
      return;
    }
    if (uStack_c < 0x1e13380) {
      _printf(aWarningClockNo);
      uStack_c = param_1;
      uStack_8 = 0;
      _setthetime(&uStack_c);
      _boottime = uStack_c;
      dword_40B67D4 = uStack_8;
    }
    else if (uVar1 < 0x76a701) {
      _printf(aWarningClockLo,uVar1 / 0x15180);
    }
    else {
      _printf(aWarningPrepost_0);
      uStack_c = param_1;
      uStack_8 = 0;
      _setthetime(&uStack_c);
      _boottime = uStack_c;
      dword_40B67D4 = uStack_8;
    }
  }
  _printf(aCheckAndResetT);
  return;
}
/* GHIDRADEC_FUNCTION index=232 start=0x400a52c */

void _getitimer(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined uVar4;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar3 = *(uint **)(dword_40B57D4 + 0x24);
  if (*puVar3 < 3) {
    uVar1 = *puVar3;
    if (uVar1 == 0) {
      _getthetime(&iStack_1c);
      iVar2 = *_active_u;
      uStack_14 = *(undefined4 *)(iVar2 + 0x52);
      uStack_10 = *(undefined4 *)(iVar2 + 0x56);
      iStack_c = *(int *)(iVar2 + 0x5a);
      iStack_8 = *(int *)(iVar2 + 0x5e);
      if ((iStack_c != 0) || (iStack_8 != 0)) {
        if ((iStack_c < iStack_1c) || ((iStack_1c == iStack_c && (iStack_8 < iStack_18)))) {
          iStack_8 = 0;
          iStack_c = 0;
        }
        else {
          _timevalsub(&iStack_c,&iStack_1c);
        }
      }
    }
    else {
      uStack_14 = *(undefined4 *)((int)_active_u + uVar1 * 0x10 + 0x1f6);
      uStack_10 = *(undefined4 *)((int)_active_u + uVar1 * 0x10 + 0x1fa);
      iStack_c = *(int *)((int)_active_u + uVar1 * 0x10 + 0x1fe);
      iStack_8 = *(int *)((int)_active_u + uVar1 * 0x10 + 0x202);
    }
    uVar4 = _copyoutmsg(&uStack_14,puVar3[1],0x10);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=233 start=0x400a60c */

void _setitimer(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  undefined uVar7;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar8;
  undefined auStack_1c [8];
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  if (*puVar2 < 3) {
    uVar3 = puVar2[1];
    if (puVar2[2] != 0) {
      puVar2[1] = puVar2[2];
      _getitimer();
    }
    if (uVar3 != 0) {
      uVar7 = _copyinmsg(uVar3,&uStack_14,0x10);
      *(undefined *)(dword_40B57D4 + 100) = uVar7;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        iVar5 = _itimerfix(&iStack_c);
        if ((iVar5 == 0) && (iVar5 = _itimerfix(&uStack_14), piVar4 = _active_u, iVar5 == 0)) {
          uVar3 = *puVar2;
          if (uVar3 == 0) {
            _getthetime(auStack_1c);
            _untimeout(_realitexpire,iVar1);
            if ((iStack_c != 0) || (iStack_8 != 0)) {
              _timevaladd(&iStack_c,auStack_1c);
              uVar6 = _hzto(&iStack_c);
              _timeout(_realitexpire,iVar1,uVar6);
            }
            *(undefined4 *)(iVar1 + 0x52) = uStack_14;
            *(undefined4 *)(iVar1 + 0x56) = uStack_10;
            *(int *)(iVar1 + 0x5a) = iStack_c;
            *(int *)(iVar1 + 0x5e) = iStack_8;
          }
          else {
            puVar8 = (undefined4 *)((int)_active_u + uVar3 * 0x10 + 0x1fa);
            *(undefined4 *)((int)_active_u + uVar3 * 0x10 + 0x1f6) = uStack_14;
            *puVar8 = uStack_10;
            *(int *)((int)piVar4 + uVar3 * 0x10 + 0x1fe) = iStack_c;
            *(int *)((int)piVar4 + uVar3 * 0x10 + 0x202) = iStack_8;
          }
        }
        else {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
        }
      }
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=234 start=0x400a74a */

uint _realitexpire(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  uint uStack_c;
  uint uStack_8;
  
  uVar2 = _psignal(param_1,0xe);
  if ((*(int *)(param_1 + 0x52) == 0) && (*(int *)(param_1 + 0x56) == 0)) {
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(undefined4 *)(param_1 + 0x5a) = 0;
  }
  else {
    _getthetime(&uStack_c);
    cVar7 = uStack_c - 10 < *(uint *)(param_1 + 0x5a);
    if ((int)*(uint *)(param_1 + 0x5a) < (int)(uStack_c - 10)) {
      *(uint *)(param_1 + 0x5a) = uStack_c;
      *(uint *)(param_1 + 0x5e) = uStack_8;
      uVar3 = _hzto(param_1 + 0x5a);
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _timeout(_realitexpire,param_1,uVar3);
      uVar2 = (uint)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8);
    }
    else {
      puVar1 = (uint *)(param_1 + 0x5a);
      do {
        _timevaladd(puVar1,param_1 + 0x52);
        uVar2 = *puVar1;
        cVar7 = uStack_c < uVar2;
        if ((int)uStack_c < (int)uVar2) break;
      } while ((uStack_c != uVar2) ||
              (cVar7 = *(uint *)(param_1 + 0x5e) < uStack_8,
              (int)*(uint *)(param_1 + 0x5e) <= (int)uStack_8));
      uVar3 = _hzto(puVar1);
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _timeout(_realitexpire,param_1,uVar3);
      uVar2 = (uint)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8);
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=235 start=0x400a832 */

undefined4 _itimerfix(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*param_1 < 0x5f5e101) && (uVar1 = param_1[1], uVar1 < 1000000)) {
    if ((*param_1 == 0) && ((uVar1 != 0 && ((int)uVar1 < (int)_tick)))) {
      param_1[1] = _tick;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=236 start=0x400a870 */

undefined4 _itimerdecr(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  if (iVar2 < param_2) {
    if (param_1[2] == 0) {
      iVar2 = param_2 - iVar2;
      goto loc_400A8B6;
    }
    param_1[3] = iVar2 + 1000000;
    param_1[2] = param_1[2] + -1;
  }
  iVar1 = param_1[3];
  param_1[3] = iVar1 - param_2;
  iVar2 = 0;
  if ((param_1[2] != 0) || (iVar1 - param_2 != 0)) {
    return 1;
  }
loc_400A8B6:
  if ((*param_1 == 0) && (param_1[1] == 0)) {
    param_1[3] = 0;
  }
  else {
    param_1[2] = *param_1;
    param_1[3] = param_1[1];
    iVar2 = param_1[3] - iVar2;
    param_1[3] = iVar2;
    if (iVar2 < 0) {
      param_1[3] = iVar2 + 1000000;
      param_1[2] = param_1[2] + -1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=237 start=0x400a8f0 */

void _timevaladd(int *param_1,int *param_2)

{
  *param_1 = *param_2 + *param_1;
  param_1[1] = param_2[1] + param_1[1];
  _timevalfix(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=238 start=0x400a914 */

void _timevalsub(int *param_1,int *param_2)

{
  *param_1 = *param_1 - *param_2;
  param_1[1] = param_1[1] - param_2[1];
  _timevalfix(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=239 start=0x400a938 */

void _timevalfix(int *param_1)

{
  if (param_1[1] < 0) {
    *param_1 = *param_1 + -1;
    param_1[1] = param_1[1] + 1000000;
  }
  if (999999 < param_1[1]) {
    *param_1 = *param_1 + 1;
    param_1[1] = param_1[1] + -1000000;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=240 start=0x400a968 */

void _uname(void)

{
  int *piVar1;
  undefined uVar2;
  int iVar3;
  undefined *puVar4;
  undefined auStack_28 [4];
  undefined auStack_24 [32];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  uVar2 = _copyoutstr(aNextstep,*piVar1,0x20,auStack_28);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = _copyoutstr(_hostname,*piVar1 + 0x20,0x20,auStack_28);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _sprintf(auStack_24,&aD_0,0);
      uVar2 = _copyoutstr(auStack_24,*piVar1 + 0x40,0x20,auStack_28);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _sprintf(auStack_24,&aD_0,4);
        uVar2 = _copyoutstr(auStack_24,*piVar1 + 0x60,0x20,auStack_28);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          switch(_machine_type) {
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextCube;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextWarp9;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextX15;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextWarp9c;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbo;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurboc;
            break;
          :
            iVar3 = *piVar1 + 0x80;
            puVar4 = (undefined *)&aUnknown;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbocube;
            break;
          case :
            iVar3 = *piVar1 + 0x80;
            puVar4 = aNextTurbocubec;
          }
          uVar2 = _copyoutstr(puVar4,iVar3,0x20,auStack_28);
          *(undefined *)(dword_40B57D4 + 100) = uVar2;
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=241 start=0x400ab9a */

void _gethostid(void)

{
  *(undefined4 *)(dword_40B57D4 + 0x5c) = _hostid;
  return;
}
/* GHIDRADEC_FUNCTION index=242 start=0x400abb0 */

void _sethostid(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    _hostid = *puVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=243 start=0x400abd8 */

void _gethostname(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = (*(undefined4 **)(dword_40B57D4 + 0x24))[1];
  if (_hostnamelen + 1U < uVar1) {
    uVar1 = _hostnamelen + 1U;
  }
  uVar2 = _copyoutmsg(_hostname,**(undefined4 **)(dword_40B57D4 + 0x24),uVar1);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=244 start=0x400ac16 */

void _sethostname(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    if ((uint)puVar1[1] < 0x100) {
      _hostnamelen = puVar1[1];
      uVar3 = _copyinmsg(*puVar1,_hostname,puVar1[1]);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      _hostname[_hostnamelen] = 0;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=245 start=0x400ac84 */

void _getdomainname(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = (*(undefined4 **)(dword_40B57D4 + 0x24))[1];
  if (_domainnamelen + 1U < uVar1) {
    uVar1 = _domainnamelen + 1U;
  }
  uVar2 = _copyoutmsg(_domainname,**(undefined4 **)(dword_40B57D4 + 0x24),uVar1);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=246 start=0x400acc2 */

void _setdomainname(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    if ((uint)puVar1[1] < 0x100) {
      _domainnamelen = puVar1[1];
      uVar3 = _copyinmsg(*puVar1,_domainname,puVar1[1]);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      _domainname[_domainnamelen] = 0;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=247 start=0x400ad30 */

void _reboot(void)

{
  int iVar1;
  undefined uVar2;
  undefined auStack_44 [64];
  
  auStack_44[0] = 0;
  iVar1 = _suser();
  if (iVar1 != 0) {
    if ((*(byte *)(*(int *)(dword_40B57D4 + 0x24) + 1) & 0x10) != 0) {
      uVar2 = _copyinstr(*(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4),auStack_44,0x40,0);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _boot(1,**(undefined4 **)(dword_40B57D4 + 0x24),auStack_44);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=248 start=0x400ad9a */

void _ptrace(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar2 < 1) {
    *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x10;
    *(undefined4 *)(*_active_u + 0x7a) = *(undefined4 *)(*_active_u + 0x42);
    *(int *)(*(int *)(*_active_u + 0x42) + 0x7e) = *_active_u;
    return;
  }
  iVar5 = _pfind(piVar2[1]);
  if (iVar5 == 0) {
loc_400ADF2:
    *(undefined *)(dword_40B57D4 + 100) = 3;
    return;
  }
  iVar3 = *(int *)(iVar5 + 0x66);
  iVar1 = *piVar2;
  if (iVar1 == 10) {
    iVar1 = *_active_u;
    if (((*(sword *)(iVar1 + 0x2c) == 0) || (*(sword *)(iVar1 + 0x2c) == *(sword *)(iVar5 + 0x2c)))
       && (((*(uint *)(iVar5 + 0x28) & 0x10) == 0 && (*(int *)(iVar1 + 0x7e) == 0)))) {
      *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 0x10;
      *(int *)(iVar5 + 0x7a) = *_active_u;
      *(int *)(iVar1 + 0x7e) = iVar5;
      _psignal(iVar5,0x11);
      return;
    }
    goto loc_400ADF2;
  }
  if ((((*(int *)(iVar3 + 0x3c) == 0) || (*(char *)(iVar5 + 0x13) != '\x06')) ||
      (iVar4 = *(int *)(iVar5 + 0x7a), iVar4 != *_active_u)) ||
     ((*(byte *)(iVar5 + 0x2b) & 0x10) == 0)) goto loc_400ADF2;
  if (iVar1 == 8) {
    *(char *)(iVar5 + 0x17) = *(char *)(iVar5 + 0x17) + ' ';
  }
  else {
    if (iVar1 < 9) {
      if (iVar1 != 7) goto loc_400AF76;
    }
    else if (iVar1 != 9) {
      if (iVar1 == 0xb) {
        iVar1 = *(int *)(iVar4 + 0x7e);
        if (iVar1 == 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
        *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xffffffef;
        *(undefined4 *)(iVar1 + 0x7a) = 0;
        *(undefined4 *)(iVar4 + 0x7e) = 0;
        goto loc_400AF46;
      }
      goto loc_400AF76;
    }
    iVar4 = *(int *)(iVar3 + 0x18);
    iVar1 = **(int **)(iVar4 + 0x80);
    if (piVar2[2] != 1) {
      *(uint *)(iVar1 + 0x40) = (int)(sword)((uint)piVar2[2] >> 0x10) | *(uint *)(iVar1 + 0x40);
      *(uint *)(iVar1 + 0x44) = (uint)*(word *)((int)piVar2 + 10) << 0x10 | *(uint *)(iVar1 + 0x44);
    }
    if (0x20 < (uint)piVar2[3]) {
loc_400AF76:
      *(undefined *)(dword_40B57D4 + 100) = 5;
      return;
    }
    if (0x1ef8 << 0x20 - *(char *)(iVar5 + 0x17) < 0) {
      *(undefined *)(*(int *)(iVar4 + 0x80) + 0x70) = 0;
    }
    *(undefined *)(iVar5 + 0x17) = *(undefined *)((int)piVar2 + 0xf);
    if (0x1ef8 << 0x20 - piVar2[3] < 0) {
      *(char *)(*(int *)(iVar4 + 0x80) + 0x70) = (char)piVar2[3];
    }
    if (*piVar2 == 9) {
      *(byte *)(iVar1 + 0x40) = *(byte *)(iVar1 + 0x40) | 0x80;
    }
  }
loc_400AF46:
  *(undefined *)(iVar5 + 0x13) = 3;
  if ((*(int *)(iVar5 + 0x6a) != 0) && (*(char *)(iVar5 + 0x17) != '\0')) {
    _clear_wait(*(int *)(iVar5 + 0x6a),2,1);
  }
  _task_resume(iVar3);
  return;
}
/* GHIDRADEC_FUNCTION index=249 start=0x400af8c */

uint _thread_psignal(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 < 0x21) {
    uVar3 = 1 << (param_2 - 1 & 0x3f);
    if ((uVar3 & 0x1ef8) == 0) {
      _printf(aSignalD);
                    /* WARNING: Subroutine does not return */
      _panic(aThreadPsignalS);
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x34);
    param_2 = uVar3 & *(uint *)(iVar2 + 0x20);
    if ((param_2 == 0) || ((*(byte *)(iVar2 + 0x2b) & 0x10) != 0)) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x80) + 0x72);
      *puVar1 = uVar3 | *puVar1;
    }
  }
  return param_2;
}

