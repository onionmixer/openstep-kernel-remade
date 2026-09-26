
/* WARNING: Removing unreachable block (ram,0xf009239c) */
/* WARNING: Removing unreachable block (ram,0xf0092380) */
/* WARNING: Removing unreachable block (ram,0xf0092320) */
/* WARNING: Removing unreachable block (ram,0xf00922e0) */
/* WARNING: Removing unreachable block (ram,0xf00922a4) */
/* WARNING: Removing unreachable block (ram,0xf0092280) */
/* WARNING: Removing unreachable block (ram,0xf00922d0) */
/* WARNING: Removing unreachable block (ram,0xf0092308) */
/* WARNING: Removing unreachable block (ram,0xf009234c) */
/* WARNING: Removing unreachable block (ram,0xf00923b4) */
/* WARNING: Removing unreachable block (ram,0xf00923c0) */
/* WARNING: Removing unreachable block (ram,0xf0092264) */

undefined8 _sdread(uint param_1,undefined4 *param_2)

{
  undefined (*pauVar1) [11];
  undefined (*pauVar2) [10];
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  int iVar7;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar11;
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
  uVar9 = (uint)(sword)param_1;
  uVar3 = uVar9;
  sub_F0092E34();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  uVar4 = uVar9;
  sub_F0092EB0();
  if (uVar3 == 0) {
    pcVar11 = (code *)0x6;
  }
  else {
    uVar8 = uVar3;
    _objc_msgSend(uVar3,paIsformatted);
    pauVar1 = paController;
    if ((uVar8 & 0xff) == 0) {
      pcVar11 = (code *)0x16;
    }
    else {
      puVar6 = (uint *)*param_2;
      _objc_msgSend(uVar4,paController);
      _objc_msgSend();
      if (_forceSdPageAlign != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) = _page_size;
      }
      _objc_msgSend(uVar4,pauVar1);
      _objc_msgSend();
      uVar10 = *puVar6;
      uVar8 = puVar6[1];
      *puVar6 = uVar4;
      pauVar2 = paBlocksize;
      iVar7 = param_2[3];
      param_2[3] = 1;
      _objc_msgSend(uVar3,pauVar2);
      pcVar11 = _sdstrategy;
      _physio(_sdstrategy,*(undefined4 *)(unk_F01123A8 + ((param_1 & 0xff) >> 3) * 4),uVar9,1,
              sub_F0092E0C,param_2,uVar3);
      if (iVar7 == 1) {
        _bcopy(uVar4,uVar10,uVar8);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      }
      else {
        _copyout(uVar4,uVar10,uVar8);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      }
      _IOFree(uVar5,*(undefined4 *)((int)register0x00000038 + -0x20));
    }
  }
  return CONCAT44(param_2,pcVar11);
}

