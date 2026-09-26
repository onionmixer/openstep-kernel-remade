
/* WARNING: Removing unreachable block (ram,0xf006c69c) */
/* WARNING: Removing unreachable block (ram,0xf006c654) */
/* WARNING: Removing unreachable block (ram,0xf006c68c) */
/* WARNING: Removing unreachable block (ram,0xf006c63c) */
/* WARNING: Removing unreachable block (ram,0xf006c6c0) */
/* WARNING: Removing unreachable block (ram,0xf006c5f0) */
/* WARNING: Removing unreachable block (ram,0xf006c5d4) */
/* WARNING: Removing unreachable block (ram,0xf006c6b4) */
/* WARNING: Removing unreachable block (ram,0xf006c61c) */
/* WARNING: Removing unreachable block (ram,0xf006c678) */
/* WARNING: Removing unreachable block (ram,0xf006c694) */
/* WARNING: Removing unreachable block (ram,0xf006c660) */
/* WARNING: Removing unreachable block (ram,0xf006c6c8) */
/* WARNING: Removing unreachable block (ram,0xf006c570) */

undefined8 _remap_vnode(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  param_1 = (undefined4 *)*param_1;
  if (param_1[3] != 0) {
    _mfs_map_remove(param_1,param_1[2],param_1[2] + param_1[3],1);
  }
  uVar5 = (uint)param_2 & ~_page_mask;
  uVar6 = ((int)param_2 + _page_mask + param_3 & ~_page_mask) - uVar5;
  if (uVar6 < 0x10000) {
    uVar6 = 0x10000;
  }
  do {
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(_mfs_map + 0x14);
    _lock_write(_mfs_alloc_lock_data);
    iVar2 = _mfs_map;
    _vm_allocate_with_pager
              (_mfs_map,(undefined *)((int)register0x00000038 + -0xc),uVar6,1,*param_1,uVar5);
    if (iVar2 == 3) {
      do {
        do {
        } while (_vm_info_lock_data != 0);
        puVar3 = &_vm_info_lock_data;
        _simple_lock_try();
        puVar1 = _vm_info_queue;
      } while (puVar3 == (undefined4 *)0x0);
      param_2 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        _vm_info_dequeue();
        param_2 = puVar1;
      }
      _vm_info_lock_data = 0;
      if (param_2 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait(&_mfs_map,0);
        _mfs_alloc_blocks = _mfs_alloc_blocks + 1;
        _lock_done(_mfs_alloc_lock_data);
        _thread_block();
      }
      else {
        _lock_done(_mfs_alloc_lock_data);
        _mfs_memfree(param_2,1);
      }
      _lock_write(_mfs_alloc_lock_data);
    }
    else if (iVar2 != 0) {
      _printf(aUnexpectedErro,iVar2);
      _panic(aRemapVnode);
    }
    _lock_done(_mfs_alloc_lock_data);
  } while (iVar2 != 0);
  param_1[3] = uVar6;
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  param_1[4] = uVar5;
  param_1[2] = uVar4;
  return CONCAT44(param_2,1);
}
