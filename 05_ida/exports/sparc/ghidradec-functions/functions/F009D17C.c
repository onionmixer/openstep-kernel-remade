
/* WARNING: Removing unreachable block (ram,0xf009d7e0) */
/* WARNING: Removing unreachable block (ram,0xf009d434) */
/* WARNING: Removing unreachable block (ram,0xf009d708) */
/* WARNING: Removing unreachable block (ram,0xf009d5f8) */
/* WARNING: Removing unreachable block (ram,0xf009d560) */
/* WARNING: Removing unreachable block (ram,0xf009d1e4) */
/* WARNING: Removing unreachable block (ram,0xf009d418) */
/* WARNING: Removing unreachable block (ram,0xf009d5d0) */
/* WARNING: Removing unreachable block (ram,0xf009d644) */
/* WARNING: Removing unreachable block (ram,0xf009d724) */
/* WARNING: Removing unreachable block (ram,0xf009d7b8) */
/* WARNING: Removing unreachable block (ram,0xf009d7e8) */
/* WARNING: Removing unreachable block (ram,0xf009d1ac) */

undefined8 _pmap_remove(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  byte bVar10;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar11;
  undefined4 unaff_l0;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 unaff_l1;
  uint *puVar16;
  int iVar17;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int *piVar18;
  undefined4 unaff_i0;
  int *piVar19;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar20;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar21;
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
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  piVar19 = param_1;
  if (param_1 != (int *)0x0) {
    iVar4 = dword_F013DEC4 + 1;
    dword_F013DEC4 = iVar4;
    _splvm();
    *(int *)((int)register0x00000038 + -0x34) = iVar4;
    *(uint *)((int)register0x00000038 + -0xc) =
         *(uint *)((int)register0x00000038 + -0x14) & ~_page_mask;
    if ((*(uint *)((int)register0x00000038 + -0x14) & ~_page_mask) <
        *(uint *)((int)register0x00000038 + -0x1c)) {
      param_2 = 1;
      do {
        piVar5 = param_1;
        _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar5 == (int *)0x0) {
          *(uint *)((int)register0x00000038 + -0xc) =
               *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
loc_F009D7C0:
          uVar20 = *(uint *)((int)register0x00000038 + -0xc);
        }
        else {
          if (*(char *)((int)piVar5 + 0xd) == '\x03') {
            uVar20 = *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
          }
          else {
            uVar20 = 0xffffe000;
            if (*(char *)((int)piVar5 + 0xd) == '\x02') {
              uVar20 = *(int *)((int)register0x00000038 + -0xc) + 0x1000000U & 0xff000000;
            }
          }
          if (*(uint *)((int)register0x00000038 + -0x1c) < uVar20) {
            uVar20 = *(uint *)((int)register0x00000038 + -0x1c);
          }
          uVar6 = *(uint *)((int)register0x00000038 + -0xc);
          if (uVar6 < uVar20) {
            do {
              if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                iVar4 = *piVar5;
                uVar6 = uVar6 >> 10 & 0xfc;
              }
              else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                iVar4 = *piVar5;
                uVar6 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
              }
              else {
                iVar4 = *piVar5;
                uVar6 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
              }
              puVar12 = (uint *)(iVar4 + uVar6);
              puVar16 = puVar12 + 1;
              if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                puVar16 = puVar12 + _pmap_info;
              }
              bVar2 = false;
              bVar3 = false;
              if ((*puVar12 & 3) == 2) {
                cVar1 = *(char *)((int)piVar5 + 0xd);
                *(int *)((int)register0x00000038 + -0x24) =
                     *(int *)((int)register0x00000038 + -0x24) + 1;
                if (cVar1 == '\x03') {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
                  bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009D348:
                  if ((*(uint *)((int)piVar5 + (uVar6 & 4) + 0x10) & 1 << bVar10) == 0) {
                    uVar6 = *puVar12;
                  }
                  else {
                    cVar1 = *(char *)((int)piVar5 + 0xd);
loc_F009D38C:
                    if (cVar1 == '\x03') {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf & 4;
                      bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
                    }
                    else {
                      bVar10 = *(byte *)((int)register0x00000038 + -0xc);
                      if (cVar1 == '\x02') {
                        bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12);
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15 & 4;
                      }
                      else {
                        uVar6 = (uint)(bVar10 >> 5) << 2;
                      }
                      bVar10 = bVar10 & 0x1f;
                    }
                    *(uint *)((int)piVar5 + uVar6 + 0x10) =
                         *(uint *)((int)piVar5 + uVar6 + 0x10) & ~(1 << bVar10);
                    *(int *)((int)register0x00000038 + -0x2c) =
                         *(int *)((int)register0x00000038 + -0x2c) + 1;
                    uVar6 = *puVar12;
                  }
                }
                else {
                  if (cVar1 == '\x02') {
                    uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
                    bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
                    goto loc_F009D348;
                  }
                  if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 4] &
                      1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) {
                    cVar1 = *(char *)((int)piVar5 + 0xd);
                    goto loc_F009D38C;
                  }
                  uVar6 = *puVar12;
                }
                if (uVar6 >> 8 < _physmaxpfn) {
                  iVar4 = (uVar6 >> 8) << 0xc;
                  _vm_valid_page();
                  if (iVar4 != 0) {
                    if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfff;
                    }
                    else {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0x3ffff;
                    }
                    piVar19 = (int *)((*puVar12 >> 8) * 0x1000 + uVar6);
                    if (puVar12 < puVar16) {
                      uVar11 = *(uint *)((int)register0x00000038 + -0xc);
                      uVar6 = *puVar12;
                      do {
                        if ((uVar6 & 0x40) == 0) {
                          if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                            if ((*(uint *)((int)piVar5 + (uVar11 >> 0xf & 4) + 0x18) &
                                1 << ((byte)(uVar11 >> 0xc) & 0x1e)) != 0) goto loc_F009D538;
                            uVar6 = *puVar12;
                          }
                          else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                            if ((*(uint *)((int)piVar5 + (uVar11 >> 0x15 & 4) + 0x18) &
                                1 << ((byte)(uVar11 >> 0x12) & 0x1f)) != 0) goto loc_F009D538;
                            uVar6 = *puVar12;
                          }
                          else if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                                   1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) == 0) {
                            uVar6 = *puVar12;
                          }
                          else {
loc_F009D538:
                            bVar2 = true;
                            uVar6 = *puVar12;
                          }
                        }
                        else {
                          bVar2 = true;
                        }
                        if ((uVar6 & 0x20) != 0) {
                          bVar3 = true;
                        }
                        puVar12 = puVar12 + 1;
                        if (puVar16 <= puVar12) break;
                        uVar6 = *puVar12;
                      } while( true );
                    }
                    *(int **)((int)register0x00000038 + -0x10) = piVar5;
                    _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                                    *(undefined4 *)((int)register0x00000038 + -0xc));
                    if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                      uVar6 = (*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size
                      ;
                    }
                    else {
                      if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000;
                        iVar4 = 0x40000;
                      }
                      else {
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xff000000;
                        iVar4 = 0x1000000;
                      }
                      uVar6 = uVar6 + iVar4;
                    }
                    piVar18 = piVar19;
                    for (uVar11 = *(uint *)((int)register0x00000038 + -0xc); uVar11 < uVar6;
                        uVar11 = uVar11 + _page_size) {
                      piVar7 = piVar19;
                      _vm_mem_ppi();
                      iVar4 = _pg_desc_tbl;
                      iVar17 = (int)piVar7 * 0x14;
                      puVar13 = (undefined4 *)(_pg_desc_tbl + iVar17);
                      if (bVar2) {
                        piVar7 = piVar18;
                        _vm_phys_to_vm_page();
                        piVar7[7] = piVar7[7] & 0xfffffbff;
                        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 1;
                      }
                      if (bVar3) {
                        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 2;
                      }
                      if (puVar13[1] == 0) {
                        _panic(aPmapRemovePmap);
                        uVar8 = puVar13[2];
                      }
                      else {
                        uVar8 = puVar13[2];
                      }
                      if ((uVar8 >> 8) * 0x1000 - uVar11 == 0) {
                        if ((int *)puVar13[1] != param_1) {
                          puVar14 = (undefined4 *)*puVar13;
                          goto loc_F009D6B0;
                        }
                        puVar14 = *(undefined4 **)(iVar4 + iVar17);
                        if (puVar14 != (undefined4 *)0x0) {
                          *(undefined4 *)(iVar4 + iVar17) = *puVar14;
                          puVar13[1] = puVar14[1];
                          uVar9 = _pv_entry_zone;
                          puVar13[2] = puVar14[2];
                          goto loc_F009D724;
                        }
                        puVar13[1] = 0;
                      }
                      else {
                        puVar14 = (undefined4 *)*puVar13;
loc_F009D6B0:
                        bVar21 = puVar14 == (undefined4 *)0x0;
                        if (!bVar21) {
                          uVar8 = puVar14[2];
                          while( true ) {
                            puVar15 = puVar14;
                            if (((uVar8 >> 8) * 0x1000 - uVar11 == 0) &&
                               (bVar21 = puVar15 == (undefined4 *)0x0, puVar14 = puVar15,
                               (int *)puVar15[1] == param_1)) goto loc_F009D6FC;
                            puVar14 = (undefined4 *)*puVar15;
                            puVar13 = puVar15;
                            if (puVar14 == (undefined4 *)0x0) break;
                            uVar8 = puVar14[2];
                          }
                          bVar21 = true;
                        }
loc_F009D6FC:
                        if (bVar21) {
                          _panic(aPmapRemovePmap_0,puVar14);
                        }
                        uVar9 = _pv_entry_zone;
                        *puVar13 = *puVar14;
loc_F009D724:
                        _zfree(uVar9,puVar14);
                      }
                      piVar18 = (int *)((int)piVar18 + _page_size);
                    }
                    goto loc_F009D744;
                  }
                  *(int **)((int)register0x00000038 + -0x10) = piVar5;
                }
                else {
                  *(int **)((int)register0x00000038 + -0x10) = piVar5;
                }
                _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                                *(undefined4 *)((int)register0x00000038 + -0xc));
                cVar1 = *(char *)((int)piVar5 + 0xd);
              }
              else {
loc_F009D744:
                cVar1 = *(char *)((int)piVar5 + 0xd);
              }
              if (cVar1 == '\x03') {
                uVar6 = (*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size;
              }
              else {
                if (cVar1 == '\x02') {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000;
                  iVar4 = 0x40000;
                }
                else {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xff000000;
                  iVar4 = 0x1000000;
                }
                uVar6 = uVar6 + iVar4;
              }
              *(uint *)((int)register0x00000038 + -0xc) = uVar6;
            } while (uVar6 < uVar20);
            cVar1 = *(char *)((int)piVar5 + 0xf);
          }
          else {
            cVar1 = *(char *)((int)piVar5 + 0xf);
          }
          uVar20 = *(uint *)((int)register0x00000038 + -0xc);
          if (cVar1 == '\0') {
            _pmap_dealloc_seg_entry(piVar5);
            goto loc_F009D7C0;
          }
        }
      } while (uVar20 < *(uint *)((int)register0x00000038 + -0x1c));
    }
    _pmap_deallocate_mappings
              (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),
               *(undefined4 *)((int)register0x00000038 + -0x24),
               *(undefined4 *)((int)register0x00000038 + -0x2c));
    _splx(*(undefined4 *)((int)register0x00000038 + -0x34));
  }
  return CONCAT44(param_2,piVar19);
}
