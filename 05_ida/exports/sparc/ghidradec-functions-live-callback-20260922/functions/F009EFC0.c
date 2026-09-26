
/* WARNING: Removing unreachable block (ram,0xf009f0d4) */
/* WARNING: Removing unreachable block (ram,0xf009f040) */
/* WARNING: Removing unreachable block (ram,0xf009eff4) */
/* WARNING: Removing unreachable block (ram,0xf009f058) */
/* WARNING: Removing unreachable block (ram,0xf009f220) */
/* WARNING: Removing unreachable block (ram,0xf009efd8) */

undefined8 _pmap_clear_page_attrib(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined *puVar4;
  byte bVar5;
  int iVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int *piVar8;
  undefined4 unaff_l3;
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
  dword_F013DEF8 = dword_F013DEF8 + 1;
  piVar1 = param_1;
  _vm_mem_ppi();
  piVar7 = (int *)(_pg_desc_tbl + (int)piVar1 * 0x14);
  _splvm();
  *(byte *)(piVar7 + 4) = *(byte *)(piVar7 + 4) & ~(byte)param_2;
  piVar8 = (int *)piVar7[1];
  if (piVar8 == (int *)0x0) {
loc_F009F220:
    _splx(piVar1);
    return CONCAT44(param_2,param_1);
  }
  uVar2 = piVar7[2];
  do {
    *(uint *)((int)register0x00000038 + -0xc) = (uVar2 >> 8) << 0xc;
    do {
      do {
      } while (piVar8[6] != 0);
      piVar3 = piVar8 + 6;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_1 = piVar8;
    _pmap_page_table_entry(piVar8,*(undefined4 *)((int)register0x00000038 + -0xc),0);
    if (param_1 != (int *)0x0) {
      if (*(char *)((int)param_1 + 0xd) == '\x03') {
        iVar6 = *param_1;
        uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
      }
      else if (*(char *)((int)param_1 + 0xd) == '\x02') {
        iVar6 = *param_1;
        uVar2 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
      }
      else {
        iVar6 = *param_1;
        uVar2 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
      }
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      if ((*(uint *)(iVar6 + uVar2) & 3) == 2) {
        *(int **)((int)register0x00000038 + -0x10) = param_1;
        _set_pte_modref(puVar4,*(undefined4 *)((int)register0x00000038 + -0xc),param_2 & 1,
                        param_2 & 2);
        if (puVar4 != (undefined *)0x0) {
          if (puVar4 == (undefined *)0x2) {
            if (*(char *)((int)param_1 + 0xd) == '\x03') {
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
            }
            else {
              if (*(char *)((int)param_1 + 0xd) != '\x02') {
                bVar5 = *(byte *)((int)register0x00000038 + -0xc) >> 5;
                param_1[bVar5 + 0xc] =
                     param_1[bVar5 + 0xc] | 1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f);
                goto loc_F009F174;
              }
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
            }
            *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) =
                 *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) | 1 << bVar5;
          }
loc_F009F174:
          if (puVar4 == (undefined *)0x1) {
            if (*(char *)((int)param_1 + 0xd) == '\x03') {
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
            }
            else {
              if (*(char *)((int)param_1 + 0xd) != '\x02') {
                bVar5 = *(byte *)((int)register0x00000038 + -0xc) >> 5;
                param_1[bVar5 + 0xc] =
                     param_1[bVar5 + 0xc] &
                     ~(1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f));
                goto loc_F009F1FC;
              }
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
            }
            *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) =
                 *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) & ~(1 << bVar5);
          }
        }
      }
    }
loc_F009F1FC:
    piVar8[6] = 0;
    piVar7 = (int *)*piVar7;
    if ((piVar7 == (int *)0x0) || (piVar8 = (int *)piVar7[1], piVar8 == (int *)0x0))
    goto loc_F009F220;
    uVar2 = piVar7[2];
  } while( true );
}

