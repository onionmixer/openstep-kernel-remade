/* GHIDRADEC_FUNCTION index=100 start=0x40046d8 */

int _rewhence(int param_1,int param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  undefined auStack_3e [20];
  int iStack_2a;
  
  if (((*(sword *)(param_1 + 2) == 2) || (param_3 == 2)) &&
     (iVar1 = (**(code **)(*(int *)(*(int *)(param_2 + 0x16) + 0x1c) + 0x14))
                        (*(int *)(param_2 + 0x16),auStack_3e,*(undefined4 *)(_active_u + 0x1a)),
     iVar1 != 0)) {
    return iVar1;
  }
  sVar2 = *(sword *)(param_1 + 2);
  if (sVar2 == 1) {
    *(int *)(param_1 + 4) = *(int *)(param_2 + 0x1a) + *(int *)(param_1 + 4);
  }
  else if (sVar2 < 2) {
    if (sVar2 != 0) {
      return 0x16;
    }
  }
  else {
    if (sVar2 != 2) {
      return 0x16;
    }
    *(int *)(param_1 + 4) = iStack_2a + *(int *)(param_1 + 4);
  }
  sVar2 = (sword)param_3;
  *(sword *)(param_1 + 2) = sVar2;
  if (sVar2 == 1) {
    iStack_2a = *(int *)(param_2 + 0x1a);
  }
  else if (sVar2 != 2) {
    return 0;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - iStack_2a;
  return 0;
}
/* GHIDRADEC_FUNCTION index=101 start=0x400477c */

void _flock(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined uVar4;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (((*puVar1 < *(uint *)(_active_u + 0x152)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x146) + *puVar1 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(sword *)(iVar3 + 0xc) == 1) {
      uVar2 = puVar1[1];
      if ((uVar2 & 8) == 0) {
        if ((uVar2 & 2) == 0) {
          if ((uVar2 & 1) == 0) {
            *(undefined *)(dword_40B57D4 + 100) = 0x16;
            return;
          }
        }
        else {
          puVar1[1] = uVar2 & 0xfffffffe;
        }
        uVar4 = _vno_bsd_lock(iVar3,puVar1[1]);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
      }
      else {
        _vno_bsd_unlock(iVar3,0x180);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x2d;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=102 start=0x400481e */

void _expand_fdlist(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x152) <= param_2) {
    iVar2 = param_2 + 1;
    iVar3 = iVar2 * 4;
    uVar4 = _kalloc(iVar3);
    uVar5 = _kalloc(iVar2);
    iVar1 = *(int *)(param_1 + 0x152);
    if (param_2 < iVar1) {
      _kfree(uVar4,iVar3);
      _kfree(uVar5,iVar2);
    }
    else {
      _bzero(uVar4,iVar3);
      _bzero(uVar5,iVar2);
      if (iVar1 != 0) {
        _bcopy(*(undefined4 *)(param_1 + 0x146),uVar4,iVar1 << 2);
        _bcopy(*(undefined4 *)(param_1 + 0x14a),uVar5,iVar1);
        _kfree(*(undefined4 *)(param_1 + 0x146),iVar1 << 2);
        _kfree(*(undefined4 *)(param_1 + 0x14a),iVar1);
      }
      *(undefined4 *)(param_1 + 0x146) = uVar4;
      *(undefined4 *)(param_1 + 0x14a) = uVar5;
      *(int *)(param_1 + 0x152) = iVar2;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=103 start=0x40048d6 */

void _execv(void)

{
  undefined uVar1;
  
  *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 8) = 0;
  uVar1 = _execve();
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=104 start=0x40048fc */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int _execve(void)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  sword sVar5;
  char cVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  int iVar12;
  word wVar13;
  int iVar14;
  sword sVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  int iVar20;
  char *pcVar21;
  int iVar22;
  int iStack_e0;
  undefined4 uStack_d0;
  int iStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 auStack_c0 [3];
  int *piStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_90;
  undefined2 uStack_8c;
  undefined4 uStack_88;
  byte bStack_80;
  undefined auStack_7e [8];
  undefined4 uStack_76;
  undefined4 uStack_72;
  char acStack_6a [32];
  char *apcStack_4a [2];
  uint uStack_42;
  undefined auStack_3e [4];
  word wStack_3a;
  sword sStack_38;
  sword sStack_36;
  
  piVar2 = (int *)dword_40B57D4[9];
  piVar3 = *(int **)(*(int *)(_active_threads + 0xc) + 0x30);
  iVar9 = _pn_get(*piVar2,0,apcStack_4a);
  if (iVar9 != 0) {
    *(char *)(dword_40B57D4 + 0x19) = (char)iVar9;
    return iVar9;
  }
  iVar9 = _lookuppn(apcStack_4a,1,0,&piStack_b4);
  if ((iVar9 != 0) || (piStack_b4 == (int *)0x0)) {
    _pn_free(apcStack_4a);
    goto loc_40051B8;
  }
  iStack_e0 = 0;
  bVar7 = false;
  iVar9 = *(int *)((int)piVar3 + 0x1a);
  sVar15 = *(sword *)(iVar9 + 2);
  sVar5 = *(sword *)(iVar9 + 4);
  iVar9 = (**(code **)(piStack_b4[7] + 0x14))(piStack_b4,auStack_3e,iVar9);
  if (iVar9 == 0) {
    if ((*(byte *)(piStack_b4[9] + 0xf) & 8) == 0) {
      if ((wStack_3a & 0xc00) != 0) {
        iVar9 = _task_secure(*(undefined4 *)(_active_threads + 0xc));
        if (iVar9 == 0) {
          _uprintf(aSPrivilegesDis,piVar3 + 2);
        }
        else {
          if ((wStack_3a & 0x800) != 0) {
            sVar15 = sStack_38;
          }
          if ((wStack_3a & 0x400) != 0) {
            sVar5 = sStack_36;
          }
        }
      }
    }
    else if ((wStack_3a & 0xc00) != 0) {
      iVar9 = _pn_get(*piVar2,0,auStack_c0);
      if (iVar9 != 0) goto loc_400517E;
      _uprintf(aSSetuidExecuti,auStack_c0[0]);
      _pn_free(auStack_c0);
    }
    while (iVar9 = _check_exec_access(piStack_b4), iVar9 == 0) {
      uStack_b0 = uStack_b0 & 0xffffff;
      iVar9 = _vn_rdwr(0,piStack_b4,&uStack_b0,0x20,0,1,1,&uStack_c4);
      if (iVar9 != 0) break;
      if ((0x18 < uStack_c4) && (uStack_b0._0_1_ != '#')) goto loc_4004DE4;
      if (uStack_b0 == 0xfeedface) {
        bVar8 = false;
loc_4004C44:
        iVar16 = 0;
        iVar17 = 0;
        iVar14 = 0;
        iStack_e0 = _kmem_alloc_wait(_kernel_pageable_map,0xa000);
        iVar12 = 0xa000;
        iVar19 = iStack_e0;
        if (piVar2[1] == 0) goto loc_4004D6E;
        goto loc_4004C72;
      }
      if ((uStack_b0 == 0xcafebabe) || (uStack_c8 = 0xcafebabe, uStack_b0 == 0xbebafeca)) {
        bVar8 = true;
        goto loc_4004C44;
      }
      uStack_c8 = 0xfeedface;
      if (uStack_b0 == 0xcefaedfe) {
        iVar9 = 0x54;
        break;
      }
      if ((uStack_b0._0_2_ != 0x2321) || (bVar7)) goto loc_4004DE4;
      for (pcVar21 = (char *)((int)&uStack_b0 + 2); pcVar21 < &uStack_90; pcVar21 = pcVar21 + 1) {
        if (*pcVar21 == '\t') {
          *pcVar21 = ' ';
        }
        else if (*pcVar21 == '\n') {
          *pcVar21 = '\0';
          break;
        }
      }
      if (*pcVar21 != '\0') goto loc_4004DE4;
      pcVar21 = (char *)((int)&uStack_b0 + 2);
      cVar6 = uStack_b0._2_1_;
      while (cVar6 == ' ') {
        pcVar21 = pcVar21 + 1;
        cVar6 = *pcVar21;
      }
      cVar6 = *pcVar21;
      pcVar11 = pcVar21;
      while ((cVar6 != '\0' && (*pcVar11 != ' '))) {
        pcVar11 = pcVar11 + 1;
        cVar6 = *pcVar11;
      }
      acStack_6a[0] = '\0';
      if (*pcVar11 != '\0') {
        pcVar18 = pcVar11 + 1;
        *pcVar11 = '\0';
        cVar6 = *pcVar18;
        while (cVar6 == ' ') {
          pcVar18 = pcVar18 + 1;
          cVar6 = *pcVar18;
        }
        if (*pcVar18 != '\0') {
          _bcopy(pcVar18,acStack_6a,0x20);
        }
      }
      bVar7 = true;
      _vn_rele(piStack_b4);
      piStack_b4 = (int *)0x0;
      iVar9 = _pn_set(apcStack_4a,pcVar21);
      if (((iVar9 != 0) || (iVar9 = _lookuppn(apcStack_4a,1,0,&piStack_b4), iVar9 != 0)) ||
         (iVar9 = (**(code **)(piStack_b4[7] + 0x14))
                            (piStack_b4,auStack_3e,*(undefined4 *)(_active_u + 0x1a)), iVar9 != 0))
      break;
    }
  }
  goto loc_400517E;
loc_4004C72:
  pcVar21 = (char *)0x0;
  pcVar11 = (char *)0x0;
  if (bVar7) {
    if (iVar16 == 0) {
      piVar2[1] = piVar2[1] + 4;
      pcVar11 = apcStack_4a[0];
      pcVar21 = apcStack_4a[0];
    }
    else if ((iVar16 == 1) && (acStack_6a[0] != '\0')) {
      pcVar11 = acStack_6a;
      pcVar21 = pcVar11;
    }
    else {
      if ((!bVar7) || ((iVar16 != 1 && ((iVar16 != 2 || (acStack_6a[0] == '\0'))))))
      goto loc_4004CBC;
      pcVar21 = (char *)*piVar2;
    }
  }
  else {
loc_4004CBC:
    if (piVar2[1] != 0) {
      pcVar21 = (char *)_fuword(piVar2[1]);
      piVar2[1] = piVar2[1] + 4;
    }
  }
  if (pcVar21 == (char *)0x0) {
    if (piVar2[2] != 0) {
      piVar2[1] = 0;
      pcVar21 = (char *)_fuword(piVar2[2]);
      if (pcVar21 == (char *)0x0) goto loc_4004D6E;
      piVar2[2] = piVar2[2] + 4;
      iVar17 = iVar17 + 1;
    }
    if (pcVar21 == (char *)0x0) goto loc_4004D6E;
  }
  iVar16 = iVar16 + 1;
  if (pcVar21 != (char *)0xffffffff) {
    if (0x9ffe < iVar14) {
      iVar9 = 7;
      goto loc_400517E;
    }
    do {
      if (pcVar11 == (char *)0x0) {
        iVar9 = _copyinstr(pcVar21,iVar19,iVar12,&iStack_cc);
        pcVar21 = pcVar21 + iStack_cc;
      }
      else {
        iVar9 = _copystr(pcVar11,iVar19,iVar12,&iStack_cc);
        pcVar11 = pcVar11 + iStack_cc;
      }
      iVar19 = iStack_cc + iVar19;
      iVar14 = iStack_cc + iVar14;
      iVar12 = iVar12 - iStack_cc;
      if (iVar9 != 2) goto loc_4004D64;
    } while (iVar14 < 0x9fff);
    iVar9 = 7;
loc_4004D64:
    if (iVar9 != 0) goto loc_400517E;
    goto loc_4004C72;
  }
  iVar9 = 0xe;
loc_4004D6E:
  if (bVar8) {
    iVar12 = _fatfile_getarch(piStack_b4,&uStack_b0,auStack_7e);
    if (iVar12 != 0) goto loc_4004F62;
    iVar9 = _vn_rdwr(0,piStack_b4,&uStack_b0,0x1c,uStack_76,1,1,&uStack_c4);
    if (iVar9 == 0) {
      if (uStack_c4 == 0) {
        if (uStack_b0 == 0xfeedface) goto loc_4004E16;
loc_4004DE4:
        iVar9 = 8;
      }
      else {
        iVar9 = 0x53;
      }
    }
  }
  else {
    uStack_72 = *(undefined4 *)(*piStack_b4 + 0x14);
    uStack_76 = 0;
loc_4004E16:
    iVar12 = _load_machfile(piStack_b4,&uStack_b0,uStack_76,uStack_72,&uStack_90);
    if (iVar12 == 0) {
      if ((*(byte *)(*piVar3 + 0x2b) & 0x10) == 0) {
        iVar19 = _get_posix_proc((int)*(sword *)(*piVar3 + 0x30));
        _lock_write(_active_u + 0x1e);
        iVar12 = *(int *)((int)piVar3 + 0x1a);
        if ((*(sword *)(iVar12 + 2) != sVar15) || (*(sword *)(iVar12 + 4) != sVar5)) {
          uVar10 = _crcopy(iVar12);
          *(undefined4 *)((int)piVar3 + 0x1a) = uVar10;
        }
        *(sword *)(*(int *)((int)piVar3 + 0x1a) + 2) = sVar15;
        *(sword *)(*piVar3 + 0x2c) = sVar15;
        *(sword *)(*(int *)((int)piVar3 + 0x1a) + 4) = sVar5;
        _lock_done(_active_u + 0x1e);
        *(sword *)(iVar19 + 8) = sVar5;
        *(undefined2 *)(iVar19 + 4) = *(undefined2 *)(*(int *)((int)piVar3 + 0x1a) + 6);
        *(sword *)(iVar19 + 6) = sVar15;
      }
      else {
        _exception_from_kernel(6,0,0);
      }
      uStack_d0 = 0;
      iVar12 = _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_d0,
                            _page_size,0);
      if (iVar12 == 0) {
        _vm_protect(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),0,_page_size,0,0);
      }
      if (iVar9 == 0) {
        _vn_rele(piStack_b4);
        piStack_b4 = (int *)0x0;
        if (((char)bStack_80 < '\0') &&
           (iVar12 = _create_unix_stack(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),
                                        uStack_88), iVar12 != 0)) {
          iVar12 = 5;
          goto loc_4004F62;
        }
        if ((char)bStack_80 < '\0') {
          iVar12 = (*(int *)(*piVar3 + 0x82) - (iVar14 + 3U & 0xfffffffc)) + -4;
          iVar14 = iVar12 + iVar16 * -4 + -0xc;
          *(int *)(*dword_40B57D4 + 0x3c) = iVar14;
          _suword(iVar14,iVar16 - iVar17);
          iVar19 = 0xa000;
          iVar20 = iStack_e0;
          do {
            iVar22 = iVar14 + 4;
            if (iVar17 == iVar16) {
              _suword(iVar22,0);
              iVar22 = iVar14 + 8;
            }
            iVar16 = iVar16 + -1;
            if (iVar16 < 0) break;
            _suword(iVar22,iVar12);
            do {
              iVar9 = _copyoutstr(iVar20,iVar12,iVar19,&iStack_cc);
              iVar12 = iStack_cc + iVar12;
              iVar20 = iStack_cc + iVar20;
              iVar19 = iVar19 - iStack_cc;
            } while (iVar9 == 2);
            iVar14 = iVar22;
          } while (iVar9 != 0xe);
          _suword(iVar22,0);
        }
        if ((bStack_80 & 0x40) != 0) {
          iVar17 = *(int *)(*dword_40B57D4 + 0x3c) + -4;
          *(int *)(*dword_40B57D4 + 0x3c) = iVar17;
          _suword(iVar17,uStack_90);
        }
        *(undefined2 *)(*dword_40B57D4 + 0x42) = uStack_8c;
        *(uint *)(*dword_40B57D4 + 0x44) =
             CONCAT22((sword)_uStack_8c,*(undefined2 *)(*dword_40B57D4 + 0x46));
        iVar17 = *piVar3;
        iVar16 = *(int *)(iVar17 + 0x24);
        while (iVar16 != 0) {
          uVar4 = *(uint *)(iVar17 + 0x24);
          iVar16 = _ffs(uVar4);
          *(uint *)(iVar17 + 0x24) = ~(1 << (iVar16 - 1U & 0x3f)) & uVar4;
          *(undefined4 *)((int)piVar3 + iVar16 * 4 + 0x2a) = 0;
          iVar17 = *piVar3;
          iVar16 = *(int *)(iVar17 + 0x24);
        }
        *(undefined4 *)((int)piVar3 + 0x142) = 0;
        *(undefined4 *)((int)piVar3 + 0x13e) = 0;
        *(undefined4 *)((int)piVar3 + 0x132) = 0;
        *(undefined4 *)((int)piVar3 + 0x136) = 0;
        iVar17 = *(int *)((int)piVar3 + 0x14e);
        if (-1 < iVar17) {
          do {
            if ((*(byte *)(*(int *)((int)piVar3 + 0x14a) + iVar17) & 1) != 0) {
              uVar10 = *(undefined4 *)(*(int *)((int)piVar3 + 0x146) + iVar17 * 4);
              _vno_lockrelease(uVar10);
              _closef(uVar10);
              *(undefined4 *)(*(int *)((int)piVar3 + 0x146) + iVar17 * 4) = 0;
              *(undefined *)(*(int *)((int)piVar3 + 0x14a) + iVar17) = 0;
            }
            pbVar1 = (byte *)(*(int *)((int)piVar3 + 0x14a) + iVar17);
            *pbVar1 = *pbVar1 & 0xfd;
            wVar13 = (word)((uint)iVar17 >> 0x10);
            sVar15 = (sword)iVar17 + -1;
            iVar17 = CONCAT22(wVar13,sVar15);
          } while ((sVar15 != -1) || (iVar17 = (uint)wVar13 * 0x10000 + -1, wVar13 != 0));
        }
        for (iVar17 = *(int *)((int)piVar3 + 0x14e);
            (-1 < iVar17 && (*(int *)(*(int *)((int)piVar3 + 0x146) + iVar17 * 4) == 0));
            iVar17 = iVar17 + -1) {
          *(int *)((int)piVar3 + 0x14e) = iVar17 + -1;
        }
        *(undefined *)((int)dword_40B57D4 + 0x65) = 1;
        *(word *)((int)piVar3 + 0x23a) = *(word *)((int)piVar3 + 0x23a) & 0xfffe;
        if (0x10 < uStack_42) {
          uStack_42 = 0x10;
        }
        _bcopy(apcStack_4a[0],piVar3 + 2,uStack_42 + 1);
        if ((byte_40B60C0 & 0x10) != 0) {
          _pmonlogexec(0x11,0x10000000,_active_threads,piVar3 + 2);
        }
        *(byte *)(*piVar3 + 0x28) = *(byte *)(*piVar3 + 0x28) | 0x80;
      }
    }
    else {
loc_4004F62:
      iVar9 = sub_400544E(iVar12);
    }
  }
loc_400517E:
  _pn_free(apcStack_4a);
  if (iStack_e0 != 0) {
    _kmem_free_wakeup(_kernel_pageable_map,iStack_e0,0xa000);
  }
  if (piStack_b4 != (int *)0x0) {
    _vn_rele(piStack_b4);
  }
loc_40051B8:
  *(char *)(dword_40B57D4 + 0x19) = (char)iVar9;
  return iVar9;
}
/* GHIDRADEC_FUNCTION index=105 start=0x40051ce */

void _create_unix_stack(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uStack_8;
  
  *(int *)(*_active_u + 0x82) = param_2;
  uVar1 = ~_page_mask & _page_mask + *(int *)((int)_active_u + 0x26e);
  uStack_8 = ~_page_mask & param_2 - uVar1;
  _vm_map_find(param_1,0,0,&uStack_8,uVar1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=106 start=0x4005220 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _load_init_program(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar2 = 0;
  do {
    if ((__boothowto & 0x10) != 0) {
      _printf(aInitProgram);
      _gets(_init_program_name,_init_program_name);
    }
    if (((iVar2 != 0) && ((__boothowto & 0x10) == 0)) && (_init_attempts == 1)) {
      _printf(aLoadOfSErrnoDT,_init_program_name,iVar2,aEtcInit);
      iVar2 = 0;
      _bcopy(aEtcInit,_init_program_name,10);
    }
    _init_attempts = _init_attempts + 1;
    if (iVar2 == 0) {
      uStack_14 = 0;
      _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_14,_page_size,1);
      if (uStack_14 == 0) {
        uStack_14 = 1;
      }
      _copyoutmsg(_init_program_name,uStack_14,0x81);
      uStack_10 = uStack_14;
      uStack_14 = uStack_14 + 0x8f & 0xfffffff0;
      _copyoutmsg(&_init_args,uStack_14,0x80);
      uStack_c = uStack_14;
      uStack_14 = uStack_14 + 0x8f & 0xfffffff0;
      uStack_8 = 0;
      _copyoutmsg(&uStack_10,uStack_14,0xc);
      _init_exec_args = uStack_10;
      dword_40B6074 = uStack_14;
      dword_40B6078 = 0;
      uVar1 = *(undefined4 *)(dword_40B57D4 + 0x24);
      *(uint **)(dword_40B57D4 + 0x24) = &_init_exec_args;
      iVar2 = _execve();
      *(undefined4 *)(dword_40B57D4 + 0x24) = uVar1;
    }
    else {
      _printf(aLoadOfSFailedE,_init_program_name,iVar2);
      iVar2 = 0;
      __boothowto = __boothowto | 0x10;
    }
  } while (iVar2 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=107 start=0x40053ba */

int _check_exec_access(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined auStack_3e [4];
  word wStack_3a;
  
  uVar1 = *(undefined4 *)((int)_active_u + 0x1a);
  iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))(param_1,auStack_3e,uVar1);
  if ((iVar2 == 0) &&
     (iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x40,uVar1), iVar2 == 0)) {
    if (((*(byte *)(*_active_u + 0x2b) & 0x10) != 0) &&
       (iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x1c))(param_1,0x100,uVar1), iVar2 != 0)) {
      return iVar2;
    }
    if ((*(int *)(param_1 + 0x28) == 1) && ((wStack_3a & 0x49) != 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0xd;
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=108 start=0x40054a6 */

void _rexit(void)

{
                    /* WARNING: Subroutine does not return */
  _exit((uint)*(byte *)(*(int *)(dword_40B57D4 + 0x24) + 3) << 8);
}
/* GHIDRADEC_FUNCTION index=109 start=0x40054ca */

void _exit(undefined4 param_1)

{
  _do_exit(*_active_u,param_1);
  do {
    _thread_halt_self_with_continuation(0);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=110 start=0x40054f0 */

void _do_exit(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  word wVar9;
  int iVar10;
  sword sVar11;
  int iVar12;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  if (*(int *)(param_1 + 0x76) != _active_threads) {
    if ((*(int *)(param_1 + 0x72) != 0) || (*(int *)(param_1 + 0x76) != 0)) {
      do {
        if (*(int *)(param_1 + 0x76) == 0) goto loc_400554E;
        while( true ) {
          if (_active_threads == *(int *)(param_1 + 0x76)) {
            return;
          }
          _thread_hold(_active_threads);
loc_400554E:
          _thread_block();
          if ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            return;
          }
          if (*(int *)(param_1 + 0x72) != 0) break;
          if (*(int *)(param_1 + 0x76) == 0) goto loc_4005572;
        }
      } while( true );
    }
loc_4005572:
    *(int *)(param_1 + 0x76) = _active_threads;
    _task_hold(*(undefined4 *)(_active_threads + 0xc));
    _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
  }
  iVar2 = *(int *)(param_1 + 0x66);
  _task_halt(iVar2);
  iVar8 = *(int *)(iVar2 + 0x30);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffaf | 0x400;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  iVar10 = 0x1f;
  do {
    do {
      *(undefined4 *)(iVar8 + 0x2a + iVar10 * 4) = 1;
      wVar9 = (word)((uint)iVar10 >> 0x10);
      sVar11 = (sword)iVar10 + -1;
      iVar10 = CONCAT22(wVar9,sVar11);
    } while (sVar11 != -1);
    iVar10 = (uint)wVar9 * 0x10000 + -1;
  } while (wVar9 != 0);
  _untimeout(_realitexpire,param_1);
  iVar10 = 0;
  if (*(uint *)(iVar8 + 0x14e) < 0x80000000) {
    do {
      iVar12 = *(int *)(*(int *)(iVar8 + 0x146) + iVar10 * 4);
      if ((iVar12 != 0) && (iVar12 != -0x10000)) {
        _vno_lockrelease(iVar12);
        *(undefined4 *)(*(int *)(iVar8 + 0x146) + iVar10 * 4) = 0;
        _closef(iVar12);
      }
      *(undefined *)(*(int *)(iVar8 + 0x14a) + iVar10) = 0;
      iVar10 = iVar10 + 1;
    } while (iVar10 <= *(int *)(iVar8 + 0x14e));
  }
  if (*(int *)(iVar8 + 0x156) != 0) {
    _vn_rele(*(int *)(iVar8 + 0x156));
  }
  if (*(int *)(iVar8 + 0x15a) != 0) {
    _vn_rele(*(int *)(iVar8 + 0x15a));
  }
  *(undefined4 *)(iVar8 + 0x25e) = 0x7fffffff;
  _acct();
  _crfree(*(undefined4 *)(iVar8 + 0x1a));
  if ((_machine_type == '\0') || (_machine_type == '\x02')) {
    _od_unlock_check((int)*(sword *)(param_1 + 0x30));
  }
  iVar10 = *(int *)(param_1 + 8);
  **(int **)(param_1 + 0xc) = iVar10;
  if (iVar10 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 8) = _zombproc;
  if (_zombproc != 0) {
    *(int *)(_zombproc + 0xc) = param_1 + 8;
  }
  *(int **)(param_1 + 0xc) = &_zombproc;
  _zombproc = param_1;
  *(undefined *)(param_1 + 0x13) = 5;
  uVar5 = *(word *)(param_1 + 0x30) & 0x3f;
  iVar10 = *(int *)(_pidhash + uVar5 * 4);
  if (*(int *)(_pidhash + uVar5 * 4) == param_1) {
    *(undefined4 *)(_pidhash + uVar5 * 4) = *(undefined4 *)(param_1 + 0x3e);
    if (*(sword *)(param_1 + 0x30) == 1) {
      _printf(aInitExitedWith,param_2 >> 8);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    do {
      iVar12 = iVar10;
      if (iVar12 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aExit);
      }
      iVar10 = *(int *)(iVar12 + 0x3e);
    } while (param_1 != *(int *)(iVar12 + 0x3e));
    *(undefined4 *)(iVar12 + 0x3e) = *(undefined4 *)(param_1 + 0x3e);
  }
  *(sword *)(param_1 + 0x34) = (sword)param_2;
  piVar3 = (int *)(iVar8 + 0x166);
  *piVar3 = 0;
  *(undefined4 *)(iVar8 + 0x16a) = 0;
  piVar4 = (int *)(iVar8 + 0x16e);
  *piVar4 = 0;
  *(undefined4 *)(iVar8 + 0x172) = 0;
  for (puVar1 = *(undefined4 **)(iVar2 + 0x18); puVar1 != (undefined4 *)(iVar2 + 0x18);
      puVar1 = (undefined4 *)puVar1[4]) {
    _thread_read_times(puVar1,&iStack_c,&iStack_14);
    *piVar3 = iStack_c + *piVar3;
    *(int *)(iVar8 + 0x16a) = iStack_8 + *(int *)(iVar8 + 0x16a);
    *piVar4 = iStack_14 + *piVar4;
    *(int *)(iVar8 + 0x172) = iStack_10 + *(int *)(iVar8 + 0x172);
  }
  *piVar3 = *(int *)(iVar2 + 0x4c) + *piVar3;
  *(int *)(iVar8 + 0x16a) = *(int *)(iVar2 + 0x50) + *(int *)(iVar8 + 0x16a);
  *piVar4 = *(int *)(iVar2 + 0x54) + *piVar4;
  *(int *)(iVar8 + 0x172) = *(int *)(iVar2 + 0x58) + *(int *)(iVar8 + 0x172);
  uVar7 = _kalloc(0x48);
  *(undefined4 *)(param_1 + 0x36) = uVar7;
  _bcopy(_active_u + 0x166,uVar7,0x48);
  _ruadd(*(undefined4 *)(param_1 + 0x36),iVar8 + 0x1ae);
  if (*(int *)(param_1 + 0x46) != 0) {
    _wakeup(_init_proc);
  }
  iVar8 = *(int *)(param_1 + 0x7e);
  if (iVar8 != 0) {
    *(undefined4 *)(iVar8 + 0x7a) = 0;
    *(uint *)(iVar8 + 0x28) = *(uint *)(iVar8 + 0x28) & 0xffffffef;
    _psignal(iVar8,9);
    *(undefined4 *)(param_1 + 0x7e) = 0;
  }
  if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
    iVar6 = *(int *)(*(int *)(iVar6 + 0xe) + 8);
    if (param_1 == *(int *)(iVar6 + 4)) {
      if ((*(int *)(iVar6 + 8) != 0) &&
         (iVar8 = _ttynty(*(int *)(iVar6 + 8)), iVar6 == *(int *)(iVar8 + 8))) {
        if (*(int *)(iVar8 + 0xc) != 0) {
          _pgsignal(*(int *)(iVar8 + 0xc),1,1);
        }
        _ttywait(*(undefined4 *)(iVar6 + 8));
      }
      *(undefined4 *)(iVar6 + 4) = 0;
    }
    if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
      iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30),0);
      _fixjobc(param_1,*(undefined4 *)(iVar6 + 0xe));
    }
  }
  iVar6 = *(int *)(param_1 + 0x46);
  while (iVar6 != 0) {
    iVar8 = *(int *)(iVar6 + 0x4a);
    if (iVar8 != 0) {
      *(undefined4 *)(iVar8 + 0x4e) = 0;
    }
    if (*(int *)(_init_proc + 0x46) != 0) {
      *(int *)(*(int *)(_init_proc + 0x46) + 0x4e) = iVar6;
    }
    iVar10 = _init_proc;
    *(undefined4 *)(iVar6 + 0x4a) = *(undefined4 *)(_init_proc + 0x46);
    *(undefined4 *)(iVar6 + 0x4e) = 0;
    *(int *)(iVar10 + 0x46) = iVar6;
    *(int *)(iVar6 + 0x42) = iVar10;
    *(undefined2 *)(iVar6 + 0x32) = 1;
    if ((*(uint *)(iVar6 + 0x28) & 0x10) == 0) {
      if ((*(int *)(iVar6 + 0x66) != 0) && (0 < *(int *)(*(int *)(iVar6 + 0x66) + 0x3c))) {
        _psignal(iVar6,1);
        _psignal(iVar6,0x13);
      }
    }
    else {
      *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) & 0xffffffef;
      *(undefined4 *)(iVar6 + 0x7a) = 0;
      _psignal(iVar6,9);
    }
    _spgrp(iVar6);
    iVar6 = iVar8;
  }
  *(undefined4 *)(param_1 + 0x46) = 0;
  if (*(int *)(param_1 + 0x7a) != 0) {
    _psignal(*(int *)(param_1 + 0x7a),0x14);
    _wakeup(*(undefined4 *)(param_1 + 0x7a));
    *(undefined4 *)(*(int *)(param_1 + 0x7a) + 0x7e) = 0;
  }
  if (*(int *)(_active_u + 0x23c) != 0) {
    *(undefined4 *)(_active_u + 0x250) = 0;
    _simple_lock_free(*(undefined4 *)(_active_u + 0x23c));
  }
  iVar6 = *(int *)(_active_u + 0x240);
  while (iVar6 != 0) {
    iVar8 = *(int *)(iVar6 + 4);
    _kfree(iVar6,0x18);
    iVar6 = iVar8;
  }
  _psignal(*(undefined4 *)(param_1 + 0x42),0x14);
  _wakeup(*(undefined4 *)(param_1 + 0x42));
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  _task_terminate(iVar2);
  if (iVar2 == *(int *)(_active_threads + 0xc)) {
    _thread_halt_self();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=111 start=0x4005a3e */

void _wait4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined auStack_50 [4];
  undefined auStack_4c [72];
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _wait1(puVar1[2],auStack_4c,auStack_50,*puVar1,_wait4);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (puVar1[3] != 0) {
    iVar2 = _copyoutmsg(auStack_4c,puVar1[3],0x48);
  }
  if (puVar1[1] != 0) {
    iVar2 = _copyoutmsg(auStack_50,puVar1[1],4);
  }
  _unix_syscall_return(iVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=112 start=0x4005ac6 */

void _wait(void)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  
  uVar1 = _wait1(0,0,&uStack_8,0,_wait);
  *(undefined4 *)(dword_40B57D4 + 0x60) = uStack_8;
  _unix_syscall_return(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=113 start=0x4005af8 */

void _wait3(void)

{
  int iVar1;
  int iVar2;
  undefined auStack_4c [72];
  
  iVar1 = *(int *)(*(int *)(dword_40B57D4 + 0x24) + 8);
  iVar2 = _wait1(*(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4),auStack_4c,dword_40B57D4 + 0x60
                 ,0,_wait3);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (iVar1 != 0) {
    iVar2 = _copyoutmsg(auStack_4c,iVar1,0x48);
  }
  _unix_syscall_return(iVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=114 start=0x4005b6c */

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
/* GHIDRADEC_FUNCTION index=115 start=0x4005e60 */

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
/* GHIDRADEC_FUNCTION index=116 start=0x40060ea */

undefined4 _init_process(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = *_active_u;
    if (*(int *)(iVar1 + 0x4a) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x4a) + 0x4e) = *(undefined4 *)(iVar1 + 0x4e);
    }
    if (*(int *)(iVar1 + 0x4e) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x4e) + 0x4a) = *(undefined4 *)(iVar1 + 0x4a);
    }
    if (iVar1 == *(int *)(*(int *)(iVar1 + 0x42) + 0x46)) {
      *(undefined4 *)(*(int *)(iVar1 + 0x42) + 0x46) = *(undefined4 *)(iVar1 + 0x4a);
    }
    *(int *)(iVar1 + 0x42) = iVar1;
    *(undefined4 *)(iVar1 + 0x4a) = 0;
    *(undefined4 *)(iVar1 + 0x4e) = 0;
    if (*(sword *)(iVar1 + 0x30) != *(sword *)(iVar1 + 0x2e)) {
      _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),0);
    }
    *(undefined2 *)(iVar1 + 0x32) = 0;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=117 start=0x4006164 */

void _fork(void)

{
  _fork1(0);
  return;
}
/* GHIDRADEC_FUNCTION index=118 start=0x4006174 */

void _vfork(void)

{
  _fork1(1);
  return;
}
/* GHIDRADEC_FUNCTION index=119 start=0x4006186 */

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
/* GHIDRADEC_FUNCTION index=120 start=0x40062d6 */

void _newproc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _alloc_posix_proc();
  _cloneproc(*_active_u,param_1,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=121 start=0x4006300 */

undefined4 _cloneproc(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  sword *psVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x66) + 0x30);
  do {
    _mpid = _mpid + 1;
    while( true ) {
      if (29999 < _mpid) {
        _mpid = 100;
        dword_40AE232 = 0;
      }
      if (_mpid < dword_40AE232) break;
      bVar4 = false;
      dword_40AE232 = 30000;
      iVar5 = _allproc;
      while( true ) {
        while (iVar5 == 0) {
          if (bVar4) goto loc_40063D2;
          bVar4 = true;
          iVar5 = _zombproc;
        }
        if (((_mpid == *(sword *)(iVar5 + 0x30)) || (_mpid == *(sword *)(iVar5 + 0x2e))) &&
           (iVar6 = _mpid + 1, iVar1 = _mpid + 1, _mpid = iVar6, dword_40AE232 <= iVar1)) break;
        iVar6 = (int)*(sword *)(iVar5 + 0x30);
        if ((_mpid < iVar6) && (iVar6 < dword_40AE232)) {
          dword_40AE232 = iVar6;
        }
        iVar6 = (int)*(sword *)(iVar5 + 0x2e);
        if ((_mpid < iVar6) && (iVar6 < dword_40AE232)) {
          dword_40AE232 = iVar6;
        }
        iVar5 = *(int *)(iVar5 + 8);
      }
    }
loc_40063D2:
    iVar5 = _insert_posix_proc(param_3,_mpid);
    if (iVar5 != 0) {
      iVar5 = _freeproc;
      if (_freeproc == 0) {
        iVar5 = _getproc();
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNoProcs);
        }
        *(int *)(iVar5 + 8) = _freeproc;
      }
      _freeproc = *(undefined4 *)(iVar5 + 8);
      *(undefined *)(iVar5 + 0x13) = 4;
      *(undefined4 *)(iVar5 + 0x5e) = 0;
      *(undefined4 *)(iVar5 + 0x5a) = 0;
      *(uint *)(iVar5 + 0x28) = *(uint *)(param_1 + 0x28) & 0x2108000 | 1;
      *(undefined2 *)(iVar5 + 0x2c) = *(undefined2 *)(param_1 + 0x2c);
      *(uint *)(iVar5 + 0x28) = *(uint *)(param_1 + 0x28) & 0x40000000 | *(uint *)(iVar5 + 0x28);
      *(uint *)(iVar5 + 0x16) =
           *(uint *)(iVar5 + 0x16) & 0xbfffffff |
           ((*(int *)(param_1 + 0x16) << 1) >> 0x1f & 1U) << 0x1e;
      iVar6 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(iVar6 + 4);
      *(undefined2 *)(param_3 + 6) = *(undefined2 *)(iVar6 + 6);
      *(undefined2 *)(param_3 + 8) = *(undefined2 *)(iVar6 + 8);
      *(undefined4 *)(param_3 + 0xe) = *(undefined4 *)(iVar6 + 0xe);
      *(byte *)(param_3 + 0x16) = *(byte *)(param_3 + 0x16) & 0x3f;
      *(undefined4 *)(param_3 + 0x12) = 0;
      *(undefined2 *)(iVar5 + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
      *(undefined *)(iVar5 + 0x15) = *(undefined *)(param_1 + 0x15);
      *(undefined2 *)(iVar5 + 0x30) = *(undefined2 *)(param_3 + 2);
      *(undefined2 *)(iVar5 + 0x32) = *(undefined2 *)(param_1 + 0x30);
      *(int *)(iVar5 + 0x42) = param_1;
      *(undefined4 *)(iVar5 + 0x4a) = *(undefined4 *)(param_1 + 0x46);
      if (*(int *)(param_1 + 0x46) != 0) {
        *(int *)(*(int *)(param_1 + 0x46) + 0x4e) = iVar5;
      }
      *(undefined4 *)(iVar5 + 0x4e) = 0;
      *(undefined4 *)(iVar5 + 0x46) = 0;
      *(int *)(param_1 + 0x46) = iVar5;
      *(undefined *)(iVar5 + 0x14) = 0;
      *(undefined *)(iVar5 + 0x12) = 0;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(iVar5 + 0x20) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(iVar5 + 0x7a) = 0;
      *(undefined4 *)(iVar5 + 0x7e) = 0;
      *(undefined2 *)(iVar5 + 0x34) = 0;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      *(undefined *)(iVar5 + 0x17) = 0;
      *(byte *)(iVar5 + 0x16) = *(byte *)(iVar5 + 0x16) & 0x7f;
      _pidhash_enter(iVar5);
      if (*(int *)(iVar8 + 0x156) != 0) {
        psVar3 = (sword *)(*(int *)(iVar8 + 0x156) + 6);
        *psVar3 = *psVar3 + 1;
      }
      if (*(int *)(iVar8 + 0x15a) != 0) {
        psVar3 = (sword *)(*(int *)(iVar8 + 0x15a) + 6);
        *psVar3 = *psVar3 + 1;
      }
      **(sword **)(iVar8 + 0x1a) = **(sword **)(iVar8 + 0x1a) + 1;
      *(word *)(param_1 + 0x2a) = *(word *)(param_1 + 0x2a) | 0x100;
      *(undefined4 *)(iVar5 + 0x72) = 0;
      *(undefined4 *)(iVar5 + 0x76) = 0;
      uVar7 = _procdup(iVar5,param_1);
      for (iVar8 = 0; iVar8 <= *(int *)(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x14e);
          iVar8 = iVar8 + 1) {
        iVar1 = *(int *)(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x146);
        iVar2 = *(int *)(iVar1 + iVar8 * 4);
        if (iVar2 != 0) {
          if (iVar2 == -0x10000) {
            *(undefined4 *)(iVar1 + iVar8 * 4) = 0;
          }
          else {
            *(sword *)(iVar2 + 0xe) = *(sword *)(iVar2 + 0xe) + 1;
          }
        }
      }
      _lock_init(*(int *)(*(int *)(iVar5 + 0x66) + 0x30) + 0x1e,1);
      _uarea_init(uVar7);
      *(undefined4 *)(param_3 + 10) = *(undefined4 *)(iVar6 + 10);
      *(int *)(iVar6 + 10) = iVar5;
      *(int *)(iVar5 + 8) = _allproc;
      *(int *)(_allproc + 0xc) = iVar5 + 8;
      *(int **)(iVar5 + 0xc) = &_allproc;
      _allproc = iVar5;
      *(undefined *)(iVar5 + 0x13) = 3;
      *(word *)(param_1 + 0x2a) = *(word *)(param_1 + 0x2a) & 0xfeff;
      return uVar7;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=122 start=0x40065f4 */

void _uzone_init(void)

{
  _u_task_zone = _zinit(0x28a,0x51400,0xa280,0,&aUtasks);
  _u_thread_zone = _zinit(0x14e,0x29c00,0x5380,0,aUthreads);
  return;
}
/* GHIDRADEC_FUNCTION index=123 start=0x4006646 */

void _utask_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x152);
  if (iVar1 != 0) {
    _kfree(*(undefined4 *)(param_1 + 0x146),iVar1 << 2);
    _kfree(*(undefined4 *)(param_1 + 0x14a),iVar1);
    *(undefined4 *)(param_1 + 0x152) = 0;
  }
  _zfree(_u_task_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=124 start=0x4006692 */

void _uthread_free(undefined4 param_1)

{
  _zfree(_u_thread_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=125 start=0x40066aa */

void _uarea_init(int param_1)

{
  *(int *)(*(int *)(param_1 + 0x80) + 0x24) = *(int *)(param_1 + 0x80) + 4;
  return;
}
/* GHIDRADEC_FUNCTION index=126 start=0x40066c2 */

void _uarea_zero(int param_1)

{
  _bzero(*(undefined4 *)(param_1 + 0x80),0x14e);
  return;
}
/* GHIDRADEC_FUNCTION index=127 start=0x40066dc */

void _utask_zero(int param_1)

{
  _bzero(*(undefined4 *)(param_1 + 0x30),0x28a);
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=128 start=0x4006700 */

void _switch_unix_context(int param_1)

{
  dword_40B57D4 = *(undefined4 *)(param_1 + 0x80);
  _active_u = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x30);
  return;
}
/* GHIDRADEC_FUNCTION index=129 start=0x4006720 */

void _sbrk(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=130 start=0x4006728 */

void _sstk(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=131 start=0x4006730 */

void _getpagesize(void)

{
  *(undefined4 *)(dword_40B57D4 + 0x5c) = _m68k_page_size;
  return;
}
/* GHIDRADEC_FUNCTION index=132 start=0x4006746 */

void _smmap(void)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  code *pcVar8;
  word wVar9;
  undefined uVar14;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uStack_10;
  uint uStack_c;
  int iStack_8;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  uStack_c = *puVar2;
  uVar3 = puVar2[1];
  uVar4 = puVar2[5];
  uVar5 = puVar2[2];
  uVar14 = _getvnodefp(puVar2[4],&iStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar14;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  if (*(sword *)(iStack_8 + 0xc) == 1) {
    piVar6 = *(int **)(iStack_8 + 0x16);
    uStack_c = ~_page_mask & uStack_c;
    uVar3 = ~_page_mask & uVar3 + _page_mask;
    if (((uVar5 & 2) == 0) || ((*(byte *)(iStack_8 + 0xb) & 2) != 0)) {
      if (((uVar5 & 1) == 0) || ((*(byte *)(iStack_8 + 0xb) & 1) != 0)) {
        uVar7 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
        iVar10 = _vm_map_check_protection(uVar7,uStack_c,uStack_c + uVar3,3);
        if (iVar10 != 0) {
          iVar10 = piVar6[10];
          if ((iVar10 == 4) || (iVar10 == 9)) {
            wVar9 = *(word *)(*(int *)((int)piVar6 + 0x2e) + 0x40);
            pcVar8 = (&off_40B0AE0)[(uint)(wVar9 >> 8) * 0xb];
            if ((pcVar8 == _nulldev) || ((pcVar8 == _nodev || (pcVar8 == (code *)0x0))))
            goto loc_4006A1C;
            iVar10 = 0;
            if (0 < (int)puVar2[1]) {
              do {
                iVar11 = (*pcVar8)((int)(sword)wVar9,iVar10 + uVar4,uVar5);
                if (iVar11 == -1) goto loc_4006A1C;
                iVar10 = _m68k_page_size + iVar10;
              } while (iVar10 < (int)puVar2[1]);
            }
            if ((puVar2[3] != 1) || (iVar10 = _vm_deallocate(uVar7,uStack_c,uVar3), iVar10 != 0))
            goto loc_4006A1C;
            uVar12 = _vm_object_special((int)(sword)wVar9,pcVar8,uVar5,uVar4,uVar3);
            iVar10 = _vm_map_find(uVar7,uVar12,0,&uStack_c,uVar3,0);
            if (iVar10 != 0) {
              _vm_object_deallocate(uVar12);
              goto loc_4006A1C;
            }
          }
          else {
            if (iVar10 != 1) goto loc_4006A1C;
            uVar12 = _vnode_pager_setup(piVar6,0,0);
            iVar10 = *piVar6;
            if (*(int *)(iVar10 + 0x2c) == 0) {
              **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
              *(undefined4 *)(iVar10 + 0x2c) = *(undefined4 *)(_active_u + 0x1a);
            }
            if (puVar2[3] == 1) {
              _vm_deallocate(uVar7,uStack_c,uVar3);
              iVar10 = _vm_allocate_with_pager(uVar7,&uStack_c,uVar3,0,uVar12,uVar4);
              if (iVar10 != 0) {
loc_40069B6:
                *(char *)(dword_40B57D4 + 100) = (char)iVar10;
                return;
              }
            }
            else {
              uVar13 = _pmap_create(uVar3,0,uVar3,1);
              uVar13 = _vm_map_create(uVar13);
              uStack_10 = 0;
              iVar10 = _vm_allocate_with_pager(uVar13,&uStack_10,uVar3,0,uVar12,uVar4);
              if ((iVar10 != 0) ||
                 (iVar10 = _vm_map_copy(uVar7,uVar13,uStack_c,uVar3,0,0,0), iVar10 != 0)) {
                _vm_map_deallocate(uVar13);
                goto loc_40069B6;
              }
              _vm_map_deallocate(uVar13);
            }
          }
          if ((((uVar5 & 2) != 0) || (iVar10 = _vm_protect(uVar7,uStack_c,uVar3,0,1), iVar10 == 0))
             && ((puVar2[3] != 1 || (iVar10 = _vm_inherit(uVar7,uStack_c,uVar3,0), iVar10 == 0)))) {
            pbVar1 = (byte *)(puVar2[4] + *(int *)(_active_u + 0x14a));
            *pbVar1 = *pbVar1 | 2;
            return;
          }
          _vm_deallocate(uVar7,uStack_c,uVar3);
        }
      }
loc_4006A1C:
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
  }
  *(undefined *)(dword_40B57D4 + 100) = 0x16;
  return;
}
/* GHIDRADEC_FUNCTION index=133 start=0x4006a48 */

void _mremap(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=134 start=0x4006a50 */

uint _munmap(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  uVar2 = (*(uint **)(dword_40B57D4 + 0x24))[1];
  uVar3 = _page_mask & uVar1;
  if ((uVar3 == 0) && (uVar3 = _page_mask & uVar2, uVar3 == 0)) {
    uVar3 = _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1,uVar2);
    if (uVar3 != 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=135 start=0x4006ab6 */

void _munmapfd(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + *(int *)(_active_u + 0x14a));
  *pbVar1 = *pbVar1 & 0xfd;
  return;
}
/* GHIDRADEC_FUNCTION index=136 start=0x4006ad2 */

void _mprotect(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=137 start=0x4006ada */

void _madvise(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=138 start=0x4006ae2 */

void _mincore(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=139 start=0x4006aea */

void _obreak(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_c;
  int iStack_8;
  
  uVar1 = ~_page_mask & _page_mask + **(int **)(dword_40B57D4 + 0x24);
  if (*(int *)(_active_u + 0x266) < (int)uVar1) {
    *(undefined *)(dword_40B57D4 + 100) = 0xc;
  }
  else {
    iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 8);
    _lock_write(iVar3);
    *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + 1;
    iVar2 = _vm_map_lookup_entry(iVar3,uVar1,&iStack_8);
    if (iVar2 == 0) {
      iStack_c = *(int *)(iStack_8 + 0xc);
      _lock_done(iVar3);
      iVar3 = _vm_allocate(iVar3,&iStack_c,uVar1 - iStack_c,0);
      if (iVar3 != 0) {
        _uprintf(aCouldNotSbrkRe,iVar3);
      }
    }
    else {
      _lock_done(iVar3);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=140 start=0x4006ba4 */

void _ovadvise(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=141 start=0x4006bac */

int _spgrp(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    do {
      iVar3 = iVar1;
      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffcdffff;
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(iVar3 + 0x46);
    } while (*(int *)(iVar3 + 0x46) != 0);
    while( true ) {
      if (param_1 == iVar3) {
        return iVar2;
      }
      iVar1 = *(int *)(iVar3 + 0x4a);
      if (*(int *)(iVar3 + 0x4a) != 0) break;
      iVar3 = *(int *)(iVar3 + 0x42);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=142 start=0x4006be0 */

undefined4 _inferior(int param_1)

{
  while( true ) {
    if (*_active_u == param_1) {
      return 1;
    }
    if (*(sword *)(param_1 + 0x32) == 0) break;
    param_1 = *(int *)(param_1 + 0x42);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=143 start=0x4006c0c */

int _pfind(uint param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(_pidhash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == (int)*(sword *)(iVar1 + 0x30)) break;
    iVar1 = *(int *)(iVar1 + 0x3e);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=144 start=0x4006c40 */

void _pidhash_enter(int param_1)

{
  uint uVar1;
  
  uVar1 = *(word *)(param_1 + 0x30) & 0x3f;
  *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(_pidhash + uVar1 * 4);
  *(int *)(_pidhash + uVar1 * 4) = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=145 start=0x4006c64 */

undefined4 _getproc(void)

{
  undefined4 uVar1;
  
  if (dword_40B317C < _max_proc) {
    dword_40B317C = dword_40B317C + 1;
    uVar1 = _zalloc(_proc_zone);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=146 start=0x4006c92 */

void _proc_cache_clear(void)

{
  int iVar1;
  
  iVar1 = _freeproc;
  while (iVar1 != 0) {
    dword_40B317C = dword_40B317C + -1;
    _freeproc = *(int *)(iVar1 + 8);
    _zfree(_proc_zone,iVar1);
    iVar1 = _freeproc;
  }
  _freeproc = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=147 start=0x4006cce */

void _pqinit(void)

{
  int iVar1;
  
  _proc_zone = _zinit(0x86,_max_proc * 0x3458,0,0,aProcStructures);
  dword_40B317C = 0;
  _freeproc = 0;
  iVar1 = _getproc();
  _bzero(iVar1,0x86);
  _allproc = iVar1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(int **)(iVar1 + 0xc) = &_allproc;
  _kernel_proc = iVar1;
  _zombproc = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=148 start=0x4006d4a */

undefined4 * _pgfind(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&_pgrphash)[param_1 & 0x3f];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (param_1 == puVar1[3]) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=149 start=0x4006d7a */

void _enterpgrp(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  
  puVar1 = (undefined4 *)_pgfind(param_2);
  iVar2 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_kalloc(0x14);
    if (param_3 == 0) {
      puVar1[2] = *(undefined4 *)(*(int *)(iVar2 + 0xe) + 8);
      *(int *)puVar1[2] = *(int *)puVar1[2] + 1;
    }
    else {
      puVar3 = (undefined4 *)_kalloc(0xe);
      puVar3[1] = param_1;
      *puVar3 = 1;
      puVar3[2] = 0;
      *(undefined2 *)(puVar3 + 3) = 0;
      *(byte *)(param_1 + 0x28) = *(byte *)(param_1 + 0x28) & 0xbf;
      puVar1[2] = puVar3;
    }
    puVar1[3] = param_2;
    *puVar1 = (&_pgrphash)[param_2 & 0x3f];
    (&_pgrphash)[param_2 & 0x3f] = puVar1;
    puVar1[4] = 0;
    puVar1[1] = 0;
  }
  else if (puVar1[3] == *(int *)(*(int *)(iVar2 + 0xe) + 0xc)) {
    return;
  }
  if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
    _fixjobc(param_1,puVar1,1);
    _fixjobc(param_1,*(undefined4 *)(iVar2 + 0xe),0);
  }
  piVar5 = (int *)(*(int *)(iVar2 + 0xe) + 4);
  while( true ) {
    if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aEnterpgrpCanTF);
    }
    if (param_1 == *piVar5) break;
    iVar4 = _get_posix_proc((int)*(sword *)(*piVar5 + 0x30));
    piVar5 = (int *)(iVar4 + 10);
  }
  *piVar5 = *(int *)(iVar2 + 10);
  if (*(int *)(*(int *)(iVar2 + 0xe) + 4) == 0) {
    _pgdelete(*(int *)(iVar2 + 0xe));
  }
  *(undefined4 **)(iVar2 + 0xe) = puVar1;
  *(undefined4 *)(iVar2 + 10) = puVar1[1];
  puVar1[1] = param_1;
  *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(*(int *)(iVar2 + 0xe) + 0xe);
  return;
}

