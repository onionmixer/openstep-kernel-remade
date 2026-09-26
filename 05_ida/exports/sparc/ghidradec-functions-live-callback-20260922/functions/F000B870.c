
/* WARNING: Removing unreachable block (ram,0xf000c360) */
/* WARNING: Removing unreachable block (ram,0xf000bc6c) */
/* WARNING: Removing unreachable block (ram,0xf000bc3c) */
/* WARNING: Removing unreachable block (ram,0xf000c324) */
/* WARNING: Removing unreachable block (ram,0xf000c27c) */
/* WARNING: Removing unreachable block (ram,0xf000c1bc) */
/* WARNING: Removing unreachable block (ram,0xf000c174) */
/* WARNING: Removing unreachable block (ram,0xf000c13c) */
/* WARNING: Removing unreachable block (ram,0xf000c09c) */
/* WARNING: Removing unreachable block (ram,0xf000c064) */
/* WARNING: Removing unreachable block (ram,0xf000c024) */
/* WARNING: Removing unreachable block (ram,0xf000bfd4) */
/* WARNING: Removing unreachable block (ram,0xf000bf78) */
/* WARNING: Removing unreachable block (ram,0xf000bf3c) */
/* WARNING: Removing unreachable block (ram,0xf000bea0) */
/* WARNING: Removing unreachable block (ram,0xf000be38) */
/* WARNING: Removing unreachable block (ram,0xf000bd94) */
/* WARNING: Removing unreachable block (ram,0xf000ba00) */
/* WARNING: Removing unreachable block (ram,0xf000b97c) */
/* WARNING: Removing unreachable block (ram,0xf000b9c0) */
/* WARNING: Removing unreachable block (ram,0xf000b9a0) */
/* WARNING: Removing unreachable block (ram,0xf000b8bc) */
/* WARNING: Removing unreachable block (ram,0xf000b8dc) */
/* WARNING: Removing unreachable block (ram,0xf000b9b8) */
/* WARNING: Removing unreachable block (ram,0xf000b940) */
/* WARNING: Removing unreachable block (ram,0xf000b9c8) */
/* WARNING: Removing unreachable block (ram,0xf000bcc8) */
/* WARNING: Removing unreachable block (ram,0xf000bdc8) */
/* WARNING: Removing unreachable block (ram,0xf000be14) */
/* WARNING: Removing unreachable block (ram,0xf000bed4) */
/* WARNING: Removing unreachable block (ram,0xf000bf64) */
/* WARNING: Removing unreachable block (ram,0xf000bfa4) */
/* WARNING: Removing unreachable block (ram,0xf000bffc) */
/* WARNING: Removing unreachable block (ram,0xf000c050) */
/* WARNING: Removing unreachable block (ram,0xf000c088) */
/* WARNING: Removing unreachable block (ram,0xf000c0e4) */
/* WARNING: Removing unreachable block (ram,0xf000c15c) */
/* WARNING: Removing unreachable block (ram,0xf000c188) */
/* WARNING: Removing unreachable block (ram,0xf000c208) */
/* WARNING: Removing unreachable block (ram,0xf000c284) */
/* WARNING: Removing unreachable block (ram,0xf000bc30) */
/* WARNING: Removing unreachable block (ram,0xf000bc50) */
/* WARNING: Removing unreachable block (ram,0xf000c340) */
/* WARNING: Removing unreachable block (ram,0xf000c378) */
/* WARNING: Removing unreachable block (ram,0xf000b89c) */

