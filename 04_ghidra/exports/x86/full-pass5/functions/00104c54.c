/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104c54 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int _execve(char *param_1,char **param_2,char **param_3)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  byte bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  kern_return_t kVar13;
  char *pcVar14;
  char *pcVar15;
  int iVar16;
  int local_114;
  int local_10c;
  int local_f8;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_d8;
  vm_address_t local_d4;
  int local_d0;
  uint local_cc;
  undefined4 local_c8 [3];
  int *local_bc;
  undefined4 local_b8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  byte local_88;
  undefined1 local_84 [8];
  undefined4 local_7c;
  undefined4 local_78;
  char local_70 [32];
  char *local_50 [2];
  uint local_48;
  undefined1 local_44 [4];
  ushort local_40;
  short local_3e;
  short local_3c;
  
  puVar4 = (undefined4 *)DAT_001e875c[9];
  piVar5 = *(int **)(*(int *)(_active_threads + 0xc) + 0x38);
  iVar11 = _pn_get(*puVar4,0,local_50);
  if (iVar11 != 0) {
    local_10c._0_1_ = (undefined1)iVar11;
    *(undefined1 *)(DAT_001e875c + 0x1a) = (undefined1)local_10c;
    return iVar11;
  }
  local_10c = _lookuppn(local_50,1,0,&local_bc);
  if ((local_10c != 0) || (local_bc == (int *)0x0)) {
    _pn_free(local_50);
    goto LAB_001057cf;
  }
  local_f8 = 0;
  bVar9 = false;
  iVar11 = piVar5[7];
  sVar2 = *(short *)(iVar11 + 2);
  sVar3 = *(short *)(iVar11 + 4);
  local_10c = (**(code **)(local_bc[7] + 0x14))(local_bc,local_44,iVar11);
  if (local_10c == 0) {
    if ((*(byte *)(local_bc[9] + 0xc) & 8) == 0) {
      if ((local_40 & 0xc00) != 0) {
        iVar11 = _task_secure(*(undefined4 *)(_active_threads + 0xc));
        if (iVar11 == 0) {
          _uprintf(s__s__privileges_disabled_because_o_001da684,piVar5 + 2);
        }
        else {
          if ((local_40 & 0x800) != 0) {
            sVar2 = local_3e;
          }
          if ((local_40 & 0x400) != 0) {
            sVar3 = local_3c;
          }
        }
      }
    }
    else if ((local_40 & 0xc00) != 0) {
      local_10c = _pn_get(*puVar4,0,local_c8);
      if (local_10c != 0) goto LAB_0010578f;
      _uprintf(s__s__Setuid_execution_not_allowed_001da6c7,local_c8[0]);
      _pn_free(local_c8);
    }
    while (local_10c = _check_exec_access(local_bc), local_10c == 0) {
      local_b8 = local_b8 & 0xffffff00;
      local_10c = _vn_rdwr(0,local_bc,&local_b8,0x20,0,1,1,&local_cc);
      if (local_10c != 0) break;
      if ((0x18 < local_cc) && ((char)local_b8 != '#')) goto LAB_001052e2;
      if (local_b8 == 0xfeedface) {
        bVar10 = false;
LAB_0010501c:
        local_e0 = 0;
        local_e4 = 0;
        local_d8 = 0;
        local_f8 = _kmem_alloc_wait(_kernel_pageable_map,0xa000);
        local_e8 = 0xa000;
        iVar11 = local_f8;
        if (puVar4[1] != 0) goto LAB_00105074;
        goto LAB_00105240;
      }
      if ((local_b8 == 0xcafebabe) || (local_b8 == 0xbebafeca)) {
        bVar10 = true;
        goto LAB_0010501c;
      }
      if (local_b8 == 0xcefaedfe) {
        local_10c = 0x54;
        break;
      }
      if (((short)local_b8 != 0x2123) || (bVar9)) goto LAB_001052e2;
      for (pcVar14 = (char *)((int)&local_b8 + 2); pcVar14 < &local_98; pcVar14 = pcVar14 + 1) {
        if (*pcVar14 == '\t') {
          *pcVar14 = ' ';
        }
        else if (*pcVar14 == '\n') {
          *pcVar14 = '\0';
          break;
        }
      }
      if (*pcVar14 != '\0') goto LAB_001052e2;
      pcVar14 = (char *)((int)&local_b8 + 2);
      cVar1 = local_b8._2_1_;
      while (cVar1 == ' ') {
        pcVar14 = pcVar14 + 1;
        cVar1 = *pcVar14;
      }
      cVar1 = *pcVar14;
      pcVar15 = pcVar14;
      while ((cVar1 != '\0' && (*pcVar15 != ' '))) {
        pcVar15 = pcVar15 + 1;
        cVar1 = *pcVar15;
      }
      local_70[0] = '\0';
      if (*pcVar15 != '\0') {
        *pcVar15 = '\0';
        do {
          pcVar15 = pcVar15 + 1;
        } while (*pcVar15 == ' ');
        if (*pcVar15 != '\0') {
          _bcopy(pcVar15,local_70,0x20);
        }
      }
      bVar9 = true;
      _vn_rele(local_bc);
      local_bc = (int *)0x0;
      local_10c = _pn_set(local_50,pcVar14);
      if (((local_10c != 0) || (local_10c = _lookuppn(local_50,1,0,&local_bc), local_10c != 0)) ||
         (local_10c = (**(code **)(local_bc[7] + 0x14))
                                (local_bc,local_44,*(undefined4 *)(_active_u + 0x1c)),
         local_10c != 0)) break;
    }
  }
  goto LAB_0010578f;
