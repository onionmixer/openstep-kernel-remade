
/* WARNING: Removing unreachable block (ram,0xf004a87c) */
/* WARNING: Removing unreachable block (ram,0xf004a798) */
/* WARNING: Removing unreachable block (ram,0xf004a748) */
/* WARNING: Removing unreachable block (ram,0xf004a708) */
/* WARNING: Removing unreachable block (ram,0xf004a6c8) */
/* WARNING: Removing unreachable block (ram,0xf004a6ac) */
/* WARNING: Removing unreachable block (ram,0xf004a6a0) */
/* WARNING: Removing unreachable block (ram,0xf004a6b8) */
/* WARNING: Removing unreachable block (ram,0xf004a6e0) */
/* WARNING: Removing unreachable block (ram,0xf004a73c) */
/* WARNING: Removing unreachable block (ram,0xf004a75c) */
/* WARNING: Removing unreachable block (ram,0xf004a7a4) */
/* WARNING: Removing unreachable block (ram,0xf004a8a8) */
/* WARNING: Removing unreachable block (ram,0xf004a680) */

undefined8 _ifree(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  byte bVar7;
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
  iVar6 = *(int *)(param_1 + 0x50);
  uVar1 = *(uint *)(iVar6 + 0xb8);
  .umul(uVar1,*(undefined4 *)(iVar6 + 0x2c));
  if (uVar1 <= param_2) {
    _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x46),param_2,iVar6 + 0xd4);
    _panic(aIfreeRange);
  }
  uVar1 = param_2;
  .udiv(param_2,*(undefined4 *)(iVar6 + 0xb8));
  iVar2 = *(int *)(iVar6 + 0xbc);
  .umul(iVar2,uVar1);
  iVar4 = *(int *)(iVar6 + 0x18);
  .umul(iVar4,uVar1 & ~*(uint *)(iVar6 + 0x1c));
  puVar3 = *(uint **)(param_1 + 0x40);
  _bread(puVar3,iVar2 + iVar4 + *(int *)(iVar6 + 0xc) << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f)
         ,*(undefined4 *)(iVar6 + 0xa0));
  uVar5 = puVar3[8];
  if (((*puVar3 & 4) == 0) && (*(int *)(uVar5 + 0x3d4) == 0x90255)) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(uVar5 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
    .urem(param_2,*(undefined4 *)(iVar6 + 0xb8));
    iVar2 = (param_2 >> 3) + uVar5;
    bVar7 = (byte)param_2 & 7;
    if (((int)*(char *)(iVar2 + 0x2d4) >> bVar7 & 1U) == 0) {
      _printf(aDev0xXInoDFsS_0,(int)*(sword *)(param_1 + 0x46),param_2,iVar6 + 0xd4);
      _panic(aIfreeFreeingFr);
    }
    *(byte *)(iVar2 + 0x2d4) = *(byte *)(iVar2 + 0x2d4) & ~(byte)(1 << bVar7);
    if (param_2 < *(uint *)(uVar5 + 0x30)) {
      *(uint *)(uVar5 + 0x30) = param_2;
    }
    *(int *)(uVar5 + 0x20) = *(int *)(uVar5 + 0x20) + 1;
    *(int *)(iVar6 + 200) = *(int *)(iVar6 + 200) + 1;
    iVar2 = *(int *)(((int)uVar1 >> ((byte)*(undefined4 *)(iVar6 + 0x70) & 0x1f)) * 4 + iVar6 +
                    0x2d8) + (uVar1 & ~*(uint *)(iVar6 + 0x6c)) * 0x10;
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    if ((param_3 & 0xf000) == 0x4000) {
      *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + -1;
      *(int *)(iVar6 + 0xc0) = *(int *)(iVar6 + 0xc0) + -1;
      iVar4 = *(int *)(((int)uVar1 >> ((byte)*(undefined4 *)(iVar6 + 0x70) & 0x1f)) * 4 + iVar6 +
                      0x2d8);
      iVar2 = (uVar1 & ~*(uint *)(iVar6 + 0x6c)) * 0x10;
      *(int *)(iVar4 + iVar2) = *(int *)(iVar4 + iVar2) + -1;
    }
    *(char *)(iVar6 + 0xd0) = *(char *)(iVar6 + 0xd0) + '\x01';
    _bdwrite(puVar3);
    if (((*(byte *)(iVar6 + 0xd3) & 2) != 0) && (*(int *)(iVar6 + 0x90) < *(int *)(iVar6 + 200))) {
      _wakeup(iVar6 + 200);
      *(byte *)(iVar6 + 0xd3) = *(byte *)(iVar6 + 0xd3) & 0xfd;
    }
  }
  else {
    _brelse(puVar3);
  }
  return CONCAT44(param_2,param_1);
}
