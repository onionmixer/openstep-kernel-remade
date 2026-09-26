
/* WARNING: Removing unreachable block (ram,0xf000e3cc) */
/* WARNING: Removing unreachable block (ram,0xf000e3ec) */
/* WARNING: Removing unreachable block (ram,0xf000e398) */
/* WARNING: Removing unreachable block (ram,0xf000e3b4) */
/* WARNING: Removing unreachable block (ram,0xf000e3e0) */
/* WARNING: Removing unreachable block (ram,0xf000e37c) */

undefined8 _obreak(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar3 = **(int **)(dword_F0133DDC + 0x24) + _page_mask & ~_page_mask;
  if (*(int *)(_active_u + 0x270) < (int)uVar3) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0xc;
  }
  else {
    iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
    _lock_write(iVar2);
    *(int *)(iVar2 + 0x4c) = *(int *)(iVar2 + 0x4c) + 1;
    iVar1 = iVar2;
    _vm_map_lookup_entry(iVar2,uVar3,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) =
           *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc);
      _lock_done(iVar2);
      _vm_allocate(iVar2,(undefined *)((int)register0x00000038 + -0x10),
                   uVar3 - *(int *)((int)register0x00000038 + -0x10),0);
      if (iVar2 != 0) {
        _uprintf(aCouldNotSbrkRe,iVar2);
      }
    }
    else {
      _lock_done(iVar2);
    }
  }
  return CONCAT44(param_2,param_1);
}
