
undefined4 _wait1(uint param_1,int param_2,uint *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char cVar5;
  undefined4 uVar4;
  
  if (*(char *)(dword_40B57D4 + 100) < '\0') {
    iVar3 = _thread_wait_result();
    if (iVar3 - 2U < 2) {
      if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
        _unix_syscall_return(4);
      }
      *(undefined *)(dword_40B57D4 + 0x65) = 2;
      _unix_syscall_return(0);
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0;
    }
  }
  else {
    *(undefined4 *)(dword_40B57D4 + 0x7e) = 0;
  }
  iVar3 = *_active_u;
  for (iVar1 = *(int *)(iVar3 + 0x46); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4a)) {
    if ((param_4 == 0) || (*(sword *)(iVar1 + 0x30) == param_4)) {
      *(int *)(dword_40B57D4 + 0x7e) = *(int *)(dword_40B57D4 + 0x7e) + 1;
      if (*(int *)(iVar1 + 0x66) == 0) {
        if ((*(int *)(iVar1 + 0x7a) == 0) || (iVar3 == *(int *)(iVar1 + 0x7a))) {
          *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
          *param_3 = (uint)*(word *)(iVar1 + 0x34);
          *(undefined2 *)(iVar1 + 0x34) = 0;
          if (param_2 != 0) {
            if (*(int *)(iVar1 + 0x36) == 0) goto loc_4005C98;
            _bcopy(*(int *)(iVar1 + 0x36),param_2,0x48);
          }
          if (*(int *)(iVar1 + 0x36) != 0) {
            _ruadd((int)_active_u + 0x1ae,*(int *)(iVar1 + 0x36));
            _kfree(*(undefined4 *)(iVar1 + 0x36),0x48);
            *(undefined4 *)(iVar1 + 0x36) = 0;
          }
loc_4005C98:
          _leavepgrp(iVar1);
          _delete_posix_proc(iVar1);
          *(undefined *)(iVar1 + 0x13) = 0;
          *(undefined2 *)(iVar1 + 0x30) = 0;
          *(undefined2 *)(iVar1 + 0x32) = 0;
          iVar3 = *(int *)(iVar1 + 8);
          **(int **)(iVar1 + 0xc) = iVar3;
          if (iVar3 != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
          }
          *(int *)(iVar1 + 8) = _freeproc;
          _freeproc = iVar1;
          if (*(int *)(iVar1 + 0x4e) != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 0x4e) + 0x4a) = *(undefined4 *)(iVar1 + 0x4a);
          }
          if (*(int *)(iVar1 + 0x4a) != 0) {
            *(undefined4 *)(*(int *)(iVar1 + 0x4a) + 0x4e) = *(undefined4 *)(iVar1 + 0x4e);
          }
          if (iVar1 == *(int *)(*(int *)(iVar1 + 0x42) + 0x46)) {
            *(undefined4 *)(*(int *)(iVar1 + 0x42) + 0x46) = *(undefined4 *)(iVar1 + 0x4a);
          }
          *(undefined4 *)(iVar1 + 0x42) = 0;
          *(undefined4 *)(iVar1 + 0x4e) = 0;
          *(undefined4 *)(iVar1 + 0x4a) = 0;
          *(undefined4 *)(iVar1 + 0x46) = 0;
          *(undefined4 *)(iVar1 + 0x18) = 0;
          *(undefined4 *)(iVar1 + 0x24) = 0;
          *(undefined4 *)(iVar1 + 0x20) = 0;
          *(undefined4 *)(iVar1 + 0x1c) = 0;
          *(undefined2 *)(iVar1 + 0x2e) = 0;
          *(undefined4 *)(iVar1 + 0x28) = 0;
          *(undefined *)(iVar1 + 0x17) = 0;
          return 0;
        }
      }
      else if ((((0 < *(int *)(*(int *)(iVar1 + 0x66) + 0x3c)) &&
                (*(char *)(iVar1 + 0x13) == '\x06')) &&
               (uVar2 = *(uint *)(iVar1 + 0x28), (uVar2 & 0x20) == 0)) &&
              ((((uVar2 & 0x10) != 0 || ((param_1 & 2) != 0)) &&
               ((*(int *)(iVar1 + 0x7a) == 0 || (iVar3 == *(int *)(iVar1 + 0x7a))))))) {
        *(uint *)(iVar1 + 0x28) = uVar2 | 0x20;
        *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
        cVar5 = *(char *)(iVar1 + 0x17);
        if (cVar5 != '\0') goto loc_4005E10;
        iVar3 = *(int *)(iVar1 + 0x3a);
        goto loc_4005E12;
      }
    }
  }
  iVar3 = *(int *)(iVar3 + 0x7e);
  if (iVar3 != 0) {
    *(int *)(dword_40B57D4 + 0x7e) = *(int *)(dword_40B57D4 + 0x7e) + 1;
    if (*(int *)(iVar3 + 0x66) == 0) {
      *(undefined4 *)(iVar3 + 0x7a) = 0;
      *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & 0xffffffef;
      _wakeup(*(undefined4 *)(iVar3 + 0x42));
      return 0;
    }
    if ((((0 < *(int *)(*(int *)(iVar3 + 0x66) + 0x3c)) && (*(char *)(iVar3 + 0x13) == '\x06')) &&
        (uVar2 = *(uint *)(iVar3 + 0x28), (uVar2 & 0x20) == 0)) &&
       (((uVar2 & 0x10) != 0 || ((param_1 & 2) != 0)))) {
      *(uint *)(iVar3 + 0x28) = uVar2 | 0x20;
      *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar3 + 0x30);
      cVar5 = *(char *)(iVar3 + 0x17);
      if (cVar5 == '\0') {
        iVar3 = *(int *)(iVar3 + 0x3a);
      }
      else {
loc_4005E10:
        iVar3 = (int)cVar5;
      }
loc_4005E12:
      *param_3 = iVar3 << 8 | 0x7f;
      return 0;
    }
  }
  if (*(int *)(dword_40B57D4 + 0x7e) == 0) {
    uVar4 = 10;
  }
  else if ((param_1 & 1) == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0xff;
    uVar4 = _sleep_with_continuation(*_active_u,0x1e,param_5);
  }
  else {
    *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
    uVar4 = 0;
  }
  return uVar4;
}
