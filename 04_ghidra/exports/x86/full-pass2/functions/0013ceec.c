/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ceec */

void _free_block(int param_1,int param_2,uint param_3)

{
  short *psVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint local_88;
  byte local_84;
  int local_24;
  undefined4 local_c [2];
  
  iVar4 = *(int *)(param_1 + 0x50);
  if ((*(uint *)(iVar4 + 0x30) < param_3) || ((~*(uint *)(iVar4 + 0x4c) & param_3) != 0)) {
    _printf(s_dev___0x_x__bsize____d__size_____001ddc52,(int)*(short *)(param_1 + 0x46),
            *(uint *)(iVar4 + 0x30),param_3,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(s_free_block__bad_size_001ddc7e);
  }
  uVar6 = param_2 / *(int *)(iVar4 + 0xbc);
  iVar7 = _badblock(iVar4,param_2);
  if (iVar7 == 0) {
    pbVar8 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                            (~*(uint *)(iVar4 + 0x1c) & uVar6) * *(int *)(iVar4 + 0x18) +
                            uVar6 * *(int *)(iVar4 + 0xbc) + *(int *)(iVar4 + 0xc) <<
                            ((byte)*(undefined4 *)(iVar4 + 100) & 0x1f),
                            *(undefined4 *)(iVar4 + 0xa0));
    iVar7 = *(int *)(pbVar8 + 0x20);
    if ((*pbVar8 & 4) == 0) {
      _byte_swap_cylgroup(iVar7);
      if (*(int *)(iVar7 + 0x3d4) == 0x90255) {
        bVar5 = true;
      }
      else {
        _byte_swap_cylgroup(iVar7);
        _brelse(pbVar8);
        bVar5 = false;
      }
    }
    else {
      _brelse(pbVar8);
      bVar5 = false;
    }
    if (bVar5) {
      _getthetime(local_c);
      *(undefined4 *)(iVar7 + 8) = local_c[0];
      uVar11 = param_2 % *(int *)(iVar4 + 0xbc);
      if (*(uint *)(iVar4 + 0x30) == param_3) {
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,
                         (int)uVar11 >> ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f));
        if (iVar9 != 0) {
          _printf(s_dev___0x_x__block____d__fs____s_001ddca9,(int)*(short *)(param_1 + 0x46),uVar11,
                  iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
          _panic(s_free_block__freeing_free_block_001ddcca);
        }
        _setblock(iVar4,iVar7 + 0x3d8,(int)uVar11 >> ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f));
        *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
        *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
        piVar2 = (int *)(*(int *)(iVar4 + 0x2d8 +
                                 ((int)uVar6 >> ((byte)*(undefined4 *)(iVar4 + 0x70) & 0x1f)) * 4) +
                         4 + (~*(uint *)(iVar4 + 0x6c) & uVar6) * 0x10);
        *piVar2 = *piVar2 + 1;
        iVar13 = uVar11 * *(int *)(iVar4 + 0x7c);
        iVar9 = iVar13 / *(int *)(iVar4 + 0xac);
        psVar1 = (short *)(iVar7 + 0xd4 + iVar9 * 0x10 +
                          (((iVar13 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8) << 3) /
                          *(int *)(iVar4 + 0xa8)) * 2);
        *psVar1 = *psVar1 + 1;
        piVar2 = (int *)(iVar7 + 0x54 + iVar9 * 4);
        *piVar2 = *piVar2 + 1;
      }
      else {
        uVar12 = -*(int *)(iVar4 + 0x38) & uVar11;
        local_88 = uVar12;
        if ((int)uVar12 < 0) {
          local_88 = uVar12 + 7;
        }
        _fragacct(iVar4,(int)(uint)*(byte *)(((int)local_88 >> 3) + 0x3d8 + iVar7) >>
                        ((char)uVar12 + (char)((int)local_88 >> 3) * -8 & 0x1fU) &
                        0xff >> (8U - (char)*(int *)(iVar4 + 0x38) & 0x1f),iVar7 + 0x34,0xffffffff);
        param_3 = param_3 >> ((byte)*(undefined4 *)(iVar4 + 0x54) & 0x1f);
        local_24 = 0;
        if (0 < (int)param_3) {
          do {
            iVar13 = uVar11 + local_24;
            iVar9 = iVar13;
            if (iVar13 < 0) {
              iVar9 = iVar13 + 7;
            }
            iVar9 = iVar9 >> 3;
            uVar10 = iVar13 + iVar9 * -8;
            if (((uint)(int)*(char *)(iVar7 + 0x3d8 + iVar9) >> (uVar10 & 0x1f) & 1) != 0) {
              _printf(s_dev___0x_x__block____d__fs____s_001ddce9,(int)*(short *)(param_1 + 0x46),
                      iVar13,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(s_free_block__freeing_free_frag_001ddd0a);
            }
            local_84 = (byte)(1 << ((byte)uVar10 & 0x1f));
            pbVar3 = (byte *)(iVar7 + 0x3d8 + iVar9);
            *pbVar3 = *pbVar3 | local_84;
            local_24 = local_24 + 1;
          } while (local_24 < (int)param_3);
        }
        *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + local_24;
        *(int *)(iVar4 + 0xcc) = *(int *)(iVar4 + 0xcc) + local_24;
        piVar2 = (int *)(*(int *)(iVar4 + 0x2d8 +
                                 ((int)uVar6 >> ((byte)*(undefined4 *)(iVar4 + 0x70) & 0x1f)) * 4) +
                         0xc + (uVar6 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
        *piVar2 = *piVar2 + local_24;
        uVar11 = uVar12;
        if ((int)uVar12 < 0) {
          uVar11 = uVar12 + 7;
        }
        _fragacct(iVar4,(int)(uint)*(byte *)(((int)uVar11 >> 3) + 0x3d8 + iVar7) >>
                        ((char)uVar12 + (char)((int)uVar11 >> 3) * -8 & 0x1fU) &
                        0xff >> (8U - (char)*(undefined4 *)(iVar4 + 0x38) & 0x1f),iVar7 + 0x34,1);
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,
                         (int)uVar12 >> ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f));
        if (iVar9 != 0) {
          *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) - *(int *)(iVar4 + 0x38);
          *(int *)(iVar4 + 0xcc) = *(int *)(iVar4 + 0xcc) - *(int *)(iVar4 + 0x38);
          piVar2 = (int *)(*(int *)(iVar4 + 0x2d8 +
                                   ((int)uVar6 >> ((byte)*(undefined4 *)(iVar4 + 0x70) & 0x1f)) * 4)
                           + 0xc + (~*(uint *)(iVar4 + 0x6c) & uVar6) * 0x10);
          *piVar2 = *piVar2 - *(int *)(iVar4 + 0x38);
          *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
          *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
          piVar2 = (int *)(*(int *)(iVar4 + 0x2d8 +
                                   ((int)uVar6 >> ((byte)*(undefined4 *)(iVar4 + 0x70) & 0x1f)) * 4)
                           + 4 + (~*(uint *)(iVar4 + 0x6c) & uVar6) * 0x10);
          *piVar2 = *piVar2 + 1;
          iVar13 = uVar12 * *(int *)(iVar4 + 0x7c);
          iVar9 = iVar13 / *(int *)(iVar4 + 0xac);
          psVar1 = (short *)(iVar7 + 0xd4 + iVar9 * 0x10 +
                            ((((iVar13 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8)) * 8) /
                            *(int *)(iVar4 + 0xa8)) * 2);
          *psVar1 = *psVar1 + 1;
          piVar2 = (int *)(iVar7 + 0x54 + iVar9 * 4);
          *piVar2 = *piVar2 + 1;
        }
      }
      *(char *)(iVar4 + 0xd0) = *(char *)(iVar4 + 0xd0) + '\x01';
      _byte_swap_cylgroup(iVar7);
      _bdwrite(pbVar8);
      if (((*(byte *)(iVar4 + 0xd3) & 1) != 0) &&
         (*(int *)(iVar4 + 0x88) <
          (*(int *)(iVar4 + 0xc4) << ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f)) +
          *(int *)(iVar4 + 0xcc))) {
        _wakeup(iVar4 + 0xcc);
        *(byte *)(iVar4 + 0xd3) = *(byte *)(iVar4 + 0xd3) & 0xfe;
      }
    }
  }
  else {
    _printf(s_bad_block__d__ino__d_001ddc93,param_2,*(undefined4 *)(param_1 + 0x48));
  }
  return;
}

