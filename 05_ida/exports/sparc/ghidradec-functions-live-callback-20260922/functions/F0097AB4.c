
/* WARNING: Removing unreachable block (ram,0xf0097b54) */
/* WARNING: Removing unreachable block (ram,0xf0097ab8) */

undefined8 sub_F0097AB4(undefined8 *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  bool bVar6;
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
  puVar1 = param_1;
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
  uVar4 = (uint)uVar5 + uVar3;
  iVar2 = (int)((qword)uVar5 >> 0x20) + (uint)CARRY4((uint)uVar5,uVar3);
  if ((DAT_f0131480._0_4_ == iVar2) && (DAT_f0131480._4_4_ == uVar4)) {
    bVar6 = 0xfffffffe < uVar4;
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + (uint)bVar6;
  }
  DAT_f0131480 = CONCAT44(iVar2,uVar4);
  *param_1 = CONCAT44(iVar2,uVar4);
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}

