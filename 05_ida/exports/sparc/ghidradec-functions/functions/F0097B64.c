
/* WARNING: Removing unreachable block (ram,0xf0097c04) */
/* WARNING: Removing unreachable block (ram,0xf0097b68) */

undefined8 _event_set_ts(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
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
  puVar2 = param_1;
  _splusclock();
  if ((int)uRamfeffd004 < 0) {
    uVar3 = 1;
    uVar5 = CONCAT44((int)((qword)qword_F0131478 >> 0x20) +
                     (uint)(0xffffd8ef < (uint)qword_F0131478),(uint)qword_F0131478 + 10000);
  }
  else {
    uVar3 = uRamfeffd004 >> 10;
    uVar5 = qword_F0131478;
  }
  uVar1 = (uint)uVar5 + uVar3;
  iVar4 = (int)((qword)uVar5 >> 0x20) + (uint)CARRY4((uint)uVar5,uVar3);
  uVar5 = CONCAT44(iVar4,uVar1);
  if ((DAT_f0131480._0_4_ == iVar4) && (DAT_f0131480._4_4_ == uVar1)) {
    uVar5 = CONCAT44(iVar4 + (uint)(0xfffffffe < uVar1),uVar1 + 1);
  }
  *(undefined8 *)((int)register0x00000038 + -0x10) = uVar5;
  DAT_f0131480 = uVar5;
  _splx(puVar2);
  uVar5 = *(undefined8 *)((int)register0x00000038 + -0x10);
  param_1[1] = (int)((qword)uVar5 >> 0x20);
  *param_1 = (int)uVar5;
  return CONCAT44(param_2,param_1);
}