LAB_00105074:
  pcVar15 = (char *)0x0;
  pcVar14 = (char *)0x0;
  if (bVar9) {
    if (local_e0 == 0) {
      puVar4[1] = puVar4[1] + 4;
      pcVar14 = local_50[0];
      pcVar15 = local_50[0];
    }
    else if ((local_e0 == 1) && (local_70[0] != '\0')) {
      pcVar14 = local_70;
      pcVar15 = pcVar14;
    }
    else {
      if ((!bVar9) || ((local_e0 != 1 && ((local_e0 != 2 || (local_70[0] == '\0'))))))
      goto LAB_001050e0;
      pcVar15 = (char *)*puVar4;
    }
  }
  else {
LAB_001050e0:
    if (puVar4[1] != 0) {
      pcVar15 = (char *)_fuword(puVar4[1]);
      puVar4[1] = puVar4[1] + 4;
      pcVar14 = (char *)0x0;
    }
  }
  if (pcVar15 == (char *)0x0) {
    if (puVar4[2] != 0) {
      puVar4[1] = 0;
      pcVar15 = (char *)_fuword(puVar4[2]);
      if (pcVar15 == (char *)0x0) goto LAB_00105240;
      puVar4[2] = puVar4[2] + 4;
      local_e4 = local_e4 + 1;
    }
    if (pcVar15 == (char *)0x0) goto LAB_00105240;
  }
  local_e0 = local_e0 + 1;
  if (pcVar15 != (char *)0xffffffff) {
    if (0x9ffe < local_d8) {
      local_10c = 7;
      goto LAB_0010578f;
    }
    do {
      if (pcVar14 == (char *)0x0) {
        local_10c = _copyinstr(pcVar15,iVar11,local_e8,&local_d0);
        pcVar15 = pcVar15 + local_d0;
      }
      else {
        local_10c = _copystr(pcVar14,iVar11,local_e8,&local_d0);
        pcVar14 = pcVar14 + local_d0;
      }
      iVar11 = iVar11 + local_d0;
      local_d8 = local_d8 + local_d0;
      local_e8 = local_e8 - local_d0;
      if (local_10c != 2) goto LAB_0010522b;
    } while (local_d8 < 0x9fff);
    local_10c = 7;
LAB_0010522b:
    if (local_10c != 0) goto LAB_0010578f;
    goto LAB_00105074;
  }
  local_10c = 0xe;
