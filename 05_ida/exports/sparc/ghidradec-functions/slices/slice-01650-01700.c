/* GHIDRADEC_FUNCTION index=1650 start=0xf0075a8c */

/* WARNING: Removing unreachable block (ram,0xf0075b24) */
/* WARNING: Removing unreachable block (ram,0xf0075b14) */
/* WARNING: Removing unreachable block (ram,0xf0075b70) */
/* WARNING: Removing unreachable block (ram,0xf0075b58) */
/* WARNING: Removing unreachable block (ram,0xf0075ab8) */
/* WARNING: Removing unreachable block (ram,0xf0075b64) */
/* WARNING: Removing unreachable block (ram,0xf0075b08) */
/* WARNING: Removing unreachable block (ram,0xf0075b1c) */
/* WARNING: Removing unreachable block (ram,0xf0075b40) */
/* WARNING: Removing unreachable block (ram,0xf0075a9c) */

void _reaper_thread_continue(code *param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  code *pcVar2;
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
  do {
    _splusclock();
    do {
      do {
      } while (_reaper_lock != 0);
      puVar1 = &_reaper_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    while( true ) {
      if (_reaper_queue._0_4_ == (code *)&_reaper_queue) {
        pcVar2 = (code *)0x0;
      }
      else {
        *(undefined8 **)(*(int *)_reaper_queue._0_4_ + 4) = &_reaper_queue;
        pcVar2 = _reaper_queue._0_4_;
        _reaper_queue._0_4_ = *(code **)_reaper_queue._0_4_;
      }
      if (pcVar2 == (code *)0x0) break;
      _reaper_lock = 0;
      _splx(param_1);
      _thread_dowait(pcVar2,1);
      _thread_deallocate();
      _splusclock();
      do {
        do {
        } while (_reaper_lock != 0);
        puVar1 = &_reaper_lock;
        _simple_lock_try();
        param_1 = pcVar2;
      } while (puVar1 == (undefined4 *)0x0);
    }
    _assert_wait(&_reaper_queue,0);
    _reaper_lock = 0;
    _splx(param_1);
    param_1 = _reaper_thread_continue;
    _thread_block_with_continuation();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1651 start=0xf0075b84 */

/* WARNING: Removing unreachable block (ram,0xf0075b88) */

undefined8 _reaper_thread(undefined4 param_1,undefined4 param_2)

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
  _reaper_thread_continue();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1652 start=0xf0075b98 */

undefined8 _thread_assign(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=1653 start=0xf0075ba4 */

/* WARNING: Removing unreachable block (ram,0xf0075bb0) */

undefined8 _thread_assign_default(undefined4 param_1,undefined4 param_2)

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
  _thread_assign(param_1,_default_pset);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1654 start=0xf0075bc0 */

/* WARNING: Removing unreachable block (ram,0xf0075bc8) */

sqword _thread_get_assignment(int param_1,undefined4 *param_2)

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
  *param_2 = *(undefined4 *)(param_1 + 400);
  _pset_reference();
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=1655 start=0xf0075bd8 */

/* WARNING: Removing unreachable block (ram,0xf0075c5c) */
/* WARNING: Removing unreachable block (ram,0xf0075c18) */
/* WARNING: Removing unreachable block (ram,0xf0075c74) */
/* WARNING: Removing unreachable block (ram,0xf0075bfc) */

undefined8 _thread_priority(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  uVar3 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
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
    if (*(int *)(param_1 + 0x54) < (int)param_2) {
      uVar3 = 5;
    }
    else {
      if (*(int *)(param_1 + 100) < 0) {
        *(uint *)(param_1 + 0x50) = param_2;
        _compute_priority(param_1,1);
      }
      else {
        *(uint *)(param_1 + 100) = param_2;
      }
      if (param_3 != 0) {
        *(uint *)(param_1 + 0x54) = param_2;
      }
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1656 start=0xf0075c88 */

/* WARNING: Removing unreachable block (ram,0xf0075cdc) */
/* WARNING: Removing unreachable block (ram,0xf0075cb0) */
/* WARNING: Removing unreachable block (ram,0xf0075ce8) */
/* WARNING: Removing unreachable block (ram,0xf0075c90) */

undefined8 _thread_set_own_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
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
  puVar2 = DAT_f0134000;
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar1 + 0x20) != 0);
    piVar3 = (int *)(iVar1 + 0x20);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  if (param_1 < *(int *)(iVar1 + 0x54)) {
    *(int *)(iVar1 + 0x54) = param_1;
  }
  *(int *)(iVar1 + 0x50) = param_1;
  _compute_priority(iVar1,1);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1657 start=0xf0075cf8 */

/* WARNING: Removing unreachable block (ram,0xf0075d68) */
/* WARNING: Removing unreachable block (ram,0xf0075d3c) */
/* WARNING: Removing unreachable block (ram,0xf0075d90) */
/* WARNING: Removing unreachable block (ram,0xf0075d20) */

undefined8 _thread_max_priority(int param_1,int *param_2,uint param_3)

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
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (0x1f < param_3)) {
    uVar3 = 4;
  }
  else {
    param_2 = (int *)(param_1 + 0x20);
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*param_2 != 0);
      piVar2 = param_2;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(uint *)(param_1 + 0x54) = param_3;
    if ((int)param_3 < *(int *)(param_1 + 0x50)) {
      *(uint *)(param_1 + 0x50) = param_3;
      _compute_priority(param_1,1);
    }
    else if ((-1 < *(int *)(param_1 + 100)) && ((int)param_3 < *(int *)(param_1 + 100))) {
      *(uint *)(param_1 + 100) = param_3;
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1658 start=0xf0075da4 */

/* WARNING: Removing unreachable block (ram,0xf0075ec4) */
/* WARNING: Removing unreachable block (ram,0xf0075e9c) */
/* WARNING: Removing unreachable block (ram,0xf0075e34) */
/* WARNING: Removing unreachable block (ram,0xf0075de8) */
/* WARNING: Removing unreachable block (ram,0xf0075e4c) */
/* WARNING: Removing unreachable block (ram,0xf0075eb4) */
/* WARNING: Removing unreachable block (ram,0xf0075ed0) */
/* WARNING: Removing unreachable block (ram,0xf0075dcc) */

undefined8 _thread_policy(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  uVar5 = 0;
  if ((param_1 == 0) || (uVar2 = param_2 - 1, 3 < uVar2)) {
    uVar5 = 4;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar3 = (int *)(param_1 + 0x20);
      _simple_lock_try();
      uVar1 = _tick;
    } while (piVar3 == (int *)0x0);
    if (param_2 == *(uint *)(param_1 + 0x60)) {
      if (param_2 == 2) {
        param_3 = param_3 * 1000;
        iVar4 = param_3;
        .rem(param_3,_tick);
        if (iVar4 != 0) {
          param_3 = param_3 + uVar1;
        }
        .div(param_3,uVar1);
        *(int *)(param_1 + 0x5c) = param_3;
        param_2 = uVar1;
      }
    }
    else if ((*(uint *)(*(int *)(param_1 + 400) + 0x168) & param_2) == 0) {
      uVar5 = 5;
    }
    else {
      *(uint *)(param_1 + 0x60) = param_2;
      uVar1 = _tick;
      if (param_2 == 2) {
        param_3 = param_3 * 1000;
        iVar4 = param_3;
        .rem(param_3,_tick);
        if (iVar4 != 0) {
          param_3 = param_3 + uVar1;
        }
        .div(param_3,uVar1);
        *(int *)(param_1 + 0x5c) = param_3;
        param_2 = uVar1;
      }
      _compute_priority(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar2);
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1659 start=0xf0075ee4 */

/* WARNING: Removing unreachable block (ram,0xf0075f50) */
/* WARNING: Removing unreachable block (ram,0xf0075f30) */
/* WARNING: Removing unreachable block (ram,0xf0075f68) */
/* WARNING: Removing unreachable block (ram,0xf0075f14) */

undefined8 _thread_wire(int param_1,int param_2,int param_3)

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
  if (((param_1 == 0) || (param_2 == 0)) || (param_2 != _active_threads)) {
    uVar3 = 4;
  }
  else {
    iVar1 = _active_threads;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_2 + 0x20) != 0);
      piVar2 = (int *)(param_2 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (param_3 == 0) {
      *(undefined4 *)(param_2 + 0x78) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x78) = 1;
      _stack_privilege(param_2);
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
    _splx(iVar1);
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1660 start=0xf0075f7c */

undefined8 _thread_collect_scan(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1661 start=0xf0075f88 */

/* WARNING: Removing unreachable block (ram,0xf0075fe0) */

undefined8 _consider_thread_collect(undefined4 param_1,undefined4 param_2)

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
  if (_thread_collect_max_rate == 0) {
    _thread_collect_max_rate = _hz;
  }
  if ((_thread_collect_allowed != 0) &&
     (_thread_collect_last_tick + _thread_collect_max_rate < _sched_tick)) {
    _thread_collect_last_tick = _sched_tick;
    _thread_collect_scan();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1662 start=0xf0075ff0 */

undefined8 _stack_usage(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar3;
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
  uVar2 = 0;
  iVar3 = 0;
  do {
    if (*(int *)(iVar3 + param_1) != -0x21524111) {
      iVar1 = uVar2 << 2;
      goto loc_F0076028;
    }
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar2 < 0xffd);
  iVar1 = uVar2 * 4;
loc_F0076028:
  return CONCAT44(iVar3,0x3ff4 - iVar1);
}
/* GHIDRADEC_FUNCTION index=1663 start=0xf007603c */

undefined8 _stack_init(int param_1)

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
  uint uVar2;
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
  uVar2 = 0;
  if (_stack_check_usage != 0) {
    iVar1 = 0;
    do {
      *(undefined4 *)(iVar1 + param_1) = 0xdeadbeef;
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < 0xffd);
  }
  return CONCAT44(uVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=1664 start=0xf007607c */

/* WARNING: Removing unreachable block (ram,0xf00760b8) */
/* WARNING: Removing unreachable block (ram,0xf0076094) */

undefined8 _stack_finalize(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  puVar2 = param_1;
  if (_stack_check_usage != 0) {
    _stack_usage();
    puVar2 = &_stack_usage_lock;
    do {
      do {
      } while (_stack_usage_lock != 0);
      puVar1 = puVar2;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    if (_stack_max_usage < param_1) {
      _stack_max_usage = param_1;
    }
    _stack_usage_lock = 0;
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=1665 start=0xf00760ec */

/* WARNING: Removing unreachable block (ram,0xf0076144) */
/* WARNING: Removing unreachable block (ram,0xf007611c) */

undefined8
_host_stack_usage(int param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if (param_1 == 0) {
    uVar4 = 0x16;
  }
  else {
    do {
      do {
      } while (_stack_usage_lock != 0);
      puVar1 = &_stack_usage_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    _stack_usage_lock = 0;
    *(undefined4 *)((int)register0x00000038 + -0x10) = _stack_max_usage;
    _stack_statistics((undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    *param_2 = 0;
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    uVar2 = *(int *)((int)register0x00000038 + -0xc) * 0x3ff4 + _page_mask & ~_page_mask;
    *param_4 = uVar2;
    *param_5 = uVar2;
    uVar4 = 0;
    *param_6 = *(undefined4 *)((int)register0x00000038 + -0x10);
    *puVar3 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1666 start=0xf00761a0 */

/* WARNING: Removing unreachable block (ram,0xf0076230) */
/* WARNING: Removing unreachable block (ram,0xf0076338) */
/* WARNING: Removing unreachable block (ram,0xf007626c) */
/* WARNING: Removing unreachable block (ram,0xf007631c) */
/* WARNING: Removing unreachable block (ram,0xf007635c) */
/* WARNING: Removing unreachable block (ram,0xf007623c) */
/* WARNING: Removing unreachable block (ram,0xf00761e8) */

undefined8
_processor_set_stack_usage
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5,int *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  *(int *)((int)register0x00000038 + -0xc) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4;
  if (param_1 == 0) {
    uVar13 = 4;
  }
  else {
    uVar12 = 0;
    uVar11 = 0;
    do {
      do {
        do {
        } while (*(int *)(param_1 + 0x158) != 0);
        piVar1 = (int *)(param_1 + 0x158);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0x154) == 0) {
        *(undefined4 *)(param_1 + 0x158) = 0;
        uVar13 = 4;
        goto locret_F00763AC;
      }
      uVar10 = *(uint *)(param_1 + 0x140);
      uVar5 = uVar10 * 4;
      uVar9 = 0;
      if (uVar5 < uVar11 || uVar5 - uVar11 == 0) {
        iVar6 = *(int *)(param_1 + 0x138);
        if (uVar10 != 0) {
          iVar8 = 0;
          do {
            _thread_reference(iVar6);
            *(int *)(iVar8 + uVar12) = iVar6;
            iVar8 = iVar8 + 4;
            uVar9 = uVar9 + 1;
            iVar6 = *(int *)(iVar6 + 0x18);
          } while (uVar9 < uVar10);
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        iVar6 = 0;
        uVar5 = 0;
        param_2 = 0;
        uVar9 = 0;
        if (uVar10 != 0) {
          iVar8 = 0;
          do {
            iVar7 = *(int *)(iVar8 + uVar12);
            uVar4 = 0;
            if ((*(uint *)(iVar7 + 0x4c) & 0x100) == 0) {
              uVar4 = *(uint *)(iVar7 + 0x2c);
              iVar3 = 0;
              iVar2 = 0;
              do {
                if (*(int *)((int)&_active_threads + iVar2) == iVar7) {
                  uVar4 = *(uint *)((int)&_active_stacks + iVar2);
                  break;
                }
                iVar3 = iVar3 + 1;
                iVar2 = iVar2 + 4;
              } while (iVar3 < 1);
            }
            if (((uVar4 != 0) && (iVar6 = iVar6 + 1, _stack_check_usage != 0)) &&
               (_stack_usage(), uVar5 < uVar4)) {
              uVar5 = uVar4;
              param_2 = iVar7;
            }
            _thread_deallocate(iVar7);
            uVar9 = uVar9 + 1;
            iVar8 = iVar8 + 4;
          } while (uVar9 < uVar10);
        }
        if (uVar11 != 0) {
          _kfree(uVar12,uVar11);
        }
        **(int **)((int)register0x00000038 + -0xc) = iVar6;
        uVar12 = iVar6 * 0x3ff4 + _page_mask & ~_page_mask;
        **(uint **)((int)register0x00000038 + -0x14) = uVar12;
        uVar13 = 0;
        **(uint **)((int)register0x00000038 + -0x1c) = uVar12;
        *param_5 = uVar5;
        *param_6 = param_2;
        goto locret_F00763AC;
      }
      *(undefined4 *)(param_1 + 0x158) = 0;
      if (uVar11 != 0) {
        _kfree(uVar12,uVar11);
      }
      uVar12 = uVar5;
      _kalloc();
      uVar11 = uVar5;
    } while (uVar12 != 0);
    uVar13 = 6;
  }
locret_F00763AC:
  return CONCAT44(param_2,uVar13);
}
/* GHIDRADEC_FUNCTION index=1667 start=0xf00763b4 */

/* WARNING: Removing unreachable block (ram,0xf0076410) */
/* WARNING: Removing unreachable block (ram,0xf0076400) */

undefined8 _thread_stats(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar2 = 0;
  iVar4 = 0;
  if ((undefined4 **)dword_F01350F8 != &dword_F01350F8) {
    iVar1 = dword_F01350F8[0x30];
    puVar3 = dword_F01350F8;
    while( true ) {
      iVar2 = iVar2 + 1;
      if (iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      puVar3 = (undefined4 *)puVar3[6];
      if ((undefined4 **)puVar3 == &dword_F01350F8) break;
      iVar1 = puVar3[0x30];
    }
  }
  _printf(aDTotalThreads,iVar2);
  _printf(aDUsingRpcReply,iVar4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1668 start=0xf0076420 */

undefined8 _current_thread_EXTERNAL(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,_active_threads);
}
/* GHIDRADEC_FUNCTION index=1669 start=0xf0076434 */

undefined8 _swapper_init(undefined4 param_1,undefined4 param_2)

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
  DAT_f013cb2c = &_swapin_queue;
  _swapin_queue._0_4_ = &_swapin_queue;
  _swapper_lock_data = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1670 start=0xf0076458 */

/* WARNING: Removing unreachable block (ram,0xf00764d8) */
/* WARNING: Removing unreachable block (ram,0xf00764e4) */
/* WARNING: Removing unreachable block (ram,0xf00764a0) */

undefined8 _thread_swapin(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
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
  uVar2 = param_1[0x13] & 0x300;
  if (uVar2 == 0x100) {
    param_1[0x13] = param_1[0x13] & 0xfffffcff | 0x200;
    do {
      do {
      } while (_swapper_lock_data != 0);
      puVar1 = &_swapper_lock_data;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    *param_1 = &_swapin_queue;
    param_1[1] = DAT_f013cb2c;
    *DAT_f013cb2c = param_1;
    _swapper_lock_data = 0;
    DAT_f013cb2c = param_1;
    _thread_wakeup_prim(&_swapin_queue,0,0);
  }
  else if (uVar2 != 0x200) {
    _panic(aThreadSwapin);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1671 start=0xf00764f4 */

/* WARNING: Removing unreachable block (ram,0xf0076550) */
/* WARNING: Removing unreachable block (ram,0xf0076508) */
/* WARNING: Removing unreachable block (ram,0xf0076524) */
/* WARNING: Removing unreachable block (ram,0xf007655c) */
/* WARNING: Removing unreachable block (ram,0xf0076500) */

undefined8 _thread_doswapin(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
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
  _stack_alloc(param_1,_thread_continue);
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  uVar3 = *(uint *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffcff;
  if ((uVar3 & 4) != 0) {
    _thread_setrun(param_1,1);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1672 start=0xf007656c */

/* WARNING: Removing unreachable block (ram,0xf00765f8) */
/* WARNING: Removing unreachable block (ram,0xf00765e8) */
/* WARNING: Removing unreachable block (ram,0xf0076638) */
/* WARNING: Removing unreachable block (ram,0xf0076598) */
/* WARNING: Removing unreachable block (ram,0xf007662c) */
/* WARNING: Removing unreachable block (ram,0xf0076644) */
/* WARNING: Removing unreachable block (ram,0xf00765f0) */
/* WARNING: Removing unreachable block (ram,0xf0076614) */
/* WARNING: Removing unreachable block (ram,0xf007657c) */

void _swapin_thread_continue(code *param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  code *pcVar2;
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
  do {
    _splusclock();
    do {
      do {
      } while (_swapper_lock_data != 0);
      puVar1 = &_swapper_lock_data;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    while( true ) {
      if (_swapin_queue._0_4_ == (code *)&_swapin_queue) {
        pcVar2 = (code *)0x0;
      }
      else {
        *(undefined8 **)(*(int *)_swapin_queue._0_4_ + 4) = &_swapin_queue;
        pcVar2 = _swapin_queue._0_4_;
        _swapin_queue._0_4_ = *(code **)_swapin_queue._0_4_;
      }
      if (pcVar2 == (code *)0x0) break;
      _swapper_lock_data = 0;
      _splx(param_1);
      _thread_doswapin();
      _splusclock();
      do {
        do {
        } while (_swapper_lock_data != 0);
        puVar1 = &_swapper_lock_data;
        _simple_lock_try();
        param_1 = pcVar2;
      } while (puVar1 == (undefined4 *)0x0);
    }
    _assert_wait(&_swapin_queue,0);
    _swapper_lock_data = 0;
    _splx(param_1);
    param_1 = _swapin_thread_continue;
    _thread_block_with_continuation();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1673 start=0xf0076658 */

/* WARNING: Removing unreachable block (ram,0xf0076668) */
/* WARNING: Removing unreachable block (ram,0xf0076660) */

undefined8 _swapin_thread(undefined4 param_1,undefined4 param_2)

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
  _stack_privilege(_active_threads);
  _swapin_thread_continue();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1674 start=0xf0076678 */

/* WARNING: Removing unreachable block (ram,0xf0076720) */
/* WARNING: Removing unreachable block (ram,0xf0076710) */

undefined8 _calloutInitialize(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  if (dword_F0110BB0 == 0) {
    dword_F0130F20 = 0;
    DAT_f0130f30 = &dword_F0130F2C;
    dword_F0130F2C = &dword_F0130F2C;
    DAT_f0130f38 = &dword_F0130F34;
    dword_F0130F34 = &dword_F0130F34;
    DAT_f0130f28 = &dword_F0130F24;
    dword_F0130F24 = &dword_F0130F24;
    unk_F0130520._0_4_ = &dword_F0130F24;
    puVar1 = (undefined4 *)unk_F0130520;
    while( true ) {
      puVar1[1] = DAT_f0130f28;
      *DAT_f0130f28 = puVar1;
      puVar2 = puVar1 + 10;
      DAT_f0130f28 = puVar1;
      if (unk_F0130520 + 0x9ff < puVar2) break;
      *puVar2 = &dword_F0130F24;
      puVar1 = puVar2;
    }
    _kernel_thread(_kernel_task,sub_F00776A8,0);
    _set_timer_expire_func(0,sub_F00776C8);
    dword_F0110BB0 = 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1675 start=0xf0076968 */

/* WARNING: Removing unreachable block (ram,0xf007696c) */

undefined8 _calloutDeadlineFromInterval(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
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
  iVar1 = 1;
  uVar2 = param_2;
  _clock_value(1);
  return CONCAT44(param_2 + uVar2,param_1 + iVar1 + (uint)CARRY4(param_2,uVar2));
}
/* GHIDRADEC_FUNCTION index=1676 start=0xf0076984 */

/* WARNING: Removing unreachable block (ram,0xf0076a64) */
/* WARNING: Removing unreachable block (ram,0xf00769c0) */
/* WARNING: Removing unreachable block (ram,0xf00769ec) */
/* WARNING: Removing unreachable block (ram,0xf0076a6c) */
/* WARNING: Removing unreachable block (ram,0xf007699c) */

undefined8 _calloutDispatch(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar2 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      _panic(aInternalentrya);
    }
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
      piVar3 = dword_F0130F24;
      dword_F0130F24 = (int *)*dword_F0130F24;
    }
    piVar3[2] = param_1;
    piVar3[3] = param_2;
    piVar3[4] = 0;
    piVar3[6] = 0;
    piVar3[7] = 0;
    *piVar3 = (int)&dword_F0130F2C;
    piVar3[1] = (int)DAT_f0130f30;
    *DAT_f0130f30 = (int)piVar3;
    dword_F0130F3C = dword_F0130F3C + 1;
    DAT_f0130f30 = piVar3;
    piVar3[8] = 1;
    sub_F00773A8();
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1677 start=0xf0076a7c */

/* WARNING: Removing unreachable block (ram,0xf0076bbc) */
/* WARNING: Removing unreachable block (ram,0xf0076ab8) */
/* WARNING: Removing unreachable block (ram,0xf0076b44) */
/* WARNING: Removing unreachable block (ram,0xf0076bcc) */
/* WARNING: Removing unreachable block (ram,0xf0076a94) */

undefined8 _calloutDispatchUnique(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar4 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    puVar4 = dword_F0130F2C;
    if ((undefined4 **)dword_F0130F2C != &dword_F0130F2C) {
      iVar2 = dword_F0130F2C[2];
      do {
        if (iVar2 == param_1) {
          if (puVar4[3] == param_2) break;
          puVar4 = (undefined4 *)*puVar4;
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((undefined4 **)puVar4 == &dword_F0130F2C) break;
        iVar2 = puVar4[2];
      } while( true );
    }
    if ((undefined4 **)puVar4 == &dword_F0130F2C) {
      if ((int **)dword_F0130F24 == &dword_F0130F24) {
        _panic(aInternalentrya);
      }
      if ((int **)dword_F0130F24 == &dword_F0130F24) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
        piVar3 = dword_F0130F24;
        dword_F0130F24 = (int *)*dword_F0130F24;
      }
      piVar3[2] = param_1;
      piVar3[3] = param_2;
      piVar3[4] = 0;
      piVar3[6] = 0;
      piVar3[7] = 0;
      *piVar3 = (int)&dword_F0130F2C;
      piVar3[1] = (int)DAT_f0130f30;
      *DAT_f0130f30 = (int)piVar3;
      dword_F0130F3C = dword_F0130F3C + 1;
      DAT_f0130f30 = piVar3;
      piVar3[8] = 1;
      sub_F00773A8();
    }
    else {
      dword_F0130F20 = 0;
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1678 start=0xf0076bdc */

/* WARNING: Removing unreachable block (ram,0xf0076d34) */
/* WARNING: Removing unreachable block (ram,0xf0076c18) */
/* WARNING: Removing unreachable block (ram,0xf0076c44) */
/* WARNING: Removing unreachable block (ram,0xf0076d44) */
/* WARNING: Removing unreachable block (ram,0xf0076bf4) */

undefined8 _calloutDispatchDelayed(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
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
  if (dword_F0110BB0 != 0) {
    iVar1 = dword_F0110BB0;
    _splusclock();
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar2 = &dword_F0130F20;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      _panic(aInternalentrya);
    }
    if ((int **)dword_F0130F24 == &dword_F0130F24) {
      piVar4 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_F0130F24 + 4) = &dword_F0130F24;
      piVar4 = dword_F0130F24;
      dword_F0130F24 = (int *)*dword_F0130F24;
    }
    piVar4[2] = param_1;
    piVar4[3] = param_2;
    piVar4[4] = 0;
    *(qword *)(piVar4 + 6) = CONCAT44(param_3,param_4);
    piVar5 = dword_F0130F34;
    while (piVar6 = DAT_f0130f38, (int **)piVar5 != &dword_F0130F34) {
      if ((uint)piVar4[6] < (uint)piVar5[6]) {
        piVar6 = (int *)piVar5[1];
        break;
      }
      if (piVar5[6] == piVar4[6]) {
        if ((uint)piVar4[7] < (uint)piVar5[7]) {
          piVar6 = (int *)piVar5[1];
          break;
        }
        iVar3 = piVar4[6];
      }
      else {
        iVar3 = piVar4[6];
      }
      if (iVar3 == piVar5[6]) {
        if (piVar4[7] == piVar5[7]) {
          iVar3 = *piVar5;
          goto loc_F0076D04;
        }
        piVar5 = (int *)*piVar5;
      }
      else {
        piVar5 = (int *)*piVar5;
      }
    }
    iVar3 = *piVar6;
    piVar5 = piVar6;
loc_F0076D04:
    *piVar4 = iVar3;
    piVar4[1] = (int)piVar5;
    *(int **)(*piVar5 + 4) = piVar4;
    *piVar5 = (int)piVar4;
    piVar4[8] = 2;
    if (dword_F0130F34 == piVar4) {
      sub_F007673C(piVar4);
    }
    dword_F0130F20 = 0;
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1679 start=0xf0076d54 */

/* WARNING: Removing unreachable block (ram,0xf0076db0) */
/* WARNING: Removing unreachable block (ram,0xf0076d7c) */
/* WARNING: Removing unreachable block (ram,0xf0076d94) */
/* WARNING: Removing unreachable block (ram,0xf0076dc0) */
/* WARNING: Removing unreachable block (ram,0xf0076d58) */

undefined8 _calloutRemove(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
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
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  iVar3 = param_1;
  sub_F00767D8(param_1,param_2,0);
  if (iVar3 == 0) {
    sub_F00768A8(param_1,param_2,0);
  }
  dword_F0130F20 = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1680 start=0xf0076dd0 */

/* WARNING: Removing unreachable block (ram,0xf0076e20) */
/* WARNING: Removing unreachable block (ram,0xf0076df8) */
/* WARNING: Removing unreachable block (ram,0xf0076e10) */
/* WARNING: Removing unreachable block (ram,0xf0076e30) */
/* WARNING: Removing unreachable block (ram,0xf0076dd4) */

undefined8 _calloutRemoveAll(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
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
  uVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  sub_F00767D8(param_1,param_2,1);
  sub_F00768A8(param_1,param_2,1);
  dword_F0130F20 = 0;
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1681 start=0xf0076e40 */

/* WARNING: Removing unreachable block (ram,0xf0076e44) */

undefined8 _calloutEntryAllocate(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x28;
  _kalloc();
  *(undefined4 *)(iVar1 + 8) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined8 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1682 start=0xf0076e70 */

/* WARNING: Removing unreachable block (ram,0xf0076ed4) */
/* WARNING: Removing unreachable block (ram,0xf0076e98) */
/* WARNING: Removing unreachable block (ram,0xf0076ec4) */
/* WARNING: Removing unreachable block (ram,0xf0076ee0) */
/* WARNING: Removing unreachable block (ram,0xf0076e74) */

undefined8 _calloutEntryFree(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (*(int *)(param_1 + 0x20) != 0) {
    dword_F0130F20 = 0;
    _panic(aCalloutentryfr);
  }
  dword_F0130F20 = 0;
  _splx(iVar1);
  _kfree(param_1,0x28);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1683 start=0xf0076ef0 */

/* WARNING: Removing unreachable block (ram,0xf0076f80) */
/* WARNING: Removing unreachable block (ram,0xf0076f18) */
/* WARNING: Removing unreachable block (ram,0xf0076f90) */
/* WARNING: Removing unreachable block (ram,0xf0076ef4) */

undefined8 _calloutEntryDispatch(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  puVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 0) {
    *(undefined8 *)(param_1 + 6) = 0;
    *param_1 = &dword_F0130F2C;
    param_1[3] = param_1[4];
    dword_F0130F3C = dword_F0130F3C + 1;
    param_1[1] = DAT_f0130f30;
    *DAT_f0130f30 = param_1;
    DAT_f0130f30 = param_1;
    param_1[8] = 1;
    sub_F00773A8();
  }
  else {
    dword_F0130F20 = 0;
  }
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1684 start=0xf0076fa0 */

/* WARNING: Removing unreachable block (ram,0xf007702c) */
/* WARNING: Removing unreachable block (ram,0xf0076fc8) */
/* WARNING: Removing unreachable block (ram,0xf007703c) */
/* WARNING: Removing unreachable block (ram,0xf0076fa4) */

undefined8 _calloutEntryDispatchWithArgument(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  puVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 0) {
    param_1[3] = param_2;
    *(undefined8 *)(param_1 + 6) = 0;
    *param_1 = &dword_F0130F2C;
    param_1[1] = DAT_f0130f30;
    *DAT_f0130f30 = param_1;
    dword_F0130F3C = dword_F0130F3C + 1;
    DAT_f0130f30 = param_1;
    param_1[8] = 1;
    sub_F00773A8();
  }
  else {
    dword_F0130F20 = 0;
  }
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1685 start=0xf007704c */

/* WARNING: Removing unreachable block (ram,0xf007715c) */
/* WARNING: Removing unreachable block (ram,0xf007707c) */
/* WARNING: Removing unreachable block (ram,0xf007716c) */
/* WARNING: Removing unreachable block (ram,0xf0077058) */

undefined8 _calloutEntryDispatchDelayed(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
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
  piVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 0) {
    *(qword *)(param_1 + 6) = CONCAT44(param_2,param_3);
    param_1[3] = param_1[4];
    piVar4 = dword_F0130F34;
    while (piVar5 = DAT_f0130f38, (int **)piVar4 != &dword_F0130F34) {
      if ((uint)param_1[6] < (uint)piVar4[6]) {
        piVar5 = (int *)piVar4[1];
        break;
      }
      if (piVar4[6] == param_1[6]) {
        if ((uint)param_1[7] < (uint)piVar4[7]) {
          piVar5 = (int *)piVar4[1];
          break;
        }
        iVar3 = param_1[6];
      }
      else {
        iVar3 = param_1[6];
      }
      if (iVar3 == piVar4[6]) {
        if (param_1[7] == piVar4[7]) {
          iVar3 = *piVar4;
          goto loc_F007712C;
        }
        piVar4 = (int *)*piVar4;
      }
      else {
        piVar4 = (int *)*piVar4;
      }
    }
    iVar3 = *piVar5;
    piVar4 = piVar5;
loc_F007712C:
    *param_1 = iVar3;
    param_1[1] = (int)piVar4;
    *(int **)(*piVar4 + 4) = param_1;
    *piVar4 = (int)param_1;
    param_1[8] = 2;
    if (dword_F0130F34 == param_1) {
      sub_F007673C(param_1);
    }
  }
  dword_F0130F20 = 0;
  _splx(piVar1);
  return CONCAT44(piVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=1686 start=0xf007717c */

/* WARNING: Removing unreachable block (ram,0xf0077280) */
/* WARNING: Removing unreachable block (ram,0xf00771a4) */
/* WARNING: Removing unreachable block (ram,0xf0077290) */
/* WARNING: Removing unreachable block (ram,0xf0077180) */

undefined8
_calloutEntryDispatchWithArgumentDelayed
          (int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
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
  piVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 0) {
    param_1[3] = param_2;
    *(qword *)(param_1 + 6) = CONCAT44(param_3,param_4);
    piVar4 = dword_F0130F34;
    while (piVar5 = DAT_f0130f38, (int **)piVar4 != &dword_F0130F34) {
      if ((uint)param_1[6] < (uint)piVar4[6]) {
        piVar5 = (int *)piVar4[1];
        break;
      }
      if (piVar4[6] == param_1[6]) {
        if ((uint)param_1[7] < (uint)piVar4[7]) {
          piVar5 = (int *)piVar4[1];
          break;
        }
        iVar3 = param_1[6];
      }
      else {
        iVar3 = param_1[6];
      }
      if (iVar3 == piVar4[6]) {
        if (param_1[7] == piVar4[7]) {
          iVar3 = *piVar4;
          goto loc_F0077250;
        }
        piVar4 = (int *)*piVar4;
      }
      else {
        piVar4 = (int *)*piVar4;
      }
    }
    iVar3 = *piVar5;
    piVar4 = piVar5;
loc_F0077250:
    *param_1 = iVar3;
    param_1[1] = (int)piVar4;
    *(int **)(*piVar4 + 4) = param_1;
    *piVar4 = (int)param_1;
    param_1[8] = 2;
    if (dword_F0130F34 == param_1) {
      sub_F007673C(param_1);
    }
  }
  dword_F0130F20 = 0;
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1687 start=0xf00772a0 */

/* WARNING: Removing unreachable block (ram,0xf00772c8) */
/* WARNING: Removing unreachable block (ram,0xf0077398) */
/* WARNING: Removing unreachable block (ram,0xf00772a4) */

undefined8 _calloutEntryRemove(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
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
  piVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (param_1[8] == 1) {
    *(int *)(*param_1 + 4) = param_1[1];
    dword_F0130F3C = dword_F0130F3C + -1;
    *(int *)param_1[1] = *param_1;
    param_1[8] = 0;
  }
  else {
    if (param_1[8] != 2) goto loc_F0077394;
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    param_1[8] = 0;
  }
  if ((&DAT_f013051f < param_1) && (param_1 <= &DAT_f0130f1f)) {
    *param_1 = (int)&dword_F0130F24;
    param_1[1] = (int)DAT_f0130f28;
    *DAT_f0130f28 = (int)param_1;
    DAT_f0130f28 = param_1;
  }
loc_F0077394:
  dword_F0130F20 = 0;
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1688 start=0xf00778c0 */

/* WARNING: Removing unreachable block (ram,0xf00778d0) */
/* WARNING: Removing unreachable block (ram,0xf00778e0) */
/* WARNING: Removing unreachable block (ram,0xf00778c4) */

undefined8 _kern_timestamp(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
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
  _clock_value(1);
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  _ns_time_to_tsval();
  _copyout(puVar1,param_1,8);
  return CONCAT44(param_2,(uint)(puVar1 != (undefined *)0x0));
}
/* GHIDRADEC_FUNCTION index=1689 start=0xf00778f8 */

/* WARNING: Removing unreachable block (ram,0xf0077914) */

undefined8 _init_timers(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined *puVar3;
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
  puVar3 = _kernel_timer;
  iVar2 = 0;
  iVar1 = 0;
  do {
    _timer_init(puVar3);
    *(undefined4 *)((int)&_current_timer + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 0x10;
  } while (iVar2 < 1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1690 start=0xf007793c */

undefined8 _timer_init(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1691 start=0xf0077958 */

/* WARNING: Removing unreachable block (ram,0xf0077980) */
/* WARNING: Removing unreachable block (ram,0xf0077964) */

undefined8 _timer_normalize(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *param_1;
  .udiv(iVar1,1000000);
  iVar2 = *param_1;
  param_1[2] = param_1[2] + iVar1;
  .urem(iVar2,1000000);
  *param_1 = iVar2;
  param_1[1] = param_1[1] + iVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1692 start=0xf00779a0 */

/* WARNING: Removing unreachable block (ram,0xf00779e0) */
/* WARNING: Removing unreachable block (ram,0xf00779cc) */

undefined8 _timer_read(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = param_1[1];
  while( true ) {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
    iVar1 = *param_1;
    *(int *)((int)register0x00000038 + -0x10) = iVar1;
    if (iVar2 == param_1[2]) break;
    iVar2 = param_1[1];
  }
  .udiv(iVar1,1000000);
  *param_2 = iVar2 + iVar1;
  iVar2 = *(int *)((int)register0x00000038 + -0x10);
  .urem(iVar2,1000000);
  param_2[1] = iVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1693 start=0xf00779f4 */

/* WARNING: Removing unreachable block (ram,0xf0077a70) */
/* WARNING: Removing unreachable block (ram,0xf0077a38) */
/* WARNING: Removing unreachable block (ram,0xf0077a84) */
/* WARNING: Removing unreachable block (ram,0xf0077a24) */

undefined8 _thread_read_times(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0xe4);
  while( true ) {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
    iVar1 = *(int *)(param_1 + 0xe0);
    *(int *)((int)register0x00000038 + -0x10) = iVar1;
    if (iVar2 == *(int *)(param_1 + 0xe8)) break;
    iVar2 = *(int *)(param_1 + 0xe4);
  }
  .udiv(iVar1,1000000);
  *param_2 = iVar2 + iVar1;
  iVar2 = *(int *)((int)register0x00000038 + -0x10);
  .urem(iVar2,1000000);
  param_2[1] = iVar2;
  iVar2 = *(int *)(param_1 + 0xf4);
  while( true ) {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
    iVar1 = *(int *)(param_1 + 0xf0);
    *(int *)((int)register0x00000038 + -0x10) = iVar1;
    if (iVar2 == *(int *)(param_1 + 0xf8)) break;
    iVar2 = *(int *)(param_1 + 0xf4);
  }
  .udiv(iVar1,1000000);
  *param_3 = iVar2 + iVar1;
  iVar2 = *(int *)((int)register0x00000038 + -0x10);
  .urem(iVar2,1000000);
  param_3[1] = iVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1694 start=0xf0077a98 */

undefined8 _timer_delta(int *param_1,int *param_2)

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
  int iVar2;
  undefined4 unaff_i2;
  int iVar3;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar4;
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
  iVar3 = param_1[1];
  while( true ) {
    *(int *)((int)register0x00000038 + -0xc) = iVar3;
    iVar4 = *param_1;
    *(int *)((int)register0x00000038 + -0x10) = iVar4;
    if (iVar3 == param_1[2]) break;
    iVar3 = param_1[1];
  }
  iVar1 = param_2[1];
  iVar2 = *param_2;
  param_2[1] = iVar3;
  *param_2 = *(int *)((int)register0x00000038 + -0x10);
  return CONCAT44(iVar2,((iVar3 - iVar1) * 1000000 + iVar4) - iVar2);
}
/* GHIDRADEC_FUNCTION index=1695 start=0xf0077f38 */

/* WARNING: Removing unreachable block (ram,0xf0078054) */
/* WARNING: Removing unreachable block (ram,0xf0077f98) */
/* WARNING: Removing unreachable block (ram,0xf0077f5c) */
/* WARNING: Removing unreachable block (ram,0xf0077f70) */
/* WARNING: Removing unreachable block (ram,0xf0078078) */
/* WARNING: Removing unreachable block (ram,0xf0077f7c) */

undefined8 _zinit(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar3;
  undefined4 unaff_i2;
  uint uVar4;
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
  if (_zone_zone == (undefined4 *)0x0) {
    puVar1 = __zone_default_space;
    _zget_space(__zone_default_space,0x44,0);
  }
  else {
    puVar1 = (undefined *)_zone_zone;
    _zalloc();
  }
  if ((undefined4 *)puVar1 == (undefined4 *)0x0) {
    _panic(&aZinit);
  }
  if (param_3 == 0) {
    param_3 = _page_size;
  }
  if (param_1 == 0) {
    param_1 = 4;
  }
  uVar3 = param_2 + _page_mask & ~_page_mask;
  uVar4 = param_3 + _page_mask & ~_page_mask;
  if (uVar3 < uVar4) {
    uVar3 = uVar4;
  }
  *(undefined4 *)((int)puVar1 + 0x10) = 0;
  *(undefined4 *)((int)puVar1 + 0xc) = 0;
  *(undefined4 *)((int)puVar1 + 0x14) = 0;
  *(uint *)((int)puVar1 + 0x18) = uVar3;
  *(uint *)((int)puVar1 + 0x1c) = param_1 + 0xfU & 0xfffffff0;
  *(uint *)((int)puVar1 + 0x20) = uVar4;
  *(undefined4 *)((int)puVar1 + 0x28) = param_5;
  *(undefined4 *)((int)puVar1 + 8) = 0;
  *(undefined4 *)((int)puVar1 + 0x24) = 0;
  *(uint *)((int)puVar1 + 0x2c) = *(uint *)((int)puVar1 + 0x2c) & 0x7fffffff | param_4 << 0x1f;
  uVar3 = *(uint *)((int)puVar1 + 0x2c) & 0x9fffffff | 0x10000000;
  *(uint *)((int)puVar1 + 0x2c) = uVar3;
  if ((int)uVar3 < 0) {
    _lock_init((undefined4 *)((int)puVar1 + 0x30),1);
  }
  else {
    *(undefined4 *)puVar1 = 0;
  }
  sub_F0078AB4(puVar1);
  *(undefined4 *)((int)puVar1 + 0x40) = 0;
  do {
    do {
    } while (_all_zones_lock != 0);
    puVar2 = &_all_zones_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  *_last_zone = puVar1;
  _last_zone = (undefined4 *)((int)puVar1 + 0x40);
  _all_zones_lock = 0;
  _num_zones = _num_zones + 1;
  return CONCAT44(&_all_zones_lock,puVar1);
}
/* GHIDRADEC_FUNCTION index=1696 start=0xf00780bc */

/* WARNING: Removing unreachable block (ram,0xf00781b0) */
/* WARNING: Removing unreachable block (ram,0xf0078114) */
/* WARNING: Removing unreachable block (ram,0xf00780f8) */
/* WARNING: Removing unreachable block (ram,0xf00780e8) */
/* WARNING: Removing unreachable block (ram,0xf00781c0) */
/* WARNING: Removing unreachable block (ram,0xf00780d0) */

undefined8 _zcram(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  if (param_2 == (int *)0x0) {
    _panic(aZcramMemoryAtZ);
    iVar1 = param_1[0xb];
  }
  else {
    iVar1 = param_1[0xb];
  }
  uVar4 = param_1[7];
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = iVar1;
  }
  if (param_3 < uVar4) {
    iVar1 = param_1[0xb];
  }
  else {
    do {
      piVar2 = (int *)param_1[3];
      if ((piVar2 == (int *)0x0) || (param_2 <= piVar2)) {
        piVar2 = param_1 + 4;
      }
      do {
        piVar3 = piVar2;
        piVar2 = (int *)*piVar3;
        if (piVar2 == (int *)0x0) {
          *param_2 = 0;
          goto loc_F0078174;
        }
      } while (piVar2 < param_2);
      *param_2 = (int)piVar2;
loc_F0078174:
      *piVar3 = (int)param_2;
      param_1[3] = (int)param_2;
      param_1[2] = param_1[2];
      param_3 = param_3 - uVar4;
      param_2 = (int *)((int)param_2 + uVar4);
      param_1[5] = param_1[5] + uVar4;
    } while (uVar4 <= param_3);
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_done(param_1 + 0xc);
  }
  else {
    *param_1 = 0;
    _splx(param_1[1]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1697 start=0xf00781d0 */

/* WARNING: Removing unreachable block (ram,0xf00782d8) */

undefined8 _zone_free_space_add(undefined *param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint *puVar6;
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
  if (param_1 == (undefined *)0x0) {
    param_1 = __zone_default_space;
  }
  puVar1 = *(uint **)(param_1 + 8);
  puVar6 = (uint *)(param_1 + 8);
  while (((puVar4 = puVar1, puVar4 != (uint *)0x0 && (puVar4 < param_3)) &&
         ((uint *)((int)puVar4 + puVar4[1]) != param_3))) {
    puVar6 = puVar4;
    puVar1 = (uint *)*puVar4;
  }
  if ((puVar4 == (uint *)0x0) || ((uint *)((int)puVar4 + puVar4[1]) < param_3)) {
    if (0xf < (uint)(param_4 - param_2)) {
      if (puVar4 != (uint *)0x0) {
        puVar6 = puVar4;
      }
      uVar5 = (int)param_3 + param_2;
      *(int *)(uVar5 + 4) = param_4 - param_2;
      uVar2 = *puVar6;
      *(uint *)((int)param_3 + param_2) = uVar2;
      if (uVar2 != 0) {
        *(uint *)(uVar2 + 8) = uVar5;
      }
      *(uint **)(uVar5 + 8) = puVar6;
      *puVar6 = uVar5;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      uVar2 = *(uint *)(uVar5 + 4) >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
      if ((int)*(uint *)(param_1 + 0x18) < (int)uVar2) {
        uVar2 = *(uint *)(param_1 + 0x18);
      }
      iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
      uVar2 = *(uint *)(iVar3 + -0x10);
      if ((uVar2 == 0) || (uVar5 < uVar2)) {
        *(uint *)(iVar3 + -0x10) = uVar5;
      }
    }
  }
  else if ((uint *)((int)puVar4 + puVar4[1]) == param_3) {
    sub_F0077B04(param_1,puVar4);
    uVar5 = (int)puVar4 + param_2;
    *(uint *)(uVar5 + 4) = (puVar4[1] + param_4) - param_2;
    uVar2 = *puVar4;
    *(uint *)((int)puVar4 + param_2) = uVar2;
    if (uVar2 != 0) {
      *(uint *)(uVar2 + 8) = uVar5;
    }
    *(uint **)(uVar5 + 8) = puVar6;
    *puVar6 = uVar5;
    uVar2 = *(uint *)(uVar5 + 4) >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
    if ((int)*(uint *)(param_1 + 0x18) < (int)uVar2) {
      uVar2 = *(uint *)(param_1 + 0x18);
    }
    iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
    uVar2 = *(uint *)(iVar3 + -0x10);
    param_3 = puVar4;
    if ((uVar2 == 0) || (uVar5 < uVar2)) {
      *(uint *)(iVar3 + -0x10) = uVar5;
    }
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=1698 start=0xf0078360 */

/* WARNING: Removing unreachable block (ram,0xf0078524) */
/* WARNING: Removing unreachable block (ram,0xf007849c) */
/* WARNING: Removing unreachable block (ram,0xf00784dc) */

undefined8 _zone_collect(int param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  undefined *puVar7;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
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
  bool bVar11;
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
  puVar7 = *(undefined **)(param_1 + 0x3c);
  iVar9 = *(int *)(param_1 + 0x1c);
  if ((puVar7 != (undefined *)0x0) &&
     (puVar8 = (uint *)(puVar7 + 8), puVar7 != __zone_default_space)) {
    puVar1 = (uint *)*(uint *)(param_1 + 0x10);
    while (puVar1 != (uint *)0x0) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar9;
      puVar5 = (uint *)*puVar8;
      bVar11 = puVar5 == (uint *)0x0;
      uVar10 = *puVar1;
      if (!bVar11) {
        uVar2 = puVar5[1];
        while (puVar6 = puVar5, bVar11 = puVar6 == (uint *)0x0, puVar5 = puVar6,
              (int)puVar6 + uVar2 < puVar1) {
          puVar5 = (uint *)*puVar6;
          puVar8 = puVar6;
          if (puVar5 == (uint *)0x0) {
            bVar11 = true;
            break;
          }
          uVar2 = puVar5[1];
        }
      }
      if (bVar11) {
        puVar1[1] = iVar9;
loc_F00783FC:
        *puVar1 = (uint)puVar5;
        if (puVar5 != (uint *)0x0) {
          puVar5[2] = (uint)puVar1;
        }
        puVar1[2] = (uint)puVar8;
        *puVar8 = (uint)puVar1;
        *(int *)(puVar7 + 0xc) = *(int *)(puVar7 + 0xc) + 1;
        uVar2 = puVar1[1] >> ((byte)*(undefined4 *)(puVar7 + 0x10) & 0x1f);
        if ((int)*(uint *)(puVar7 + 0x18) < (int)uVar2) {
          uVar2 = *(uint *)(puVar7 + 0x18);
        }
        iVar3 = *(int *)(puVar7 + 0x14) + uVar2 * 0x10;
        uVar2 = *(uint *)(iVar3 + -0x10);
        if ((uVar2 == 0) || (puVar1 < uVar2)) {
          *(uint **)(iVar3 + -0x10) = puVar1;
        }
      }
      else {
        if ((uint *)((int)puVar1 + iVar9) < puVar5) {
          puVar1[1] = iVar9;
          goto loc_F00783FC;
        }
        uVar2 = puVar5[1];
        if ((uint *)((int)puVar1 + iVar9) == puVar5) {
          puVar1[1] = uVar2 + iVar9;
          iVar3 = *(int *)((int)puVar1 + iVar9);
          *puVar1 = iVar3;
          if (iVar3 != 0) {
            *(uint **)(iVar3 + 8) = puVar1;
          }
          puVar1[2] = (uint)puVar8;
          *puVar8 = (uint)puVar1;
          sub_F0077BC0(puVar7,puVar1,uVar2,puVar5);
        }
        else if ((uint *)((int)puVar5 + uVar2) == puVar1) {
          puVar5[1] = uVar2 + iVar9;
          uVar4 = (int)puVar5 + uVar2 + iVar9;
          if (uVar4 == *puVar5) {
            sub_F0077B04(puVar7,uVar4);
            puVar5[1] = puVar5[1] + *(int *)(*puVar5 + 4);
            uVar4 = *(uint *)*puVar5;
            *puVar5 = uVar4;
            if (uVar4 != 0) {
              *(uint **)(uVar4 + 8) = puVar5;
            }
            *(int *)(puVar7 + 0xc) = *(int *)(puVar7 + 0xc) + -1;
          }
          sub_F0077CDC(puVar7,puVar5,uVar2);
        }
      }
      *(uint *)(param_1 + 0x10) = uVar10;
      puVar1 = (uint *)uVar10;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1699 start=0xf0078548 */

/* WARNING: Removing unreachable block (ram,0xf00787c8) */
/* WARNING: Removing unreachable block (ram,0xf00785e4) */

undefined8 _zone_free_space_reclaim(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l3;
  int *piVar7;
  undefined4 unaff_l4;
  int *piVar8;
  undefined4 unaff_l5;
  int *piVar9;
  undefined4 unaff_l6;
  int iVar10;
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
  piVar6 = &_zone_free_space;
  iVar10 = 1;
  piVar9 = (int *)0x0;
  if (1 < _zone_free_space_count) {
    do {
      piVar6 = piVar6 + 1;
      piVar4 = *(int **)(*piVar6 + 8);
      if (piVar4 != (int *)0x0) {
        uVar3 = piVar4[1];
        piVar8 = (int *)(*piVar6 + 8);
        do {
          piVar2 = piVar4;
          if (_page_size <= uVar3) {
            piVar5 = (int *)((int)piVar4 + _page_mask & ~_page_mask);
            piVar7 = (int *)((int)piVar4 + uVar3 & ~_page_mask);
            if (((piVar5 < piVar7) && (_zone_min <= piVar5)) && (piVar7 <= _zone_max)) {
              sub_F0077B04(*piVar6,piVar4);
              if ((int *)((int)piVar4 + piVar4[1]) == piVar7) {
                if (piVar4 == piVar5) {
                  iVar1 = *piVar4;
                  *piVar8 = iVar1;
                  if (iVar1 != 0) {
                    *(int **)(*piVar4 + 8) = piVar8;
                  }
                  *(int *)(*piVar6 + 0xc) = *(int *)(*piVar6 + 0xc) + -1;
                }
                else {
                  piVar4[1] = (int)piVar5 - (int)piVar4;
                  iVar1 = *piVar6;
                  uVar3 = (uint)((int)piVar5 - (int)piVar4) >>
                          ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                  if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                    uVar3 = *(uint *)(iVar1 + 0x18);
                  }
                  iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                  piVar2 = *(int **)(iVar1 + -0x10);
                  if ((piVar2 == (int *)0x0) || (piVar4 < piVar2)) {
                    *(int **)(iVar1 + -0x10) = piVar4;
                  }
                }
              }
              else {
                piVar7[1] = ((int)piVar4 + piVar4[1]) - (int)piVar7;
                iVar1 = *piVar4;
                *piVar7 = iVar1;
                if (iVar1 != 0) {
                  *(int **)(iVar1 + 8) = piVar7;
                }
                if (piVar4 == piVar5) {
                  *piVar8 = (int)piVar7;
                  piVar7[2] = (int)piVar8;
loc_F0078698:
                  iVar1 = *piVar6;
                }
                else {
                  piVar4[1] = (int)piVar5 - (int)piVar4;
                  *piVar4 = (int)piVar7;
                  piVar7[2] = (int)piVar4;
                  *(int *)(*piVar6 + 0xc) = *(int *)(*piVar6 + 0xc) + 1;
                  iVar1 = *piVar6;
                  uVar3 = (uint)piVar4[1] >> ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                  if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                    uVar3 = *(uint *)(iVar1 + 0x18);
                  }
                  iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                  piVar2 = *(int **)(iVar1 + -0x10);
                  if ((piVar2 == (int *)0x0) || (piVar4 < piVar2)) {
                    *(int **)(iVar1 + -0x10) = piVar4;
                    goto loc_F0078698;
                  }
                  iVar1 = *piVar6;
                }
                uVar3 = (uint)piVar7[1] >> ((byte)*(undefined4 *)(iVar1 + 0x10) & 0x1f);
                if ((int)*(uint *)(iVar1 + 0x18) < (int)uVar3) {
                  uVar3 = *(uint *)(iVar1 + 0x18);
                }
                iVar1 = *(int *)(iVar1 + 0x14) + uVar3 * 0x10;
                piVar4 = *(int **)(iVar1 + -0x10);
                if ((piVar4 == (int *)0x0) || (piVar7 < piVar4)) {
                  *(int **)(iVar1 + -0x10) = piVar7;
                }
              }
              piVar5[1] = (int)piVar7 - (int)piVar5;
              *piVar5 = (int)piVar9;
              piVar2 = piVar8;
              piVar9 = piVar5;
            }
          }
          piVar4 = (int *)*piVar2;
          if (piVar4 == (int *)0x0) break;
          uVar3 = piVar4[1];
          piVar8 = piVar2;
        } while( true );
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < _zone_free_space_count);
  }
  _zget_space_lock = 0;
  if (piVar9 != (int *)0x0) {
    for (piVar6 = (int *)*piVar9; _kmem_free(_zone_map,piVar9,piVar9[1]), piVar6 != (int *)0x0;
        piVar6 = (int *)*piVar6) {
      piVar9 = piVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}

