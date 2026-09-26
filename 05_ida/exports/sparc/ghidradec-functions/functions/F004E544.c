
/* WARNING: Removing unreachable block (ram,0xf004e6ec) */
/* WARNING: Removing unreachable block (ram,0xf004e680) */
/* WARNING: Removing unreachable block (ram,0xf004e604) */
/* WARNING: Removing unreachable block (ram,0xf004e5c0) */
/* WARNING: Removing unreachable block (ram,0xf004e59c) */
/* WARNING: Removing unreachable block (ram,0xf004e584) */
/* WARNING: Removing unreachable block (ram,0xf004e5b8) */
/* WARNING: Removing unreachable block (ram,0xf004e5e8) */
/* WARNING: Removing unreachable block (ram,0xf004e61c) */
/* WARNING: Removing unreachable block (ram,0xf004e6ac) */
/* WARNING: Removing unreachable block (ram,0xf004e6e0) */
/* WARNING: Removing unreachable block (ram,0xf004e574) */

undefined8 _iupdat(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 uVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  iVar9 = *(int *)(param_1 + 0x50);
  if (((*(word *)(param_1 + 0x44) & 0x4e) != 0) && (*(char *)(iVar9 + 0xd2) == '\0')) {
    uVar7 = *(uint *)(param_1 + 0x48);
    uVar8 = *(undefined4 *)(iVar9 + 0xb8);
    uVar6 = uVar7;
    .udiv(uVar7,uVar8);
    iVar2 = *(int *)(iVar9 + 0xbc);
    .umul(iVar2,uVar6);
    iVar4 = *(int *)(iVar9 + 0x18);
    .umul(iVar4,uVar6 & ~*(uint *)(iVar9 + 0x1c));
    iVar5 = *(int *)(iVar9 + 0x10);
    .urem(uVar7,uVar8);
    .udiv();
    puVar3 = *(uint **)(param_1 + 0x40);
    _bread(puVar3,iVar2 + iVar4 + iVar5 + (uVar7 << ((byte)*(undefined4 *)(iVar9 + 0x60) & 0x1f)) <<
                  ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f),*(undefined4 *)(iVar9 + 0x30));
    if ((*puVar3 & 4) == 0) {
      if ((*(word *)(param_1 + 0x44) & 0x46) != 0) {
        _microtime(&_iuniqtime);
        if ((*(word *)(param_1 + 0x44) & 4) != 0) {
          *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
        }
        if ((*(word *)(param_1 + 0x44) & 2) != 0) {
          *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(param_1 + 0x44) & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x4c) = 0;
          *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
        }
      }
      wVar1 = *(word *)(param_1 + 0x44);
      iVar2 = *(int *)(param_1 + 0x48);
      *(word *)(param_1 + 0x44) = wVar1 & 0xffb1;
      .urem(iVar2,*(undefined4 *)(iVar9 + 0x78));
      uVar6 = puVar3[8];
      *(word *)(param_1 + 0x44) = wVar1 & 0xfdb1;
      iVar9 = uVar6 + iVar2 * 0x80;
      _memcpy(iVar9,param_1 + 100,0x80);
      if (*(sword *)(*(int *)(param_1 + 0x30) + 0x124) != 0) {
        *(undefined2 *)(iVar9 + 4) = *(undefined2 *)(param_1 + 0xe4);
        *(undefined2 *)(iVar9 + 6) = *(undefined2 *)(param_1 + 0xe6);
      }
      if (param_2 == 0) {
        _bdwrite(puVar3);
      }
      else {
        _bwrite(puVar3);
      }
    }
    else {
      _brelse(puVar3);
    }
  }
  return CONCAT44(param_2,param_1);
}
