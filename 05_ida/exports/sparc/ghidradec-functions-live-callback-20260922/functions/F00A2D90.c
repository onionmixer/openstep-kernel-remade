
/* WARNING: Removing unreachable block (ram,0xf00a2fe4) */
/* WARNING: Removing unreachable block (ram,0xf00a2f70) */
/* WARNING: Removing unreachable block (ram,0xf00a2f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a2e9c) */
/* WARNING: Removing unreachable block (ram,0xf00a2edc) */
/* WARNING: Removing unreachable block (ram,0xf00a2e18) */
/* WARNING: Removing unreachable block (ram,0xf00a2e00) */
/* WARNING: Removing unreachable block (ram,0xf00a2e40) */
/* WARNING: Removing unreachable block (ram,0xf00a2e84) */
/* WARNING: Removing unreachable block (ram,0xf00a2f1c) */
/* WARNING: Removing unreachable block (ram,0xf00a2f68) */
/* WARNING: Removing unreachable block (ram,0xf00a2fd4) */
/* WARNING: Removing unreachable block (ram,0xf00a3014) */
/* WARNING: Removing unreachable block (ram,0xf00a2dec) */
/* WARNING: Removing unreachable block (ram,0xf00a2de0) */

undefined8 _pmap_dealloc_seg_entry(undefined4 *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
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
  dword_F013DF68 = dword_F013DF68 + 1;
  if ((param_1[2] == _kernel_pmap) ||
     ((_kernel_seg_entries <= param_1 && (param_1 <= _kernel_seg_entries_end)))) {
    _pmap_dealloc_kseg_entry(param_1);
    goto locret_F00A301C;
  }
  puVar2 = param_1;
  _check_ptbl();
  if (puVar2 != (undefined4 *)0x0) {
    _panic(aPmapDeallocSeg_1);
  }
  if (*(char *)((int)param_1 + 0xf) != '\0') {
    _panic(aPmapDeallocSeg_2);
  }
  if ((param_1[4] != 0) || (param_1[5] != 0)) {
    _panic(aPampDeallocSeg);
  }
  if (*(char *)((int)param_1 + 0xd) == '\x03') {
    *(undefined4 *)(param_1[2] + 0x10) = 0xfff;
    *(undefined4 *)(param_1[2] + 8) = 0;
    iVar3 = param_1[8];
    if (iVar3 == 0) {
loc_F00A2EE4:
      param_1[2] = 0;
    }
    else {
      _set_invalidptp(iVar3,param_1[9] & 0xfffc0000);
      if (*(char *)(iVar3 + 0xf) == '\0') {
        _pmap_dealloc_seg_entry(iVar3);
        param_1[2] = 0;
      }
      else {
        param_1[2] = 0;
      }
    }
  }
  else {
    if (*(char *)((int)param_1 + 0xd) == '\x02') {
      *(undefined4 *)(param_1[2] + 0xc) = 0xfff;
      *(undefined4 *)(param_1[2] + 4) = 0;
      if (param_1[8] != 0) {
        _set_invalidptp(param_1[8],param_1[9] & 0xff000000);
      }
      goto loc_F00A2EE4;
    }
    param_1[2] = 0;
  }
  DAT_f013de88._0_4_ = DAT_f013de88._0_4_ + -1;
  param_1 = (undefined4 *)param_1[1];
  if (*(sword *)((int)param_1 + 0x1e) == 0) {
    *(undefined2 *)((int)param_1 + 0x1e) = 1;
    _del_any_pool(&_seg_active,param_1);
    _add_pool(&_seg_semi_active,param_1);
    sVar1 = *(sword *)((int)param_1 + 0x1e);
  }
  else {
    *(sword *)((int)param_1 + 0x1e) = *(sword *)((int)param_1 + 0x1e) + 1;
    sVar1 = *(sword *)((int)param_1 + 0x1e);
  }
  if ((sVar1 == *(sword *)(param_1 + 7)) && (100 < dword_F013DFE8)) {
    _del_any_pool(&_seg_semi_active,param_1);
    iVar3 = param_1[1];
    _vm_mem_ppi();
    iVar4 = _pg_desc_tbl + iVar3 * 0x14;
    if ((*(int *)(iVar4 + 4) != _kernel_pmap) ||
       (((*(uint *)(iVar4 + 8) >> 8) * 0x1000 - param_1[2] != 0 ||
        (*(int *)(_pg_desc_tbl + iVar3 * 0x14) != 0)))) {
      _panic(aPmapDeallocSeg_3);
    }
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *param_1 = 0;
    _kmem_free(param_1[2]);
    DAT_f013de88._4_4_ = DAT_f013de88._4_4_ - (uint)word_F013DE74;
    param_1[2] = 0;
    param_1[1] = 0;
    _add_pool(&_seg_free);
  }
locret_F00A301C:
  return CONCAT44(param_2,param_1);
}

