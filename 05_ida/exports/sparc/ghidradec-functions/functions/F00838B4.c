
/* WARNING: Removing unreachable block (ram,0xf0083960) */
/* WARNING: Removing unreachable block (ram,0xf0083938) */
/* WARNING: Removing unreachable block (ram,0xf00838fc) */
/* WARNING: Removing unreachable block (ram,0xf0083998) */
/* WARNING: Removing unreachable block (ram,0xf0083950) */
/* WARNING: Removing unreachable block (ram,0xf008397c) */
/* WARNING: Removing unreachable block (ram,0xf00838e4) */

undefined8 sub_F00838B4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (param_3 == 0) {
    uVar5 = 1;
  }
  else {
    do {
      do {
        do {
        } while (*(int *)(param_1 + 0x10) != 0);
        piVar2 = (int *)(param_1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      while (iVar3 = param_1, _vm_page_alloc_sequential(param_1,param_2,1), iVar3 == 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        if (param_4 == 0) {
          uVar5 = 0;
          goto locret_F00839C8;
        }
        do {
          do {
          } while (_vm_pages_needed_lock != 0);
          puVar4 = &_vm_pages_needed_lock;
          _simple_lock_try();
        } while (puVar4 == (undefined4 *)0x0);
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
        do {
          do {
          } while (*(int *)(param_1 + 0x10) != 0);
          piVar2 = (int *)(param_1 + 0x10);
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_page_zero_fill(iVar3);
      iVar1 = _page_size;
      *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0x7fffffff;
      param_3 = param_3 - iVar1;
      param_2 = param_2 + iVar1;
    } while (param_3 != 0);
    uVar5 = 1;
  }
locret_F00839C8:
  return CONCAT44(param_2,uVar5);
}
