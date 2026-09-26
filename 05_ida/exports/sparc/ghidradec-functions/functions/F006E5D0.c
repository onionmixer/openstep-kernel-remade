
/* WARNING: Removing unreachable block (ram,0xf006e668) */
/* WARNING: Removing unreachable block (ram,0xf006e5e0) */
/* WARNING: Removing unreachable block (ram,0xf006e678) */
/* WARNING: Removing unreachable block (ram,0xf006e5d4) */

undefined8 _microtime(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  uint uVar5;
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
  uVar3 = param_2;
  _splusclock();
  uVar2 = 0;
  _clock_value();
  uVar4 = uVar2;
  uVar5 = uVar3;
  if ((uVar2 < qword_F0110058._0_4_) ||
     ((qword_F0110058._0_4_ == uVar2 && (uVar3 < qword_F0110058._4_4_)))) {
    if (qword_F0110058._0_4_ - uVar2 != (uint)(qword_F0110058._4_4_ < uVar3)) {
      qword_F0110058 = CONCAT44(uVar2,uVar3);
      goto loc_F006E668;
    }
    uVar4 = qword_F0110058._0_4_;
    uVar5 = qword_F0110058._4_4_;
    if (999999999 < qword_F0110058._4_4_ - uVar3) {
      uVar4 = uVar2;
      uVar5 = uVar3;
    }
  }
  qword_F0110058 = CONCAT44(uVar4,uVar5);
loc_F006E668:
  _splx(uVar1);
  _ns_time_to_timeval(uVar4,uVar5,param_1);
  return CONCAT44(param_2,param_1);
}