undefined8 _execve(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  code *pcVar11;
  undefined4 uVar12;
  undefined4 unaff_l0;
  int *piVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 unaff_l1;
  int *piVar16;
  int iVar17;
  undefined4 unaff_l3;
  int iVar18;
  undefined4 unaff_l4;
  int iVar19;
  int iVar20;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int *piVar21;
  undefined4 unaff_l7;
  int *piVar22;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar23;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  sword sVar24;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar25;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  char acStack_c6 [198];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar22 = (int *)dword_F0133DDC[9];
  piVar21 = *(int **)(*(int *)(_active_threads + 0xc) + 0x38);
  piVar13 = (int *)((int)register0x00000038 + -0x58);
  piVar3 = (int *)*piVar22;
  _pn_get(piVar3,0,piVar13);
  if (piVar3 != (int *)0x0) goto loc_F000C388;
  piVar3 = piVar13;
  _lookuppn(piVar13,1,0,(undefined *)((int)register0x00000038 + -0xcc));
  piVar4 = *(int **)((int)register0x00000038 + -0xcc);
  if ((piVar3 != (int *)0x0) || (piVar4 == (int *)0x0)) {
    _pn_free(piVar13);
    goto loc_F000C388;
  }
  iVar8 = piVar21[7];
  iVar10 = piVar4[7];
  *(undefined4 *)((int)register0x00000038 + -0x114) = 0;
  sVar24 = *(sword *)(iVar8 + 2);
  param_2 = 0;
  pcVar11 = *(code **)(iVar10 + 0x14);
  *(int *)((int)register0x00000038 + -0x10c) = (int)*(sword *)(iVar8 + 4);
  (*pcVar11)(piVar4,(undefined *)((int)register0x00000038 + -0x48));
  piVar3 = piVar4;
  if (piVar4 == (int *)0x0) {
    if ((*(uint *)(*(int *)(*(int *)((int)register0x00000038 + -0xcc) + 0x24) + 0xc) & 8) == 0) {
      if ((*(word *)((int)register0x00000038 + -0x44) & 0xc00) != 0) {
        iVar8 = *(int *)(_active_threads + 0xc);
        _task_secure();
        if (iVar8 == 0) {
          _uprintf(aSPrivilegesDis,piVar21 + 2);
        }
        else {
          if ((*(word *)((int)register0x00000038 + -0x44) & 0x800) != 0) {
            sVar24 = *(sword *)((int)register0x00000038 + -0x42);
          }
          if ((*(word *)((int)register0x00000038 + -0x44) & 0x400) != 0) {
            *(int *)((int)register0x00000038 + -0x10c) =
                 (int)*(sword *)((int)register0x00000038 + -0x40);
          }
        }
      }
    }
    else if ((*(uint *)((int)register0x00000038 + -0x44) & 0xc000000) != 0) {
      piVar3 = (int *)*piVar22;
      _pn_get(piVar3,0,(undefined *)((int)register0x00000038 + -0xe0));
      if (piVar3 != (int *)0x0) goto loc_F000C340;
      _uprintf(aSSetuidExecuti,*(undefined4 *)((int)register0x00000038 + -0xe0));
      _pn_free((undefined *)((int)register0x00000038 + -0xe0));
    }
    while( true ) {
      piVar3 = *(int **)((int)register0x00000038 + -0xcc);
      _check_exec_access();
      piVar13 = (int *)0x0;
      if (piVar3 != (int *)0x0) break;
      *(undefined *)((int)register0x00000038 + -200) = 0;
      _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0xcc),
               (undefined *)((int)register0x00000038 + -200),0x20,0,1,1,
               (undefined *)((int)register0x00000038 + -0xe4));
      piVar3 = piVar13;
      if (piVar13 != (int *)0x0) break;
      if ((0x18 < *(uint *)((int)register0x00000038 + -0xe4)) &&
         (*(char *)((int)register0x00000038 + -200) != '#')) {
        piVar3 = (int *)0x8;
        break;
      }
      uVar7 = *(uint *)((int)register0x00000038 + -200);
      piVar4 = (int *)((int)register0x00000038 + -200);
      *(int **)((int)register0x00000038 + -0x124) = piVar4;
      if (uVar7 == 0xfeedface) {
        *(undefined4 *)((int)register0x00000038 + -0x11c) = 0;
loc_F000BCB4:
        iVar8 = 0;
        iVar23 = 0;
        iVar18 = 0;
        uVar9 = _kernel_pageable_map;
        _kmem_alloc_wait(_kernel_pageable_map,0xa000);
        *(undefined4 *)((int)register0x00000038 + -0x114) = uVar9;
        iVar19 = 0xa000;
        iVar10 = *(int *)((int)register0x00000038 + -0x114);
        if (piVar22[1] == 0) goto loc_F000BE84;
        goto loc_F000BCF4;
      }
      if ((uVar7 == 0xcafebabe) ||
         (*(undefined4 *)((int)register0x00000038 + -0x100) = 0xcafebabe,
         uVar7 == ((uint)*(byte *)((int)register0x00000038 + -0xfd) << 0x18 |
                   (uint)*(byte *)((int)register0x00000038 + -0xfe) << 0x10 |
                   (uint)*(byte *)((int)register0x00000038 + -0xff) << 8 |
                  (uint)*(byte *)((int)register0x00000038 + -0x100)))) {
        *(undefined4 *)((int)register0x00000038 + -0x11c) = 1;
        goto loc_F000BCB4;
      }
      *(undefined4 *)((int)register0x00000038 + -0x100) = 0xfeedface;
      if (uVar7 == ((uint)*(byte *)((int)register0x00000038 + -0xfd) << 0x18 |
                    (uint)*(byte *)((int)register0x00000038 + -0xfe) << 0x10 |
                    (uint)*(byte *)((int)register0x00000038 + -0xff) << 8 |
                   (uint)*(byte *)((int)register0x00000038 + -0x100))) {
        piVar3 = (int *)0x54;
        break;
      }
      piVar3 = (int *)0x8;
      if (((uVar7 & 0xffff0000) != 0x23210000) ||
         (pcVar14 = (char *)((int)register0x00000038 + -0xc6), param_2 != 0)) break;
      if (pcVar14 < (char *)((int)register0x00000038 + -0xa8)) {
        cVar1 = *pcVar14;
loc_F000BB60:
        if (cVar1 == '\t') {
          *pcVar14 = ' ';
loc_F000BB84:
          pcVar14 = pcVar14 + 1;
          if ((char *)((int)register0x00000038 + -0xa8) <= pcVar14) goto loc_F000BB90;
          cVar1 = *pcVar14;
          goto loc_F000BB60;
        }
        if (cVar1 != '\n') goto loc_F000BB84;
        *pcVar14 = '\0';
loc_F000BB90:
        cVar1 = *pcVar14;
      }
      else {
        cVar1 = *pcVar14;
      }
      piVar3 = (int *)0x8;
      if (cVar1 != '\0') break;
      pcVar14 = (char *)((int)register0x00000038 + -0xc6);
      if (*(char *)((int)register0x00000038 + -0xc6) == ' ') {
        for (pcVar14 = (char *)((int)register0x00000038 + -0xc5); *pcVar14 == ' ';
            pcVar14 = pcVar14 + 1) {
        }
      }
      cVar1 = *pcVar14;
      pcVar15 = pcVar14;
      while (cVar1 != '\0') {
        if (*pcVar15 == ' ') {
          *(undefined *)((int)register0x00000038 + -0x78) = 0;
          goto loc_F000BBF4;
        }
        pcVar15 = pcVar15 + 1;
        cVar1 = *pcVar15;
      }
      *(undefined *)((int)register0x00000038 + -0x78) = 0;
loc_F000BBF4:
      uVar9 = *(undefined4 *)((int)register0x00000038 + -0xcc);
      if (*pcVar15 != '\0') {
        *pcVar15 = '\0';
        do {
          pcVar15 = pcVar15 + 1;
        } while (*pcVar15 == ' ');
        if (*pcVar15 != '\0') {
          _bcopy(pcVar15,(undefined *)((int)register0x00000038 + -0x78),0x20);
        }
        uVar9 = *(undefined4 *)((int)register0x00000038 + -0xcc);
      }
      param_2 = 1;
      _vn_rele(uVar9);
      *(undefined4 *)((int)register0x00000038 + -0xcc) = 0;
      piVar13 = (int *)((int)register0x00000038 + -0x58);
      piVar3 = piVar13;
      _pn_set(piVar13,pcVar14);
      if ((piVar3 != (int *)0x0) ||
         (_lookuppn(piVar13,1,0,(undefined *)((int)register0x00000038 + -0xcc)), piVar3 = piVar13,
         piVar13 != (int *)0x0)) break;
      piVar3 = *(int **)((int)register0x00000038 + -0xcc);
      (**(code **)(piVar3[7] + 0x14))
                (piVar3,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(_active_u + 0x1c));
      if (piVar3 != (int *)0x0) break;
    }
  }
  goto loc_F000C340;
