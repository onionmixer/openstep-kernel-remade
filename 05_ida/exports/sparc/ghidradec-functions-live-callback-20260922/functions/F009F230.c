
/* WARNING: Removing unreachable block (ram,0xf009f284) */
/* WARNING: Removing unreachable block (ram,0xf009f2ec) */
/* WARNING: Removing unreachable block (ram,0xf009f294) */
/* WARNING: Removing unreachable block (ram,0xf009f2d4) */
/* WARNING: Removing unreachable block (ram,0xf009f45c) */
/* WARNING: Removing unreachable block (ram,0xf009f49c) */
/* WARNING: Removing unreachable block (ram,0xf009f248) */

undefined8 _pmap_check_page_attrib(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 unaff_l0;
  int *piVar8;
  undefined4 unaff_l1;
  int *piVar9;
  int *piVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
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
  dword_F013DEFC = dword_F013DEFC + 1;
  _vm_mem_ppi();
  piVar8 = (int *)(_pg_desc_tbl + param_1 * 0x14);
  uVar1 = *(byte *)(piVar8 + 4) & param_2;
  uVar11 = 1;
  if (uVar1 != param_2) {
    _splvm();
    piVar9 = (int *)piVar8[1];
    if (piVar9 != (int *)0x0) {
      uVar2 = piVar8[2];
      piVar10 = piVar8;
      do {
        *(uint *)((int)register0x00000038 + -0xc) = (uVar2 >> 8) << 0xc;
        do {
          do {
          } while (piVar9[6] != 0);
          piVar3 = piVar9 + 6;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        piVar3 = piVar9;
        _pmap_page_table_entry(piVar9,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar3 != (int *)0x0) {
          if (*(char *)((int)piVar3 + 0xd) == '\x03') {
            iVar5 = *piVar3;
            uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
          }
          else if (*(char *)((int)piVar3 + 0xd) == '\x02') {
            iVar5 = *piVar3;
            uVar2 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
          }
          else {
            iVar5 = *piVar3;
            uVar2 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
          }
          puVar6 = (uint *)(iVar5 + uVar2);
          if ((*puVar6 & 3) == 2) {
            puVar7 = puVar6 + 1;
            if (*(char *)((int)piVar3 + 0xd) == '\x03') {
              puVar7 = puVar6 + _pmap_info;
            }
            while (puVar6 < puVar7) {
              if ((*puVar6 & 0x40) == 0) {
                if (*(char *)((int)piVar3 + 0xd) == '\x03') {
                  uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
                  bVar4 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009F3D8:
                  if ((*(uint *)((int)piVar3 + (uVar2 & 4) + 0x18) & 1 << bVar4) != 0) {
                    bVar4 = *(byte *)(piVar8 + 4);
                    goto loc_F009F41C;
                  }
                  uVar2 = *puVar6;
                }
                else {
                  if (*(char *)((int)piVar3 + 0xd) == '\x02') {
                    uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
                    bVar4 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
                    goto loc_F009F3D8;
                  }
                  if ((piVar3[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                      1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) {
                    bVar4 = *(byte *)(piVar8 + 4);
                    goto loc_F009F41C;
                  }
                  uVar2 = *puVar6;
                }
              }
              else {
                bVar4 = *(byte *)(piVar8 + 4);
loc_F009F41C:
                *(byte *)(piVar8 + 4) = bVar4 | 1;
                uVar2 = *puVar6;
              }
              puVar6 = puVar6 + 1;
              if ((uVar2 & 0x20) != 0) {
                *(byte *)(piVar8 + 4) = *(byte *)(piVar8 + 4) | 2;
              }
            }
            if (*(char *)((int)piVar3 + 0xd) != '\x03') {
              _panic(aPmapCheckPageA);
            }
            if ((*(byte *)(piVar8 + 4) & param_2) == param_2) {
              piVar9[6] = 0;
              _splx(uVar1);
              uVar11 = 1;
              goto locret_F009F4A8;
            }
          }
        }
        piVar9[6] = 0;
        piVar10 = (int *)*piVar10;
        if ((piVar10 == (int *)0x0) || (piVar9 = (int *)piVar10[1], piVar9 == (int *)0x0)) break;
        uVar2 = piVar10[2];
      } while( true );
    }
    _splx(uVar1);
    uVar11 = 0;
  }
locret_F009F4A8:
  return CONCAT44(param_2,uVar11);
}

