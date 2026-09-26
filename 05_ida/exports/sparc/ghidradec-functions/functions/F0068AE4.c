
/* WARNING: Removing unreachable block (ram,0xf0068b7c) */
/* WARNING: Removing unreachable block (ram,0xf0068ba4) */
/* WARNING: Removing unreachable block (ram,0xf0068aec) */

undefined8 _stack_alloc_try(int param_1,undefined4 param_2)

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
  _lock_write(_stack_queue_lock);
  if (dword_F010FB00 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    if ((int **)dword_F012F670 == &dword_F012F670) {
      piVar1 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_F012F670 + 4) = &dword_F012F670;
      piVar1 = dword_F012F670;
      dword_F012F670 = (int *)*dword_F012F670;
    }
    piVar1[2] = 2;
    piVar1 = piVar1 + 3;
    dword_F010FB00 = dword_F010FB00 + -1;
    DAT_f013c0c4._4_4_ = DAT_f013c0c4._4_4_ + -1;
    DAT_f013c0c4._0_4_ = DAT_f013c0c4._0_4_ + 1;
  }
  _lock_done(_stack_queue_lock);
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)(param_1 + 0x30);
  }
  if (piVar1 != (int *)0x0) {
    _stack_attach(param_1,piVar1,param_2);
  }
  return CONCAT44(param_2,(uint)(piVar1 != (int *)0x0));
}
