
/* WARNING: Removing unreachable block (ram,0xf004efa8) */
/* WARNING: Removing unreachable block (ram,0xf004ef54) */
/* WARNING: Removing unreachable block (ram,0xf004eef4) */
/* WARNING: Removing unreachable block (ram,0xf004eecc) */
/* WARNING: Removing unreachable block (ram,0xf004eeac) */
/* WARNING: Removing unreachable block (ram,0xf004ee78) */
/* WARNING: Removing unreachable block (ram,0xf004ee48) */
/* WARNING: Removing unreachable block (ram,0xf004ee6c) */
/* WARNING: Removing unreachable block (ram,0xf004ee90) */
/* WARNING: Removing unreachable block (ram,0xf004eeb4) */
/* WARNING: Removing unreachable block (ram,0xf004eeec) */
/* WARNING: Removing unreachable block (ram,0xf004ef3c) */
/* WARNING: Removing unreachable block (ram,0xf004ef80) */
/* WARNING: Removing unreachable block (ram,0xf004efb4) */
/* WARNING: Removing unreachable block (ram,0xf004ee24) */

undefined8 _indirtrunc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  int iVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  int iVar12;
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
  iVar12 = 0;
  uVar11 = 1;
  iVar7 = 0;
  iVar8 = *(int *)(param_1 + 0x50);
  if (0 < param_4) {
    do {
      iVar7 = iVar7 + 1;
      umul(uVar11,*(undefined4 *)(iVar8 + 0x74));
    } while (iVar7 < param_4);
  }
  iVar7 = param_3;
  if (param_3 < 1) {
    iVar1 = *(int *)(param_1 + 0x28);
  }
  else {
    div(param_3,uVar11);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  iVar2 = param_1 + 0xc;
  (**(code **)(iVar1 + 0x80))(iVar2);
  iVar5 = *(int *)(iVar8 + 0x30);
  iVar1 = iVar5;
  div(iVar5,iVar2);
  _geteblk();
  puVar3 = *(uint **)(param_1 + 0x40);
  _bread(puVar3,param_2 << ((byte)*(undefined4 *)(iVar8 + 100) & 0x1f),*(undefined4 *)(iVar8 + 0x30)
        );
  if ((*puVar3 & 4) == 0) {
    uVar9 = puVar3[8];
    _bcopy(uVar9,*(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar8 + 0x30));
    _bzero(uVar9 + iVar7 * 4 + 4,((*(int *)(iVar8 + 0x74) + -1) - iVar7) * 4);
    _bwrite(puVar3);
    iVar2 = *(int *)(iVar8 + 0x74) + -1;
    iVar10 = *(int *)(iVar5 + 0x20);
    if (iVar7 < iVar2) {
      param_2 = iVar2 * 4;
      do {
        iVar6 = *(int *)(param_2 + iVar10);
        if (iVar6 != 0) {
          if (0 < param_4) {
            iVar4 = param_1;
            _indirtrunc(param_1,iVar6,0xffffffff,param_4 + -1);
            iVar12 = iVar12 + iVar4;
          }
          iVar12 = iVar12 + iVar1;
          _free_block(param_1,iVar6,*(undefined4 *)(iVar8 + 0x30));
        }
        iVar2 = iVar2 + -1;
        param_2 = param_2 + -4;
      } while (iVar7 < iVar2);
    }
    if ((0 < param_4) && (-1 < param_3)) {
      rem(param_3,uVar11);
      iVar7 = *(int *)(iVar10 + iVar2 * 4);
      if (iVar7 != 0) {
        _indirtrunc(param_1,iVar7,param_3,param_4 + -1);
        iVar12 = iVar12 + param_1;
      }
    }
    _brelse(iVar5);
  }
  else {
    _brelse(iVar5);
    _brelse(puVar3);
    iVar12 = 0;
  }
  return CONCAT44(param_2,iVar12);
}

