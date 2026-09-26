/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013cc20 */

int _ialloccg(int param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int local_18;
  int local_14;
  undefined4 local_c [2];
  
  iVar3 = *(int *)(param_1 + 0x50);
  if (*(int *)(*(int *)(iVar3 + 0x2d8 +
                       ((int)param_2 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) + 8 +
              (~*(uint *)(iVar3 + 0x6c) & param_2) * 0x10) == 0) {
    return 0;
  }
  pbVar6 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                          (~*(uint *)(iVar3 + 0x1c) & param_2) * *(int *)(iVar3 + 0x18) +
                          param_2 * *(int *)(iVar3 + 0xbc) + *(int *)(iVar3 + 0xc) <<
                          ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),*(undefined4 *)(iVar3 + 0xa0))
  ;
  iVar4 = *(int *)(pbVar6 + 0x20);
  if ((*pbVar6 & 4) == 0) {
    _byte_swap_cylgroup(iVar4);
    if (*(int *)(iVar4 + 0x3d4) == 0x90255) {
      bVar5 = true;
    }
    else {
      _byte_swap_cylgroup(iVar4);
      _brelse(pbVar6);
      bVar5 = false;
    }
  }
  else {
    _brelse(pbVar6);
    bVar5 = false;
  }
  if (!bVar5) {
    return 0;
  }
  if (*(int *)(iVar4 + 0x20) == 0) {
    _byte_swap_cylgroup(iVar4);
    _brelse(pbVar6);
    return 0;
  }
  _getthetime(local_c);
  *(undefined4 *)(iVar4 + 8) = local_c[0];
  if (param_3 != 0) {
    param_3 = param_3 % *(int *)(iVar3 + 0xb8);
    iVar8 = param_3;
    if (param_3 < 0) {
      iVar8 = param_3 + 7;
    }
    if (((uint)(int)*(char *)(iVar4 + 0x2d4 + (iVar8 >> 3)) >> (param_3 + (iVar8 >> 3) * -8 & 0x1fU)
        & 1) == 0) goto LAB_0013ce40;
  }
  iVar8 = *(int *)(iVar4 + 0x30);
  local_14 = iVar8;
  if (iVar8 < 0) {
    local_14 = iVar8 + 7;
  }
  local_14 = local_14 >> 3;
  iVar8 = *(int *)(iVar3 + 0xb8) - iVar8;
  local_18 = iVar8 + 7;
  if (local_18 < 0) {
    local_18 = iVar8 + 0xe;
  }
  local_18 = local_18 >> 3;
  iVar8 = _skpc(0xff,local_18,iVar4 + 0x2d4 + local_14);
  if (iVar8 == 0) {
    local_18 = local_14 + 1;
    local_14 = 0;
    iVar8 = _skpc(0xff,local_18,iVar4 + 0x2d4);
    if (iVar8 == 0) {
      _printf(s_cg____s__irotor____d__fs____s_001ddbf7,param_2,*(undefined4 *)(iVar4 + 0x30),
              iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_ialloccg__map_corrupted_001ddc16);
    }
  }
  iVar8 = (local_14 + local_18) - iVar8;
  param_3 = iVar8 * 8;
  uVar7 = 1;
  while ((uVar7 & (int)*(char *)(iVar8 + 0x2d4 + iVar4)) != 0) {
    uVar7 = uVar7 * 2;
    param_3 = param_3 + 1;
    if (0xff < (int)uVar7) {
      _printf(s_fs____s_001ddc2e,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_ialloccg__block_not_in_map_001ddc37);
    }
  }
  *(int *)(iVar4 + 0x30) = param_3;
LAB_0013ce40:
  iVar8 = param_3;
  if (param_3 < 0) {
    iVar8 = param_3 + 7;
  }
  pbVar2 = (byte *)(iVar4 + 0x2d4 + (iVar8 >> 3));
  *pbVar2 = *pbVar2 | (byte)(1 << ((char)param_3 + (char)(iVar8 >> 3) * -8 & 0x1fU));
  *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + -1;
  *(int *)(iVar3 + 200) = *(int *)(iVar3 + 200) + -1;
  piVar1 = (int *)(*(int *)(iVar3 + 0x2d8 +
                           ((int)param_2 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) + 8 +
                  (~*(uint *)(iVar3 + 0x6c) & param_2) * 0x10);
  *piVar1 = *piVar1 + -1;
  *(char *)(iVar3 + 0xd0) = *(char *)(iVar3 + 0xd0) + '\x01';
  if ((param_4 & 0xf000) == 0x4000) {
    *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
    *(int *)(iVar3 + 0xc0) = *(int *)(iVar3 + 0xc0) + 1;
    piVar1 = (int *)(*(int *)(iVar3 + 0x2d8 +
                             ((int)param_2 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) +
                    (~*(uint *)(iVar3 + 0x6c) & param_2) * 0x10);
    *piVar1 = *piVar1 + 1;
  }
  _byte_swap_cylgroup(iVar4);
  _bdwrite(pbVar6);
  return param_2 * *(int *)(iVar3 + 0xb8) + param_3;
}

