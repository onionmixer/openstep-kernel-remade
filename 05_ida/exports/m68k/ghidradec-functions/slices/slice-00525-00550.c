/* GHIDRADEC_FUNCTION index=525 start=0x4018ee6 */

undefined4 _vno_select(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  uVar2 = *(uint *)(iVar1 + 0x28);
  if ((uVar2 == 4) || (((3 < uVar2 && (uVar2 < 10)) && (7 < uVar2)))) {
    uVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x10))
                      (iVar1,param_2,*(undefined4 *)(param_1 + 0x1e));
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=526 start=0x4018f2c */

int _vno_stat(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined auStack_3e [4];
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1a;
  int iStack_16;
  undefined4 uStack_12;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                    (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  if (iVar1 == 0) {
    param_2[3] = uStack_3a;
    param_2[5] = uStack_38;
    param_2[6] = uStack_36;
    *param_2 = uStack_32;
    *(undefined4 *)(param_2 + 1) = uStack_30;
    param_2[4] = uStack_2c;
    *(undefined4 *)(param_2 + 8) = uStack_2a;
    *(undefined4 *)(param_2 + 0x16) = uStack_26;
    *(undefined4 *)(param_2 + 10) = uStack_22;
    *(undefined4 *)(param_2 + 0xc) = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    if (((iVar1 == 0) && (*(int *)(param_1 + 0x18) == 0)) ||
       ((iVar1 <= iStack_1a && ((iStack_1a != iVar1 || (*(int *)(param_1 + 0x18) <= iStack_16))))))
    {
      *(int *)(param_2 + 0xe) = iStack_1a;
    }
    else {
      *(int *)(param_2 + 0xe) = iVar1;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x12) = uStack_12;
    *(undefined4 *)(param_2 + 0x14) = 0;
    param_2[7] = uStack_a;
    *(undefined4 *)(param_2 + 0x18) = uStack_8;
    *(undefined4 *)(param_2 + 0x1c) = 0;
    *(undefined4 *)(param_2 + 0x1a) = 0;
    if (*(undefined **)(param_1 + 0x1c) == _ufs_vnodeops) {
      *(undefined4 *)(param_2 + 0x1a) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0xce);
    }
    else if ((*(undefined **)(param_1 + 0x1c) == _nfs_vnodeops) &&
            (iVar1 = *(int *)(param_1 + 0x2e), *(int *)(iVar1 + 0x48) == *(int *)(param_2 + 1))) {
      *(undefined4 *)(param_2 + 0x1a) = 0xfeedface;
      *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x4c);
    }
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=527 start=0x4019032 */

int _vno_close(int param_1)

{
  undefined4 uVar1;
  undefined uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x16);
  if ((*(sword *)(param_1 + 0xe) == 1) && ((*(uint *)(param_1 + 8) & 0x180) != 0)) {
    _vno_bsd_unlock(param_1,0x180);
  }
  uVar2 = _vn_close(uVar1,*(undefined4 *)(param_1 + 8),(int)*(sword *)(param_1 + 0xe));
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(sword *)(param_1 + 0xe) == 1) {
    _vn_rele(uVar1);
  }
  return (int)*(char *)(dword_40B57D4 + 100);
}
/* GHIDRADEC_FUNCTION index=528 start=0x40190ac */