LAB_00105240:
  if (bVar10) {
    iVar11 = _fatfile_getarch(local_bc,&local_b8,local_84);
    if (iVar11 != 0) goto LAB_001054b5;
    local_10c = _vn_rdwr(0,local_bc,&local_b8,0x1c,local_7c,1,1,&local_cc);
    if (local_10c == 0) {
      if (local_cc == 0) {
        if (local_b8 == 0xfeedface) goto LAB_00105331;
LAB_001052e2:
        local_10c = 8;
      }
      else {
        local_10c = 0x53;
      }
    }
  }
  else {
    local_78 = *(undefined4 *)(*local_bc + 0x14);
    local_7c = 0;
LAB_00105331:
    iVar11 = _load_machfile(local_bc,&local_b8,local_7c,local_78,&local_98);
    if (iVar11 == 0) {
      if ((*(byte *)(*piVar5 + 0x28) & 0x10) == 0) {
        iVar12 = _get_posix_proc((int)*(short *)(*piVar5 + 0x30));
        _lock_write(_active_u + 0x20);
        iVar11 = piVar5[7];
        if ((sVar2 != *(short *)(iVar11 + 2)) || (sVar3 != *(short *)(iVar11 + 4))) {
          iVar11 = _crcopy(iVar11);
          piVar5[7] = iVar11;
        }
        *(short *)(piVar5[7] + 2) = sVar2;
        *(short *)(*piVar5 + 0x2c) = sVar2;
        *(short *)(piVar5[7] + 4) = sVar3;
        _lock_done(_active_u + 0x20);
        *(short *)(iVar12 + 8) = sVar3;
        *(undefined2 *)(iVar12 + 4) = *(undefined2 *)(piVar5[7] + 6);
        *(short *)(iVar12 + 6) = sVar2;
      }
      else {
        _exception_from_kernel(6,0,0);
      }
      local_d4 = 0;
      kVar13 = _vm_allocate(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),&local_d4,
                            _page_size,0);
      if (kVar13 == 0) {
        _vm_protect(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),0,_page_size,0,0);
      }
      if (local_10c == 0) {
        _vn_rele(local_bc);
        local_bc = (int *)0x0;
        if (((local_88 & 1) != 0) &&
           (iVar11 = _create_unix_stack(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),
                                        local_90), iVar11 != 0)) {
          iVar11 = 5;
          goto LAB_001054b5;
        }
        if ((local_88 & 1) != 0) {
          local_114 = (*(int *)(*piVar5 + 0x84) - (local_d8 + 3U & 0xfffffffc)) + -4;
          iVar11 = local_114 + local_e0 * -4 + -0xc;
          *(int *)(*DAT_001e875c + 0x44) = iVar11;
          _suword(iVar11,local_e0 - local_e4);
          local_e8 = 0xa000;
          iVar12 = local_f8;
          do {
            iVar16 = iVar11 + 4;
            if (local_e0 == local_e4) {
              _suword(iVar16,0);
              iVar16 = iVar11 + 8;
            }
            local_e0 = local_e0 + -1;
            if (local_e0 < 0) break;
            _suword(iVar16,local_114);
            do {
              local_10c = _copyoutstr(iVar12,local_114,local_e8,&local_d0);
              local_114 = local_114 + local_d0;
              iVar12 = iVar12 + local_d0;
              local_e8 = local_e8 - local_d0;
            } while (local_10c == 2);
            iVar11 = iVar16;
          } while (local_10c != 0xe);
          _suword(iVar16,0);
        }
        if ((local_88 & 2) != 0) {
          iVar11 = *(int *)(*DAT_001e875c + 0x44) + -4;
          *(int *)(*DAT_001e875c + 0x44) = iVar11;
          _suword(iVar11,local_98);
        }
        *(undefined4 *)(*DAT_001e875c + 0x38) = local_94;
        iVar11 = *piVar5;
        iVar12 = *(int *)(iVar11 + 0x24);
        while (iVar12 != 0) {
          uVar6 = *(uint *)(iVar11 + 0x24);
          iVar12 = 0;
          if (uVar6 != 0) {
            for (; (uVar6 >> iVar12 & 1) == 0; iVar12 = iVar12 + 1) {
            }
          }
          if (uVar6 == 0) {
            iVar12 = -1;
          }
          bVar8 = (byte)iVar12 & 0x1f;
          *(uint *)(iVar11 + 0x24) = uVar6 & (-2 << bVar8 | 0xfffffffeU >> 0x20 - bVar8);
          piVar5[iVar12 + 0xd] = 0;
          iVar11 = *piVar5;
          iVar12 = *(int *)(iVar11 + 0x24);
        }
        piVar5[0x53] = 0;
        piVar5[0x52] = 0;
        piVar5[0x4f] = 0;
        piVar5[0x50] = 0;
        for (iVar11 = piVar5[0x56]; -1 < iVar11; iVar11 = iVar11 + -1) {
          if ((*(byte *)(iVar11 + piVar5[0x55]) & 1) != 0) {
            uVar7 = *(undefined4 *)(piVar5[0x54] + iVar11 * 4);
            _vno_lockrelease(uVar7);
            _closef(uVar7);
            *(undefined4 *)(piVar5[0x54] + iVar11 * 4) = 0;
            *(undefined1 *)(iVar11 + piVar5[0x55]) = 0;
          }
          *(byte *)(iVar11 + piVar5[0x55]) = *(byte *)(iVar11 + piVar5[0x55]) & 0xfd;
        }
        iVar11 = piVar5[0x56];
        if (-1 < iVar11) {
          iVar12 = *(int *)(piVar5[0x54] + iVar11 * 4);
          while (iVar12 == 0) {
            piVar5[0x56] = iVar11 + -1;
            iVar11 = iVar11 + -1;
            if (iVar11 < 0) break;
            iVar12 = *(int *)(piVar5[0x54] + iVar11 * 4);
          }
        }
        *(undefined1 *)((int)DAT_001e875c + 0x69) = 1;
        *(byte *)(piVar5 + 0x91) = *(byte *)(piVar5 + 0x91) & 0xfe;
        if (0x10 < local_48) {
          local_48 = 0x10;
        }
        _bcopy(local_50[0],piVar5 + 2,local_48 + 1);
        *(uint *)(*piVar5 + 0x28) = *(uint *)(*piVar5 + 0x28) | 0x80000000;
      }
    }
    else {
LAB_001054b5:
      local_10c = FUN_00105a3c(iVar11);
    }
  }
LAB_0010578f:
  _pn_free(local_50);
  if (local_f8 != 0) {
    _kmem_free_wakeup(_kernel_pageable_map,local_f8,0xa000);
  }
  if (local_bc != (int *)0x0) {
    _vn_rele(local_bc);
  }
LAB_001057cf:
  *(undefined1 *)(DAT_001e875c + 0x1a) = (undefined1)local_10c;
  return local_10c;
}

