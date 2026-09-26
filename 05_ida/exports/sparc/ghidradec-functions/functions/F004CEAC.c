
/* WARNING: Removing unreachable block (ram,0xf004d0c0) */
/* WARNING: Removing unreachable block (ram,0xf004d084) */
/* WARNING: Removing unreachable block (ram,0xf004d058) */
/* WARNING: Removing unreachable block (ram,0xf004d048) */
/* WARNING: Removing unreachable block (ram,0xf004cf90) */
/* WARNING: Removing unreachable block (ram,0xf004d008) */
/* WARNING: Removing unreachable block (ram,0xf004d01c) */
/* WARNING: Removing unreachable block (ram,0xf004cfdc) */
/* WARNING: Removing unreachable block (ram,0xf004d0a0) */
/* WARNING: Removing unreachable block (ram,0xf004d0d8) */
/* WARNING: Removing unreachable block (ram,0xf004cedc) */

undefined8 sub_F004CEAC(int param_1,int param_2)

{
  sword sVar1;
  word wVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
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
  iVar8 = 0;
  while ((unk_F010EB7D._0_1_ & 1) != 0) {
    unk_F010EB7D._0_1_ = unk_F010EB7D._0_1_ | 2;
    _sleep(&unk_F010EB7D,10);
  }
  unk_F010EB7D._0_1_ = 1;
  iVar5 = param_2;
  if (*(int *)(param_2 + 0x48) == *(int *)(param_1 + 0x48)) {
    iVar8 = 0x16;
  }
  else if (*(int *)(param_2 + 0x48) != 2) {
    wVar2 = *(word *)(param_2 + 100);
    while (((iVar7 = 0, (wVar2 & 0xf000) == 0x4000 && (*(sword *)(iVar5 + 0x66) != 0)) &&
           (0x17 < *(uint *)(iVar5 + 0x70)))) {
      iVar7 = iVar5;
      _blkatoff(iVar5,0,(undefined *)((int)register0x00000038 + -0xc));
      iVar4 = iVar5;
      if (iVar7 == 0) {
loc_F004D070:
        iVar8 = (int)*(char *)(dword_F0133DDC + 0x38);
        iVar5 = iVar4;
        goto loc_F004D07C;
      }
      iVar4 = *(int *)((int)register0x00000038 + -0xc);
      if ((*(sword *)(iVar4 + 0x12) != 2) || ((*(uint *)(iVar4 + 0x14) & 0xffff0000) != 0x2e2e0000))
      {
        puVar3 = aMangledEntry_1;
        goto loc_F004CFDC;
      }
      iVar6 = *(int *)(iVar4 + 0xc);
      if (iVar6 == *(int *)(param_1 + 0x48)) {
        iVar8 = 0x16;
        goto loc_F004D07C;
      }
      if (iVar6 == 2) goto loc_F004D07C;
      _brelse(iVar7);
      iVar7 = 0;
      if (iVar5 == param_2) {
        wVar2 = *(word *)(param_2 + 0x44);
        *(word *)(param_2 + 0x44) = wVar2 & 0xfffe;
        if ((wVar2 & 0x10) != 0) {
          *(word *)(param_2 + 0x44) = wVar2 & 0xffee;
          _wakeup(param_2);
        }
        sVar1 = *(sword *)(iVar5 + 0x46);
      }
      else {
        _iput(iVar5);
        sVar1 = *(sword *)(iVar5 + 0x46);
      }
      iVar4 = (int)sVar1;
      _iget(iVar4,*(undefined4 *)(iVar5 + 0x50),iVar6);
      if (iVar4 == 0) goto loc_F004D070;
      wVar2 = *(word *)(iVar4 + 100);
      iVar5 = iVar4;
    }
    puVar3 = aBadSizeUnlinke;
loc_F004CFDC:
    sub_F004CD8C(iVar5,puVar3,0);
    iVar8 = 0x14;
loc_F004D07C:
    if (iVar7 != 0) {
      _brelse(iVar7);
    }
  }
  if ((unk_F010EB7D._0_1_ & 2) != 0) {
    _wakeup(&unk_F010EB7D);
  }
  unk_F010EB7D._0_1_ = 0;
  if ((iVar5 != 0) && (iVar5 != param_2)) {
    _iput(iVar5);
    wVar2 = *(word *)(param_2 + 0x44);
    while ((wVar2 & 1) != 0) {
      *(word *)(param_2 + 0x44) = wVar2 | 0x10;
      _sleep(param_2,10);
      wVar2 = *(word *)(param_2 + 0x44);
    }
    *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 1;
    if ((iVar8 == 0) && (*(sword *)(param_2 + 0x66) == 0)) {
      iVar8 = 2;
    }
  }
  return CONCAT44(param_2,iVar8);
}
