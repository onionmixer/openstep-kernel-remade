
/* WARNING: Removing unreachable block (ram,0xf009790c) */

undefined8 _clock_value(int param_1)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined8 uVar4;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  sub_F0097AB4((undefined *)((int)register0x00000038 + -0x10));
  uVar3 = (uint)*(undefined8 *)((int)register0x00000038 + -0x10);
  iVar1 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  uVar2 = uVar3 * 0x7d >> 0x1d |
          ((uVar3 * 0x1f >> 0x1e |
           (((uVar3 >> 0x1b | iVar1 << 5) - iVar1) - (uint)(uVar3 * 0x20 < uVar3)) * 4) + iVar1 +
          (uint)CARRY4(uVar3 * 0x7c,uVar3)) * 8;
  uVar3 = uVar3 * 1000;
  *(qword *)((int)register0x00000038 + -0x10) = CONCAT44(uVar2,uVar3);
  if (param_1 == 0) {
    uVar4 = CONCAT44(uVar2 + (int)((qword)qword_F0131468 >> 0x20) +
                     (uint)CARRY4(uVar3,(uint)qword_F0131468),uVar3 + (uint)qword_F0131468);
    *(undefined8 *)((int)register0x00000038 + -0x10) = uVar4;
  }
  else if (param_1 == 1) {
    uVar4 = CONCAT44(uVar2,uVar3);
  }
  else {
    uVar4 = 0;
  }
  return CONCAT44((int)uVar4,(int)((qword)uVar4 >> 0x20));
}