undefined4 _vno_lockrelease(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  word wVar6;
  sword sVar9;
  undefined4 uVar8;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iVar7;
  
  uVar1 = *(uint *)(*_active_u + 0x28);
  if ((uVar1 & 0x20000000) != 0) {
    bVar5 = false;
    *(uint *)(*_active_u + 0x28) = uVar1 & 0xdfffffff;
    iVar2 = *(int *)(param_1 + 0x16);
    iVar7 = *(int *)((int)_active_u + 0x14e);
    if (-1 < iVar7) {
      do {
        iVar3 = *(int *)(*(int *)((int)_active_u + 0x146) + iVar7 * 4);
        if (iVar3 != 0) {
          bVar4 = *(byte *)(*(int *)((int)_active_u + 0x14a) + iVar7);
          if ((bVar4 & 4) != 0) {
            if (iVar2 == *(int *)(iVar3 + 0x16)) {
              bVar5 = true;
              *(byte *)(*(int *)((int)_active_u + 0x14a) + iVar7) = bVar4 & 0xfb;
            }
            else {
              *(byte *)(*_active_u + 0x28) = *(byte *)(*_active_u + 0x28) | 0x20;
            }
          }
        }
        wVar6 = (word)((uint)iVar7 >> 0x10);
        sVar9 = (sword)iVar7 + -1;
        iVar7 = CONCAT22(wVar6,sVar9);
      } while ((sVar9 != -1) || (iVar7 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
    }
    if (bVar5) {
      uStack_16 = 3;
      uStack_14 = 0;
      uStack_12 = 0;
      uStack_e = 0;
      uVar8 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x60))
                        (iVar2,&uStack_16,8,*(undefined4 *)((int)_active_u + 0x1a),
                         (int)*(sword *)(*_active_u + 0x30));
      return uVar8;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=529 start=0x4019174 */

undefined4 _vno_bsd_lock(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if ((((*(uint *)(param_1 + 8) & 0x100) == 0) || ((param_2 & 2) == 0)) &&
     ((-1 < (char)*(uint *)(param_1 + 8) || ((param_2 & 1) == 0)))) {
    uStack_8 = 0x23;
    iVar1 = *(int *)(param_1 + 0x16);
    if ((param_2 & 2) == 0) {
      uStack_8 = 0x24;
    }
    iVar2 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar2 == 0) {
      do {
        while ((*(byte *)(iVar1 + 5) & 4) == 0) {
          if (((param_2 & 2) == 0) || ((*(word *)(iVar1 + 4) & 8) == 0)) {
            if ((*(byte *)(param_1 + 10) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
              _panic(aVnoBsdLock);
            }
            if ((param_2 & 2) != 0) {
              *(sword *)(iVar1 + 10) = *(sword *)(iVar1 + 10) + 1;
              *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 4;
              *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x100;
            }
            if ((param_2 & 1) == 0) {
              return 0;
            }
            if (*(char *)(param_1 + 0xb) < '\0') {
              return 0;
            }
            *(sword *)(iVar1 + 8) = *(sword *)(iVar1 + 8) + 1;
            *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 8;
            *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x80;
            return 0;
          }
          if (*(char *)(param_1 + 0xb) < '\0') {
            _vno_bsd_unlock(param_1,0x80);
          }
          else {
            if ((param_2 & 4) != 0) {
              return 0x23;
            }
            *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 0x10;
            iVar2 = iVar1 + 8;
            uVar3 = 0x23;
loc_4019246:
            _sleep(iVar2,uVar3);
          }
        }
        if ((*(byte *)(param_1 + 10) & 1) == 0) {
          if ((param_2 & 4) != 0) {
            return 0x23;
          }
          *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 0x10;
          iVar2 = iVar1 + 10;
          uVar3 = uStack_8;
          goto loc_4019246;
        }
        _vno_bsd_unlock(param_1,0x100);
      } while( true );
    }
    if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
      return 4;
    }
    *(undefined *)(dword_40B57D4 + 0x65) = 2;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=530 start=0x401931a */

void _vno_bsd_unlock(int param_1,uint param_2)

{
  int iVar1;
  word wVar2;
  sword sVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  param_2 = *(uint *)(param_1 + 8) & param_2;
  if ((iVar1 != 0) && (param_2 != 0)) {
    wVar2 = *(word *)(iVar1 + 4);
    if ((char)param_2 < '\0') {
      if ((wVar2 & 8) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVnoBsdUnlockSh);
      }
      sVar3 = *(sword *)(iVar1 + 8);
      *(sword *)(iVar1 + 8) = sVar3 + -1;
      if ((sVar3 == 1) &&
         (*(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) & 0xfff7, (wVar2 & 0x10) != 0)) {
        _wakeup(iVar1 + 8);
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xff7f;
    }
    if ((param_2 & 0x100) != 0) {
      if ((wVar2 & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVnoBsdUnlockEx);
      }
      sVar3 = *(sword *)(iVar1 + 10);
      *(sword *)(iVar1 + 10) = sVar3 + -1;
      if ((sVar3 == 1) &&
         (*(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) & 0xffeb, (wVar2 & 0x10) != 0)) {
        _wakeup(iVar1 + 10);
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xfeff;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=531 start=0x40193de */

int _lookupname(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined auStack_10 [12];
  
  iVar1 = _pn_get(param_1,param_2,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _lookuppn(auStack_10,param_3,param_4,param_5);
    _pn_free(auStack_10);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=532 start=0x401942e */

int _lookuppn(int param_1,int param_2,int *param_3,int *param_4)

{
  sword *psVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined auStack_114 [8];
  int iStack_10c;
  int iStack_108;
  char acStack_104 [256];
  
  iVar5 = 0;
  iVar4 = *(int *)((int)_active_u + 0x156);
  psVar1 = (sword *)(iVar4 + 6);
  *psVar1 = *psVar1 + 1;
loc_401945A:
  acStack_104[0] = '\0';
  if (*(int *)(param_1 + 8) != 0) {
    if (**(char **)(param_1 + 4) == '/') {
      _vn_rele(iVar4);
      _pn_skipslash(param_1);
      iVar4 = _rootdir;
      if (*(int *)((int)_active_u + 0x15a) != 0) {
        iVar4 = *(int *)((int)_active_u + 0x15a);
      }
      *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
      goto loc_40194BA;
    }
    if (**(char **)(param_1 + 4) != '\0') goto loc_40194BA;
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    return 2;
  }
loc_40194BA:
  iVar3 = 0;
  iVar8 = iVar4;
  if (*(int *)(iVar4 + 0x28) != 2) {
    iVar7 = 0x14;
    goto loc_401989A;
  }
  iVar7 = _pn_getcomponent(param_1,acStack_104,0);
  if (iVar7 != 0) goto loc_401989A;
  if (acStack_104[0] != '\0') {
    iVar3 = _strcmp(acStack_104,&asc_40A6712);
    if (iVar3 != 0) {
loc_40195CE:
      do {
        iVar3 = 0;
        if (*(int *)(iVar8 + 0x10) == 0) goto loc_401966A;
        iVar7 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x1c))
                          (iVar8,0x40,*(undefined4 *)((int)_active_u + 0x1a));
        if (iVar7 != 0) goto loc_401989A;
        iVar4 = *(int *)(iVar8 + 0x10);
        while( true ) {
          if (iVar4 == 0) goto loc_401966A;
          iVar7 = _strncmp(iVar4 + 0x20,acStack_104,0xff);
          if (iVar7 == 0) break;
          iVar4 = *(int *)(iVar4 + 0x120);
        }
        if ((*(uint *)(iVar4 + 0xc) & 2) == 0) {
          iVar7 = (**(code **)(*(int *)(iVar4 + 4) + 8))(iVar4,&iStack_108);
          iVar4 = iStack_108;
          if (iVar7 == 0) goto loc_40197C6;
          goto loc_401989A;
        }
        *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 4;
        _sleep(iVar4,0x1b);
      } while( true );
    }
    do {
      iVar3 = *(int *)((int)_active_u + 0x15a);
      iVar8 = iVar4;
      if (((iVar3 == iVar4) ||
          (((((iVar4 != 0 && (iVar3 != 0)) && (*(int *)(iVar4 + 0x1c) == *(int *)(iVar3 + 0x1c))) &&
            (iVar3 = (**(code **)(*(int *)(iVar4 + 0x1c) + 0x6c))(iVar4,iVar3), iVar3 != 0)) ||
           (_rootdir == iVar4)))) ||
         (((iVar4 != 0 && (_rootdir != 0)) &&
          ((*(int *)(iVar4 + 0x1c) == *(int *)(_rootdir + 0x1c) &&
           (iVar3 = (**(code **)(*(int *)(iVar4 + 0x1c) + 0x6c))(iVar4,_rootdir), iVar3 != 0))))))
      break;
      if ((*(byte *)(iVar4 + 5) & 1) == 0) goto loc_40195CE;
      iVar8 = *(int *)(*(int *)(iVar4 + 0x24) + 8);
      *(sword *)(iVar8 + 6) = *(sword *)(iVar8 + 6) + 1;
      _vn_rele(iVar4);
      iVar4 = iVar8;
    } while (*(int *)(iVar8 + 0xc) != 0);
    *(sword *)(iVar8 + 6) = *(sword *)(iVar8 + 6) + 1;
    iVar4 = iVar8;
    goto loc_40197C6;
  }
  if (param_3 != (int *)0x0) {
    _vn_rele(iVar4);
    return 0x11;
  }
  _pn_set(param_1,&asc_40A6047);
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
    return 0;
  }
  goto loc_4019876;
loc_401966A:
  iVar7 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x20))
                    (iVar8,acStack_104,&iStack_108,*(undefined4 *)((int)_active_u + 0x1a),param_1,0)
  ;
  iVar3 = iStack_108;
  if (iVar7 != 0) {
    iVar3 = 0;
    if (((*(int *)(param_1 + 8) == 0) && (param_3 != (int *)0x0)) && (iVar7 != 0xd)) {
      _pn_set(param_1,acStack_104);
      *param_3 = iVar8;
      if (param_4 == (int *)0x0) {
        return 0;
      }
      *param_4 = 0;
      return 0;
    }
    goto loc_401989A;
  }
  while (iVar4 = *(int *)(iVar3 + 0xc), iVar4 != 0) {
    if ((*(uint *)(iVar4 + 0xc) & 2) == 0) {
      iVar7 = (**(code **)(*(int *)(*(int *)(iVar3 + 0xc) + 4) + 8))
                        (*(int *)(iVar3 + 0xc),&iStack_108);
      if (iVar7 != 0) goto loc_401989A;
      _vn_rele(iVar3);
      iVar3 = iStack_108;
    }
    else {
      *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 4;
      _sleep(iVar4,0x1b);
    }
  }
  iVar4 = iVar3;
  if (*(int *)(iVar3 + 0x28) == 5) goto loc_401973a;
loc_40197C6:
  iVar3 = iVar4;
  if (*(int *)(param_1 + 8) == 0) goto loc_4019810;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
    pcVar6 = *(char **)(param_1 + 4);
    cVar2 = *pcVar6;
    while (cVar2 == '/') {
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar6;
    }
    if ((*pcVar6 == '\0') && (*(int *)(iVar4 + 0x28) == 2)) {
      **(undefined **)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  if (*(int *)(param_1 + 8) == 0) goto loc_4019810;
  _pn_skipslash(param_1);
  _vn_rele(iVar8);
  goto loc_40194BA;
loc_401973a:
  if ((param_2 != 1) && (*(int *)(param_1 + 8) == 0)) {
loc_4019810:
    _pn_set(param_1,acStack_104);
    if (param_3 == (int *)0x0) {
      _vn_rele(iVar8);
    }
    else {
      if ((iVar3 == iVar8) ||
         ((((iVar8 != 0 && (iVar3 != 0)) && (*(int *)(iVar8 + 0x1c) == *(int *)(iVar3 + 0x1c))) &&
          (iVar4 = (**(code **)(*(int *)(iVar8 + 0x1c) + 0x6c))(iVar8,iVar3), iVar4 != 0)))) {
        _vn_rele(iVar8);
        _vn_rele(iVar3);
        return 0x11;
      }
      *param_3 = iVar8;
    }
    iVar4 = iVar3;
    if (param_4 == (int *)0x0) {
loc_4019876:
      _vn_rele(iVar4);
    }
    else {
      *param_4 = iVar3;
    }
    return 0;
  }
  iVar5 = iVar5 + 1;
  if (0x14 < iVar5) {
    iVar7 = 0x3e;
loc_401989A:
    if (iVar3 != 0) {
      _vn_rele(iVar3);
    }
    _vn_rele(iVar8);
    return iVar7;
  }
  iVar7 = sub_40198BC(iVar3,acStack_104,iVar8,auStack_114);
  if (iVar7 != 0) goto loc_401989A;
  if (iStack_10c == 0) {
    _pn_set(auStack_114,&asc_40A6047);
  }
  iVar7 = _pn_combine(param_1,auStack_114);
  _pn_free(auStack_114);
  if (iVar7 != 0) goto loc_401989A;
  _vn_rele(iVar3);
  iVar4 = iVar8;
  goto loc_401945A;
}
/* GHIDRADEC_FUNCTION index=533 start=0x4019ab2 */

void _pn_alloc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = _kalloc(0x400);
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=534 start=0x4019ad8 */

int _pn_get(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  _pn_alloc(param_3);
  if (param_2 == 0) {
    iVar1 = _copyinstr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  else {
    iVar1 = _copystr(param_1,*(undefined4 *)(param_3 + 4),0x400,param_3 + 8);
  }
  if (((iVar1 == 0) && (*(int *)(param_3 + 8) == 0x400)) &&
     (*(char *)(*(int *)(param_3 + 4) + 0x3ff) != '\0')) {
    iVar1 = 0x3f;
  }
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + -1;
  if (iVar1 != 0) {
    _pn_free(param_3);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=535 start=0x4019b5e */

void _pn_set(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  
  param_1[1] = *param_1;
  piVar1 = param_1 + 2;
  _copystr(param_2,param_1[1],0x400,piVar1);
  *piVar1 = *piVar1 + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=536 start=0x4019b8e */

undefined4 _pn_combine(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((uint)(*(int *)(param_2 + 8) + param_1[2]) < 0x400) {
    _ovbcopy(param_1[1],*param_1 + *(int *)(param_2 + 8),param_1[2]);
    _bcopy(*(undefined4 *)(param_2 + 4),*param_1,*(undefined4 *)(param_2 + 8));
    param_1[2] = *(int *)(param_2 + 8) + param_1[2];
    param_1[1] = *param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x3f;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=537 start=0x4019bee */

undefined4 _pn_append(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _strlen(param_2);
  if ((uint)(iVar1 + *(int *)(param_1 + 8)) < 0x400) {
    _bcopy(param_2,*(int *)(param_1 + 4) + *(int *)(param_1 + 8),iVar1 + 1);
    *(int *)(param_1 + 8) = iVar1 + *(int *)(param_1 + 8);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x3f;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=538 start=0x4019c42 */

undefined4 _pn_getcomponent(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0xff;
  for (pcVar3 = *(char **)(param_1 + 4); (0 < iVar1 && (*pcVar3 != '/')); pcVar3 = pcVar3 + 1) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      return 0x3f;
    }
    *param_2 = *pcVar3;
    iVar1 = iVar1 + -1;
    param_2 = param_2 + 1;
  }
  *(char **)(param_1 + 4) = pcVar3;
  *(int *)(param_1 + 8) = iVar1;
  *param_2 = '\0';
  return 0;
}
/* GHIDRADEC_FUNCTION index=539 start=0x4019c94 */

void _pn_skipslash(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    do {
      if (**(char **)(param_1 + 4) != '/') {
        return;
      }
      *(char **)(param_1 + 4) = *(char **)(param_1 + 4) + 1;
      iVar1 = *(int *)(param_1 + 8);
      *(int *)(param_1 + 8) = iVar1 + -1;
    } while (iVar1 != 1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=540 start=0x4019cce */

void _pn_free(undefined4 *param_1)

{
  _kfree(*param_1,0x400);
  *param_1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=541 start=0x4019cee */

void _chdir(void)

{
  undefined uVar1;
  undefined4 uStack_8;
  
  uVar1 = _chdirec(**(undefined4 **)(dword_40B57D4 + 0x24),&uStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vn_rele(*(undefined4 *)(_active_u + 0x156));
    *(undefined4 *)(_active_u + 0x156) = uStack_8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=542 start=0x4019d40 */

void _chroot(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    uVar3 = _chdirec(*puVar1,&uStack_8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if (*(int *)(_active_u + 0x15a) != 0) {
        _vn_rele(*(int *)(_active_u + 0x15a));
      }
      *(undefined4 *)(_active_u + 0x15a) = uStack_8;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=543 start=0x4019da6 */

int _chdirec(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _lookupname(param_1,0,1,0,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 0x28) == 2) {
      iVar1 = (**(code **)(*(int *)(iStack_8 + 0x1c) + 0x1c))
                        (iStack_8,0x40,*(undefined4 *)(_active_u + 0x1a));
      if (iVar1 == 0) {
        *param_2 = iStack_8;
        return 0;
      }
    }
    else {
      iVar1 = 0x14;
    }
    _vn_rele(iStack_8);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=544 start=0x4019e26 */

void _open(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  *(byte *)(iVar2 + 0x16) =
       *(byte *)(iVar2 + 0x16) & 0xbf |
       (byte)(((*(uint *)((int)puVar1 + 7) & 0x1fffffff) >> 0x1c) << 6);
  uVar3 = _copen(*puVar1,puVar1[1] + 1,puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0xbf;
  return;
}
/* GHIDRADEC_FUNCTION index=545 start=0x4019e90 */

void _creat(void)

{
  undefined uVar1;
  
  uVar1 = _copen(**(undefined4 **)(dword_40B57D4 + 0x24),0x602,
                 (*(undefined4 **)(dword_40B57D4 + 0x24))[1]);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=546 start=0x4019ebc */

int _copen(undefined4 param_1,uint param_2,word param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar2 = _falloc();
  if (iVar2 == 0) {
    iVar3 = (int)*(char *)(dword_40B57D4 + 100);
  }
  else {
    iVar1 = *(int *)(dword_40B57D4 + 0x5c);
    iVar3 = _vn_open(param_1,0,param_2,param_3 & ~*(word *)(_active_u + 0x59) & 0xfff,&iStack_8);
    if (iVar3 == 0) {
      *(uint *)(iVar2 + 8) = param_2 & 0xa000004b;
      if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (*(int *)(iStack_8 + 0x28) == 1)) {
        *(uint *)(iVar2 + 8) = param_2 & 0xa000004b | 0x40001000;
      }
      *(undefined2 *)(iVar2 + 0xc) = 1;
      *(int *)(iVar2 + 0x16) = iStack_8;
      *(undefined **)(iVar2 + 0x12) = _vnodefops;
      if (*(int *)(iStack_8 + 0x28) == 8) {
        *(uint *)(iVar2 + 8) = param_2 & 4 | *(uint *)(iVar2 + 8);
      }
      *(int *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = iVar2;
    }
    else {
      *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = 0;
      _crfree(*(undefined4 *)(iVar2 + 0x1e));
      *(undefined2 *)(iVar2 + 0xe) = 0;
      _free_file(iVar2);
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=547 start=0x4019fba */

void _mknod(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  word wStack_3a;
  undefined2 uStack_a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((puVar1[1] & 0xf000) == 0) {
    puVar1[1] = puVar1[1] | 0x8000;
  }
  if (((puVar1[1] & 0xf000) == 0x1000) || (iVar2 = _suser(), iVar2 != 0)) {
    _vattr_null(&uStack_3e);
    uStack_3e = *(undefined4 *)(_mftovt_tab + (*(uint *)((int)puVar1 + 6) >> 0x1d) * 4);
    wStack_3a = ~*(word *)(_active_u + 0x164) & *(word *)((int)puVar1 + 6) & 0xfff;
    switch(uStack_3e) {
    case :
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      break;
    case :
      *(undefined *)(dword_40B57D4 + 100) = 0x15;
      break;
    case :
    case :
    case :
    case :
      uStack_a = *(undefined2 *)((int)puVar1 + 10);
    :
      uVar3 = _vn_create(*puVar1,0,&uStack_3e,1,0,&uStack_42);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _vn_rele(uStack_42);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=548 start=0x401a0e0 */

void _mkdir(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  word wStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(&uStack_3e);
  uStack_3e = 2;
  wStack_3a = ~*(word *)(_active_u + 0x164) & *(word *)((int)puVar1 + 6) & 0x1ff;
  uVar2 = _vn_create(*puVar1,0,&uStack_3e,1,0,&uStack_42);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vn_rele(uStack_42);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=549 start=0x401a162 */

void _link(void)

{
  undefined uVar1;
  
  uVar1 = _vn_link(**(undefined4 **)(dword_40B57D4 + 0x24),
                   (*(undefined4 **)(dword_40B57D4 + 0x24))[1],0);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}

