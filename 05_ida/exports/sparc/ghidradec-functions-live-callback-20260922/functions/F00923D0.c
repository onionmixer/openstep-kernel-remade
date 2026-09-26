
/* WARNING: Removing unreachable block (ram,0xf00924ec) */
/* WARNING: Removing unreachable block (ram,0xf00924d4) */
/* WARNING: Removing unreachable block (ram,0xf0092480) */
/* WARNING: Removing unreachable block (ram,0xf0092448) */
/* WARNING: Removing unreachable block (ram,0xf00923f8) */
/* WARNING: Removing unreachable block (ram,0xf009241c) */
/* WARNING: Removing unreachable block (ram,0xf0092458) */
/* WARNING: Removing unreachable block (ram,0xf0092498) */
/* WARNING: Removing unreachable block (ram,0xf00924c0) */
/* WARNING: Removing unreachable block (ram,0xf0092524) */
/* WARNING: Removing unreachable block (ram,0xf009253c) */
/* WARNING: Removing unreachable block (ram,0xf00923dc) */

undefined8 _sdwrite(uint param_1,undefined4 *param_2)

{
  undefined (*pauVar1) [11];
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar6;
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
  uVar4 = (uint)(sword)param_1;
  uVar2 = uVar4;
  sub_F0092E34();
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  sub_F0092EB0();
  if (uVar2 == 0) {
    pcVar6 = (code *)0x6;
  }
  else {
    uVar3 = uVar2;
    _objc_msgSend(uVar2,paIsformatted);
    pauVar1 = paController;
    if ((uVar3 & 0xff) == 0) {
      pcVar6 = (code *)0x16;
    }
    else {
      puVar5 = (uint *)*param_2;
      _objc_msgSend(uVar4,paController);
      _objc_msgSend();
      if (_forceSdPageAlign != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x14) = _page_size;
      }
      _objc_msgSend(uVar4,pauVar1);
      _objc_msgSend();
      uVar3 = *puVar5;
      *puVar5 = uVar4;
      if (param_2[3] == 1) {
        _bcopy(uVar3,uVar4,puVar5[1]);
      }
      else {
        _copyin(uVar3,uVar4,puVar5[1]);
        param_2[3] = 1;
      }
      _objc_msgSend(uVar2,paBlocksize);
      pcVar6 = _sdstrategy;
      _physio(_sdstrategy,*(undefined4 *)(unk_F01123A8 + ((param_1 & 0xff) >> 3) * 4),
              (int)(sword)param_1,0,sub_F0092E0C,param_2,uVar2);
      _IOFree(*(undefined4 *)((int)register0x00000038 + -0x1c),
              *(undefined4 *)((int)register0x00000038 + -0x20));
    }
  }
  return CONCAT44(param_2,pcVar6);
}

