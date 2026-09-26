/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d3f0 */

void _ifree(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  byte *pbVar7;
  sbyte sVar8;
  undefined4 local_c [2];
  
  iVar3 = *(int *)(param_1 + 0x50);
  if ((uint)(*(int *)(iVar3 + 0xb8) * *(int *)(iVar3 + 0x2c)) <= param_2) {
    _printf(s_dev___0x_x__ino____d__fs____s_001ddd28,(int)*(short *)(param_1 + 0x46),param_2,
            iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(s_ifree__range_001ddd47);
  }
  uVar6 = param_2 / *(uint *)(iVar3 + 0xb8);
  pbVar7 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                          uVar6 * *(int *)(iVar3 + 0xbc) +
                          (~*(uint *)(iVar3 + 0x1c) & uVar6) * *(int *)(iVar3 + 0x18) +
                          *(int *)(iVar3 + 0xc) << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),
                          *(undefined4 *)(iVar3 + 0xa0));
  iVar4 = *(int *)(pbVar7 + 0x20);
  if ((*pbVar7 & 4) == 0) {
    _byte_swap_cylgroup(iVar4);
    if (*(int *)(iVar4 + 0x3d4) == 0x90255) {
      bVar5 = true;
    }
    else {
      _byte_swap_cylgroup(iVar4);
      _brelse(pbVar7);
      bVar5 = false;
    }
  }
  else {
    _brelse(pbVar7);
    bVar5 = false;
  }
  if (bVar5) {
    _getthetime(local_c);
    *(undefined4 *)(iVar4 + 8) = local_c[0];
    param_2 = param_2 % *(uint *)(iVar3 + 0xb8);
    if (((uint)(int)*(char *)(iVar4 + 0x2d4 + (param_2 >> 3)) >> (param_2 & 7) & 1) == 0) {
      _printf(s_dev___0x_x__ino____d__fs____s_001ddd54,(int)*(short *)(param_1 + 0x46),param_2,
              iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(s_ifree__freeing_free_inode_001ddd73);
    }
    sVar8 = (sbyte)(param_2 & 7);
    pbVar2 = (byte *)(iVar4 + 0x2d4 + (param_2 >> 3));
    *pbVar2 = *pbVar2 & ((byte)(-2 << sVar8) | (byte)(0xfffffffe >> 0x20 - sVar8));
    if (param_2 < *(uint *)(iVar4 + 0x30)) {
      *(uint *)(iVar4 + 0x30) = param_2;
    }
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 1;
    *(int *)(iVar3 + 200) = *(int *)(iVar3 + 200) + 1;
    piVar1 = (int *)(*(int *)(iVar3 + 0x2d8 +
                             ((int)uVar6 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) + 8 +
                    (~*(uint *)(iVar3 + 0x6c) & uVar6) * 0x10);
    *piVar1 = *piVar1 + 1;
    if ((param_3 & 0xf000) == 0x4000) {
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
      *(int *)(iVar3 + 0xc0) = *(int *)(iVar3 + 0xc0) + -1;
      piVar1 = (int *)(*(int *)(iVar3 + 0x2d8 +
                               ((int)uVar6 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) +
                      (~*(uint *)(iVar3 + 0x6c) & uVar6) * 0x10);
      *piVar1 = *piVar1 + -1;
    }
    *(char *)(iVar3 + 0xd0) = *(char *)(iVar3 + 0xd0) + '\x01';
    _byte_swap_cylgroup(iVar4);
    _bdwrite(pbVar7);
    if (((*(byte *)(iVar3 + 0xd3) & 2) != 0) && (*(int *)(iVar3 + 0x90) < *(int *)(iVar3 + 200))) {
      _wakeup(iVar3 + 200);
      *(byte *)(iVar3 + 0xd3) = *(byte *)(iVar3 + 0xd3) & 0xfd;
    }
  }
  return;
}

