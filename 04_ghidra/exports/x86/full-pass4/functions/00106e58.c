/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106e58 */

void _smmap(void)

{
  byte *pbVar1;
  short sVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  vm_map_t target_task;
  code *pcVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  kern_return_t kVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 local_10;
  uint local_c;
  int local_8;
  
  puVar3 = *(uint **)(DAT_001e875c + 0x24);
  local_c = *puVar3;
  uVar9 = puVar3[1];
  uVar4 = puVar3[5];
  uVar5 = puVar3[2];
  uVar8 = _getvnodefp(puVar3[4],&local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar8;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return;
  }
  if (*(short *)(local_8 + 0xc) == 1) {
    piVar6 = *(int **)(local_8 + 0x18);
    local_c = local_c & ~_page_mask;
    uVar9 = _page_mask + uVar9 & ~_page_mask;
    if (((uVar5 & 2) == 0) || ((*(byte *)(local_8 + 8) & 2) != 0)) {
      if (((uVar5 & 1) == 0) || ((*(byte *)(local_8 + 8) & 1) != 0)) {
        target_task = *(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc);
        iVar10 = _vm_map_check_protection(target_task,local_c,uVar9 + local_c,3);
        if (iVar10 != 0) {
          iVar10 = piVar6[10];
          if ((iVar10 == 4) || (iVar10 == 9)) {
            sVar2 = *(short *)(piVar6[0xc] + 0x42);
            pcVar7 = (code *)(&PTR__nodev_001e2f58)[(uint)*(byte *)(piVar6[0xc] + 0x43) * 0xb];
            if ((pcVar7 == _nulldev) || ((pcVar7 == _nodev || (pcVar7 == (code *)0x0))))
            goto LAB_0010719e;
            iVar10 = 0;
            if (0 < (int)puVar3[1]) {
              do {
                iVar11 = (*pcVar7)((int)sVar2,uVar4 + iVar10,uVar5);
                if (iVar11 == -1) goto LAB_0010719e;
                iVar10 = iVar10 + _page_size;
              } while (iVar10 < (int)puVar3[1]);
            }
            if ((puVar3[3] != 1) ||
               (kVar12 = _vm_deallocate(target_task,local_c,uVar9), kVar12 != 0)) goto LAB_0010719e;
            uVar13 = _vm_object_special((int)sVar2,pcVar7,uVar5,uVar4,uVar9);
            iVar10 = _vm_map_find(target_task,uVar13,0,&local_c,uVar9,0);
            if (iVar10 != 0) {
              _vm_object_deallocate(uVar13);
              goto LAB_0010719e;
            }
          }
          else {
            if (iVar10 != 1) goto LAB_0010719e;
            uVar13 = _vnode_pager_setup(piVar6,0,0);
            iVar10 = *piVar6;
            if (*(int *)(iVar10 + 0x30) == 0) {
              **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
              *(undefined4 *)(iVar10 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
            }
            if (puVar3[3] == 1) {
              _vm_deallocate(target_task,local_c,uVar9);
              iVar10 = _vm_allocate_with_pager(target_task,&local_c,uVar9,0,uVar13,uVar4);
              if (iVar10 != 0) {
LAB_00107119:
                *(char *)(DAT_001e875c + 0x68) = (char)iVar10;
                return;
              }
            }
            else {
              uVar14 = _pmap_create(uVar9,0,uVar9,1);
              uVar14 = _vm_map_create(uVar14);
              local_10 = 0;
              iVar10 = _vm_allocate_with_pager(uVar14,&local_10,uVar9,0,uVar13,uVar4);
              if ((iVar10 != 0) ||
                 (iVar10 = _vm_map_copy(target_task,uVar14,local_c,uVar9,0,0,0), iVar10 != 0)) {
                _vm_map_deallocate(uVar14);
                goto LAB_00107119;
              }
              _vm_map_deallocate(uVar14);
            }
          }
          if ((((uVar5 & 2) != 0) ||
              (kVar12 = _vm_protect(target_task,local_c,uVar9,0,1), kVar12 == 0)) &&
             ((puVar3[3] != 1 || (kVar12 = _vm_inherit(target_task,local_c,uVar9,0), kVar12 == 0))))
          {
            pbVar1 = (byte *)(puVar3[4] + *(int *)(_active_u + 0x154));
            *pbVar1 = *pbVar1 | 2;
            return;
          }
          _vm_deallocate(target_task,local_c,uVar9);
        }
      }
LAB_0010719e:
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  return;
}

