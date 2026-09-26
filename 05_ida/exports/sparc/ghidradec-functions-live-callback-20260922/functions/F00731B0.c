
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

