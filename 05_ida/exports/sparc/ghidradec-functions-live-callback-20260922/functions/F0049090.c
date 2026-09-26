
/* WARNING: Removing unreachable block (ram,0xf0049124) */
/* WARNING: Removing unreachable block (ram,0xf004909c) */

undefined8 _dirpref(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 unaff_l0;
  int iVar12;
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
  iVar12 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 200);
  div(iVar2,iVar12);
  uVar10 = 0;
  uVar6 = 0;
  if (0 < iVar12) {
    bVar1 = (byte)*(undefined4 *)(param_1 + 0x70);
    iVar3 = 0 >> (bVar1 & 0x1f);
    iVar8 = *(int *)(param_1 + 0xb8);
    uVar11 = uVar10;
    do {
      iVar3 = *(int *)(iVar3 * 4 + param_1 + 0x2d8);
      iVar5 = (uVar6 & ~*(uint *)(param_1 + 0x6c)) * 0x10;
      iVar7 = *(int *)(iVar3 + iVar5);
      iVar9 = iVar8;
      uVar10 = uVar11;
      if ((iVar7 < iVar8) && (iVar9 = iVar7, uVar10 = uVar6, *(int *)(iVar3 + iVar5 + 8) < iVar2)) {
        iVar9 = iVar8;
        uVar10 = uVar11;
      }
      uVar6 = uVar6 + 1;
      iVar3 = (int)uVar6 >> (bVar1 & 0x1f);
      iVar8 = iVar9;
      uVar11 = uVar10;
    } while ((int)uVar6 < iVar12);
  }
  uVar4 = *(undefined4 *)(param_1 + 0xb8);
  umul(uVar4,uVar10);
  return CONCAT44(param_2,uVar4);
}

