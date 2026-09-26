
/* WARNING: Removing unreachable block (ram,0xf00bdc24) */
/* WARNING: Removing unreachable block (ram,0xf00bdb4c) */
/* WARNING: Removing unreachable block (ram,0xf00bdb5c) */
/* WARNING: Removing unreachable block (ram,0xf00bdc58) */
/* WARNING: Removing unreachable block (ram,0xf00bdabc) */

undefined8 -[kmDevice graphicPanelString:](int param_1,undefined4 param_2,byte *param_3)

{
  sword sVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  byte *pbVar9;
  int iVar10;
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
  if (*(int *)(param_1 + 0x114) == 2) {
    dword_F0132F38 = 0;
    dword_F0132F20 = 0x120;
    dword_F0132F24 = 0x34;
    sub_F00BD880();
    iVar10 = 0;
    bVar4 = *param_3;
    pbVar9 = param_3;
    bVar2 = 0;
    while (bVar3 = bVar4, bVar3 != 0) {
      if (bVar3 == 10) {
        iVar10 = iVar10 + 1;
      }
      pbVar9 = pbVar9 + 1;
      bVar2 = bVar3;
      bVar4 = *pbVar9;
    }
    if (bVar2 != 10) {
      iVar10 = iVar10 + 1;
    }
    dword_F0132F28 = dword_F0132F28 + 3 & 0xfffffffc;
    dword_F0132F20 = dword_F0132F20 & 0xfffffffc;
    sVar1 = *(sword *)(*off_F012054C + 8);
    iVar5 = sVar1 + 9;
    div(iVar5,10);
    iVar5 = sVar1 + iVar5;
    iVar6 = iVar5;
    umul(iVar5,iVar10 + -1);
    dword_F0132F34 = (dword_F0132F24 - iVar6) / 2 + 2;
    bVar2 = *param_3;
    while (bVar2 != 0) {
      iVar10 = 0;
      uVar7 = (uint)(char)*param_3;
      pbVar9 = param_3;
      do {
        uVar8 = uVar7 & 0xff;
        if (uVar7 == 10) break;
        pbVar9 = pbVar9 + 1;
        uVar7 = (uint)(char)*pbVar9;
        iVar10 = iVar10 + *(sword *)(off_F012054C[-1] + uVar8 * 0x10 + 0x430);
      } while (uVar7 != 0);
      dword_F0132F30 = (int)(dword_F0132F20 - iVar10) / 2;
      while ((uVar7 = (uint)*param_3, uVar7 != 0 && (param_3 = param_3 + 1, uVar7 != 10))) {
        sub_F00BD8B0(off_F012054C[-1] + uVar7 * 0x10 + 0x428);
      }
      dword_F0132F34 = dword_F0132F34 + iVar5;
      bVar2 = *param_3;
    }
    sub_F00BDA30(*(undefined4 *)(param_1 + 0x10c));
  }
  return CONCAT44(param_2,param_1);
}

