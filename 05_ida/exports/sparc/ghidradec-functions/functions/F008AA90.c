
/* WARNING: Removing unreachable block (ram,0xf008ab44) */
/* WARNING: Removing unreachable block (ram,0xf008ab1c) */
/* WARNING: Removing unreachable block (ram,0xf008aaf4) */
/* WARNING: Removing unreachable block (ram,0xf008aadc) */

undefined8 _vm_read(undefined4 param_1,uint param_2,uint param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  uVar1 = param_2 + _page_mask & ~_page_mask;
  if ((uVar1 == param_2) && (param_2 = param_3 + _page_mask & ~_page_mask, param_2 == param_3)) {
    iVar2 = _ipc_soft_map;
    _vm_allocate(_ipc_soft_map,(undefined *)((int)register0x00000038 + -0xc),param_2,1);
    if (iVar2 == 0) {
      iVar2 = _ipc_soft_map;
      _vm_map_copy(_ipc_soft_map,param_1,*(undefined4 *)((int)register0x00000038 + -0xc),param_2,
                   uVar1,0,0);
      if (iVar2 == 0) {
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *param_5 = param_2;
      }
      else {
        _vm_deallocate(_ipc_soft_map,*(undefined4 *)((int)register0x00000038 + -0xc),param_2);
      }
    }
    else {
      _printf(aVmReadKernelEr,iVar2);
      iVar2 = 6;
    }
  }
  else {
    iVar2 = 4;
  }
  return CONCAT44(param_2,iVar2);
}
