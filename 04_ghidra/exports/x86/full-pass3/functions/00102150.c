/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102150 */

void _table(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 *puVar11;
  uint local_d0;
  int *local_cc;
  int local_c0;
  int local_bc;
  undefined1 local_b4 [6];
  undefined2 local_ae;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  char local_98 [8];
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64 [16];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [16];
  undefined1 local_28;
  int local_24 [3];
  undefined4 local_18;
  int local_14 [4];
  
  piVar2 = *(int **)(DAT_001e875c + 0x24);
  local_bc = 0;
  local_c0 = 0;
  if (piVar2[3] < 0) {
    iVar5 = _machine_table_setokay(*piVar2);
    if (((iVar5 == 0) || (iVar5 < 1)) || (iVar5 != 1)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return;
    }
    local_c0 = 1;
    piVar2[3] = -piVar2[3];
  }
  *(undefined4 *)(DAT_001e875c + 0x60) = 0;
  if ((*piVar2 == 1) &&
     (((piVar2[1] != (int)*(short *)(*_active_u + 0x30) && (piVar2[1] != 0)) || (piVar2[3] != 1))))
  {
switchD_001022a2_caseD_4:
    if (*(int *)(DAT_001e875c + 0x60) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    }
  }
  else {
    while (0 < piVar2[3]) {
      local_cc = (int *)0x0;
      local_d0 = 0;
      iVar5 = _machine_table(*piVar2,piVar2[1],piVar2[2],piVar2[3],piVar2[4],local_c0);
      if (iVar5 != 0) {
        if ((0 < iVar5) && (iVar5 == 1)) goto LAB_001028df;
        goto switchD_001022a2_caseD_4;
      }
      switch(*piVar2) {
      case 1:
        if (_active_u[0x5a] == 0) {
          local_ae = 0xffff;
          piVar9 = (int *)&local_ae;
        }
        else {
          piVar9 = _active_u + 0x5b;
        }
        uVar8 = 2;
        break;
      case 2:
        iVar5 = _pfind(piVar2[1]);
        if (iVar5 == 0) {
LAB_001021ac:
          *(undefined1 *)(DAT_001e875c + 0x68) = 3;
          return;
        }
        piVar9 = *(int **)(iVar5 + 0x68);
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar5 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        if (piVar9[9] < 1) {
          LOCK();
          *piVar9 = 0;
          UNLOCK();
          goto LAB_001021ac;
        }
        iVar5 = piVar9[7];
        _thread_reference(iVar5);
        LOCK();
        *piVar9 = 0;
        UNLOCK();
        piVar9 = (int *)_kmem_alloc_wait(_kernel_pageable_map,_page_mask + 0x800 & ~_page_mask);
        _fake_u(piVar9,iVar5);
        _thread_deallocate(iVar5);
        uVar8 = 0x800;
        local_d0 = (_page_mask + 0x800 & ~_page_mask) + (int)piVar9;
        local_cc = piVar9;
        break;
      case 3:
        if ((piVar2[1] == 0) && (piVar2[3] == 1)) {
          puVar11 = &_avenrun;
          goto LAB_00102671;
        }
      default:
        goto switchD_001022a2_caseD_4;
      case 5:
        piVar9 = local_14;
        iVar5 = _table_fsparam(piVar2[1],piVar9);
        if (iVar5 == 0) goto switchD_001022a2_caseD_4;
        uVar8 = 0x10;
        break;
      case 6:
        iVar5 = _pfind(piVar2[1]);
        if (iVar5 == 0) goto LAB_001021ac;
        uVar3 = *(undefined4 *)(*(int *)(iVar5 + 0x68) + 0xc);
        uVar8 = piVar2[4];
        if ((uVar8 == 0) || (iVar5 = *(int *)(iVar5 + 0x84), iVar5 == 0))
        goto switchD_001022a2_caseD_4;
        _vm_map_reference(uVar3);
        local_cc = (int *)_kmem_alloc_wait(_kernel_pageable_map,uVar8 + _page_mask & ~_page_mask);
        uVar7 = ~_page_mask;
        local_d0 = (int)local_cc + _page_mask + uVar8 & uVar7;
        iVar5 = _vm_map_copy(_kernel_pageable_map,uVar3,local_cc,_page_mask + uVar8 & uVar7,
                             iVar5 - uVar8 & uVar7,0,0);
        if (iVar5 != 0) {
          _kmem_free_wakeup(_kernel_pageable_map,local_cc,uVar8 + _page_mask & ~_page_mask);
          _vm_map_deallocate(uVar3);
          goto switchD_001022a2_caseD_4;
        }
        _vm_map_deallocate(uVar3);
        piVar9 = (int *)(local_d0 - uVar8);
        piVar6 = (int *)(local_d0 - 0xc);
        iVar5 = *(int *)(local_d0 - 0xc);
        while ((iVar5 != 0 && (piVar6 != piVar9))) {
          piVar6 = piVar6 + -1;
          iVar5 = *piVar6;
        }
        _bzero(piVar9,(int)piVar6 - (int)piVar9);
        break;
      case 10:
        if (piVar2[1] < 0) {
          piVar2[1] = -piVar2[1];
        }
        iVar5 = _pfind(piVar2[1]);
        if (iVar5 == 0) goto LAB_001021ac;
        if (*(char *)(iVar5 + 0x13) == '\0') {
          _bzero(&local_54,0x30);
          local_40 = 0;
        }
        else {
          local_54 = (int)*(short *)(iVar5 + 0x2c);
          local_50 = (int)*(short *)(iVar5 + 0x30);
          local_4c = (int)*(short *)(iVar5 + 0x32);
          local_48 = (int)*(short *)(iVar5 + 0x2e);
          local_3c = *(undefined4 *)(iVar5 + 0x28);
          if (*(int *)(iVar5 + 0x68) == 0) {
            local_40 = 3;
          }
          else {
            iVar4 = *(int *)(*(int *)(iVar5 + 0x68) + 0x38);
            if (*(int *)(iVar4 + 0x168) == 0) {
              local_44 = -1;
            }
            else {
              local_44 = (int)*(short *)(iVar4 + 0x16c);
            }
            _bcopy((void *)(iVar4 + 8),local_38,0x10);
            local_28 = 0;
            if ((*(byte *)(iVar5 + 0x29) & 4) == 0) {
              local_40 = 1;
            }
            else {
              local_40 = 2;
            }
          }
        }
        piVar9 = &local_54;
        uVar8 = 0x30;
        break;
      case 0xb:
        if ((piVar2[1] != 0) || (piVar2[3] != 1)) goto switchD_001022a2_caseD_4;
        puVar11 = &_mach_factor;
LAB_00102671:
        piVar9 = local_24;
        _bcopy(puVar11,piVar9,0xc);
        local_18 = 1000;
        uVar8 = 0x10;
        break;
      case 0xc:
        if ((piVar2[1] != 0) || (piVar2[3] != 1)) goto switchD_001022a2_caseD_4;
        local_7c = _cnt;
        local_78 = DAT_001e894c;
        local_74 = DAT_001e8948;
        local_70 = DAT_001e8944;
        local_6c = _hz;
        local_68 = 0;
        piVar9 = &local_7c;
        _bcopy(&_cp_time,local_64,0x10);
        uVar8 = 0x28;
        break;
      case 0xd:
        if ((piVar2[1] != 0) || (piVar2[3] != 1)) goto switchD_001022a2_caseD_4;
        local_90 = _tk_nin;
        local_8c = _tk_nout;
        local_88 = _dk_busy;
        local_84 = _dk_ndrive;
        local_80 = 0;
        for (puVar11 = _ifnet; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)puVar11[0x17])
        {
          local_80 = local_80 + 1;
        }
        piVar9 = &local_90;
        uVar8 = 0x14;
        break;
      case 0xf:
        iVar5 = piVar2[1];
        puVar11 = _ifnet;
        if (_ifnet == (undefined4 *)0x0) goto switchD_001022a2_caseD_4;
        do {
          if (iVar5 == 0) break;
          puVar11 = (undefined4 *)puVar11[0x17];
          iVar5 = iVar5 + -1;
        } while (puVar11 != (undefined4 *)0x0);
        if (puVar11 == (undefined4 *)0x0) goto switchD_001022a2_caseD_4;
        local_ac = puVar11[0x11];
        local_a8 = puVar11[0x12];
        local_a4 = puVar11[0x13];
        local_a0 = puVar11[0x14];
        local_9c = puVar11[0x15];
        piVar9 = &local_ac;
        _strncpy(local_98,(char *)*puVar11,6);
        uVar8 = 0xffffffff;
        pcVar10 = local_98;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        local_98[~uVar8 - 1] = *(char *)(puVar11 + 2) + '0';
        local_98[~uVar8] = '\0';
        uVar8 = 0x1c;
      }
      if ((uint)piVar2[4] < uVar8) {
        uVar8 = piVar2[4];
      }
      if (uVar8 != 0) {
        if (local_c0 == 0) {
          local_bc = _copyout(piVar9,piVar2[2],uVar8);
        }
        else {
          local_bc = _copyin(piVar2[2],local_b4,uVar8);
          if (local_bc == 0) {
            _bcopy(local_b4,piVar9,uVar8);
          }
        }
      }
      if (local_cc != (int *)0x0) {
        _kmem_free_wakeup(_kernel_pageable_map,local_cc,local_d0 - (int)local_cc);
      }
      if (local_bc != 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = (undefined1)local_bc;
        return;
      }
LAB_001028df:
      piVar2[2] = piVar2[2] + piVar2[4];
      piVar2[3] = piVar2[3] + -1;
      piVar2[1] = piVar2[1] + 1;
      *(int *)(DAT_001e875c + 0x60) = *(int *)(DAT_001e875c + 0x60) + 1;
    }
  }
  return;
}

