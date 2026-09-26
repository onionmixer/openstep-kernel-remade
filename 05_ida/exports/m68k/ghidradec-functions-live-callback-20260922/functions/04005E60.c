
undefined4 _waitpgrp(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined uVar5;
  int iVar4;
  int iStack_10;
  uint uStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iStack_10 = 0;
  while( true ) {
    for (iVar4 = *(int *)(*_active_u + 0x46); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4a)) {
      if ((int)*(sword *)(iVar4 + 0x2e) == *piVar1) {
        iStack_10 = iStack_10 + 1;
        if (*(int *)(iVar4 + 0x66) == 0) {
          *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar4 + 0x30);
          uVar5 = _copyoutmsg((undefined2 *)(iVar4 + 0x34),piVar1[1],4);
          *(undefined *)(dword_40B57D4 + 100) = uVar5;
          if (*(char *)(dword_40B57D4 + 100) != '\0') {
            return 0;
          }
          *(undefined2 *)(iVar4 + 0x34) = 0;
          if (*(int *)(iVar4 + 0x36) != 0) {
            _ruadd((int)_active_u + 0x1ae,*(int *)(iVar4 + 0x36));
            _kfree(*(undefined4 *)(iVar4 + 0x36),0x48);
            *(undefined4 *)(iVar4 + 0x36) = 0;
          }
          _leavepgrp(iVar4);
          _delete_posix_proc(iVar4);
          *(undefined *)(iVar4 + 0x13) = 0;
          *(undefined2 *)(iVar4 + 0x30) = 0;
          *(undefined2 *)(iVar4 + 0x32) = 0;
          iVar2 = *(int *)(iVar4 + 8);
          **(int **)(iVar4 + 0xc) = iVar2;
          if (iVar2 != 0) {
            *(undefined4 *)(*(int *)(iVar4 + 8) + 0xc) = *(undefined4 *)(iVar4 + 0xc);
          }
          *(int *)(iVar4 + 8) = _freeproc;
          _freeproc = iVar4;
          if (*(int *)(iVar4 + 0x4e) != 0) {
            *(undefined4 *)(*(int *)(iVar4 + 0x4e) + 0x4a) = *(undefined4 *)(iVar4 + 0x4a);
          }
          if (*(int *)(iVar4 + 0x4a) != 0) {
            *(undefined4 *)(*(int *)(iVar4 + 0x4a) + 0x4e) = *(undefined4 *)(iVar4 + 0x4e);
          }
          if (iVar4 == *(int *)(*(int *)(iVar4 + 0x42) + 0x46)) {
            *(undefined4 *)(*(int *)(iVar4 + 0x42) + 0x46) = *(undefined4 *)(iVar4 + 0x4a);
          }
          *(undefined4 *)(iVar4 + 0x42) = 0;
          *(undefined4 *)(iVar4 + 0x4e) = 0;
          *(undefined4 *)(iVar4 + 0x4a) = 0;
          *(undefined4 *)(iVar4 + 0x46) = 0;
          *(undefined4 *)(iVar4 + 0x18) = 0;
          *(undefined4 *)(iVar4 + 0x24) = 0;
          *(undefined4 *)(iVar4 + 0x20) = 0;
          *(undefined4 *)(iVar4 + 0x1c) = 0;
          *(undefined4 *)(iVar4 + 0x28) = 0;
          *(undefined *)(iVar4 + 0x17) = 0;
          return 0;
        }
        if ((((0 < *(int *)(*(int *)(iVar4 + 0x66) + 0x3c)) && (*(char *)(iVar4 + 0x13) == '\x06'))
            && (uVar3 = *(uint *)(iVar4 + 0x28), (uVar3 & 0x20) == 0)) &&
           ((((uVar3 & 0x10) != 0 || ((*(byte *)((int)piVar1 + 0xb) & 2) != 0)) &&
            ((*(int *)(iVar4 + 0x7a) == 0 || (*_active_u == *(int *)(iVar4 + 0x7a))))))) {
          *(uint *)(iVar4 + 0x28) = uVar3 | 0x20;
          *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar4 + 0x30);
          if (*(char *)(iVar4 + 0x17) == '\0') {
            iVar4 = *(int *)(iVar4 + 0x3a);
          }
          else {
            iVar4 = (int)*(char *)(iVar4 + 0x17);
          }
          uStack_8 = iVar4 << 8 | 0x7f;
          iVar4 = piVar1[1];
          goto loc_400601A;
        }
      }
    }
    if (iStack_10 == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 10;
      return 0;
    }
    if ((*(byte *)((int)piVar1 + 0xb) & 1) != 0) break;
    iVar4 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar4 != 0) {
      if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
        *(undefined *)(dword_40B57D4 + 100) = 4;
      }
      else {
        *(undefined *)(dword_40B57D4 + 0x65) = 2;
      }
      return 0;
    }
    _sleep(*_active_u,0x1e);
  }
  uStack_8 = 0;
  *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
  iVar4 = piVar1[1];
loc_400601A:
  uVar5 = _copyoutmsg(&uStack_8,iVar4,4);
  *(undefined *)(dword_40B57D4 + 100) = uVar5;
  return 0;
}

