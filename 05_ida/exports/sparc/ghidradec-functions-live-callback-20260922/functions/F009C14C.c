
/* WARNING: Removing unreachable block (ram,0xf009c2b4) */
/* WARNING: Removing unreachable block (ram,0xf009c274) */
/* WARNING: Removing unreachable block (ram,0xf009c2c8) */
/* WARNING: Removing unreachable block (ram,0xf009c264) */

undefined8 _pmap_bootstrap(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  dword_F013DF98 = 0;
  dword_F013DFB8 = 0;
  dword_F013DFA8 = 0;
  dword_F013DFC8 = 0;
  dword_F013DFE8 = 0;
  dword_F013DFD8 = 0;
  DAT_f013df94 = &_reg_active;
  _reg_active._0_4_ = &_reg_active;
  DAT_f013dfb4 = &_reg_semi_active;
  _reg_semi_active._0_4_ = &_reg_semi_active;
  DAT_f013dfa4 = &_reg_free;
  _reg_free._0_4_ = &_reg_free;
  DAT_f013dfc4 = &_seg_active;
  _seg_active._0_4_ = &_seg_active;
  DAT_f013dfe4 = &_seg_semi_active;
  _seg_semi_active._0_4_ = &_seg_semi_active;
  DAT_f013dfd4 = &_seg_free;
  _seg_free._0_4_ = &_seg_free;
  dword_F013DE1C = &_garbage;
  _garbage = &_garbage;
  uVar3 = param_1 + param_2 * 0x1c;
  iVar5 = 0;
  if (param_1 < uVar3) {
    piVar4 = (int *)(param_1 + 0x14);
    do {
      param_1 = param_1 + 0x1c;
      iVar5 = iVar5 + ((uint)(piVar4[1] - *piVar4) >> ((byte)_page_shift & 0x1f));
      piVar4 = piVar4 + 7;
    } while (param_1 < uVar3);
  }
  iVar7 = 0;
  iVar6 = 0;
  uVar3 = iVar5 * 0x14 + _page_mask & ~_page_mask;
  _vm_alloc_from_regions(uVar3,_page_size);
  _pg_desc_tbl = uVar3;
  _bzero();
  puVar1 = &_tmp_maps;
  do {
    iVar5 = _page_size;
    uVar3 = _econtig + _page_mask & ~_page_mask;
    _econtig = uVar3;
    puVar1[1] = uVar3;
    _pmap_map(uVar3,0,0,iVar5,7,1);
    iVar7 = iVar7 + 1;
    uVar2 = _kernel_pmap;
    _pmap_page_table_entry(_kernel_pmap,_econtig,3);
    *puVar1 = uVar2;
    *(undefined4 *)(DAT_f013dff8 + iVar6) = 0;
    puVar1 = puVar1 + 3;
    iVar6 = iVar6 + 0xc;
    _econtig = _econtig + _page_size;
  } while (iVar7 < 5);
  *param_3 = 0xf0000000;
  *param_4 = 0xff000000;
  return CONCAT44(0xf0111c00,iVar7);
}

