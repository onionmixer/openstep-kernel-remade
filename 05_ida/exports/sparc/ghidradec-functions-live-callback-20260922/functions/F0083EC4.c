
/* WARNING: Removing unreachable block (ram,0xf0083f60) */
/* WARNING: Removing unreachable block (ram,0xf0083f48) */
/* WARNING: Removing unreachable block (ram,0xf0083f1c) */
/* WARNING: Removing unreachable block (ram,0xf0083eec) */
/* WARNING: Removing unreachable block (ram,0xf0083f10) */
/* WARNING: Removing unreachable block (ram,0xf0083f78) */
/* WARNING: Removing unreachable block (ram,0xf0083f58) */
/* WARNING: Removing unreachable block (ram,0xf0083f68) */
/* WARNING: Removing unreachable block (ram,0xf0083ed8) */

undefined8 _kmem_alloc_wait(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  uVar2 = param_2 + _page_mask & ~_page_mask;
  do {
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    _lock_set_recursive(param_1);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
    iVar1 = param_1;
    _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar2,1);
    _lock_clear_recursive(param_1);
    if (iVar1 == 0) {
      _lock_done(param_1);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) < uVar2) {
        _lock_done(param_1);
        uVar3 = 0;
        goto locret_F0083F90;
      }
      _assert_wait(param_1,1);
      _lock_done(param_1);
      _thread_block();
    }
  } while (iVar1 != 0);
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
locret_F0083F90:
  return CONCAT44(iVar1,uVar3);
}

