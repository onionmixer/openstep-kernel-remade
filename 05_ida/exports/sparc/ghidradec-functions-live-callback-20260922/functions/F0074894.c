
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

