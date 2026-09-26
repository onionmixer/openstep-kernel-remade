
/* WARNING: Removing unreachable block (ram,0xf009e72c) */
/* WARNING: Removing unreachable block (ram,0xf009e6dc) */
/* WARNING: Removing unreachable block (ram,0xf009e654) */
/* WARNING: Removing unreachable block (ram,0xf009e5f0) */
/* WARNING: Removing unreachable block (ram,0xf009e5fc) */
/* WARNING: Removing unreachable block (ram,0xf009e66c) */
/* WARNING: Removing unreachable block (ram,0xf009e70c) */
/* WARNING: Removing unreachable block (ram,0xf009e748) */
/* WARNING: Removing unreachable block (ram,0xf009e5d0) */

undefined8 _pmap_copy_on_write(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int *piVar6;
  uint *puVar7;
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
  puVar7 = (uint *)0x0;
  if ((param_1 < _physmax) && (piVar6 = param_1, _vm_valid_page(), piVar6 != (int *)0x0)) {
    iVar1 = dword_F013DEDC + 1;
    dword_F013DEDC = iVar1;
    _splvm();
    piVar6 = param_1;
    _vm_mem_ppi();
    puVar5 = (undefined4 *)(_pg_desc_tbl + (int)piVar6 * 0x14);
    if (puVar5[1] != 0) {
      for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
        piVar6 = (int *)puVar5[1];
        *(uint *)((int)register0x00000038 + -0xc) = ((uint)puVar5[2] >> 8) << 0xc;
        do {
          do {
          } while (piVar6[6] != 0);
          piVar2 = piVar6 + 6;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        param_1 = piVar6;
        _pmap_page_table_entry(piVar6,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (param_1 == (int *)0x0) {
loc_F009E6DC:
          _panic(aPmapCopyOnWrit_1);
        }
        else {
          if (*(char *)((int)param_1 + 0xd) == '\x03') {
            iVar4 = *param_1;
            uVar3 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
          }
          else if (*(char *)((int)param_1 + 0xd) == '\x02') {
            iVar4 = *param_1;
            uVar3 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
          }
          else {
            iVar4 = *param_1;
            uVar3 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
          }
          puVar7 = (uint *)(iVar4 + uVar3);
          if ((*puVar7 & 3) != 2) goto loc_F009E6DC;
        }
        uVar3 = *puVar7 & 0x1c;
        if (((uVar3 == 4) || (uVar3 == 0xc)) || (uVar3 == 0x1c)) {
          piVar2 = piVar6;
          _vm_to_srmmu_prot(piVar6,1);
          *(int **)((int)register0x00000038 + -0x10) = param_1;
          _update_pte((undefined *)((int)register0x00000038 + -0x10),
                      *(undefined4 *)((int)register0x00000038 + -0xc),piVar2,*puVar7 >> 7 & 1);
        }
        piVar6[6] = 0;
      }
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
