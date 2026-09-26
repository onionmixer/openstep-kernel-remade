
/* WARNING: Removing unreachable block (ram,0xf000e20c) */
/* WARNING: Removing unreachable block (ram,0xf000e118) */
/* WARNING: Removing unreachable block (ram,0xf000e1a0) */
/* WARNING: Removing unreachable block (ram,0xf000e18c) */
/* WARNING: Removing unreachable block (ram,0xf000e144) */
/* WARNING: Removing unreachable block (ram,0xf000e0a8) */
/* WARNING: Removing unreachable block (ram,0xf000e074) */
/* WARNING: Removing unreachable block (ram,0xf000e02c) */
/* WARNING: Removing unreachable block (ram,0xf000df40) */
/* WARNING: Removing unreachable block (ram,0xf000e054) */
/* WARNING: Removing unreachable block (ram,0xf000e088) */
/* WARNING: Removing unreachable block (ram,0xf000e134) */
/* WARNING: Removing unreachable block (ram,0xf000e164) */
/* WARNING: Removing unreachable block (ram,0xf000e1b8) */
/* WARNING: Removing unreachable block (ram,0xf000e0fc) */
/* WARNING: Removing unreachable block (ram,0xf000e1dc) */
/* WARNING: Removing unreachable block (ram,0xf000e224) */
/* WARNING: Removing unreachable block (ram,0xf000de8c) */

undefined8 _smmap(undefined4 param_1,uint param_2)

{
  word wVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  undefined4 *puVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar13;
  undefined4 unaff_i0;
  uint uVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar12 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar9 = puVar12[1];
  uVar2 = puVar12[4];
  iVar13 = puVar12[5];
  uVar14 = puVar12[2];
  *(undefined4 *)((int)register0x00000038 + -0x10) = *puVar12;
  _getvnodefp(uVar2,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  iVar6 = *(int *)((int)register0x00000038 + -0xc);
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F000E25C;
  if (*(sword *)(iVar6 + 0xc) == 1) {
    piVar7 = *(int **)(iVar6 + 0x18);
    uVar10 = iVar9 + _page_mask & ~_page_mask;
    *(uint *)((int)register0x00000038 + -0x10) =
         *(uint *)((int)register0x00000038 + -0x10) & ~_page_mask;
    if (((uVar14 & 2) == 0) || ((*(uint *)(iVar6 + 8) & 2) != 0)) {
      if (((uVar14 & 1) == 0) ||
         ((*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8) & 1) != 0)) {
        uVar11 = *(uint *)(*(int *)(_active_threads + 0xc) + 0xc);
        uVar3 = uVar11;
        _vm_map_check_protection
                  (uVar11,*(int *)((int)register0x00000038 + -0x10),
                   *(int *)((int)register0x00000038 + -0x10) + uVar10,3);
        if (uVar3 != 0) {
          iVar6 = piVar7[10];
          if ((iVar6 == 4) || (iVar6 == 9)) {
            wVar1 = *(word *)(piVar7[0xc] + 0x42);
            param_2 = (uint)wVar1;
            pcVar8 = *(code **)(DAT_f011ca10 + (uint)(wVar1 >> 8) * 0x2c);
            if ((pcVar8 != _nulldev) && ((pcVar8 != _nodev && (iVar6 = 0, pcVar8 != (code *)0x0))))
            {
              if ((int)puVar12[1] < 1) {
                iVar6 = puVar12[3];
              }
              else {
                do {
                  iVar9 = (int)(sword)wVar1;
                  (*pcVar8)((int)(sword)wVar1,iVar13 + iVar6,uVar14);
                  if (iVar9 == -1) goto loc_F000E230;
                  iVar6 = iVar6 + _page_size;
                } while (iVar6 < (int)puVar12[1]);
                iVar6 = puVar12[3];
              }
              if ((iVar6 == 1) &&
                 (uVar3 = uVar11,
                 _vm_deallocate(uVar11,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10),
                 uVar3 == 0)) {
                iVar6 = (int)(sword)wVar1;
                _vm_object_special(iVar6,pcVar8,uVar14,iVar13,uVar10);
                uVar3 = uVar11;
                _vm_map_find(uVar11,iVar6,0,(undefined *)((int)register0x00000038 + -0x10),uVar10,0)
                ;
                bVar15 = (uVar14 & 2) == 0;
                if (uVar3 == 0) goto loc_F000E1C4;
                _vm_object_deallocate(iVar6);
              }
            }
          }
          else if (iVar6 == 1) {
            piVar4 = piVar7;
            _vnode_pager_setup(piVar7,0,0);
            iVar6 = *piVar7;
            if (*(int *)(iVar6 + 0x30) == 0) {
              **(sword **)(_active_u + 0x1c) = **(sword **)(_active_u + 0x1c) + 1;
              *(undefined4 *)(iVar6 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
            }
            if (puVar12[3] == 1) {
              _vm_deallocate(uVar11,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
              uVar5 = uVar11;
              _vm_allocate_with_pager
                        (uVar11,(undefined *)((int)register0x00000038 + -0x10),uVar10,0,piVar4,
                         iVar13);
              bVar15 = (uVar14 & 2) == 0;
              if (uVar5 == 0) {
loc_F000E1C4:
                if (bVar15) {
                  uVar3 = uVar11;
                  _vm_protect(uVar11,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10,0,1);
                  if (uVar3 == 0) {
                    iVar6 = puVar12[3];
                    goto loc_F000E1F4;
                  }
                }
                else {
                  iVar6 = puVar12[3];
loc_F000E1F4:
                  if ((iVar6 != 1) ||
                     (uVar3 = uVar11,
                     _vm_inherit(uVar11,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10,0),
                     uVar3 == 0)) {
                    *(byte *)(*(int *)(_active_u + 0x150) + puVar12[4]) =
                         *(byte *)(*(int *)(_active_u + 0x150) + puVar12[4]) | 2;
                    goto locret_F000E25C;
                  }
                }
                _vm_deallocate(uVar11,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
                goto loc_F000E230;
              }
            }
            else {
              uVar3 = uVar10;
              _pmap_create();
              _vm_map_create();
              *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
              uVar5 = uVar3;
              _vm_allocate_with_pager();
              if ((uVar5 == 0) &&
                 (uVar5 = uVar11,
                 _vm_map_copy(uVar11,uVar3,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10,0
                              ,0,0), uVar5 == 0)) {
                _vm_map_deallocate(uVar3);
                bVar15 = (uVar14 & 2) == 0;
                goto loc_F000E1C4;
              }
              _vm_map_deallocate(uVar3);
            }
            *(char *)(dword_F0133DDC + 0x38) = (char)uVar5;
            goto locret_F000E25C;
          }
        }
      }
loc_F000E230:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F000E25C;
    }
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
locret_F000E25C:
  return CONCAT44(param_2,uVar14);
}
