
/* WARNING: Removing unreachable block (ram,0xf00977a0) */
/* WARNING: Removing unreachable block (ram,0xf00977dc) */
/* WARNING: Removing unreachable block (ram,0xf0097794) */

undefined8 _sparc_hardclock(undefined4 param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
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
  puVar2 = (undefined8 *)0x2710;
  qword_F0131478 =
       CONCAT44((int)((qword)qword_F0131478 >> 0x20) + (uint)(0xffffd8ef < (uint)qword_F0131478),
                (uint)qword_F0131478 + 10000);
  if (dword_F0131494 != 0) {
    _clock_interrupt(_tick,((uint)param_2 >> 6 ^ 1) & 1);
    puVar2 = param_2;
    _hardclock(param_1);
  }
  if (dword_F0131490 != (code *)0x0) {
    param_2 = &qword_F0131488;
    if ((qword_F0131488._0_4_ != 0) || (qword_F0131488._4_4_ != (undefined8 *)0x0)) {
      uVar1 = 1;
      _clock_value();
      if ((qword_F0131488._0_4_ <= uVar1) &&
         ((qword_F0131488._0_4_ != uVar1 || (qword_F0131488._4_4_ <= puVar2)))) {
        qword_F0131488 = 0;
        (*dword_F0131490)(0,0,0);
      }
    }
  }
  return CONCAT44(param_2,DAT_f0131400);
}

