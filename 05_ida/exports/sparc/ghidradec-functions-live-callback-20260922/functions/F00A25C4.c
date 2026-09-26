
/* WARNING: Removing unreachable block (ram,0xf00a2694) */
/* WARNING: Removing unreachable block (ram,0xf00a2610) */
/* WARNING: Removing unreachable block (ram,0xf00a262c) */

undefined8 _pmap_seg_entry(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
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
  dword_F013DF58 = dword_F013DF58 + 1;
  uVar4 = param_1 & ~_page_mask;
  if ((param_1 < _kernel_seg_tables_phys) ||
     (iVar1 = uVar4 - _kernel_seg_tables_phys, _kernel_seg_end < param_1)) {
    uVar2 = uVar4;
    _vm_mem_ppi();
    iVar1 = _pg_desc_tbl + uVar2 * 0x14;
    iVar3 = *(int *)(iVar1 + 0xc);
    if ((*(int *)(iVar1 + 4) != _kernel_pmap) ||
       (((*(uint *)(iVar1 + 8) >> 8) * 0x1000 - *(int *)(iVar3 + 8) != 0 ||
        (*(int *)(_pg_desc_tbl + uVar2 * 0x14) != 0)))) {
      _panic(aPmapSegEntryWr);
    }
  }
  else {
    udiv(iVar1,_page_size);
    iVar3 = _kernel_seg_pools + iVar1 * 0x20;
  }
  return CONCAT44(param_2,*(int *)(iVar3 + 0x18) + ((int)(param_1 - uVar4) >> 8) * 0x28);
}

