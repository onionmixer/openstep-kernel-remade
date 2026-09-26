
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
