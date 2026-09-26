/* GHIDRADEC_FUNCTION index=550 start=0x401a18c */

void _rename(void)

{
  undefined uVar1;
  
  uVar1 = _vn_rename(**(undefined4 **)(dword_40B57D4 + 0x24),
                     (*(undefined4 **)(dword_40B57D4 + 0x24))[1],0);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=551 start=0x401a1b6 */

void _symlink(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  int iStack_5a;
  undefined auStack_56 [4];
  undefined4 uStack_52;
  undefined auStack_4a [4];
  undefined4 uStack_46;
  undefined auStack_3e [4];
  undefined2 uStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _pn_get(puVar1[1],0,auStack_56);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = _lookuppn(auStack_56,0,&iStack_5a,0);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if ((*(byte *)(*(int *)(iStack_5a + 0x24) + 0xf) & 1) == 0) {
        uVar2 = _pn_get(*puVar1,0,auStack_4a);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        _vattr_null(auStack_3e);
        uStack_3a = 0x1ff;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          uVar2 = (**(code **)(*(int *)(iStack_5a + 0x1c) + 0x40))
                            (iStack_5a,uStack_52,auStack_3e,uStack_46,
                             *(undefined4 *)(_active_u + 0x1a));
          *(undefined *)(dword_40B57D4 + 100) = uVar2;
          _pn_free(auStack_4a);
        }
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
      }
      _pn_free(auStack_56);
      _vn_rele(iStack_5a);
    }
    else {
      _pn_free(auStack_56);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=552 start=0x401a2d6 */

void _unlink(void)

{
  undefined uVar1;
  
  uVar1 = _vn_remove(**(undefined4 **)(dword_40B57D4 + 0x24),0,0);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=553 start=0x401a2fe */

void _rmdir(void)

{
  undefined uVar1;
  
  uVar1 = _vn_remove(**(undefined4 **)(dword_40B57D4 + 0x24),0,1);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=554 start=0x401a328 */

void _getdirentries(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  int iStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _getvnodefp(*puVar1,&iStack_1e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*(byte *)(iStack_1e + 0xb) & 1) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
    }
    else {
      while( true ) {
        uStack_26 = puVar1[1];
        uStack_22 = puVar1[2];
        puStack_1a = &uStack_26;
        uStack_16 = 1;
        iStack_12 = *(int *)(iStack_1e + 0x1a);
        uStack_e = 0;
        iStack_8 = puVar1[2];
        if (iStack_12 < 0) break;
        uVar2 = (**(code **)(*(int *)(*(int *)(iStack_1e + 0x16) + 0x1c) + 0x3c))
                          (*(int *)(iStack_1e + 0x16),&puStack_1a,*(undefined4 *)(iStack_1e + 0x1e))
        ;
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        if (puVar1[2] != iStack_8) goto loc_401A408;
        *(undefined4 *)(iStack_1e + 0x1a) = 0xfffffc00;
      }
      uVar2 = _getfakedirentries(*(undefined4 *)(iStack_1e + 0x16),&puStack_1a,
                                 *(undefined4 *)(iStack_1e + 0x1e));
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
loc_401A408:
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        uVar2 = _copyoutmsg(iStack_1e + 0x1a,puVar1[3],4);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        *(int *)(dword_40B57D4 + 0x5c) = puVar1[2] - iStack_8;
        *(int *)(iStack_1e + 0x1a) = iStack_12;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=555 start=0x401a45a */

int _getfakedirentries(int param_1,int param_2)

{
  int iVar1;
  word *pwVar2;
  int iVar3;
  word wVar6;
  undefined4 *puVar4;
  undefined2 uVar7;
  int iVar5;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 != 0) {
    iVar1 = *(int *)(param_2 + 0x12);
    uVar11 = -*(int *)(param_2 + 8) - 0x400;
    if (iVar1 != 0) {
      uVar8 = 0;
      if (uVar11 != 0) {
        do {
          if (iVar5 == 0) {
            return 0;
          }
          wVar6 = _strlen(iVar5 + 0x20);
          iVar9 = (wVar6 + 4 & 0xfffffffc) + 8;
          if (iVar9 + (uVar8 & 0xfffffc00) < 0x401) {
            uVar8 = iVar9 + uVar8;
          }
          else {
            uVar8 = (uVar8 & 0xfffffc00) + 0x400;
          }
          iVar5 = *(int *)(iVar5 + 0x120);
        } while (uVar8 < uVar11);
      }
      if (iVar5 != 0) {
        puVar4 = (undefined4 *)_kalloc(iVar1);
        iVar9 = 0;
        puVar12 = puVar4;
        for (iVar3 = iVar1; iVar10 = 0, iVar3 != 0; iVar3 = iVar3 - (uint)*pwVar2) {
          *puVar12 = 0xffffffff;
          uVar7 = _strlen(iVar5 + 0x20);
          *(undefined2 *)((int)puVar12 + 6) = uVar7;
          _strcpy(puVar12 + 2,iVar5 + 0x20);
          iVar5 = *(int *)(iVar5 + 0x120);
          if (iVar5 == 0) {
            wVar6 = 0x400 - (sword)iVar9;
            *(word *)(puVar12 + 1) = wVar6;
            iVar10 = iVar3 - (uint)wVar6;
            uVar11 = wVar6 + uVar11;
            break;
          }
          wVar6 = _strlen(iVar5 + 0x20);
          if ((*(word *)((int)puVar12 + 6) + 4 & 0xfffffffc) +
              (wVar6 + 4 & 0xfffffffc) + 0x10 + iVar9 < 0x401) {
            *(word *)(puVar12 + 1) = (*(word *)((int)puVar12 + 6) + 4 & 0xfffc) + 8;
            iVar9 = iVar9 + 8 + (*(word *)((int)puVar12 + 6) + 4 & 0xfffffffc);
          }
          else {
            *(sword *)(puVar12 + 1) = 0x400 - (sword)iVar9;
            iVar9 = 0;
          }
          pwVar2 = (word *)(puVar12 + 1);
          uVar11 = *pwVar2 + uVar11;
          puVar12 = (undefined4 *)((uint)*(word *)(puVar12 + 1) + (int)puVar12);
        }
        iVar5 = _uiomove(puVar4,*(int *)(param_2 + 0x12) - iVar10,0,param_2);
        _kfree(puVar4,iVar1);
        if (iVar5 != 0) {
          return iVar5;
        }
        *(uint *)(param_2 + 8) = -(uVar11 + 0x400);
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=556 start=0x401a610 */

uint _lseek(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  undefined uVar6;
  uint uVar5;
  undefined auStack_42 [20];
  int iStack_2e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar6 = _getvnodefp(*puVar1,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  bVar4 = *(byte *)(dword_40B57D4 + 100);
  if (bVar4 == 0) {
    iVar2 = *(int *)(iStack_8 + 0x16);
    if (*(int *)(iVar2 + 0x28) != 8) {
      uVar3 = puVar1[2];
      uVar5 = uVar3;
      if (uVar3 == 1) {
        if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) &&
           (uVar5 = puVar1[1] + *(int *)(iStack_8 + 0x1a), (int)uVar5 < 0)) {
loc_401A726:
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return uVar5;
        }
        *(int *)(iStack_8 + 0x1a) = puVar1[1] + *(int *)(iStack_8 + 0x1a);
      }
      else {
        if ((int)uVar3 < 2) {
          if (uVar3 == 0) {
            if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (uVar5 = 0, (int)puVar1[1] < 0))
            goto loc_401A726;
            *(undefined4 *)(iStack_8 + 0x1a) = puVar1[1];
            uVar5 = uVar3;
            goto loc_401A746;
          }
        }
        else if (uVar3 == 2) {
          uVar5 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                            (iVar2,auStack_42,*(undefined4 *)((int)_active_u + 0x1a));
          *(char *)(dword_40B57D4 + 100) = (char)uVar5;
          if (*(char *)(dword_40B57D4 + 100) != '\0') {
            return uVar5;
          }
          if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) &&
             (uVar5 = iStack_2e + puVar1[1], (int)uVar5 < 0)) goto loc_401A726;
          *(int *)(iStack_8 + 0x1a) = iStack_2e + puVar1[1];
          goto loc_401A746;
        }
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
loc_401A746:
      *(undefined4 *)(dword_40B57D4 + 0x5c) = *(undefined4 *)(iStack_8 + 0x1a);
      return uVar5;
    }
  }
  else if (bVar4 != 0x16) {
    return (uint)bVar4;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0x1d;
  return (uint)bVar4;
}
/* GHIDRADEC_FUNCTION index=557 start=0x401a760 */

void _access(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined uVar6;
  int iVar5;
  word wVar7;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar6 = _lookupname(*puVar1,0,1,0,&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  iVar5 = *(int *)(_active_u + 0x1a);
  uVar3 = *(undefined2 *)(iVar5 + 2);
  uVar4 = *(undefined2 *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 2) = *(undefined2 *)(iVar5 + 6);
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 4) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 8);
  wVar7 = 0;
  uVar2 = puVar1[1];
  if (uVar2 != 0) {
    if ((uVar2 & 4) != 0) {
      wVar7 = 0x100;
    }
    if ((uVar2 & 2) != 0) {
      iVar5 = _isrofile(iStack_8);
      if (iVar5 != 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
        goto loc_401A83C;
      }
      wVar7 = wVar7 | 0x80;
    }
    if ((*(byte *)((int)puVar1 + 7) & 1) != 0) {
      wVar7 = wVar7 | 0x40;
    }
    uVar6 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x1c))
                      (iStack_8,wVar7,*(undefined4 *)(_active_u + 0x1a));
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
  }
loc_401A83C:
  _vn_rele(iStack_8);
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2) = uVar3;
  *(undefined2 *)(*(int *)(_active_u + 0x1a) + 4) = uVar4;
  return;
}
/* GHIDRADEC_FUNCTION index=558 start=0x401a86c */

void _stat(void)

{
  undefined uVar1;
  
  uVar1 = _stat1(*(undefined4 *)(dword_40B57D4 + 0x24),1);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=559 start=0x401a892 */

void _lstat(void)

{
  undefined uVar1;
  
  uVar1 = _stat1(*(undefined4 *)(dword_40B57D4 + 0x24),0);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=560 start=0x401a8b6 */

int _stat1(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_44;
  undefined auStack_40 [60];
  
  iVar1 = _lookupname(*param_1,0,param_2,0,&uStack_44);
  if (iVar1 == 0) {
    iVar1 = _vno_stat(uStack_44,auStack_40);
    _vn_rele(uStack_44);
    if (iVar1 == 0) {
      iVar1 = _copyoutmsg(auStack_40,param_1[1],0x3c);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=561 start=0x401a920 */

void _readlink(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _lookupname(*puVar1,0,0,0,&iStack_1e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (*(int *)(iStack_1e + 0x28) == 5) {
      uStack_26 = puVar1[1];
      uStack_22 = puVar1[2];
      puStack_1a = &uStack_26;
      uStack_16 = 1;
      uStack_12 = 0;
      uStack_e = 0;
      iStack_8 = puVar1[2];
      uVar2 = (**(code **)(*(int *)(iStack_1e + 0x1c) + 0x44))
                        (iStack_1e,&puStack_1a,*(undefined4 *)(_active_u + 0x1a));
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
    _vn_rele(iStack_1e);
    *(int *)(dword_40B57D4 + 0x5c) = puVar1[2] - iStack_8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=562 start=0x401a9ea */

void _chmod(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [4];
  word wStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  wStack_3a = *(word *)((int)puVar1 + 6) & 0xfff;
  uVar2 = _namesetattr(*puVar1,1,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=563 start=0x401aa38 */

void _fchmod(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [4];
  word wStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  wStack_3a = *(word *)((int)puVar1 + 6) & 0xfff;
  uVar2 = _fdsetattr(*puVar1,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=564 start=0x401aa82 */

void _chown(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [6];
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  uStack_38 = *(undefined2 *)((int)puVar1 + 6);
  uStack_36 = *(undefined2 *)((int)puVar1 + 10);
  uVar2 = _namesetattr(*puVar1,0,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=565 start=0x401aace */

void _fchown(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [6];
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  uStack_38 = *(undefined2 *)((int)puVar1 + 6);
  uStack_36 = *(undefined2 *)((int)puVar1 + 10);
  uVar2 = _fdsetattr(*puVar1,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=566 start=0x401ab18 */

void _utimes(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_4e [28];
  undefined4 uStack_32;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _copyinmsg(puVar1[1],&uStack_14,0x10);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vattr_null(auStack_4e);
    uStack_32 = uStack_14;
    uStack_2e = uStack_10;
    uStack_2a = uStack_c;
    uStack_26 = uStack_8;
    uVar2 = _namesetattr(*puVar1,1,auStack_4e);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=567 start=0x401ab9e */

void __utime(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  undefined4 uStack_4e;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  _getthetime(&uStack_46);
  _vattr_null(auStack_3e);
  if (((*(byte *)(*_active_u + 0x16) & 0x40) == 0) || (puVar1[1] != 0)) {
    uVar4 = _copyinmsg(puVar1[1],&uStack_4e,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) != '\0') {
      return;
    }
    uStack_22 = uStack_4e;
    uStack_1a = uStack_4a;
    uStack_16 = 0;
  }
  else {
    uStack_1a = uStack_46;
    uStack_22 = uStack_46;
    uStack_16 = uStack_42;
    *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) | 0x80;
  }
  uStack_1e = uStack_16;
  iVar3 = _namesetattr(*puVar1,1,auStack_3e);
  *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0x7f;
  if ((((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (iVar3 == 1)) && (puVar1[1] == 0)) {
    iVar3 = 0xd;
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=568 start=0x401aca0 */

void _truncate(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [20];
  undefined4 uStack_2a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    _vattr_null(auStack_3e);
    uStack_2a = puVar1[1];
    uVar2 = _namesetattr(*puVar1,1,auStack_3e);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=569 start=0x401acf6 */

void _ftruncate(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined auStack_42 [20];
  undefined4 uStack_2e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    uVar3 = _getvnodefp(*puVar1,&iStack_8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = *(int *)(iStack_8 + 0x16);
      if ((*(byte *)(iStack_8 + 0xb) & 2) == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
      else if ((*(byte *)(*(int *)(iVar2 + 0x24) + 0xf) & 1) == 0) {
        _vattr_null(auStack_42);
        uStack_2e = puVar1[1];
        uVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))
                          (iVar2,auStack_42,*(undefined4 *)(iStack_8 + 0x1e));
        *(undefined *)(dword_40B57D4 + 100) = uVar3;
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=570 start=0x401ada4 */

int _namesetattr(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,param_2,0,&iStack_8);
  if (iVar1 == 0) {
    if ((*(byte *)(*(int *)(iStack_8 + 0x24) + 0xf) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x18))
                        (iStack_8,param_3,*(undefined4 *)(_active_u + 0x1a));
    }
    else {
      iVar1 = 0x1e;
    }
    _vn_rele(iStack_8);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=571 start=0x401ae16 */

int _fdsetattr(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _getvnodefp(param_1,&iStack_8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iStack_8 + 0x16);
    if ((*(byte *)(*(int *)(iVar1 + 0x24) + 0xf) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))
                        (iVar1,param_2,*(undefined4 *)(iStack_8 + 0x1e));
    }
    else {
      iVar1 = 0x1e;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=572 start=0x401ae64 */

void _fsync(void)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _getvnodefp(**(undefined4 **)(dword_40B57D4 + 0x24),&iStack_8);
  if (iVar1 == 0) {
    iVar1 = _mfs_fsync(*(undefined4 *)(iStack_8 + 0x16));
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(iStack_8 + 0x16) + 0x1c) + 0x48))
                        (*(int *)(iStack_8 + 0x16),*(undefined4 *)(iStack_8 + 0x1e));
    }
  }
  *(char *)(dword_40B57D4 + 100) = (char)iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=573 start=0x401aec4 */

void _umask(void)

{
  int *piVar1;
  
  piVar1 = (int *)(dword_40B57D4 + 0x24);
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(_active_u + 0x164);
  *(word *)(_active_u + 0x164) = *(word *)(*piVar1 + 2) & 0xfff;
  return;
}
/* GHIDRADEC_FUNCTION index=574 start=0x401aefc */

void _vhangup(void)

{
  int iVar1;
  undefined auStack_94 [136];
  undefined4 uStack_c;
  int iStack_8;
  
  iStack_8 = 0x401af06;
  iVar1 = _suser();
  if ((iVar1 != 0) && (*(int *)(_active_u + 0x15e) != 0)) {
    iStack_8 = (int)*(sword *)(_active_u + 0x162);
    uStack_c = 0x401af22;
    _forceclose();
    uStack_c = 1;
    _bcopy(*(undefined4 *)(_active_u + 0x15e),auStack_94,0x86);
    _gsignal();
  }
  return;
}

