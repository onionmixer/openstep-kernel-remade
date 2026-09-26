
/* WARNING: Removing unreachable block (ram,0xf001ff84) */
/* WARNING: Removing unreachable block (ram,0xf001ff68) */
/* WARNING: Removing unreachable block (ram,0xf001ff3c) */
/* WARNING: Removing unreachable block (ram,0xf001ff8c) */
/* WARNING: Removing unreachable block (ram,0xf001ff54) */

undefined8 _sohasoutofband(int param_1,undefined4 param_2)

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
  iVar1 = (int)*(sword *)(param_1 + 0x5a);
  if (iVar1 < 0) {
    _gsignal(-iVar1,0x10);
    iVar1 = *(int *)(param_1 + 0x34);
  }
  else if (iVar1 < 1) {
    iVar1 = *(int *)(param_1 + 0x34);
  }
  else {
    _pfind();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x34);
    }
    else {
      _psignal();
      iVar1 = *(int *)(param_1 + 0x34);
    }
  }
  if (iVar1 != 0) {
    _selwakeup(iVar1,*(word *)(param_1 + 0x38) & 0x10);
    _selthreadclear(param_1 + 0x34);
    *(word *)(param_1 + 0x38) = *(word *)(param_1 + 0x38) & 0xffef;
  }
  return CONCAT44(param_2,param_1);
}
