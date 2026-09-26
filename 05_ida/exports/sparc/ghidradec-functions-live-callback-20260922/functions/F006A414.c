
/* WARNING: Removing unreachable block (ram,0xf006a468) */
/* WARNING: Removing unreachable block (ram,0xf006a42c) */
/* WARNING: Removing unreachable block (ram,0xf006a478) */
/* WARNING: Removing unreachable block (ram,0xf006a41c) */

undefined8 _getfakefvmseg(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
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
  puVar1 = (undefined *)&aUser;
  _getsegbyname();
  iVar2 = -0x10000000;
  sub_F006A3C4();
  if ((undefined7 *)puVar1 == (undefined7 *)0x0) {
    if (iVar2 == 0) {
      puVar1 = (undefined *)0x0;
    }
    else {
      _fvm_seg = unk_F010FC40;
      uVar3 = *(undefined4 *)(iVar2 + 0xc);
      puVar1 = unk_F010FC40;
      DAT_f010fc58._0_4_ = uVar3;
      sub_F006A498();
      DAT_f010fc58._4_4_ = uVar3;
      _strcpy(0xf010fc78,*(undefined4 *)(iVar2 + 8));
      DAT_f010fc58._64_4_ = DAT_f010fc58._0_4_;
      DAT_f010fc58._68_4_ = DAT_f010fc58._4_4_;
    }
  }
  return CONCAT44(param_2,puVar1);
}

