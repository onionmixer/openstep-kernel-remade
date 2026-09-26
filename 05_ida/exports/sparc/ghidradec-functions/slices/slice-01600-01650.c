/* GHIDRADEC_FUNCTION index=1600 start=0xf0072a40 */

/* WARNING: Removing unreachable block (ram,0xf0072ac8) */
/* WARNING: Removing unreachable block (ram,0xf0072a80) */
/* WARNING: Removing unreachable block (ram,0xf0072a5c) */
/* WARNING: Removing unreachable block (ram,0xf0072a64) */
/* WARNING: Removing unreachable block (ram,0xf0072aa4) */
/* WARNING: Removing unreachable block (ram,0xf0072ad4) */
/* WARNING: Removing unreachable block (ram,0xf0072a50) */

undefined8 _thread_depress_priority(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar3;
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
  piVar3 = (int *)(param_1 + 0x20);
  .umul(param_2,_hz);
  param_2 = param_2 + 999;
  .udiv(param_2,1000);
  iVar1 = param_2;
  _splusclock();
  do {
    do {
    } while (*piVar3 != 0);
    piVar2 = piVar3;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_1 + 0x184) == 0) {
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  else {
    _reset_timeout(param_1 + 0x150);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x50) = 0;
  if (param_2 != 0) {
    _set_timeout(param_1 + 0x150,param_2);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(piVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=1601 start=0xf0072ae4 */

/* WARNING: Removing unreachable block (ram,0xf0072b38) */
/* WARNING: Removing unreachable block (ram,0xf0072b04) */
/* WARNING: Removing unreachable block (ram,0xf0072b44) */
/* WARNING: Removing unreachable block (ram,0xf0072ae8) */

undefined8 _thread_depress_timeout(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (-1 < *(int *)(param_1 + 100)) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 100);
    *(undefined4 *)(param_1 + 100) = 0xffffffff;
    _compute_priority(param_1,0);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1602 start=0xf0072b54 */

/* WARNING: Removing unreachable block (ram,0xf0072bd8) */
/* WARNING: Removing unreachable block (ram,0xf0072b88) */
/* WARNING: Removing unreachable block (ram,0xf0072bbc) */
/* WARNING: Removing unreachable block (ram,0xf0072be4) */
/* WARNING: Removing unreachable block (ram,0xf0072b6c) */

undefined8 _thread_depress_abort(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
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
    uVar3 = 4;
  }
  else {
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar2 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (-1 < *(int *)(param_1 + 100)) {
      if (*(int *)(param_1 + 0x184) == 0) {
        uVar3 = *(undefined4 *)(param_1 + 100);
      }
      else {
        _reset_timeout(param_1 + 0x150);
        uVar3 = *(undefined4 *)(param_1 + 100);
      }
      *(undefined4 *)(param_1 + 0x50) = uVar3;
      *(undefined4 *)(param_1 + 100) = 0xffffffff;
      _compute_priority(param_1,0);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1603 start=0xf0072bf8 */

/* WARNING: Removing unreachable block (ram,0xf0072d9c) */
/* WARNING: Removing unreachable block (ram,0xf0072d54) */
/* WARNING: Removing unreachable block (ram,0xf0072d24) */
/* WARNING: Removing unreachable block (ram,0xf0072c98) */
/* WARNING: Removing unreachable block (ram,0xf0072c68) */
/* WARNING: Removing unreachable block (ram,0xf0072cb0) */
/* WARNING: Removing unreachable block (ram,0xf0072ce4) */
/* WARNING: Removing unreachable block (ram,0xf0072c80) */
/* WARNING: Removing unreachable block (ram,0xf0072d18) */
/* WARNING: Removing unreachable block (ram,0xf0072d34) */
/* WARNING: Removing unreachable block (ram,0xf0072d7c) */
/* WARNING: Removing unreachable block (ram,0xf0072da4) */
/* WARNING: Removing unreachable block (ram,0xf0072c0c) */

undefined8 _map_fd(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int *piVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar4 = *(uint *)(*(int *)(_active_threads + 0xc) + 0xc);
  _getf();
  if (param_1 == 0) {
    uVar6 = 4;
    goto locret_F0072DE4;
  }
  piVar5 = *(int **)(param_1 + 0x18);
  if (*(sword *)(param_1 + 0xc) == 1) {
    if (piVar5[10] != 1) {
      uVar6 = 4;
      goto locret_F0072DE4;
    }
    uVar3 = param_5 + _page_mask & ~_page_mask;
    if (param_4 == 0) {
      _copyin(param_3,(undefined *)((int)register0x00000038 + -0xc),4);
      uVar6 = 1;
      if (param_3 != 0) goto locret_F0072DE4;
      uVar1 = *(uint *)((int)register0x00000038 + -0xc) & ~_page_mask;
      uVar6 = 4;
      if (uVar1 != *(uint *)((int)register0x00000038 + -0xc)) goto locret_F0072DE4;
      uVar6 = uVar4;
      _vm_map_check_protection(uVar4,uVar1,uVar1 + uVar3,3);
      if (uVar6 == 0) goto loc_F0072CF8;
    }
    else {
      puVar2 = (undefined *)((int)register0x00000038 + -0xc);
      uVar6 = uVar4;
      _vm_allocate(uVar4,puVar2,param_5,1);
      if (uVar6 != 0) goto locret_F0072DE4;
      _copyout(puVar2,param_3,4);
      if (puVar2 != (undefined *)0x0) {
        _vm_deallocate(uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),param_5);
        uVar6 = 1;
        goto locret_F0072DE4;
      }
    }
    if (param_5 == 0) {
      uVar6 = 0;
    }
    else {
      _vnode_pager_setup(piVar5,0,0);
      uVar1 = uVar3;
      _pmap_create();
      _vm_map_create();
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      uVar6 = uVar1;
      _vm_allocate_with_pager();
      bVar7 = false;
      if (uVar6 == 0) {
        uVar6 = uVar4;
        _vm_map_copy(uVar4,uVar1,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3,0,0,0);
        bVar7 = uVar6 == 0;
      }
      if ((!bVar7) && (param_4 != 0)) {
        _vm_deallocate(uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3);
      }
      _vm_map_deallocate(uVar1);
      if (*(int *)(*piVar5 + 0x30) == 0) {
        **(sword **)(_active_u + 0x1c) = **(sword **)(_active_u + 0x1c) + 1;
        *(undefined4 *)(*piVar5 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
      }
    }
  }
  else {
loc_F0072CF8:
    uVar6 = 4;
  }
locret_F0072DE4:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1604 start=0xf0072dec */

sqword _null_port(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1605 start=0xf0072df8 */

undefined8 _kern_invalid(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,4);
}
/* GHIDRADEC_FUNCTION index=1606 start=0xf0072e04 */

/* WARNING: Removing unreachable block (ram,0xf0072e3c) */
/* WARNING: Removing unreachable block (ram,0xf0072e20) */

undefined8 _task_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  uVar2 = 0x8c;
  _zinit(0x8c,0x11800,0x2300,0,&aTasks);
  _task_zone = uVar2;
  _task_create(0,0,&_kernel_task);
  iVar1 = _kernel_task;
  *(undefined4 *)(_kernel_task + 0x4c) = 1;
  *(undefined4 *)(iVar1 + 0x50) = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1607 start=0xf0072e5c */

/* WARNING: Removing unreachable block (ram,0xf0072e7c) */
/* WARNING: Removing unreachable block (ram,0xf0072e70) */
/* WARNING: Removing unreachable block (ram,0xf0072eb4) */
/* WARNING: Removing unreachable block (ram,0xf0072e68) */

undefined8 _kernel_task_create(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
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
  _task_create(param_1,0,(undefined *)((int)register0x00000038 + -0xc));
  _task_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  _vm_map_deallocate(*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc));
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) = _kernel_map;
  }
  else {
    uVar1 = _kernel_map;
    _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0x10),
                   (undefined *)((int)register0x00000038 + -0x14),param_2,0);
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) = uVar1;
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(iVar2 + 0x50) = 1;
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1608 start=0xf0072ed8 */

/* WARNING: Removing unreachable block (ram,0xf007307c) */
/* WARNING: Removing unreachable block (ram,0xf007301c) */
/* WARNING: Removing unreachable block (ram,0xf0073044) */
/* WARNING: Removing unreachable block (ram,0xf0072f78) */
/* WARNING: Removing unreachable block (ram,0xf0072f48) */
/* WARNING: Removing unreachable block (ram,0xf0072f04) */
/* WARNING: Removing unreachable block (ram,0xf0072ef8) */
/* WARNING: Removing unreachable block (ram,0xf0072f10) */
/* WARNING: Removing unreachable block (ram,0xf0072f58) */
/* WARNING: Removing unreachable block (ram,0xf0072fb8) */
/* WARNING: Removing unreachable block (ram,0xf0072ff0) */
/* WARNING: Removing unreachable block (ram,0xf0073068) */
/* WARNING: Removing unreachable block (ram,0xf0073094) */
/* WARNING: Removing unreachable block (ram,0xf0072ee0) */

sqword _task_create(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar5;
  undefined4 unaff_i1;
  undefined *puVar6;
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
  puVar1 = _task_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    _panic(aTaskCreateNoMe);
  }
  uVar3 = _u_task_zone;
  _zalloc();
  puVar1[0xe] = uVar3;
  _utask_zero(puVar1);
  puVar1[1] = 2;
  uVar3 = _kernel_map;
  if (param_3 != &_kernel_task) {
    if (param_2 != 0) {
      iVar2 = param_1[3];
      _vm_map_fork();
      puVar1[3] = iVar2;
      goto loc_F0072F84;
    }
    uVar3 = 0;
    _pmap_create();
    _vm_map_create();
  }
  puVar1[3] = uVar3;
loc_F0072F84:
  *puVar1 = 0;
  puVar1[8] = puVar1 + 7;
  puVar1[7] = puVar1 + 7;
  puVar1[10] = 0;
  puVar1[6] = 0;
  puVar1[2] = 1;
  puVar1[0x11] = 0;
  puVar1[9] = 0;
  puVar1[0x10] = 0;
  puVar1[0x14] = 0;
  _ipc_task_init(puVar1,param_1);
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  if (param_1 == (int *)0x0) {
    puVar1[0x13] = 0;
    puVar6 = _default_pset;
    _pset_reference(_default_pset);
    puVar1[0x12] = 10;
    puVar5 = unk_F0135118;
  }
  else {
    puVar1[0x13] = param_1[0x13];
    do {
      do {
      } while (*param_1 != 0);
      piVar4 = param_1;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    puVar6 = (undefined *)param_1[0xb];
    if (*(int *)(puVar6 + 0x154) == 0) {
      puVar6 = _default_pset;
    }
    _pset_reference(puVar6);
    puVar1[0x12] = param_1[0x12];
    *param_1 = 0;
    puVar5 = puVar6 + 0x158;
  }
  do {
    do {
    } while (*(int *)puVar5 != 0);
    piVar4 = (int *)puVar5;
    _simple_lock_try();
  } while (piVar4 == (int *)0x0);
  _pset_add_task(puVar6,puVar1);
  *(undefined4 *)(puVar6 + 0x158) = 0;
  puVar1[0xc] = 1;
  puVar1[0xd] = 0;
  _ipc_task_enable(puVar1);
  *param_3 = puVar1;
  return ZEXT48(puVar6) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1609 start=0xf00730a8 */

/* WARNING: Removing unreachable block (ram,0xf0073144) */
/* WARNING: Removing unreachable block (ram,0xf0073134) */
/* WARNING: Removing unreachable block (ram,0xf0073120) */
/* WARNING: Removing unreachable block (ram,0xf007310c) */
/* WARNING: Removing unreachable block (ram,0xf007312c) */
/* WARNING: Removing unreachable block (ram,0xf007313c) */
/* WARNING: Removing unreachable block (ram,0xf0073154) */
/* WARNING: Removing unreachable block (ram,0xf00730c8) */

undefined8 _task_deallocate(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = param_1[1];
    *param_1 = 0;
    param_1[1] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      iVar2 = param_1[0xb];
      do {
        do {
        } while (*(int *)(iVar2 + 0x158) != 0);
        piVar1 = (int *)(iVar2 + 0x158);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      _pset_remove_task(iVar2,param_1);
      *(undefined4 *)(iVar2 + 0x158) = 0;
      _pset_deallocate(iVar2);
      _vm_map_deallocate(param_1[3]);
      _ipc_space_release(param_1[0x22]);
      _utask_free(param_1[0xe]);
      _zfree(_task_zone,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1610 start=0xf0073164 */

/* WARNING: Removing unreachable block (ram,0xf0073184) */

undefined8 _task_reference(int *param_1,undefined4 param_2)

{
  int *piVar1;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *param_1 = 0;
    param_1[1] = param_1[1] + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1611 start=0xf00731b0 */

/* WARNING: Removing unreachable block (ram,0xf0073284) */
/* WARNING: Removing unreachable block (ram,0xf0073564) */
/* WARNING: Removing unreachable block (ram,0xf0073510) */
/* WARNING: Removing unreachable block (ram,0xf00734d4) */
/* WARNING: Removing unreachable block (ram,0xf00734a4) */
/* WARNING: Removing unreachable block (ram,0xf0073484) */
/* WARNING: Removing unreachable block (ram,0xf0073470) */
/* WARNING: Removing unreachable block (ram,0xf007343c) */
/* WARNING: Removing unreachable block (ram,0xf0073428) */
/* WARNING: Removing unreachable block (ram,0xf00732d4) */
/* WARNING: Removing unreachable block (ram,0xf0073258) */
/* WARNING: Removing unreachable block (ram,0xf0073214) */
/* WARNING: Removing unreachable block (ram,0xf00733d8) */
/* WARNING: Removing unreachable block (ram,0xf00733a0) */
/* WARNING: Removing unreachable block (ram,0xf0073324) */
/* WARNING: Removing unreachable block (ram,0xf0073370) */
/* WARNING: Removing unreachable block (ram,0xf0073300) */
/* WARNING: Removing unreachable block (ram,0xf0073384) */
/* WARNING: Removing unreachable block (ram,0xf00733fc) */
/* WARNING: Removing unreachable block (ram,0xf00731f0) */
/* WARNING: Removing unreachable block (ram,0xf0073230) */
/* WARNING: Removing unreachable block (ram,0xf00732c8) */
/* WARNING: Removing unreachable block (ram,0xf00732dc) */
/* WARNING: Removing unreachable block (ram,0xf0073430) */
/* WARNING: Removing unreachable block (ram,0xf0073454) */
/* WARNING: Removing unreachable block (ram,0xf007347c) */
/* WARNING: Removing unreachable block (ram,0xf007348c) */
/* WARNING: Removing unreachable block (ram,0xf00734cc) */
/* WARNING: Removing unreachable block (ram,0xf00734fc) */
/* WARNING: Removing unreachable block (ram,0xf007352c) */
/* WARNING: Removing unreachable block (ram,0xf0073570) */
/* WARNING: Removing unreachable block (ram,0xf00733e8) */
/* WARNING: Removing unreachable block (ram,0xf007334c) */

undefined8 _task_terminate(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_threads;
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
  if (param_1 == (int *)0x0) {
    uVar7 = 4;
    goto locret_F007357C;
  }
  piVar6 = param_1 + 7;
  piVar5 = *(int **)(_active_threads + 0xc);
  if (param_1 == piVar5) {
    do {
      do {
      } while (*param_1 != 0);
      piVar5 = param_1;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    iVar2 = param_1[2];
    if (iVar2 == 0) {
loc_F0073418:
      *param_1 = 0;
      uVar7 = 5;
      goto locret_F007357C;
    }
    _splusclock();
    do {
      do {
      } while (param_1[10] != 0);
      piVar5 = param_1 + 10;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    do {
      do {
      } while (*(int *)(iVar1 + 0x20) != 0);
      piVar5 = (int *)(iVar1 + 0x20);
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    if (*(int *)(iVar1 + 0x188) != 0) {
      param_1[2] = 0;
      piVar4 = *(int **)(iVar1 + 0x10);
      piVar5 = *(int **)(iVar1 + 0x14);
      if (piVar6 == piVar4) {
        param_1[8] = (int)piVar5;
      }
      else {
        piVar4[5] = (int)piVar5;
      }
      if (piVar6 == piVar5) {
        *piVar6 = (int)piVar4;
      }
      else {
        piVar5[4] = (int)piVar4;
      }
      *(undefined4 *)(iVar1 + 0x20) = 0;
      param_1[10] = 0;
      _splx(iVar2);
      *param_1 = 0;
      _ipc_thread_disable(iVar1);
      _ipc_thread_terminate(iVar1);
loc_F0073428:
      _ipc_task_disable(param_1);
      _task_hold(param_1);
      _task_dowait(param_1,1);
      do {
        do {
        } while (*param_1 != 0);
        piVar5 = param_1;
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      piVar5 = (int *)*piVar6;
      while (piVar6 != piVar5) {
        iVar2 = *piVar6;
        _thread_reference(iVar2);
        *param_1 = 0;
        _thread_force_terminate(iVar2);
        _thread_deallocate(iVar2);
        _thread_block_with_continuation(0);
        do {
          do {
          } while (*param_1 != 0);
          piVar5 = param_1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        piVar5 = (int *)*piVar6;
      }
      *param_1 = 0;
      _ipc_task_terminate(param_1);
      _task_deallocate(param_1);
      if (*(int **)(iVar1 + 0xc) == param_1) {
        do {
          do {
          } while (*param_1 != 0);
          piVar5 = param_1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        _splusclock();
        do {
          do {
          } while (param_1[10] != 0);
          piVar4 = param_1 + 10;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        piVar4 = (int *)param_1[8];
        if (piVar6 == piVar4) {
          *piVar6 = iVar1;
        }
        else {
          piVar4[4] = iVar1;
        }
        *(int **)(iVar1 + 0x14) = piVar4;
        *(int **)(iVar1 + 0x10) = piVar6;
        param_1[8] = iVar1;
        param_1[10] = 0;
        _splx(piVar5);
        *param_1 = 0;
        _thread_terminate(iVar1);
        uVar7 = 0;
      }
      else {
        uVar7 = 0;
      }
      goto locret_F007357C;
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
    param_1[10] = 0;
    _splx(iVar2);
    *param_1 = 0;
  }
  else {
    if (param_1 < piVar5) {
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*piVar5 != 0);
        piVar4 = piVar5;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
    }
    else {
      do {
        do {
        } while (*piVar5 != 0);
        piVar4 = piVar5;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
    }
    _splusclock();
    do {
      do {
      } while (*(int *)(iVar1 + 0x20) != 0);
      piVar3 = (int *)(iVar1 + 0x20);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if ((piVar5[2] != 0) && (*(int *)(iVar1 + 0x188) != 0)) {
      *(undefined4 *)(iVar1 + 0x20) = 0;
      _splx(piVar4);
      *piVar5 = 0;
      if (param_1[2] != 0) {
        param_1[2] = 0;
        *param_1 = 0;
        goto loc_F0073428;
      }
      goto loc_F0073418;
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
    _splx(piVar4);
    *param_1 = 0;
    *piVar5 = 0;
  }
  _thread_terminate(iVar1);
  uVar7 = 5;
locret_F007357C:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1612 start=0xf0073584 */

/* WARNING: Removing unreachable block (ram,0xf00735f4) */
/* WARNING: Removing unreachable block (ram,0xf00735a0) */

undefined8 _task_hold(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _active_threads;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar3 = param_1;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  if (param_1[2] == 0) {
    *param_1 = 0;
    uVar4 = 5;
  }
  else {
    piVar3 = (int *)param_1[7];
    param_1[6] = param_1[6] + 1;
    if (param_1 + 7 != piVar3) {
      iVar1 = (int)piVar3 - iVar2;
      do {
        if (iVar1 == 0) {
          piVar3 = (int *)piVar3[4];
        }
        else {
          _thread_hold(piVar3);
          piVar3 = (int *)piVar3[4];
        }
        iVar1 = (int)piVar3 - iVar2;
      } while (param_1 + 7 != piVar3);
    }
    *param_1 = 0;
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1613 start=0xf007361c */

/* WARNING: Removing unreachable block (ram,0xf00736d4) */
/* WARNING: Removing unreachable block (ram,0xf00736ac) */
/* WARNING: Removing unreachable block (ram,0xf0073694) */
/* WARNING: Removing unreachable block (ram,0xf00736b8) */
/* WARNING: Removing unreachable block (ram,0xf0073708) */
/* WARNING: Removing unreachable block (ram,0xf0073644) */

undefined8 _task_dowait(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
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
  
  piVar1 = _active_threads;
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
  uVar7 = 0;
  piVar6 = param_1 + 7;
  piVar5 = (int *)0x0;
  do {
    do {
    } while (*param_1 != 0);
    piVar2 = param_1;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (piVar6 != (int *)*piVar6) {
    iVar3 = param_1[2];
    piVar2 = (int *)*piVar6;
    while ((iVar3 != 0 || (param_2 != 0))) {
      if (piVar2 == piVar1) {
        piVar4 = (int *)piVar2[4];
      }
      else {
        _thread_reference(piVar2);
        *param_1 = 0;
        if (piVar5 != (int *)0x0) {
          _thread_deallocate(piVar5);
        }
        _thread_dowait(piVar2,1);
        do {
          do {
          } while (*param_1 != 0);
          piVar5 = param_1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        piVar4 = (int *)piVar2[4];
        piVar5 = piVar2;
      }
      if (piVar6 == piVar4) goto loc_F00736F8;
      iVar3 = param_1[2];
      piVar2 = piVar4;
    }
    uVar7 = 5;
  }
loc_F00736F8:
  *param_1 = 0;
  if (piVar5 != (int *)0x0) {
    _thread_deallocate(piVar5);
  }
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1614 start=0xf0073718 */

/* WARNING: Removing unreachable block (ram,0xf0073778) */
/* WARNING: Removing unreachable block (ram,0xf007372c) */

undefined8 _task_release(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int *piVar2;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_1[2] == 0) {
    *param_1 = 0;
    uVar3 = 5;
  }
  else {
    piVar1 = (int *)param_1[7];
    param_1[6] = param_1[6] + -1;
    if (param_1 + 7 != piVar1) {
      for (piVar2 = (int *)piVar1[4]; _thread_release(piVar1), param_1 + 7 != piVar2;
          piVar2 = (int *)piVar2[4]) {
        piVar1 = piVar2;
      }
    }
    *param_1 = 0;
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1615 start=0xf00737a0 */

/* WARNING: Removing unreachable block (ram,0xf0073830) */
/* WARNING: Removing unreachable block (ram,0xf0073808) */
/* WARNING: Removing unreachable block (ram,0xf00737f0) */
/* WARNING: Removing unreachable block (ram,0xf0073814) */
/* WARNING: Removing unreachable block (ram,0xf0073864) */
/* WARNING: Removing unreachable block (ram,0xf00737c4) */

sqword _task_halt(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int *piVar5;
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
  
  iVar2 = _active_threads;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar3 = param_1;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  piVar4 = (int *)param_1[7];
  iVar1 = (int)piVar4 - iVar2;
  piVar3 = (int *)0x0;
  while (param_1 + 7 != piVar4) {
    if (iVar1 == 0) {
      piVar5 = (int *)piVar4[4];
      piVar4 = piVar3;
    }
    else {
      _thread_reference(piVar4);
      *param_1 = 0;
      if (piVar3 != (int *)0x0) {
        _thread_deallocate(piVar3);
      }
      _thread_halt(piVar4,1);
      do {
        do {
        } while (*param_1 != 0);
        piVar3 = param_1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      piVar5 = (int *)piVar4[4];
    }
    iVar1 = (int)piVar5 - iVar2;
    piVar3 = piVar4;
    piVar4 = piVar5;
  }
  *param_1 = 0;
  if (piVar3 != (int *)0x0) {
    _thread_deallocate(piVar3);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1616 start=0xf0073874 */

/* WARNING: Removing unreachable block (ram,0xf00738e8) */
/* WARNING: Removing unreachable block (ram,0xf0073a14) */
/* WARNING: Removing unreachable block (ram,0xf00739e0) */
/* WARNING: Removing unreachable block (ram,0xf00739a8) */
/* WARNING: Removing unreachable block (ram,0xf0073924) */
/* WARNING: Removing unreachable block (ram,0xf0073980) */
/* WARNING: Removing unreachable block (ram,0xf00739c0) */
/* WARNING: Removing unreachable block (ram,0xf00739ec) */
/* WARNING: Removing unreachable block (ram,0xf0073968) */
/* WARNING: Removing unreachable block (ram,0xf00738f4) */
/* WARNING: Removing unreachable block (ram,0xf00738a0) */

undefined8 _task_threads(int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  uint uVar7;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 *puVar9;
  undefined4 unaff_i0;
  undefined4 uVar10;
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
  if (param_1 == (int *)0x0) {
    uVar10 = 4;
  }
  else {
    puVar9 = (undefined4 *)0x0;
    puVar6 = (undefined4 *)0x0;
    do {
      do {
        do {
        } while (*param_1 != 0);
        piVar1 = param_1;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (param_1[2] == 0) {
        *param_1 = 0;
        uVar10 = 5;
        goto locret_F0073A30;
      }
      uVar7 = param_1[9];
      puVar8 = (undefined4 *)(uVar7 * 4);
      if (puVar8 < puVar6 || (int)puVar8 - (int)puVar6 == 0) {
        uVar3 = 0;
        iVar4 = param_1[7];
        if (uVar7 != 0) {
          iVar5 = 0;
          do {
            _thread_reference(iVar4);
            *(int *)(iVar5 + (int)puVar9) = iVar4;
            iVar5 = iVar5 + 4;
            uVar3 = uVar3 + 1;
            iVar4 = *(int *)(iVar4 + 0x10);
          } while (uVar3 < uVar7);
        }
        *param_1 = 0;
        if (uVar7 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (puVar6 != (undefined4 *)0x0) {
            _kfree(puVar9,puVar6);
            uVar10 = 0;
            goto locret_F0073A30;
          }
        }
        else {
          if (puVar8 < puVar6) {
            puVar2 = puVar8;
            _kalloc();
            if (puVar2 == (undefined4 *)0x0) {
              uVar3 = 0;
              iVar4 = 0;
              if (uVar7 != 0) {
                do {
                  uVar3 = uVar3 + 1;
                  _thread_deallocate(*(undefined4 *)(iVar4 + (int)puVar9));
                  iVar4 = iVar4 + 4;
                } while (uVar3 < uVar7);
              }
              _kfree(puVar9,puVar6);
              uVar10 = 6;
              goto locret_F0073A30;
            }
            _bcopy(puVar9,puVar2,puVar8);
            _kfree(puVar9,puVar6);
            *param_2 = (int)puVar2;
          }
          else {
            *param_2 = (int)puVar9;
            puVar2 = puVar9;
          }
          uVar3 = 0;
          *param_3 = uVar7;
          if (uVar7 != 0) {
            do {
              uVar10 = *puVar2;
              uVar3 = uVar3 + 1;
              _convert_thread_to_port();
              *puVar2 = uVar10;
              puVar2 = puVar2 + 1;
            } while (uVar3 < uVar7);
          }
        }
        uVar10 = 0;
        goto locret_F0073A30;
      }
      *param_1 = 0;
      if (puVar6 != (undefined4 *)0x0) {
        _kfree(puVar9,puVar6);
      }
      puVar9 = puVar8;
      _kalloc();
      puVar6 = puVar8;
    } while (puVar9 != (undefined4 *)0x0);
    uVar10 = 6;
  }
locret_F0073A30:
  return CONCAT44(param_2,uVar10);
}
/* GHIDRADEC_FUNCTION index=1617 start=0xf0073a38 */

/* WARNING: Removing unreachable block (ram,0xf0073aec) */
/* WARNING: Removing unreachable block (ram,0xf0073ab4) */
/* WARNING: Removing unreachable block (ram,0xf0073a9c) */
/* WARNING: Removing unreachable block (ram,0xf0073ae4) */
/* WARNING: Removing unreachable block (ram,0xf0073b08) */
/* WARNING: Removing unreachable block (ram,0xf0073a60) */

undefined8 _task_suspend(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  if (param_1 == (int *)0x0) {
    uVar3 = 4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = param_1[0x11];
    param_1[0x11] = iVar2 + 1;
    *param_1 = 0;
    if (iVar2 + 1 == 1) {
      piVar1 = param_1;
      _task_hold();
      if (piVar1 == (int *)0x0) {
        piVar1 = param_1;
        _task_dowait(param_1,0);
        if (piVar1 == (int *)0x0) {
          uVar3 = 0;
          if (*(int **)(_active_threads + 0xc) == param_1) {
            _thread_hold(_active_threads);
            _splusclock();
            _need_ast = _need_ast | 4;
            uVar3 = 0;
            _splx();
          }
        }
        else {
          uVar3 = 5;
        }
      }
      else {
        uVar3 = 5;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1618 start=0xf0073b18 */

/* WARNING: Removing unreachable block (ram,0xf0073b98) */
/* WARNING: Removing unreachable block (ram,0xf0073b40) */

undefined8 _task_resume(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  if (param_1 == (int *)0x0) {
    param_1 = (int *)0x4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = param_1[0x11] + -1;
    if (param_1[0x11] < 1) {
      *param_1 = 0;
      param_1 = (int *)0x5;
    }
    else {
      param_1[0x11] = iVar2;
      *param_1 = 0;
      if (iVar2 == 0) {
        _task_release(param_1);
      }
      else {
        param_1 = (int *)0x0;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1619 start=0xf0073bac */

/* WARNING: Removing unreachable block (ram,0xf0073d14) */
/* WARNING: Removing unreachable block (ram,0xf0073ce0) */
/* WARNING: Removing unreachable block (ram,0xf0073c30) */
/* WARNING: Removing unreachable block (ram,0xf0073cb0) */
/* WARNING: Removing unreachable block (ram,0xf0073cfc) */
/* WARNING: Removing unreachable block (ram,0xf0073d20) */
/* WARNING: Removing unreachable block (ram,0xf0073c14) */

undefined8 _task_info(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
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
  if (param_1 == (int *)0x0) {
loc_F0073DCC:
    uVar5 = 4;
  }
  else {
    if (param_2 == (int *)0x1) {
      if (*param_4 < 8) goto loc_F0073DCC;
      iVar1 = _kernel_map;
      if (param_1 != _kernel_task) {
        iVar1 = param_1[3];
      }
      param_3[2] = *(int *)(iVar1 + 0x28);
      iVar1 = *(int *)(*(int *)(iVar1 + 0x24) + 0x20);
      .umul(iVar1,_page_size);
      param_3[3] = iVar1;
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      param_3[1] = param_1[0x12];
      *param_3 = param_1[0x11];
      param_3[4] = param_1[0x15];
      param_3[5] = param_1[0x16];
      param_3[6] = param_1[0x17];
      param_3[7] = param_1[0x18];
      *param_1 = 0;
      *param_4 = 8;
    }
    else {
      if (param_2 != (int *)0x3) {
        uVar5 = 4;
        goto locret_F0073DD8;
      }
      if (*param_4 < 4) {
        uVar5 = 4;
        goto locret_F0073DD8;
      }
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      do {
        do {
        } while (*param_1 != 0);
        piVar4 = param_1;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      piVar4 = (int *)param_1[7];
      if (param_1 + 7 != piVar4) {
        piVar2 = (int *)0xfff0bc00;
        do {
          param_2 = piVar4 + 8;
          _splusclock();
          do {
            do {
            } while (*param_2 != 0);
            piVar3 = param_2;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          _thread_read_times(piVar4,(undefined *)((int)register0x00000038 + -0x10),
                             (undefined *)((int)register0x00000038 + -0x18));
          piVar4[8] = 0;
          _splx(piVar2);
          param_3[1] = param_3[1] + *(int *)((int)register0x00000038 + -0xc);
          *param_3 = *param_3 + *(int *)((int)register0x00000038 + -0x10);
          if (999999 < param_3[1]) {
            param_3[1] = param_3[1] + -1000000;
            *param_3 = *param_3 + 1;
          }
          param_3[3] = param_3[3] + *(int *)((int)register0x00000038 + -0x14);
          param_3[2] = param_3[2] + *(int *)((int)register0x00000038 + -0x18);
          if (999999 < param_3[3]) {
            param_3[3] = param_3[3] + -1000000;
            param_3[2] = param_3[2] + 1;
          }
          piVar4 = (int *)piVar4[4];
          piVar2 = param_1 + 7;
        } while (piVar2 != piVar4);
      }
      *param_1 = 0;
      *param_4 = 4;
    }
    uVar5 = 0;
  }
locret_F0073DD8:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1620 start=0xf0073de0 */

/* WARNING: Removing unreachable block (ram,0xf0073e44) */
/* WARNING: Removing unreachable block (ram,0xf0073e74) */
/* WARNING: Removing unreachable block (ram,0xf0073e08) */

undefined8 _task_suspend_nowait(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  if (param_1 == (int *)0x0) {
    uVar3 = 4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = param_1[0x11];
    param_1[0x11] = iVar2 + 1;
    *param_1 = 0;
    if (iVar2 + 1 == 1) {
      piVar1 = param_1;
      _task_hold();
      if (piVar1 == (int *)0x0) {
        uVar3 = 0;
        if (*(int **)(_active_threads + 0xc) == param_1) {
          _thread_hold(_active_threads);
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 5;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1621 start=0xf0073e88 */

undefined8 _task_assign(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,5);
}
/* GHIDRADEC_FUNCTION index=1622 start=0xf0073e94 */

/* WARNING: Removing unreachable block (ram,0xf0073ea4) */

undefined8 _task_assign_default(undefined4 param_1,undefined4 param_2)

{
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
  _task_assign(param_1,_default_pset,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1623 start=0xf0073eb4 */

/* WARNING: Removing unreachable block (ram,0xf0073ecc) */

undefined8 _task_get_assignment(int param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 5;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x2c);
    _pset_reference();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1624 start=0xf0073ee0 */

/* WARNING: Removing unreachable block (ram,0xf0073f48) */
/* WARNING: Removing unreachable block (ram,0xf0073f14) */

undefined8 _task_priority(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar3;
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
  uVar2 = 0;
  if ((param_1 == (int *)0x0) || (0x1f < param_2)) {
    uVar2 = 4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar3 = param_1;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_1[0x12] = param_2;
    if (param_3 != 0) {
      for (piVar3 = (int *)param_1[7]; param_1 + 7 != piVar3; piVar3 = (int *)piVar3[4]) {
        piVar1 = piVar3;
        _thread_priority(piVar3,param_2,0);
        if (piVar1 != (int *)0x0) {
          uVar2 = 5;
        }
      }
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1625 start=0xf0073f7c */

undefined8 _current_task_EXTERNAL(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(_active_threads + 0xc));
}
/* GHIDRADEC_FUNCTION index=1626 start=0xf0073f94 */

undefined8 _current_map_EXTERNAL(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
}
/* GHIDRADEC_FUNCTION index=1627 start=0xf0073fb0 */

/* WARNING: Removing unreachable block (ram,0xf0073fc8) */

undefined8 _stack_privilege(int param_1,undefined4 param_2)

{
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
  if (param_1 != _active_threads) {
    _panic(aStackPrivilege);
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 *)(param_1 + 0x30) = _active_stacks;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1628 start=0xf0073ff0 */

/* WARNING: Removing unreachable block (ram,0xf00740cc) */
/* WARNING: Removing unreachable block (ram,0xf0074098) */
/* WARNING: Removing unreachable block (ram,0xf00740a0) */
/* WARNING: Removing unreachable block (ram,0xf00740f4) */
/* WARNING: Removing unreachable block (ram,0xf0074008) */

undefined8 _thread_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = 0x1a0;
  _zinit(0x1a0,0x34000,0x6800,0,&aThreads);
  DAT_f013c988._0_4_ = 0;
  DAT_f013c988._28_4_ = 2;
  DAT_f013c988._32_4_ = 0;
  DAT_f013c988._36_4_ = 0;
  DAT_f013c988._40_4_ = 0;
  DAT_f013c988._52_4_ = 0;
  DAT_f013c988._60_4_ = 0;
  DAT_f013c988._64_4_ = 0;
  DAT_f013c988._68_4_ = 0x102;
  DAT_f013c988._44_4_ = _thread_bootstrap_return;
  DAT_f013c988._48_4_ = 0;
  DAT_f013c988._76_4_ = 0x12;
  DAT_f013c988._84_4_ = 0;
  DAT_f013c988._88_4_ = 1;
  DAT_f013c988._92_4_ = 0xffffffff;
  DAT_f013c988._96_4_ = 0;
  DAT_f013c988._100_4_ = 0;
  DAT_f013c988._108_4_ = 0;
  DAT_f013c988._112_4_ = 0;
  DAT_f013c988._116_4_ = 0;
  DAT_f013c988._120_4_ = 0;
  DAT_f013c988._128_4_ = 0xffffffff;
  DAT_f013c988._132_4_ = 1;
  _thread_zone = uVar1;
  _timer_init(0xf013ca60);
  _timer_init(0xf013ca70);
  DAT_f013c988._248_4_ = 0;
  DAT_f013c988._252_4_ = 0;
  DAT_f013c988._256_4_ = 0;
  DAT_f013c988._260_4_ = 0;
  DAT_f013c988._264_4_ = 0;
  DAT_f013c988._268_4_ = 0;
  DAT_f013c988._384_4_ = 0;
  DAT_f013c988._388_4_ = 0;
  DAT_f013c988._396_4_ = 0;
  DAT_f013c988._400_4_ = 0;
  _initKernelStacks();
  DAT_f0135154 = &_reaper_queue;
  _reaper_queue._0_4_ = &_reaper_queue;
  _reaper_lock = 0;
  _stack_usage_lock = 0;
  _pcb_module_init();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1629 start=0xf0074104 */

/* WARNING: Removing unreachable block (ram,0xf007423c) */
/* WARNING: Removing unreachable block (ram,0xf0074398) */
/* WARNING: Removing unreachable block (ram,0xf007433c) */
/* WARNING: Removing unreachable block (ram,0xf00742d4) */
/* WARNING: Removing unreachable block (ram,0xf007428c) */
/* WARNING: Removing unreachable block (ram,0xf00741dc) */
/* WARNING: Removing unreachable block (ram,0xf00741a4) */
/* WARNING: Removing unreachable block (ram,0xf0074184) */
/* WARNING: Removing unreachable block (ram,0xf007416c) */
/* WARNING: Removing unreachable block (ram,0xf007415c) */
/* WARNING: Removing unreachable block (ram,0xf0074140) */
/* WARNING: Removing unreachable block (ram,0xf0074164) */
/* WARNING: Removing unreachable block (ram,0xf0074178) */
/* WARNING: Removing unreachable block (ram,0xf007418c) */
/* WARNING: Removing unreachable block (ram,0xf00741bc) */
/* WARNING: Removing unreachable block (ram,0xf0074200) */
/* WARNING: Removing unreachable block (ram,0xf00742a4) */
/* WARNING: Removing unreachable block (ram,0xf00742f0) */
/* WARNING: Removing unreachable block (ram,0xf0074390) */
/* WARNING: Removing unreachable block (ram,0xf0074364) */
/* WARNING: Removing unreachable block (ram,0xf007424c) */
/* WARNING: Removing unreachable block (ram,0xf007411c) */

undefined8 _thread_create(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  if (param_1 == (int *)0x0) {
    uVar6 = 4;
  }
  else {
    iVar1 = _thread_zone;
    _zalloc();
    if (iVar1 == 0) {
      uVar6 = 6;
    }
    else {
      _memcpy(iVar1,_thread_template,0x1a0);
      *(int **)(iVar1 + 0xc) = param_1;
      uVar6 = _sched_tick;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(undefined4 *)(iVar1 + 0x70) = uVar6;
      _thread_timeout_setup(iVar1);
      _pcb_init(iVar1);
      _ipc_thread_init(iVar1);
      uVar6 = _u_thread_zone;
      _zalloc();
      *(undefined4 *)(iVar1 + 0x84) = uVar6;
      _uarea_zero(iVar1);
      _uarea_init(iVar1);
      do {
        do {
        } while (*param_1 != 0);
        piVar3 = param_1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      puVar5 = (undefined *)param_1[0xb];
      _pset_reference(puVar5);
      *param_1 = 0;
      while( true ) {
        do {
          do {
          } while (*(int *)(puVar5 + 0x158) != 0);
          piVar3 = (int *)(puVar5 + 0x158);
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        do {
          do {
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        puVar4 = (undefined *)param_1[0xb];
        iVar2 = (int)puVar4 - (int)puVar5;
        if (*(int *)(puVar4 + 0x154) == 0) {
          puVar4 = _default_pset;
          iVar2 = (int)_default_pset - (int)puVar5;
        }
        if (iVar2 == 0) break;
        _pset_reference(puVar4);
        *param_1 = 0;
        *(undefined4 *)(puVar5 + 0x158) = 0;
        _pset_deallocate(puVar5);
        puVar5 = puVar4;
      }
      *(int *)(iVar1 + 0x50) = param_1[0x12];
      if (*(int *)(puVar5 + 0x164) < *(int *)(iVar1 + 0x54)) {
        *(int *)(iVar1 + 0x54) = *(int *)(puVar5 + 0x164);
      }
      if (*(int *)(iVar1 + 0x54) < *(int *)(iVar1 + 0x50)) {
        *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x54);
      }
      _compute_priority(iVar1,1);
      *(int *)(iVar1 + 0x40) = param_1[6] + 1;
      _pset_add_thread(puVar5,iVar1);
      if (*(int *)(puVar5 + 0x128) == 0) {
        iVar2 = param_1[1];
      }
      else {
        *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + 1;
        iVar2 = param_1[1];
      }
      iVar2 = iVar2 + 1;
      param_1[1] = iVar2;
      _splusclock();
      do {
        do {
        } while (param_1[10] != 0);
        piVar3 = param_1 + 10;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[9] = param_1[9] + 1;
      piVar3 = (int *)param_1[8];
      if (param_1 + 7 == piVar3) {
        param_1[7] = iVar1;
      }
      else {
        piVar3[4] = iVar1;
      }
      *(int **)(iVar1 + 0x14) = piVar3;
      *(int **)(iVar1 + 0x10) = param_1 + 7;
      param_1[8] = iVar1;
      param_1[10] = 0;
      _splx(iVar2);
      *(undefined4 *)(iVar1 + 0x188) = 1;
      if (param_1[2] == 0) {
        *param_1 = 0;
        *(undefined4 *)(puVar5 + 0x158) = 0;
        _thread_terminate(iVar1);
        _thread_deallocate(iVar1);
        uVar6 = 5;
      }
      else {
        *param_1 = 0;
        *(undefined4 *)(puVar5 + 0x158) = 0;
        _ipc_thread_enable(iVar1);
        uVar6 = 0;
        _nthreads = _nthreads + 1;
        *param_2 = iVar1;
      }
    }
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1630 start=0xf00743ac */

/* WARNING: Removing unreachable block (ram,0xf00744ec) */
/* WARNING: Removing unreachable block (ram,0xf0074734) */
/* WARNING: Removing unreachable block (ram,0xf0074714) */
/* WARNING: Removing unreachable block (ram,0xf00746e4) */
/* WARNING: Removing unreachable block (ram,0xf00746c4) */
/* WARNING: Removing unreachable block (ram,0xf00746a0) */
/* WARNING: Removing unreachable block (ram,0xf0074668) */
/* WARNING: Removing unreachable block (ram,0xf0074634) */
/* WARNING: Removing unreachable block (ram,0xf0074540) */
/* WARNING: Removing unreachable block (ram,0xf0074510) */
/* WARNING: Removing unreachable block (ram,0xf0074494) */
/* WARNING: Removing unreachable block (ram,0xf0074464) */
/* WARNING: Removing unreachable block (ram,0xf007441c) */
/* WARNING: Removing unreachable block (ram,0xf00743d8) */
/* WARNING: Removing unreachable block (ram,0xf007443c) */
/* WARNING: Removing unreachable block (ram,0xf0074478) */
/* WARNING: Removing unreachable block (ram,0xf00744bc) */
/* WARNING: Removing unreachable block (ram,0xf0074528) */
/* WARNING: Removing unreachable block (ram,0xf0074624) */
/* WARNING: Removing unreachable block (ram,0xf0074644) */
/* WARNING: Removing unreachable block (ram,0xf0074680) */
/* WARNING: Removing unreachable block (ram,0xf00746bc) */
/* WARNING: Removing unreachable block (ram,0xf00746dc) */
/* WARNING: Removing unreachable block (ram,0xf00746ec) */
/* WARNING: Removing unreachable block (ram,0xf007471c) */
/* WARNING: Removing unreachable block (ram,0xf0074744) */
/* WARNING: Removing unreachable block (ram,0xf0074404) */
/* WARNING: Removing unreachable block (ram,0xf00743bc) */

undefined8 _thread_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar6;
  int iVar7;
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
  if (param_1 != 0) {
    iVar7 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar6 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    iVar1 = *(int *)(param_1 + 0x24) + -1;
    *(int *)(param_1 + 0x24) = iVar1;
    if (iVar1 < 1) {
      *(undefined4 *)(param_1 + 0x24) = 1;
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(iVar7);
      iVar7 = *(int *)(param_1 + 400);
      do {
        do {
        } while (*(int *)(iVar7 + 0x158) != 0);
        piVar6 = (int *)(iVar7 + 0x158);
        _simple_lock_try();
      } while (piVar6 == (int *)0x0);
      piVar6 = *(int **)(param_1 + 0xc);
      do {
        do {
        } while (*piVar6 != 0);
        piVar2 = piVar6;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      _splusclock();
      do {
        do {
        } while (piVar6[10] != 0);
        piVar4 = piVar6 + 10;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      iVar1 = *(int *)(param_1 + 0x24) + -1;
      *(int *)(param_1 + 0x24) = iVar1;
      if (iVar1 < 1) {
        if (*(int *)(param_1 + 0x14c) == 0) {
          iVar1 = *(int *)(param_1 + 0x184);
        }
        else {
          _reset_timeout(param_1 + 0x118);
          iVar1 = *(int *)(param_1 + 0x184);
        }
        if (iVar1 != 0) {
          _reset_timeout(param_1 + 0x150);
        }
        *(undefined4 *)(param_1 + 100) = 0xffffffff;
        _thread_read_times(param_1,(undefined *)((int)register0x00000038 + -0x10),
                           (undefined *)((int)register0x00000038 + -0x18));
        piVar6[0x16] = piVar6[0x16] + *(int *)((int)register0x00000038 + -0xc);
        piVar6[0x15] = piVar6[0x15] + *(int *)((int)register0x00000038 + -0x10);
        if (999999 < piVar6[0x16]) {
          piVar6[0x16] = piVar6[0x16] + -1000000;
          piVar6[0x15] = piVar6[0x15] + 1;
        }
        piVar6[0x18] = piVar6[0x18] + *(int *)((int)register0x00000038 + -0x14);
        piVar6[0x17] = piVar6[0x17] + *(int *)((int)register0x00000038 + -0x18);
        if (999999 < piVar6[0x18]) {
          piVar6[0x18] = piVar6[0x18] + -1000000;
          piVar6[0x17] = piVar6[0x17] + 1;
        }
        piVar6[9] = piVar6[9] + -1;
        piVar5 = *(int **)(param_1 + 0x10);
        piVar4 = *(int **)(param_1 + 0x14);
        if (piVar6 + 7 == piVar5) {
          piVar6[8] = (int)piVar4;
        }
        else {
          piVar5[5] = (int)piVar4;
        }
        if (piVar6 + 7 == piVar4) {
          piVar6[7] = (int)piVar5;
        }
        else {
          piVar4[4] = (int)piVar5;
        }
        _pset_remove_thread(iVar7,param_1);
        *(undefined4 *)(param_1 + 0x20) = 0;
        piVar6[10] = 0;
        _splx(piVar2);
        *piVar6 = 0;
        *(undefined4 *)(iVar7 + 0x158) = 0;
        _pset_deallocate(iVar7);
        if (*(int *)(param_1 + 0x7c) != 0) {
          _kmem_free(_kernel_map,*(int *)(param_1 + 0x7c),_page_size);
        }
        if (*(int *)(param_1 + 0x80) != 0) {
          _vm_object_deallocate();
        }
        if (param_1 == _active_threads) {
          _panic(aThreadDealloca);
          uVar3 = *(uint *)(param_1 + 0x4c);
        }
        else {
          uVar3 = *(uint *)(param_1 + 0x4c);
        }
        if ((uVar3 & 0xfffffeeb) != 2) {
          _panic(aUnstoppedThrea);
        }
        _task_deallocate(*(undefined4 *)(param_1 + 0xc));
        if ((*(uint *)(param_1 + 0x4c) & 0x100) == 0) {
          _splusclock();
          _stack_free(param_1);
          _splx(piVar2);
          _thread_deallocate_stack = _thread_deallocate_stack + 1;
          iVar7 = *(int *)(param_1 + 0x30);
        }
        else {
          iVar7 = *(int *)(param_1 + 0x30);
        }
        if (iVar7 != 0) {
          _freeStack();
        }
        _pcb_terminate(param_1);
        _nthreads = _nthreads + -1;
        _uthread_free(*(undefined4 *)(param_1 + 0x84));
        _zfree(_thread_zone,param_1);
      }
      else {
        *(undefined4 *)(param_1 + 0x20) = 0;
        piVar6[10] = 0;
        _splx(piVar2);
        *piVar6 = 0;
        *(undefined4 *)(iVar7 + 0x158) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(iVar7);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1631 start=0xf0074754 */

/* WARNING: Removing unreachable block (ram,0xf0074824) */
/* WARNING: Removing unreachable block (ram,0xf00747d8) */
/* WARNING: Removing unreachable block (ram,0xf0074780) */
/* WARNING: Removing unreachable block (ram,0xf0074814) */
/* WARNING: Removing unreachable block (ram,0xf00747ac) */
/* WARNING: Removing unreachable block (ram,0xf0074764) */

undefined8 _thread_deallocate_interrupt(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (param_1[8] != 0);
      piVar2 = param_1 + 8;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = param_1[9];
    param_1[9] = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      param_1[9] = 1;
      do {
        do {
        } while (_reaper_lock != 0);
        puVar4 = &_reaper_lock;
        _simple_lock_try();
      } while (puVar4 == (undefined4 *)0x0);
      *param_1 = &_reaper_queue;
      param_1[1] = DAT_f0135154;
      *DAT_f0135154 = param_1;
      _reaper_lock = 0;
      DAT_f0135154 = param_1;
      param_1[8] = 0;
      _splx(puVar1);
      _thread_wakeup_prim(&_reaper_queue,0,0);
    }
    else {
      param_1[8] = 0;
      _splx(puVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1632 start=0xf0074834 */

/* WARNING: Removing unreachable block (ram,0xf0074860) */
/* WARNING: Removing unreachable block (ram,0xf0074884) */
/* WARNING: Removing unreachable block (ram,0xf0074844) */

undefined8 _thread_reference(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
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
  if (param_1 != 0) {
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar2 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1633 start=0xf0074894 */

/* WARNING: Removing unreachable block (ram,0xf00748e0) */
/* WARNING: Removing unreachable block (ram,0xf0074aa0) */
/* WARNING: Removing unreachable block (ram,0xf0074a90) */
/* WARNING: Removing unreachable block (ram,0xf0074ab4) */
/* WARNING: Removing unreachable block (ram,0xf0074a48) */
/* WARNING: Removing unreachable block (ram,0xf007498c) */
/* WARNING: Removing unreachable block (ram,0xf00749e4) */
/* WARNING: Removing unreachable block (ram,0xf0074950) */
/* WARNING: Removing unreachable block (ram,0xf0074964) */
/* WARNING: Removing unreachable block (ram,0xf0074a0c) */
/* WARNING: Removing unreachable block (ram,0xf00749b4) */
/* WARNING: Removing unreachable block (ram,0xf0074a54) */
/* WARNING: Removing unreachable block (ram,0xf0074a84) */
/* WARNING: Removing unreachable block (ram,0xf0074a98) */
/* WARNING: Removing unreachable block (ram,0xf00748c4) */
/* WARNING: Removing unreachable block (ram,0xf007492c) */
/* WARNING: Removing unreachable block (ram,0xf00748b0) */

undefined8 _thread_terminate(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar1 = _active_threads;
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
    uVar6 = 4;
  }
  else {
    _ipc_thread_disable(param_1);
    if (param_1 == uVar1) {
      uVar1 = _active_threads;
      _splusclock();
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar5 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      if (*(int *)(param_1 + 0x188) != 0) {
        *(undefined4 *)(param_1 + 0x188) = 0;
        *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) | 2;
      }
      *(undefined4 *)(param_1 + 0x20) = 0;
      _need_ast = _need_ast | 2;
      _splx(uVar1);
      uVar6 = 0;
    }
    else {
      piVar5 = *(int **)(_active_threads + 0xc);
      do {
        do {
        } while (*piVar5 != 0);
        piVar2 = piVar5;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      _splusclock();
      if (param_1 < uVar1) {
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar4 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        do {
          do {
          } while (*(int *)(uVar1 + 0x20) != 0);
          piVar4 = (int *)(uVar1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        iVar3 = piVar5[2];
      }
      else {
        do {
          do {
          } while (*(int *)(uVar1 + 0x20) != 0);
          piVar4 = (int *)(uVar1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar4 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        iVar3 = piVar5[2];
      }
      if ((iVar3 == 0) || (*(int *)(uVar1 + 0x188) == 0)) {
        *(undefined4 *)(uVar1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        _splx(piVar2);
        *piVar5 = 0;
        _thread_terminate(uVar1);
        uVar6 = 5;
      }
      else {
        *(undefined4 *)(uVar1 + 0x20) = 0;
        *piVar5 = 0;
        if (*(int *)(param_1 + 0x188) == 0) {
          *(undefined4 *)(param_1 + 0x20) = 0;
          _splx(piVar2);
          uVar6 = 5;
        }
        else {
          *(undefined4 *)(param_1 + 0x188) = 0;
          *(undefined4 *)(param_1 + 0x20) = 0;
          _splx(piVar2);
          _thread_halt(param_1,1);
          _ipc_thread_terminate(param_1);
          _thread_deallocate(param_1);
          uVar6 = 0;
        }
      }
    }
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1634 start=0xf0074ac8 */

/* WARNING: Removing unreachable block (ram,0xf0074b24) */
/* WARNING: Removing unreachable block (ram,0xf0074b10) */
/* WARNING: Removing unreachable block (ram,0xf0074ad4) */
/* WARNING: Removing unreachable block (ram,0xf0074af0) */
/* WARNING: Removing unreachable block (ram,0xf0074b1c) */
/* WARNING: Removing unreachable block (ram,0xf0074b38) */
/* WARNING: Removing unreachable block (ram,0xf0074acc) */

undefined8 _thread_force_terminate(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
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
  iVar1 = param_1;
  _ipc_thread_disable(param_1);
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar3 = *(int *)(param_1 + 0x188);
  *(undefined4 *)(param_1 + 0x188) = 0;
  _splx(iVar1);
  _thread_halt(param_1,1);
  _ipc_thread_terminate(param_1);
  if (iVar3 != 0) {
    _thread_deallocate(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1635 start=0xf0074b48 */

/* WARNING: Removing unreachable block (ram,0xf0074f70) */
/* WARNING: Removing unreachable block (ram,0xf0074f30) */
/* WARNING: Removing unreachable block (ram,0xf0074edc) */
/* WARNING: Removing unreachable block (ram,0xf0074e88) */
/* WARNING: Removing unreachable block (ram,0xf0074e30) */
/* WARNING: Removing unreachable block (ram,0xf0074e1c) */
/* WARNING: Removing unreachable block (ram,0xf0074ddc) */
/* WARNING: Removing unreachable block (ram,0xf0074dbc) */
/* WARNING: Removing unreachable block (ram,0xf0074f84) */
/* WARNING: Removing unreachable block (ram,0xf0074d34) */
/* WARNING: Removing unreachable block (ram,0xf0074c70) */
/* WARNING: Removing unreachable block (ram,0xf0074ba0) */
/* WARNING: Removing unreachable block (ram,0xf0074bf8) */
/* WARNING: Removing unreachable block (ram,0xf0074cb8) */
/* WARNING: Removing unreachable block (ram,0xf0074c9c) */
/* WARNING: Removing unreachable block (ram,0xf0074b78) */
/* WARNING: Removing unreachable block (ram,0xf0074c20) */
/* WARNING: Removing unreachable block (ram,0xf0074bc8) */
/* WARNING: Removing unreachable block (ram,0xf0074c80) */
/* WARNING: Removing unreachable block (ram,0xf0074f7c) */
/* WARNING: Removing unreachable block (ram,0xf0074d78) */
/* WARNING: Removing unreachable block (ram,0xf0074dc8) */
/* WARNING: Removing unreachable block (ram,0xf0074df8) */
/* WARNING: Removing unreachable block (ram,0xf0074e28) */
/* WARNING: Removing unreachable block (ram,0xf0074e48) */
/* WARNING: Removing unreachable block (ram,0xf0074ec0) */
/* WARNING: Removing unreachable block (ram,0xf0074f14) */
/* WARNING: Removing unreachable block (ram,0xf0074f58) */
/* WARNING: Removing unreachable block (ram,0xf0074f98) */
/* WARNING: Removing unreachable block (ram,0xf0074b64) */

undefined8 _thread_halt(uint param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar7 = _active_threads;
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
  pcVar5 = (code *)DAT_f0134000;
  if (param_1 == _active_threads) {
    puVar1 = aThreadHaltTryi;
    _panic(aThreadHaltTryi);
    pcVar5 = (code *)puVar1;
  }
  if (param_2 == 0) {
    _splusclock();
    if (param_1 < uVar7) {
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*(int *)(uVar7 + 0x20) != 0);
        piVar4 = (int *)(uVar7 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      do {
        do {
        } while (*(int *)(uVar7 + 0x20) != 0);
        piVar4 = (int *)(uVar7 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    if ((uVar2 & 0x10) == 0) {
      if ((*(uint *)(uVar7 + 0x18c) & 1) != 0) {
        _thread_wakeup_prim(uVar7 + 0x48,0,2);
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(uVar7 + 0x20) = 0;
        _splx(pcVar5);
        uVar7 = 5;
        goto locret_F0074FA0;
      }
      *(undefined4 *)(uVar7 + 0x20) = 0;
      iVar3 = *(int *)(param_1 + 0x40);
loc_F0074CF4:
      uVar7 = *(uint *)(param_1 + 0x4c);
      *(int *)(param_1 + 0x40) = iVar3 + 1;
      *(uint *)(param_1 + 0x4c) = uVar7 | 2;
      if ((*(uint *)(param_1 + 0x18c) & 1) == 0) {
loc_F0074DAC:
        uVar7 = *(uint *)(param_1 + 0x18c);
      }
      else {
        if ((uVar7 & 0x10) == 0) {
          *(undefined4 *)(param_1 + 0x48) = 1;
          while (_thread_sleep(param_1 + 0x48,param_1 + 0x20,1),
                (*(uint *)(param_1 + 0x4c) & 0x10) == 0) {
            if ((*(int *)(_active_threads + 0x44) != 0) && (param_2 == 0)) {
              _splx(pcVar5);
              _thread_release(param_1);
              uVar7 = 5;
              goto locret_F0074FA0;
            }
            do {
              do {
              } while (*(int *)(param_1 + 0x20) != 0);
              piVar4 = (int *)(param_1 + 0x20);
              _simple_lock_try();
            } while (piVar4 == (int *)0x0);
            uVar7 = *(uint *)(param_1 + 0x18c);
            if ((uVar7 & 1) == 0) goto loc_F0074DB4;
            if ((*(uint *)(param_1 + 0x4c) & 0x10) != 0) goto loc_F0074DAC;
            *(undefined4 *)(param_1 + 0x48) = 1;
          }
          goto loc_F0074F98;
        }
        uVar7 = *(uint *)(param_1 + 0x18c);
      }
loc_F0074DB4:
      *(uint *)(param_1 + 0x18c) = uVar7 | 1;
      while( true ) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        _splx(pcVar5);
        uVar7 = param_1;
        _thread_dowait(param_1,param_2);
        if (uVar7 != 0) break;
        _clear_wait(param_1,2,1);
        if ((*(uint *)(param_1 + 0x4c) & 0x10) != 0) {
          uVar7 = 0;
          goto locret_F0074FA0;
        }
        pcVar6 = *(code **)(param_1 + 0x34);
        if ((pcVar6 == _mach_msg_continue) || (pcVar6 == _mach_msg_receive_continue)) {
          uVar7 = param_1;
          _mach_msg_interrupt();
          pcVar5 = (code *)0xf009bc00;
          if (uVar7 == 0) {
            pcVar6 = *(code **)(param_1 + 0x34);
            goto loc_F0074EA0;
          }
loc_F0074EC0:
          _splusclock();
          do {
            do {
            } while (*(int *)(param_1 + 0x20) != 0);
            piVar4 = (int *)(param_1 + 0x20);
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x10;
          *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffffffe;
          goto loc_F0074F98;
        }
loc_F0074EA0:
        pcVar5 = (code *)0xf009bc00;
        if ((pcVar6 == _thread_exception_return) ||
           (pcVar5 = _thread_bootstrap_return, pcVar6 == _thread_bootstrap_return))
        goto loc_F0074EC0;
        _splusclock();
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar4 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        if ((*(uint *)(param_1 + 0x4c) & 0xf) != 2) {
          _panic(aThreadHalt);
        }
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0xc;
        _thread_setrun(param_1,0);
      }
      uVar2 = uVar7;
      _splusclock();
      do {
        do {
        } while (*(int *)(param_1 + 0x20) != 0);
        piVar4 = (int *)(param_1 + 0x20);
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      *(uint *)(param_1 + 0x18c) = *(uint *)(param_1 + 0x18c) & 0xfffffffe;
      _thread_wakeup_prim(param_1 + 0x48,0,2);
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(uVar2);
      _thread_release(param_1);
      goto locret_F0074FA0;
    }
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    *(undefined4 *)(uVar7 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if ((*(uint *)(param_1 + 0x4c) & 0x10) == 0) {
      iVar3 = *(int *)(param_1 + 0x40);
      goto loc_F0074CF4;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
loc_F0074F98:
  uVar7 = 0;
  _splx(pcVar5);
locret_F0074FA0:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1636 start=0xf0074fa8 */

/* WARNING: Removing unreachable block (ram,0xf0074fb0) */

undefined8 _walking_zombie(undefined4 param_1,undefined4 param_2)

{
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
  _panic(aTheZombieWalks);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1637 start=0xf0074fc0 */

/* WARNING: Removing unreachable block (ram,0xf0075090) */
/* WARNING: Removing unreachable block (ram,0xf0075058) */
/* WARNING: Removing unreachable block (ram,0xf0074fec) */
/* WARNING: Removing unreachable block (ram,0xf0074fdc) */
/* WARNING: Removing unreachable block (ram,0xf00750c0) */
/* WARNING: Removing unreachable block (ram,0xf00750f0) */
/* WARNING: Removing unreachable block (ram,0xf0074fe4) */
/* WARNING: Removing unreachable block (ram,0xf0075010) */
/* WARNING: Removing unreachable block (ram,0xf007507c) */
/* WARNING: Removing unreachable block (ram,0xf00750fc) */
/* WARNING: Removing unreachable block (ram,0xf00750a4) */

undefined8 _thread_halt_self_with_continuation(code *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  code *pcVar7;
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
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar1 = _active_threads;
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
  uVar2 = _active_threads[99];
  if ((uVar2 & 2) == 0) {
    piVar5 = _active_threads + 8;
    _splusclock();
    do {
      do {
      } while (*piVar5 != 0);
      piVar6 = piVar5;
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    puVar1[99] = puVar1[99] & 0xfffffffe;
    _splx(uVar2);
    pcVar7 = param_1;
  }
  else {
    _ipc_thread_terminate(_active_threads);
    puVar3 = puVar1;
    _thread_hold(puVar1);
    _splusclock();
    do {
      do {
      } while (_reaper_lock != 0);
      puVar4 = &_reaper_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    *puVar1 = &_reaper_queue;
    puVar1[1] = DAT_f0135154;
    *DAT_f0135154 = puVar1;
    DAT_f0135154 = puVar1;
    _reaper_lock = 0;
    do {
      do {
      } while (puVar1[8] != 0);
      piVar5 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    _splx(puVar3);
    _thread_wakeup_prim(&_reaper_queue,0,0);
    pcVar7 = _walking_zombie;
  }
  _thread_block_with_continuation(pcVar7);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1638 start=0xf007510c */

/* WARNING: Removing unreachable block (ram,0xf00751e0) */
/* WARNING: Removing unreachable block (ram,0xf00751a8) */
/* WARNING: Removing unreachable block (ram,0xf007513c) */
/* WARNING: Removing unreachable block (ram,0xf007512c) */
/* WARNING: Removing unreachable block (ram,0xf0075210) */
/* WARNING: Removing unreachable block (ram,0xf0075240) */
/* WARNING: Removing unreachable block (ram,0xf0075134) */
/* WARNING: Removing unreachable block (ram,0xf0075160) */
/* WARNING: Removing unreachable block (ram,0xf00751cc) */
/* WARNING: Removing unreachable block (ram,0xf007524c) */
/* WARNING: Removing unreachable block (ram,0xf00751f4) */

undefined8 _thread_halt_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  code *pcVar7;
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
  
  puVar1 = _active_threads;
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
  uVar2 = 0xf009bc00;
  pcVar7 = _thread_exception_return;
  if ((_active_threads[99] & 2) == 0) {
    piVar5 = _active_threads + 8;
    _splusclock();
    do {
      do {
      } while (*piVar5 != 0);
      piVar6 = piVar5;
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    puVar1[99] = puVar1[99] & 0xfffffffe;
    _splx(uVar2);
  }
  else {
    _ipc_thread_terminate(_active_threads);
    puVar3 = puVar1;
    _thread_hold(puVar1);
    _splusclock();
    do {
      do {
      } while (_reaper_lock != 0);
      puVar4 = &_reaper_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    *puVar1 = &_reaper_queue;
    puVar1[1] = DAT_f0135154;
    *DAT_f0135154 = puVar1;
    DAT_f0135154 = puVar1;
    _reaper_lock = 0;
    do {
      do {
      } while (puVar1[8] != 0);
      piVar5 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    _splx(puVar3);
    _thread_wakeup_prim(&_reaper_queue,0,0);
    pcVar7 = _walking_zombie;
  }
  _thread_block_with_continuation(pcVar7);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1639 start=0xf007525c */

/* WARNING: Removing unreachable block (ram,0xf007527c) */
/* WARNING: Removing unreachable block (ram,0xf00752ac) */
/* WARNING: Removing unreachable block (ram,0xf0075260) */

undefined8 _thread_hold(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 2;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1640 start=0xf00752bc */

/* WARNING: Removing unreachable block (ram,0xf007540c) */
/* WARNING: Removing unreachable block (ram,0xf00753b4) */
/* WARNING: Removing unreachable block (ram,0xf0075300) */
/* WARNING: Removing unreachable block (ram,0xf00752e0) */
/* WARNING: Removing unreachable block (ram,0xf007537c) */
/* WARNING: Removing unreachable block (ram,0xf00753d0) */
/* WARNING: Removing unreachable block (ram,0xf0075424) */
/* WARNING: Removing unreachable block (ram,0xf00752d8) */

undefined8 _thread_dowait(undefined *param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
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
  uVar7 = 0;
  puVar1 = _active_threads;
  if (param_1 == _active_threads) {
    puVar1 = aThreadDowait;
    _panic(aThreadDowait);
  }
  iVar6 = 0;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar5 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = (int *)(param_1 + 0x20);
  uVar2 = *(uint *)(param_1 + 0x4c);
  do {
    switch(uVar2 & 0xf) {
    :
def_F007533C:
      *(undefined4 *)(param_1 + 0x20) = 0;
      _splx(puVar1);
      if (iVar6 != 0) {
        _thread_wakeup_prim(param_1 + 0x48,0,0);
      }
      return CONCAT44(param_2,uVar7);
    case :
      puVar3 = param_1;
      _rem_runq();
      if (puVar3 != (undefined *)0x0) {
        iVar6 = *(int *)(param_1 + 0x48);
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb;
        *(undefined4 *)(param_1 + 0x48) = 0;
        goto def_F007533C;
      }
      *(undefined4 *)(param_1 + 0x48) = 1;
      break;
    case :
    case :
    case :
    case :
      *(undefined4 *)(param_1 + 0x48) = 1;
    }
    _thread_sleep(param_1 + 0x48,piVar5,1);
    do {
      do {
      } while (*piVar5 != 0);
      piVar4 = piVar5;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if (*(int *)(_active_threads + 0x44) == 0) {
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      if (param_2 == 0) {
        uVar7 = 5;
        goto def_F007533C;
      }
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1641 start=0xf0075434 */

/* WARNING: Removing unreachable block (ram,0xf007549c) */
/* WARNING: Removing unreachable block (ram,0xf0075454) */
/* WARNING: Removing unreachable block (ram,0xf00754a8) */
/* WARNING: Removing unreachable block (ram,0xf0075438) */

undefined8 _thread_release(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar3 = *(int *)(param_1 + 0x40) + -1;
  *(int *)(param_1 + 0x40) = iVar3;
  if (iVar3 == 0) {
    uVar4 = *(uint *)(param_1 + 0x4c);
    uVar5 = uVar4 & 0xffffffed;
    *(uint *)(param_1 + 0x4c) = uVar5;
    if ((uVar4 & 5) == 0) {
      *(uint *)(param_1 + 0x4c) = uVar5 | 4;
      _thread_setrun(param_1,1);
    }
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1642 start=0xf00754b8 */

/* WARNING: Removing unreachable block (ram,0xf0075578) */
/* WARNING: Removing unreachable block (ram,0xf0075538) */
/* WARNING: Removing unreachable block (ram,0xf00754f0) */
/* WARNING: Removing unreachable block (ram,0xf007555c) */
/* WARNING: Removing unreachable block (ram,0xf0075584) */
/* WARNING: Removing unreachable block (ram,0xf00754d0) */

undefined8 _thread_suspend(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 == 0) {
    uVar4 = 4;
  }
  else {
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar2 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(param_1 + 0x8c) + 1;
    *(int *)(param_1 + 0x8c) = iVar3;
    if (iVar3 == 1) {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 2;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
    if (iVar3 == 1) {
      if (param_1 == _active_threads) {
        _splusclock();
        _need_ast = _need_ast | 4;
        uVar4 = 0;
        _splx();
        goto locret_F0075590;
      }
      _thread_dowait(param_1,1);
    }
    uVar4 = 0;
  }
locret_F0075590:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1643 start=0xf0075598 */

/* WARNING: Removing unreachable block (ram,0xf0075634) */
/* WARNING: Removing unreachable block (ram,0xf00755d0) */
/* WARNING: Removing unreachable block (ram,0xf0075648) */
/* WARNING: Removing unreachable block (ram,0xf00755b0) */

undefined8 _thread_resume(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  if (param_1 == 0) {
    uVar6 = 4;
  }
  else {
    uVar6 = 0;
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar2 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(param_1 + 0x8c) + -1;
    if (*(int *)(param_1 + 0x8c) < 1) {
      uVar6 = 5;
    }
    else {
      *(int *)(param_1 + 0x8c) = iVar3;
      if ((iVar3 == 0) &&
         (iVar3 = *(int *)(param_1 + 0x40) + -1, *(int *)(param_1 + 0x40) = iVar3, iVar3 == 0)) {
        uVar4 = *(uint *)(param_1 + 0x4c);
        uVar5 = uVar4 & 0xffffffed;
        *(uint *)(param_1 + 0x4c) = uVar5;
        if ((uVar4 & 5) == 0) {
          *(uint *)(param_1 + 0x4c) = uVar5 | 4;
          _thread_setrun(param_1,1);
        }
      }
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1644 start=0xf007565c */

/* WARNING: Removing unreachable block (ram,0xf00756a4) */
/* WARNING: Removing unreachable block (ram,0xf0075690) */
/* WARNING: Removing unreachable block (ram,0xf00756b0) */
/* WARNING: Removing unreachable block (ram,0xf0075684) */

undefined8 _thread_get_state(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    iVar1 = 4;
  }
  else {
    _thread_hold(param_1);
    _thread_dowait(param_1,1);
    iVar1 = param_1;
    _thread_getstatus(param_1,param_2,param_3,param_4);
    _thread_release(param_1);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1645 start=0xf00756c0 */

/* WARNING: Removing unreachable block (ram,0xf0075708) */
/* WARNING: Removing unreachable block (ram,0xf00756f4) */
/* WARNING: Removing unreachable block (ram,0xf0075714) */
/* WARNING: Removing unreachable block (ram,0xf00756e8) */

undefined8 _thread_set_state(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    iVar1 = 4;
  }
  else {
    _thread_hold(param_1);
    _thread_dowait(param_1,1);
    iVar1 = param_1;
    _thread_setstatus(param_1,param_2,param_3,param_4);
    _thread_release(param_1);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1646 start=0xf0075724 */

/* WARNING: Removing unreachable block (ram,0xf0075820) */
/* WARNING: Removing unreachable block (ram,0xf00757d8) */
/* WARNING: Removing unreachable block (ram,0xf00757ac) */
/* WARNING: Removing unreachable block (ram,0xf0075750) */
/* WARNING: Removing unreachable block (ram,0xf0075948) */
/* WARNING: Removing unreachable block (ram,0xf0075904) */
/* WARNING: Removing unreachable block (ram,0xf0075940) */
/* WARNING: Removing unreachable block (ram,0xf0075988) */
/* WARNING: Removing unreachable block (ram,0xf0075770) */
/* WARNING: Removing unreachable block (ram,0xf00757bc) */
/* WARNING: Removing unreachable block (ram,0xf00757f0) */
/* WARNING: Removing unreachable block (ram,0xf00758bc) */
/* WARNING: Removing unreachable block (ram,0xf00758e4) */

undefined8 _thread_info(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  if (param_1 == 0) {
    uVar7 = 4;
    goto locret_F00759A4;
  }
  if (param_2 == 1) {
    uVar1 = *param_4;
    if (uVar1 < 0xb) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if (((*(uint *)(param_1 + 0x4c) & 4) == 0) && (*(int *)(param_1 + 0x70) != _sched_tick)) {
      _update_priority(param_1);
    }
    _thread_read_times(param_1,param_3,param_3 + 2);
    param_3[5] = *(undefined4 *)(param_1 + 0x50);
    param_3[6] = *(undefined4 *)(param_1 + 0x58);
    iVar2 = *(int *)(param_1 + 0x68);
    .udiv(iVar2,1000);
    param_3[4] = iVar2;
    iVar2 = iVar2 * 3;
    .div(iVar2,5);
    param_3[4] = iVar2;
    iVar2 = iVar2 * 1000000;
    .div(iVar2,_sched_usec);
    param_3[4] = iVar2;
    uVar3 = *(uint *)(param_1 + 0x4c);
    uVar6 = 1;
    if ((uVar3 & 0x100) == 0) {
      uVar6 = uVar3 >> 6 & 2;
      uVar3 = *(uint *)(param_1 + 0x4c);
    }
    uVar5 = 5;
    if (((((uVar3 & 0x10) == 0) && (uVar5 = 1, (uVar3 & 4) == 0)) && (uVar5 = 4, (uVar3 & 8) == 0))
       && (uVar5 = 2, (uVar3 & 2) == 0)) {
      uVar5 = -(uVar3 & 1) & 3;
    }
    param_3[7] = uVar5;
    param_3[8] = uVar6;
    param_3[9] = *(undefined4 *)(param_1 + 0x8c);
    if (uVar5 == 1) {
      param_3[10] = 0;
    }
    else {
      param_3[10] = _sched_tick - *(int *)(param_1 + 0x70);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar1);
    uVar1 = 0xb;
  }
  else {
    if (param_2 != 2) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    uVar1 = *param_4;
    if (uVar1 < 7) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    *param_3 = *(undefined4 *)(param_1 + 0x60);
    if ((*(int *)(param_1 + 0x60) == 2) || (*(int *)(param_1 + 0x60) == 4)) {
      uVar7 = *(undefined4 *)(param_1 + 0x5c);
      .umul(uVar7,_tick);
      .div();
      param_3[1] = uVar7;
    }
    else {
      param_3[1] = 0;
    }
    param_3[2] = *(undefined4 *)(param_1 + 0x50);
    param_3[3] = *(undefined4 *)(param_1 + 0x54);
    param_3[4] = *(undefined4 *)(param_1 + 0x58);
    param_3[5] = ~*(uint *)(param_1 + 100) >> 0x1f;
    param_3[6] = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar1);
    uVar1 = 7;
  }
  param_2 = param_1 + 0x20;
  *param_4 = uVar1;
  uVar7 = 0;
locret_F00759A4:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1647 start=0xf00759ac */

/* WARNING: Removing unreachable block (ram,0xf00759f8) */
/* WARNING: Removing unreachable block (ram,0xf00759f0) */
/* WARNING: Removing unreachable block (ram,0xf0075a10) */
/* WARNING: Removing unreachable block (ram,0xf00759d4) */

undefined8 _thread_abort(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar2 = 4;
  }
  else {
    iVar1 = param_1;
    _thread_halt(param_1,0);
    if (iVar1 == 0) {
      _mach_msg_abort_rpc(param_1);
      _thread_release(param_1);
      if (*(int *)(param_1 + 100) == -1) {
        uVar2 = 0;
      }
      else {
        _thread_depress_abort(param_1);
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xe;
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1648 start=0xf0075a24 */

undefined8 _thread_start(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)(param_1 + 0x34) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1649 start=0xf0075a34 */

/* WARNING: Removing unreachable block (ram,0xf0075a5c) */
/* WARNING: Removing unreachable block (ram,0xf0075a44) */
/* WARNING: Removing unreachable block (ram,0xf0075a50) */
/* WARNING: Removing unreachable block (ram,0xf0075a78) */
/* WARNING: Removing unreachable block (ram,0xf0075a3c) */

undefined8 _kernel_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  _thread_create(param_1,(undefined *)((int)register0x00000038 + -0xc));
  _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  _thread_start(*(undefined4 *)((int)register0x00000038 + -0xc),param_2);
  *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc4) = param_3;
  _thread_doswapin();
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(iVar1 + 0x54) = 0x1f;
  *(undefined4 *)(iVar1 + 0x50) = 0x18;
  *(undefined4 *)(iVar1 + 0x58) = 0x18;
  _thread_resume();
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}

