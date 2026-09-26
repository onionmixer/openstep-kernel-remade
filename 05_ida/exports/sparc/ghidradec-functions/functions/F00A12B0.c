
/* WARNING: Removing unreachable block (ram,0xf00a1384) */
/* WARNING: Removing unreachable block (ram,0xf00a130c) */
/* WARNING: Removing unreachable block (ram,0xf00a1300) */
/* WARNING: Removing unreachable block (ram,0xf00a135c) */
/* WARNING: Removing unreachable block (ram,0xf00a13ac) */
/* WARNING: Removing unreachable block (ram,0xf00a12ec) */

undefined8 _pmap_vacflush(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 *puVar5;
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
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  dword_F013DEA0 = dword_F013DEA0 + 1;
  if (((_vac != 0) && (bVar6 = param_1 < _physmaxpfn, param_1 = param_1 << 0xc, bVar6)) &&
     (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _splvm();
    uVar2 = param_1;
    _vm_mem_ppi();
    puVar5 = (undefined4 *)(_pg_desc_tbl + uVar2 * 0x14);
    if ((puVar5[1] != 0) && (puVar5 != (undefined4 *)0x0)) {
      uVar2 = puVar5[2];
      do {
        iVar4 = 0;
        param_1 = puVar5[1];
        iVar3 = (uVar2 >> 8) << 0xc;
        _get_context();
        if (param_1 == 0xffffffff) {
          puVar5 = (undefined4 *)*puVar5;
        }
        else {
          do {
            if ((int)(uint)_pmap_info <= iVar4) break;
            _vac_pagectxflush(iVar3,param_1);
            iVar3 = iVar3 + 0x1000;
            iVar4 = iVar4 + 1;
          } while (param_1 != 0xffffffff);
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) break;
        uVar2 = puVar5[2];
      } while( true );
    }
    _splx(uVar1);
  }
  return CONCAT44(param_2,param_1);
}