loc_F000BCF4:
  piVar3 = (int *)0x0;
  if ((param_2 == 0) || (iVar8 != 0)) {
    if ((param_2 == 0) || ((iVar8 != 1 || (*(char *)((int)register0x00000038 + -0x78) == '\0')))) {
      if (param_2 == 0) {
        piVar5 = (int *)piVar22[1];
      }
      else {
        if (iVar8 == 1) {
loc_F000BD7C:
          piVar16 = (int *)*piVar22;
          goto loc_F000BDB0;
        }
        if (iVar8 == 2) {
          if (*(char *)((int)register0x00000038 + -0x78) != '\0') goto loc_F000BD7C;
          piVar5 = (int *)piVar22[1];
        }
        else {
          piVar5 = (int *)piVar22[1];
        }
      }
      piVar16 = (int *)0x0;
      if (piVar5 != (int *)0x0) {
        _fuword();
        piVar22[1] = piVar22[1] + 4;
        piVar16 = piVar5;
      }
    }
    else {
      piVar3 = (int *)((int)register0x00000038 + -0x78);
      piVar16 = piVar3;
    }
  }
  else {
    piVar3 = *(int **)((int)register0x00000038 + -0x58);
    piVar22[1] = piVar22[1] + 4;
    piVar16 = piVar3;
  }
