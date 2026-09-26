
void _table(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined *puVar14;
  undefined auStack_b2 [4];
  undefined2 uStack_ae;
  int iStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  char acStack_98 [8];
  int iStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined auStack_64 [16];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined auStack_38 [16];
  undefined uStack_28;
  int aiStack_24 [3];
  undefined4 uStack_18;
  int aiStack_14 [4];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar9 = 0;
  iVar10 = 0;
  if (piVar1[3] < 0) {
    iVar10 = _machine_table_setokay(*piVar1);
    if (((iVar10 == 0) || (iVar10 < 1)) || (iVar10 != 1)) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    iVar10 = 1;
    piVar1[3] = -piVar1[3];
  }
  *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
  if ((*piVar1 == 1) &&
     ((((int)*(sword *)(*_active_u + 0x30) != piVar1[1] && (piVar1[1] != 0)) || (piVar1[3] != 1))))
  {
loc_4002848:
    if (*(int *)(dword_40B57D4 + 0x5c) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  else {
    while (0 < piVar1[3]) {
      piVar7 = (int *)0x0;
      uVar8 = 0;
      iVar5 = _machine_table(*piVar1,piVar1[1],piVar1[2],piVar1[3],piVar1[4],iVar10);
      if (iVar5 != 0) {
        if ((0 < iVar5) && (iVar5 == 1)) goto loc_40028CE;
        goto loc_4002848;
      }
      switch(*piVar1) {
      case :
        if (*(int *)((int)_active_u + 0x15e) == 0) {
          uStack_ae = 0xffff;
          piVar12 = (int *)&uStack_ae;
        }
        else {
          piVar12 = (int *)((int)_active_u + 0x162);
        }
        uVar6 = 2;
        break;
      case :
        iVar5 = _pfind(piVar1[1]);
        if ((iVar5 == 0) || (*(int *)(*(int *)(iVar5 + 0x66) + 0x20) < 1)) {
loc_400235A:
          *(undefined *)(dword_40B57D4 + 100) = 3;
          return;
        }
        uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0x66) + 0x18);
        _thread_reference(uVar2);
        piVar7 = (int *)_kmem_alloc_wait(_kernel_pageable_map,~_page_mask & _page_mask + 0x7f0);
        _fake_u(piVar7,uVar2);
        _thread_deallocate(uVar2);
        uVar6 = 0x7f0;
        uVar8 = (~_page_mask & _page_mask + 0x7f0) + (int)piVar7;
        piVar12 = piVar7;
        break;
      case :
        if ((piVar1[1] == 0) && (piVar1[3] == 1)) {
          puVar14 = _avenrun;
          goto loc_4002700;
        }
      :
        goto loc_4002848;
      case :
        iVar5 = _table_fsparam(piVar1[1],aiStack_14);
        if (iVar5 == 0) goto loc_4002848;
        uVar6 = 0x10;
        piVar12 = aiStack_14;
        break;
      case :
        iVar5 = _pfind(piVar1[1]);
        if (iVar5 == 0) goto loc_400235A;
        uVar2 = *(undefined4 *)(*(int *)(iVar5 + 0x66) + 8);
        uVar6 = piVar1[4];
        if ((uVar6 == 0) || (iVar5 = *(int *)(iVar5 + 0x82), iVar5 == 0)) goto loc_4002848;
        _vm_map_reference(uVar2);
        piVar7 = (int *)_kmem_alloc_wait(_kernel_pageable_map,~_page_mask & _page_mask + uVar6);
        uVar4 = ~_page_mask;
        uVar8 = uVar4 & (int)piVar7 + _page_mask + uVar6;
        iVar5 = _vm_map_copy(_kernel_pageable_map,uVar2,piVar7,uVar4 & uVar6 + _page_mask,
                             uVar4 & iVar5 - uVar6,0,0);
        if (iVar5 != 0) {
          _kmem_free_wakeup(_kernel_pageable_map,piVar7,~_page_mask & _page_mask + uVar6);
          _vm_map_deallocate(uVar2);
          goto loc_4002848;
        }
        _vm_map_deallocate(uVar2);
        piVar12 = (int *)(uVar8 - uVar6);
        piVar11 = (int *)(uVar8 - 0xc);
        iVar5 = *piVar11;
        while ((iVar5 != 0 && (piVar12 != piVar11))) {
          piVar11 = piVar11 + -1;
          iVar5 = *piVar11;
        }
        _bzero(piVar12,(int)piVar11 - (int)piVar12);
        break;
      case :
        if (piVar1[1] < 0) {
          piVar1[1] = -piVar1[1];
        }
        iVar5 = _pfind(piVar1[1]);
        if (iVar5 == 0) goto loc_400235A;
        if (*(char *)(iVar5 + 0x13) == '\0') {
          _bzero(&iStack_54,0x30);
          uStack_40 = 0;
        }
        else {
          iStack_54 = (int)*(sword *)(iVar5 + 0x2c);
          iStack_50 = (int)*(sword *)(iVar5 + 0x30);
          iStack_4c = (int)*(sword *)(iVar5 + 0x32);
          iStack_48 = (int)*(sword *)(iVar5 + 0x2e);
          uStack_3c = *(undefined4 *)(iVar5 + 0x28);
          if (*(int *)(iVar5 + 0x66) == 0) {
            uStack_40 = 3;
          }
          else {
            iVar3 = *(int *)(*(int *)(iVar5 + 0x66) + 0x30);
            if (*(int *)(iVar3 + 0x15e) == 0) {
              iStack_44 = -1;
            }
            else {
              iStack_44 = (int)*(sword *)(iVar3 + 0x162);
            }
            _bcopy(iVar3 + 8,auStack_38,0x10);
            uStack_28 = 0;
            uStack_40 = 1;
            if ((*(byte *)(iVar5 + 0x2a) & 4) != 0) {
              uStack_40 = 2;
            }
          }
        }
        uVar6 = 0x30;
        piVar12 = &iStack_54;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        puVar14 = _mach_factor;
loc_4002700:
        _bcopy(puVar14,aiStack_24,0xc);
        uStack_18 = 1000;
        uVar6 = 0x10;
        piVar12 = aiStack_24;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        iStack_7c = _cnt;
        uStack_78 = dword_40B565C;
        uStack_74 = dword_40B5658;
        uStack_70 = dword_40B5654;
        uStack_6c = _hz;
        uStack_68 = 0;
        _bcopy(_cp_time,auStack_64,0x10);
        uVar6 = 0x28;
        piVar12 = &iStack_7c;
        break;
      case :
        if ((piVar1[1] != 0) || (piVar1[3] != 1)) goto loc_4002848;
        iStack_90 = _tk_nin;
        uStack_8c = _tk_nout;
        uStack_88 = _dk_busy;
        uStack_84 = _dk_ndrive;
        iStack_80 = 0;
        for (puVar13 = _ifnet; puVar13 != (undefined4 *)0x0;
            puVar13 = *(undefined4 **)((int)puVar13 + 0x5a)) {
          iStack_80 = iStack_80 + 1;
        }
        uVar6 = 0x14;
        piVar12 = &iStack_90;
        break;
      case :
        iVar5 = piVar1[1];
        puVar13 = _ifnet;
        if (_ifnet == (undefined4 *)0x0) goto loc_4002848;
        do {
          if (iVar5 == 0) break;
          puVar13 = *(undefined4 **)((int)puVar13 + 0x5a);
          iVar5 = iVar5 + -1;
        } while (puVar13 != (undefined4 *)0x0);
        if (puVar13 == (undefined4 *)0x0) goto loc_4002848;
        iStack_ac = *(int *)((int)puVar13 + 0x42);
        uStack_a8 = *(undefined4 *)((int)puVar13 + 0x46);
        uStack_a4 = *(undefined4 *)((int)puVar13 + 0x4a);
        uStack_a0 = *(undefined4 *)((int)puVar13 + 0x4e);
        uStack_9c = *(undefined4 *)((int)puVar13 + 0x52);
        _strncpy(acStack_98,*puVar13,6);
        iVar5 = _strlen(acStack_98);
        acStack_98[iVar5] = *(char *)((int)puVar13 + 9) + '0';
        acStack_98[iVar5 + 1] = '\0';
        uVar6 = 0x1c;
        piVar12 = &iStack_ac;
      }
      if ((uint)piVar1[4] < uVar6) {
        uVar6 = piVar1[4];
      }
      if (uVar6 != 0) {
        if (iVar10 == 0) {
          iVar9 = _copyoutmsg(piVar12,piVar1[2],uVar6);
        }
        else {
          iVar9 = _copyinmsg(piVar1[2],auStack_b2,uVar6);
          if (iVar9 == 0) {
            _bcopy(auStack_b2,piVar12,uVar6);
          }
        }
      }
      if (piVar7 != (int *)0x0) {
        _kmem_free_wakeup(_kernel_pageable_map,piVar7,uVar8 - (int)piVar7);
      }
      if (iVar9 != 0) {
        *(char *)(dword_40B57D4 + 100) = (char)iVar9;
        return;
      }
loc_40028CE:
      piVar1[2] = piVar1[4] + piVar1[2];
      piVar1[3] = piVar1[3] + -1;
      piVar1[1] = piVar1[1] + 1;
      *(int *)(dword_40B57D4 + 0x5c) = *(int *)(dword_40B57D4 + 0x5c) + 1;
    }
  }
  return;
}
