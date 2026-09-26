
/* WARNING: Removing unreachable block (ram,0xf009dbd8) */
/* WARNING: Removing unreachable block (ram,0xf009db7c) */
/* WARNING: Removing unreachable block (ram,0xf009da68) */
/* WARNING: Removing unreachable block (ram,0xf009d99c) */
/* WARNING: Removing unreachable block (ram,0xf009d92c) */
/* WARNING: Removing unreachable block (ram,0xf009d89c) */
/* WARNING: Removing unreachable block (ram,0xf009d830) */
/* WARNING: Removing unreachable block (ram,0xf009d83c) */
/* WARNING: Removing unreachable block (ram,0xf009d8b4) */
/* WARNING: Removing unreachable block (ram,0xf009d938) */
/* WARNING: Removing unreachable block (ram,0xf009da34) */
/* WARNING: Removing unreachable block (ram,0xf009db68) */
/* WARNING: Removing unreachable block (ram,0xf009dbc4) */
/* WARNING: Removing unreachable block (ram,0xf009dbf4) */
/* WARNING: Removing unreachable block (ram,0xf009d810) */

undefined8 _pmap_remove_all(uint param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  byte bVar8;
  uint uVar7;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 unaff_l3;
  int *piVar14;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  puVar12 = (uint *)0x0;
  if ((param_1 < _physmax) && (uVar6 = param_1, _vm_valid_page(), uVar6 != 0)) {
    param_2 = dword_F013DEC8 + 1;
    dword_F013DEC8 = param_2;
    _splvm();
    uVar6 = param_1;
    _vm_mem_ppi();
    puVar13 = (undefined4 *)(_pg_desc_tbl + uVar6 * 0x14);
    piVar14 = (int *)puVar13[1];
    while (piVar14 != (int *)0x0) {
      bVar2 = false;
      bVar3 = false;
      *(uint *)((int)register0x00000038 + -0xc) = ((uint)puVar13[2] >> 8) << 0xc;
      do {
        do {
        } while (piVar14[6] != 0);
        piVar5 = piVar14 + 6;
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      piVar5 = piVar14;
      _pmap_page_table_entry(piVar14,*(undefined4 *)((int)register0x00000038 + -0xc),0);
      if (piVar5 == (int *)0x0) {
loc_F009D924:
        _printf(aPmapXVaX,piVar14,*(undefined4 *)((int)register0x00000038 + -0xc));
        _panic(aPmapRemoveAllP);
      }
      else {
        if (*(char *)((int)piVar5 + 0xd) == '\x03') {
          iVar9 = *piVar5;
          uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
        }
        else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
          iVar9 = *piVar5;
          uVar6 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
        }
        else {
          iVar9 = *piVar5;
          uVar6 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
        }
        puVar12 = (uint *)(iVar9 + uVar6);
        if ((*puVar12 & 3) != 2) goto loc_F009D924;
      }
      if (*(char *)((int)piVar5 + 0xd) == '\x03') {
        if ((*puVar12 >> 8) * 0x1000 + (*(uint *)((int)register0x00000038 + -0xc) & 0xfff) !=
            param_1) {
loc_F009D99C:
          _panic(aPmapRemoveAllP_0);
          goto loc_F009D9A4;
        }
        cVar1 = *(char *)((int)piVar5 + 0xd);
      }
      else {
        if ((*puVar12 >> 8) * 0x1000 + (*(uint *)((int)register0x00000038 + -0xc) & 0x3ffff) !=
            param_1) goto loc_F009D99C;
loc_F009D9A4:
        cVar1 = *(char *)((int)piVar5 + 0xd);
      }
      if (cVar1 == '\x03') {
        uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
        bVar8 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009D9F0:
        if ((*(uint *)((int)piVar5 + (uVar6 & 4) + 0x10) & 1 << bVar8) == 0) {
          puVar10 = (undefined4 *)*puVar13;
        }
        else {
loc_F009DA34:
          _panic(aPmapRemoveAllR);
          puVar10 = (undefined4 *)*puVar13;
        }
      }
      else {
        if (cVar1 == '\x02') {
          uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
          bVar8 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
          goto loc_F009D9F0;
        }
        if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 4] &
            1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) goto loc_F009DA34;
        puVar10 = (undefined4 *)*puVar13;
      }
      if (puVar10 == (undefined4 *)0x0) {
        puVar13[1] = 0;
      }
      else {
        *puVar13 = *puVar10;
        puVar13[1] = puVar10[1];
        uVar4 = _pv_entry_zone;
        puVar13[2] = puVar10[2];
        _zfree(uVar4);
      }
      uVar6 = (uint)_pmap_info;
      if (uVar6 != 0) {
        uVar11 = *(uint *)((int)register0x00000038 + -0xc);
        do {
          uVar6 = uVar6 - 1;
          uVar7 = *puVar12;
          if ((uVar7 & 0x40) == 0) {
            if (*(char *)((int)piVar5 + 0xd) == '\x03') {
              if ((*(uint *)((int)piVar5 + (uVar11 >> 0xf & 4) + 0x18) &
                  1 << ((byte)(uVar11 >> 0xc) & 0x1e)) != 0) goto loc_F009DB40;
              uVar7 = *puVar12;
            }
            else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
              if ((*(uint *)((int)piVar5 + (uVar11 >> 0x15 & 4) + 0x18) &
                  1 << ((byte)(uVar11 >> 0x12) & 0x1f)) != 0) goto loc_F009DB40;
              uVar7 = *puVar12;
            }
            else if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                     1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) == 0) {
              uVar7 = *puVar12;
            }
            else {
loc_F009DB40:
              bVar2 = true;
              uVar7 = *puVar12;
            }
          }
          else {
            bVar2 = true;
          }
          if ((uVar7 & 0x20) != 0) {
            bVar3 = true;
          }
          puVar12 = puVar12 + 1;
        } while (0 < (int)uVar6);
      }
      *(int **)((int)register0x00000038 + -0x10) = piVar5;
      _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                      *(undefined4 *)((int)register0x00000038 + -0xc));
      if (bVar2) {
        uVar6 = param_1;
        _vm_phys_to_vm_page();
        *(uint *)(uVar6 + 0x1c) = *(uint *)(uVar6 + 0x1c) & 0xfffffbff;
        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 1;
      }
      if (bVar3) {
        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 2;
        cVar1 = *(char *)((int)piVar5 + 0xf);
      }
      else {
        cVar1 = *(char *)((int)piVar5 + 0xf);
      }
      if (cVar1 == '\0') {
        _pmap_dealloc_seg_entry(piVar5);
      }
      _pmap_deallocate_mappings(piVar14,*(undefined4 *)((int)register0x00000038 + -0xc),1,0);
      piVar14[6] = 0;
      piVar14 = (int *)puVar13[1];
    }
    _splx(param_2);
  }
  return CONCAT44(param_2,param_1);
}