loc_F000BDB0:
  bVar25 = piVar16 == (int *)0x0;
  if (piVar16 == (int *)0x0) {
    piVar5 = (int *)piVar22[2];
    bVar25 = true;
    if (piVar5 != (int *)0x0) {
      piVar22[1] = 0;
      _fuword();
      if (piVar5 == (int *)0x0) goto loc_F000BE84;
      iVar23 = iVar23 + 1;
      piVar22[2] = piVar22[2] + 4;
      bVar25 = false;
      piVar16 = piVar5;
    }
  }
  if (bVar25) goto loc_F000BE84;
  iVar8 = iVar8 + 1;
  if (piVar16 != (int *)0xffffffff) {
    do {
      if (0x9ffe < iVar18) {
        piVar13 = (int *)0x7;
        break;
      }
      if (piVar3 == (int *)0x0) {
        piVar13 = piVar16;
        _copyinstr(piVar16,iVar10,iVar19,(undefined *)((int)register0x00000038 + -0x104));
        piVar16 = (int *)((int)piVar16 + *(int *)((int)register0x00000038 + -0x104));
      }
      else {
        piVar13 = piVar3;
        _copystr(piVar3,iVar10,iVar19,(undefined *)((int)register0x00000038 + -0x104));
        piVar3 = (int *)((int)piVar3 + *(int *)((int)register0x00000038 + -0x104));
      }
      iVar20 = *(int *)((int)register0x00000038 + -0x104);
      iVar10 = iVar10 + iVar20;
      iVar18 = iVar18 + iVar20;
      iVar19 = iVar19 - iVar20;
    } while (piVar13 == (int *)0x2);
    piVar3 = piVar13;
    if (piVar13 != (int *)0x0) goto loc_F000C340;
    goto loc_F000BCF4;
  }
  piVar13 = (int *)0xe;
