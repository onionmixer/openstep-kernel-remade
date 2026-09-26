
/* WARNING: Removing unreachable block (ram,0xf00bc05c) */
/* WARNING: Removing unreachable block (ram,0xf00bbfc8) */
/* WARNING: Removing unreachable block (ram,0xf00bbff8) */
/* WARNING: Removing unreachable block (ram,0xf00bbf88) */
/* WARNING: Removing unreachable block (ram,0xf00bbf2c) */
/* WARNING: Removing unreachable block (ram,0xf00bbf04) */
/* WARNING: Removing unreachable block (ram,0xf00bbf48) */
/* WARNING: Removing unreachable block (ram,0xf00bbfa0) */
/* WARNING: Removing unreachable block (ram,0xf00bbfb4) */
/* WARNING: Removing unreachable block (ram,0xf00bc040) */
/* WARNING: Removing unreachable block (ram,0xf00bc078) */
/* WARNING: Removing unreachable block (ram,0xf00bbebc) */

undefined8 sub_F00BBEB8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  iVar7 = -1;
  iVar1 = param_1;
  _spl1();
  puVar6 = unk_F0131848;
  iVar2 = *(int *)(param_1 + 0x18);
  uVar4 = 0;
  while (0 < iVar2) {
    iVar7 = param_1 + 0x18;
    if ((*(uint *)(param_1 + 0x3c) & 0x200020) == 0) {
      uVar5 = 0x80;
    }
    else {
      uVar5 = 0;
    }
    _ndqb(iVar7,uVar5);
    if (iVar7 == 0) break;
    if (0x800 < uVar4 + iVar7) break;
    _q_to_b(param_1 + 0x18,puVar6,iVar7);
    puVar6 = puVar6 + iVar7;
    uVar4 = uVar4 + iVar7;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  _splx(iVar1);
  pbVar3 = (byte *)&DAT_f0131800;
  if (0 < (int)uVar4) {
    pbVar3 = unk_F0131848 + uVar4;
    for (puVar6 = unk_F0131848; puVar6 < unk_F0131848 + uVar4; puVar6 = puVar6 + 1) {
      _objc_msgSend(_kmId,paKmputc,*puVar6 & 0x7f);
      pbVar3 = _kmId;
    }
  }
  _spl1();
  if (iVar7 == 0) {
    uVar4 = param_1 + 0x18;
    _getc(uVar4);
    _timeout(_ttrstrt,param_1,uVar4 & 0x7f);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 1;
  }
  else if (0 < *(int *)(param_1 + 0x18)) {
    _callout_dispatch(4,sub_F00BBEB8,param_1);
  }
  uVar4 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = uVar4 & 0xffffffdf;
  if (*(int *)(param_1 + 0x18) <= (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)
     ) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = uVar4 & 0xffffff9f;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
  }
  _splx(pbVar3);
  return CONCAT44(param_2,param_1);
}
