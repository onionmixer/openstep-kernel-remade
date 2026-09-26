
/* WARNING: Removing unreachable block (ram,0xf0068658) */
/* WARNING: Removing unreachable block (ram,0xf006862c) */
/* WARNING: Removing unreachable block (ram,0xf006860c) */
/* WARNING: Removing unreachable block (ram,0xf0068650) */
/* WARNING: Removing unreachable block (ram,0xf006867c) */
/* WARNING: Removing unreachable block (ram,0xf00685cc) */

undefined8 _newStack(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  iVar1 = _kernel_map;
  _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),dword_F012F678);
  iVar2 = 0;
  if (iVar1 == 0) {
    _stackStats = _stackStats + 1;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar1 + 8) = 2;
    DAT_f013c0c4._0_4_ = DAT_f013c0c4._0_4_ + 1;
    _stack_init(iVar1 + 0xc);
    if (dword_F012F67C < 2) {
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
    }
    else {
      _lock_write(_stack_queue_lock);
      iVar1 = 1;
      iVar2 = *(int *)((int)register0x00000038 + -0xc) + dword_F012F678;
      if (1 < dword_F012F67C) {
        do {
          _stack_init(iVar2 + 0xc);
          sub_F0068384(iVar2);
          iVar1 = iVar1 + 1;
          iVar2 = iVar2 + dword_F012F678;
        } while (iVar1 < dword_F012F67C);
      }
      _lock_done(_stack_queue_lock);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
    }
    iVar2 = iVar2 + 0xc;
  }
  return CONCAT44(param_2,iVar2);
}

