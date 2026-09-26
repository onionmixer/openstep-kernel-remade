
/* WARNING: Removing unreachable block (ram,0xf00a2584) */
/* WARNING: Removing unreachable block (ram,0xf00a2510) */
/* WARNING: Removing unreachable block (ram,0xf00a24cc) */
/* WARNING: Removing unreachable block (ram,0xf00a24bc) */
/* WARNING: Removing unreachable block (ram,0xf00a2508) */
/* WARNING: Removing unreachable block (ram,0xf00a2574) */
/* WARNING: Removing unreachable block (ram,0xf00a25b4) */
/* WARNING: Removing unreachable block (ram,0xf00a2484) */

undefined8 _pmap_dealloc_reg_entry(int *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  int iVar2;
  int iVar3;
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
  dword_F013DF54 = dword_F013DF54 + 1;
  iVar2 = *param_1;
  if (param_1 != _kernel_pmap) {
    if (0x10 < *(byte *)(iVar2 + 0xf)) {
      _panic(aPmapDeallocReg_1,*(undefined *)(iVar2 + 0xf));
    }
    *(undefined4 *)(iVar2 + 8) = 0;
    DAT_f013de94._0_4_ = DAT_f013de94._0_4_ + -1;
    param_1 = *(int **)(iVar2 + 4);
    if (*(sword *)((int)param_1 + 0x1e) == 0) {
      *(undefined2 *)((int)param_1 + 0x1e) = 1;
      _del_any_pool(&_reg_active,param_1);
      _add_pool(&_reg_semi_active,param_1);
      sVar1 = *(sword *)((int)param_1 + 0x1e);
    }
    else {
      *(sword *)((int)param_1 + 0x1e) = *(sword *)((int)param_1 + 0x1e) + 1;
      sVar1 = *(sword *)((int)param_1 + 0x1e);
    }
    if ((sVar1 == *(sword *)(param_1 + 7)) && (10 < dword_F013DFB8)) {
      _del_any_pool(&_reg_semi_active,param_1);
      iVar2 = param_1[1];
      _vm_mem_ppi();
      iVar3 = _pg_desc_tbl + iVar2 * 0x14;
      if ((*(int **)(iVar3 + 4) != _kernel_pmap) ||
         (((*(uint *)(iVar3 + 8) >> 8) * 0x1000 - param_1[2] != 0 ||
          (*(int *)(_pg_desc_tbl + iVar2 * 0x14) != 0)))) {
        _panic(aPmapDeallocReg_2);
      }
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *param_1 = 0;
      _kmem_free(param_1[2]);
      DAT_f013de94._4_4_ = DAT_f013de94._4_4_ - (uint)word_F013DE72;
      param_1[2] = 0;
      param_1[1] = 0;
      _add_pool(&_reg_free);
    }
  }
  return CONCAT44(param_2,param_1);
}
