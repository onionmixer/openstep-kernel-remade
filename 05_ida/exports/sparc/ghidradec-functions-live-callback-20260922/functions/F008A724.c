
/* WARNING: Removing unreachable block (ram,0xf008a7fc) */
/* WARNING: Removing unreachable block (ram,0xf008a7b4) */
/* WARNING: Removing unreachable block (ram,0xf008a78c) */
/* WARNING: Removing unreachable block (ram,0xf008a764) */
/* WARNING: Removing unreachable block (ram,0xf008a7a8) */
/* WARNING: Removing unreachable block (ram,0xf008a7d4) */
/* WARNING: Removing unreachable block (ram,0xf008a810) */
/* WARNING: Removing unreachable block (ram,0xf008a75c) */

undefined8
_vm_allocate_with_pager
          (int param_1,uint *param_2,int param_3,undefined4 param_4,uint param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar2;
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
  if (param_1 == 0) {
    param_1 = 4;
  }
  else {
    *param_2 = *param_2 & ~_page_mask;
    uVar2 = param_3 + _page_mask & ~_page_mask;
    _lock_write(_vm_alloc_lock);
    uVar1 = param_5;
    _vm_object_lookup();
    DAT_f013c26c._0_4_ = DAT_f013c26c._0_4_ + 1;
    if (uVar1 == 0) {
      uVar1 = uVar2;
      _vm_object_allocate();
      if (param_5 != 0) {
        _vm_object_setpager();
        _vm_object_enter(uVar1,param_5);
      }
    }
    else {
      DAT_f013c26c._4_4_ = DAT_f013c26c._4_4_ + 1;
    }
    _lock_done(_vm_alloc_lock);
    *(uint *)(uVar1 + 0x44) = *(uint *)(uVar1 + 0x44) & 0xfffff7ff;
    _vm_map_find(param_1,uVar1,param_6,param_2,uVar2,param_4);
    if (param_1 != 0) {
      _vm_object_deallocate(uVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}

