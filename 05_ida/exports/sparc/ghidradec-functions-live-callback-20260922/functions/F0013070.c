
/* WARNING: Removing unreachable block (ram,0xf0013130) */
/* WARNING: Removing unreachable block (ram,0xf0013160) */
/* WARNING: Removing unreachable block (ram,0xf0013154) */
/* WARNING: Removing unreachable block (ram,0xf0013120) */
/* WARNING: Removing unreachable block (ram,0xf001316c) */
/* WARNING: Removing unreachable block (ram,0xf00130a4) */
/* WARNING: Removing unreachable block (ram,0xf0013094) */

uint _inittodr(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined8 in_o0_1;
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
  undefined auStackX_0 [92];
  
  uVar1 = (uint)((qword)in_o0_1 >> 0x20);
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
  if ((uVar1 < 0x1ff46b80) || ((int)uVar1 < 0)) {
    _printf(aWarningPrepost);
  }
  else {
    _microtime((undefined *)((int)register0x00000038 + -0x10));
    _boottime = *(uint *)((int)register0x00000038 + -0x10);
    DAT_f013516c = 0;
    uVar3 = _boottime - uVar1;
    if ((int)uVar3 < 0) {
      uVar3 = -uVar3;
    }
    if ((uVar3 < 0x2a300) && ((int)uVar1 < (int)_boottime)) {
      DAT_f013516c = 0;
      return uVar1;
    }
    if (_boottime < 0x1e13380) {
      puVar2 = aWarningClockNo;
    }
    else {
      if (uVar3 < 0x76a701) {
        udiv();
        _printf(aWarningClockLo);
        goto loc_F001316C;
      }
      puVar2 = aWarningPrepost_0;
    }
    _printf(puVar2);
    *(uint *)((int)register0x00000038 + -0x10) = uVar1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    _setthetime((undefined *)((int)register0x00000038 + -0x10));
    _boottime = (uint)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
    DAT_f013516c = (undefined4)*(undefined8 *)((int)register0x00000038 + -0x10);
  }
loc_F001316C:
  _printf(aCheckAndResetT);
  return uVar1;
}

