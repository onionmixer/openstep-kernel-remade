
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

