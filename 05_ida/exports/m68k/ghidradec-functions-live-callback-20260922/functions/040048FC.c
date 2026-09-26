
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

