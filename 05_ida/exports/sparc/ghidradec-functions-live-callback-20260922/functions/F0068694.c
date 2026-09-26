
/* WARNING: Removing unreachable block (ram,0xf00687e4) */
/* WARNING: Removing unreachable block (ram,0xf00687cc) */
/* WARNING: Removing unreachable block (ram,0xf006879c) */
/* WARNING: Removing unreachable block (ram,0xf0068808) */
/* WARNING: Removing unreachable block (ram,0xf0068738) */
/* WARNING: Removing unreachable block (ram,0xf0068754) */
/* WARNING: Removing unreachable block (ram,0xf0068780) */
/* WARNING: Removing unreachable block (ram,0xf00687a4) */
/* WARNING: Removing unreachable block (ram,0xf00687dc) */
/* WARNING: Removing unreachable block (ram,0xf00687bc) */
/* WARNING: Removing unreachable block (ram,0xf00686c0) */

undefined8 _allocStack(void)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
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
  bVar1 = false;
  iVar4 = 0;
  do {
    _lock_write(_stack_queue_lock);
    if (dword_F010FB00 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      if ((int **)dword_F012F670 == &dword_F012F670) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_F012F670 + 4) = &dword_F012F670;
        piVar3 = dword_F012F670;
        dword_F012F670 = (int *)*dword_F012F670;
      }
      piVar3[2] = 2;
      piVar3 = piVar3 + 3;
      dword_F010FB00 = dword_F010FB00 + -1;
      DAT_f013c0c4._4_4_ = DAT_f013c0c4._4_4_ + -1;
      DAT_f013c0c4._0_4_ = DAT_f013c0c4._0_4_ + 1;
    }
    puVar2 = _stack_queue_lock;
    _lock_done();
    if (piVar3 == (int *)0x0) {
      _newStack();
      piVar3 = (int *)puVar2;
      if ((int *)puVar2 != (int *)0x0) goto loc_F00687FC;
      if (bVar1) {
        piVar3 = (int *)0x0;
        if (iVar4 != 0) break;
      }
      else {
        _uprintf(aMachOutOfKerne);
        bVar1 = true;
        if (dword_F010FB08 == 0) {
          _printf(aStackAllocKern);
        }
      }
      _lock_write(_stack_queue_lock);
      if (dword_F010FB00 == 0) {
        _assert_wait(&dword_F012F670,0);
        dword_F010FB08 = 1;
        _lock_done(_stack_queue_lock);
        _thread_block();
        iVar4 = *(int *)(_active_threads + 0x44);
        piVar3 = (int *)puVar2;
      }
      else {
        _lock_done(_stack_queue_lock);
        iVar4 = 0;
        piVar3 = (int *)puVar2;
      }
    }
    else {
loc_F00687FC:
      if (bVar1) {
        _uprintf(aContinuing_0);
      }
    }
  } while (piVar3 == (int *)0x0);
  return CONCAT44(1,piVar3);
}

