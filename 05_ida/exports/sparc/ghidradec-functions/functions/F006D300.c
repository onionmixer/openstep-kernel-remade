
/* WARNING: Removing unreachable block (ram,0xf006d3ec) */
/* WARNING: Removing unreachable block (ram,0xf006d3c4) */
/* WARNING: Removing unreachable block (ram,0xf006d398) */
/* WARNING: Removing unreachable block (ram,0xf006d354) */
/* WARNING: Removing unreachable block (ram,0xf006d42c) */
/* WARNING: Removing unreachable block (ram,0xf006d3d4) */
/* WARNING: Removing unreachable block (ram,0xf006d414) */
/* WARNING: Removing unreachable block (ram,0xf006d32c) */

undefined8 _vno_flush(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *(int *)(*param_1 + 0x24);
  if (iVar6 != 0) {
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar2 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    do {
      do {
      } while (*(int *)(iVar6 + 0x10) != 0);
      piVar3 = (int *)(iVar6 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_3 = param_3 + param_2;
    uVar1 = ~_page_mask;
    param_2 = param_2 & uVar1;
    uVar4 = param_3 + _page_mask;
joined_r0xf006d384:
    do {
      if ((uVar4 & uVar1) <= param_2) goto loc_F006D44C;
      iVar5 = iVar6;
      _vm_page_lookup(iVar6,param_2);
      if (iVar5 != 0) {
        if ((*(uint *)(iVar5 + 0x20) & 0x80000000) != 0) {
          *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 0x40000000;
          _assert_wait(iVar5,0);
          *(undefined4 *)(iVar6 + 0x10) = 0;
          _vm_page_queue_lock = 0;
          _thread_block();
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar2 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar2 == (undefined4 *)0x0);
          do {
            do {
            } while (*(int *)(iVar6 + 0x10) != 0);
            piVar3 = (int *)(iVar6 + 0x10);
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          goto joined_r0xf006d384;
        }
        _vm_page_free(iVar5);
      }
      param_2 = param_2 + _page_size;
    } while( true );
  }
locret_F006D458:
  return CONCAT44(param_2,param_1);
loc_F006D44C:
  param_1 = (int *)(iVar6 + 0x10);
  *param_1 = 0;
  _vm_page_queue_lock = 0;
  goto locret_F006D458;
}
