
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