loc_F000BE84:
  uVar7 = iVar18 + 3U & 0xfffffffc;
  if (*(int *)((int)register0x00000038 + -0x11c) == 0) {
    piVar3 = *(int **)((int)register0x00000038 + -0xcc);
    uVar9 = 0;
    uVar12 = *(undefined4 *)(*piVar3 + 0x14);
loc_F000BF3C:
    _load_machfile(piVar3,piVar4,uVar9,uVar12,(undefined *)((int)register0x00000038 + -0xa8));
    if (piVar3 == (int *)0x0) {
      if ((*(uint *)(*piVar21 + 0x28) & 0x10) == 0) {
        iVar10 = (int)*(sword *)(*piVar21 + 0x30);
        _get_posix_proc();
        _lock_write(_active_u + 0x20);
        iVar18 = piVar21[7];
        if ((sVar24 == *(sword *)(iVar18 + 2)) &&
           (*(int *)((int)register0x00000038 + -0x10c) == (int)*(sword *)(iVar18 + 4))) {
          iVar18 = piVar21[7];
        }
        else {
          _crcopy();
          piVar21[7] = iVar18;
          iVar18 = piVar21[7];
        }
        *(sword *)(iVar18 + 2) = sVar24;
        uVar2 = *(undefined2 *)((int)register0x00000038 + -0x10a);
        *(sword *)(*piVar21 + 0x2c) = sVar24;
        *(undefined2 *)(piVar21[7] + 4) = uVar2;
        _lock_done(_active_u + 0x20);
        *(undefined2 *)(iVar10 + 8) = *(undefined2 *)((int)register0x00000038 + -0x10a);
        *(undefined2 *)(iVar10 + 4) = *(undefined2 *)(piVar21[7] + 6);
        *(sword *)(iVar10 + 6) = sVar24;
      }
      else {
        _exception_from_kernel(6,0,0);
      }
      *(undefined4 *)((int)register0x00000038 + -0x108) = 0;
      iVar10 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
      _vm_allocate(iVar10,(undefined *)((int)register0x00000038 + -0x108),_page_size,0);
      if (iVar10 == 0) {
        _vm_protect(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),0,_page_size,0,0);
      }
      piVar3 = piVar13;
      if (piVar13 == (int *)0x0) {
        _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xcc));
        *(undefined4 *)((int)register0x00000038 + -0xcc) = 0;
        if (*(int *)((int)register0x00000038 + -0x98) < 0) {
          iVar10 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
          _create_unix_stack(iVar10,*(undefined4 *)((int)register0x00000038 + -0xa0));
          piVar3 = (int *)0x5;
          if (iVar10 != 0) goto loc_F000C09C;
        }
        if ((int)*(uint *)((int)register0x00000038 + -0x98) < 0) {
          if ((*(uint *)((int)register0x00000038 + -0x98) & 0x40000000) == 0) {
            iVar10 = *(int *)(*piVar21 + 0x84) - (uVar7 + iVar8 * 4 + 0x17 & 0xfffffff8);
            *(int *)(*dword_F0133DDC + 0x44) = iVar10 + -0x40;
          }
          else {
            iVar18 = *(int *)(*piVar21 + 0x84) - (uVar7 + iVar8 * 4 + 0x1b & 0xfffffff8);
            _suword(iVar18,*(undefined4 *)((int)register0x00000038 + -0xa8));
            iVar10 = iVar18 + 4;
            *(int *)(*dword_F0133DDC + 0x44) = iVar18 + -0x40;
          }
          iVar19 = iVar10 + iVar8 * 4 + 0xc;
          _suword(iVar10,iVar8 - iVar23);
          piVar3 = *(int **)((int)register0x00000038 + -0x114);
          iVar20 = 0xa000;
          iVar18 = iVar8 - iVar23;
          do {
            iVar17 = iVar10 + 4;
            if (iVar18 == 0) {
              _suword(iVar17,0);
              iVar17 = iVar10 + 8;
            }
            iVar8 = iVar8 + -1;
            if (iVar8 < 0) break;
            _suword(iVar17,iVar19);
            do {
              piVar13 = piVar3;
              _copyoutstr(piVar3,iVar19,iVar20,(undefined *)((int)register0x00000038 + -0x104));
              iVar10 = *(int *)((int)register0x00000038 + -0x104);
              iVar19 = iVar19 + iVar10;
              piVar3 = (int *)((int)piVar3 + iVar10);
              iVar20 = iVar20 - iVar10;
            } while (piVar13 == (int *)0x2);
            iVar18 = iVar8 - iVar23;
            iVar10 = iVar17;
          } while (piVar13 != (int *)0xe);
          _suword(iVar17,0);
        }
        *(undefined4 *)(*dword_F0133DDC + 4) = *(undefined4 *)((int)register0x00000038 + -0xa4);
        *(int *)(*dword_F0133DDC + 8) = *(int *)((int)register0x00000038 + -0xa4) + 4;
        iVar8 = *piVar21;
        if (*(int *)(iVar8 + 0x24) == 0) {
          piVar21[0x52] = 0;
        }
        else {
          uVar7 = *(uint *)(iVar8 + 0x24);
          while( true ) {
            uVar6 = uVar7;
            _ffs();
            *(uint *)(iVar8 + 0x24) = uVar7 & ~(1 << ((char)uVar6 - 1U & 0x1f));
            piVar21[uVar6 + 0xc] = 0;
            iVar8 = *piVar21;
            if (*(int *)(iVar8 + 0x24) == 0) break;
            uVar7 = *(uint *)(iVar8 + 0x24);
          }
          piVar21[0x52] = 0;
        }
        piVar21[0x51] = 0;
        piVar21[0x4e] = 0;
        iVar8 = piVar21[0x55];
        piVar21[0x4f] = 0;
        if (-1 < iVar8) {
          iVar10 = piVar21[0x54];
          while( true ) {
            if ((*(byte *)(iVar10 + iVar8) & 1) != 0) {
              uVar9 = *(undefined4 *)(piVar21[0x53] + iVar8 * 4);
              _vno_lockrelease(uVar9);
              _closef(uVar9);
              *(undefined4 *)(piVar21[0x53] + iVar8 * 4) = 0;
              *(undefined *)(piVar21[0x54] + iVar8) = 0;
            }
            *(byte *)(piVar21[0x54] + iVar8) = *(byte *)(piVar21[0x54] + iVar8) & 0xfd;
            iVar8 = iVar8 + -1;
            if (iVar8 < 0) break;
            iVar10 = piVar21[0x54];
          }
        }
        iVar8 = piVar21[0x55];
        while ((-1 < iVar8 && (*(int *)(piVar21[0x53] + iVar8 * 4) == 0))) {
          iVar8 = iVar8 + -1;
          piVar21[0x55] = iVar8;
        }
        *(undefined *)((int)dword_F0133DDC + 0x39) = 1;
        *(word *)(piVar21 + 0x90) = *(word *)(piVar21 + 0x90) & 0xfffe;
        if (*(uint *)((int)register0x00000038 + -0x50) < 0x11) {
          iVar8 = *(int *)((int)register0x00000038 + -0x50);
        }
        else {
          *(undefined4 *)((int)register0x00000038 + -0x50) = 0x10;
          iVar8 = *(int *)((int)register0x00000038 + -0x50);
        }
        _bcopy(*(undefined4 *)((int)register0x00000038 + -0x58),piVar21 + 2,iVar8 + 1);
        *(uint *)(*piVar21 + 0x28) = *(uint *)(*piVar21 + 0x28) | 0x80000000;
        piVar3 = piVar13;
      }
    }
    else {
loc_F000C09C:
      sub_F000C670();
    }
  }
  else {
    piVar3 = *(int **)((int)register0x00000038 + -0xcc);
    _fatfile_getarch(piVar3,*(undefined4 *)((int)register0x00000038 + -0x124),
                     (undefined *)((int)register0x00000038 + -0x90));
    if (piVar3 != (int *)0x0) goto loc_F000C09C;
    piVar13 = (int *)0x0;
    _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0xcc),
             (undefined *)((int)register0x00000038 + -200),0x1c,
             *(undefined4 *)((int)register0x00000038 + -0x88),1,1,
             (undefined *)((int)register0x00000038 + -0xe4));
    piVar3 = piVar13;
    if (piVar13 == (int *)0x0) {
      if (*(int *)((int)register0x00000038 + -0xe4) == 0) {
        piVar3 = *(int **)((int)register0x00000038 + -0xcc);
        if (*piVar4 == -0x1120532) {
          uVar9 = *(undefined4 *)((int)register0x00000038 + -0x88);
          uVar12 = *(undefined4 *)((int)register0x00000038 + -0x84);
          goto loc_F000BF3C;
        }
        piVar3 = (int *)0x8;
      }
      else {
        piVar3 = (int *)0x53;
      }
    }
  }
loc_F000C340:
  _pn_free((undefined *)((int)register0x00000038 + -0x58));
  if (*(int *)((int)register0x00000038 + -0x114) != 0) {
    _kmem_free_wakeup(_kernel_pageable_map,*(undefined4 *)((int)register0x00000038 + -0x114),0xa000)
    ;
  }
  if (*(int *)((int)register0x00000038 + -0xcc) != 0) {
    _vn_rele();
  }
loc_F000C388:
  *(char *)(dword_F0133DDC + 0xe) = (char)piVar3;
  return CONCAT44(param_2,piVar3);
}

