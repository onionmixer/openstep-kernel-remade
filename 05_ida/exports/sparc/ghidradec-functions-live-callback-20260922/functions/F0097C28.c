
/* WARNING: Removing unreachable block (ram,0xf0097cc8) */
/* WARNING: Removing unreachable block (ram,0xf0097c2c) */

undefined8 _event_get(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
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
  bool bVar5;
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
  _splusclock();
  if ((int)uRamfeffd004 < 0) {
    uVar2 = 1;
    uVar4 = CONCAT44((int)((qword)qword_F0131478 >> 0x20) +
                     (uint)(0xffffd8ef < (uint)qword_F0131478),(uint)qword_F0131478 + 10000);
  }
  else {
    uVar2 = uRamfeffd004 >> 10;
    uVar4 = qword_F0131478;
  }
  uVar3 = (uint)uVar4 + uVar2;
  iVar1 = (int)((qword)uVar4 >> 0x20) + (uint)CARRY4((uint)uVar4,uVar2);
  if ((DAT_f0131480._0_4_ == iVar1) && (DAT_f0131480._4_4_ == uVar3)) {
    bVar5 = 0xfffffffe < uVar3;
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + (uint)bVar5;
  }
  DAT_f0131480 = CONCAT44(iVar1,uVar3);
  *(qword *)((int)register0x00000038 + -0x10) = CONCAT44(iVar1,uVar3);
  _splx(param_1);
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}

