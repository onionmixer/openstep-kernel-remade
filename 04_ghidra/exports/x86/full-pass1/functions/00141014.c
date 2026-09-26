/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141014 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int _itrunc(undefined4 *param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  ushort local_120;
  int local_118;
  int local_fc;
  undefined4 local_f8 [27];
  uint local_8c;
  int aiStack_6c [12];
  int aiStack_3c [11];
  int local_10 [3];
  
  local_fc = 0;
  local_118 = 0;
  uVar1 = *(ushort *)(param_1 + 0x11);
  *(ushort *)(param_1 + 0x11) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x11) = uVar1 & 0xffee;
    _wakeup(param_1);
  }
  iVar5 = _mfs_trunc(param_1 + 3,param_2);
  while ((*(ushort *)(param_1 + 0x11) & 1) != 0) {
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 0x10;
    _sleep((uint)param_1);
  }
  *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 1;
  if (((*(ushort *)(param_1 + 0x19) & 0xf000) == 0xa000) && ((*(byte *)(param_1 + 0x32) & 1) != 0))
  {
    iVar5 = 0xe;
    do {
      param_1[iVar5 + 0x23] = 0;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
    param_1[0x32] = 0;
    param_1[0x1b] = 0;
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 0x42;
    iVar5 = param_1[0x14];
    if (*(char *)(iVar5 + 0xd2) != '\0') {
      return 0;
    }
    uVar6 = (uint)param_1[0x12] / *(uint *)(iVar5 + 0xb8);
    pbVar7 = (byte *)_bread(param_1[0x10],
                            *(int *)(iVar5 + 0xbc) * uVar6 +
                            (uVar6 & ~*(uint *)(iVar5 + 0x1c)) * *(int *)(iVar5 + 0x18) +
                            *(int *)(iVar5 + 0x10) +
                            ((int)(((ulonglong)(uint)param_1[0x12] %
                                   (ulonglong)*(uint *)(iVar5 + 0xb8)) /
                                  (ulonglong)*(uint *)(iVar5 + 0x78)) <<
                            ((byte)*(undefined4 *)(iVar5 + 0x60) & 0x1f)) <<
                            ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f),
                            *(undefined4 *)(iVar5 + 0x30));
    bVar14 = *pbVar7;
  }
  else {
    if (param_2 != param_1[0x1b]) {
      iVar2 = param_1[0x14];
      uVar6 = ~*(uint *)(iVar2 + 0x48) & param_2;
      bVar14 = (byte)*(undefined4 *)(iVar2 + 0x50);
      uVar15 = param_2 - 1 >> (bVar14 & 0x1f);
      if ((uint)param_1[0x1b] < param_2) {
        if (uVar6 == 0) {
          uVar6 = *(uint *)(iVar2 + 0x30);
        }
        iVar5 = _bmap(param_1,uVar15,0,uVar6,&local_fc);
        if ((*(char *)(DAT_001e875c + 0x68) == '\0') || (-1 < iVar5)) {
          param_1[0x1b] = param_2;
          uVar1 = *(ushort *)(param_1 + 0x11);
          *(ushort *)(param_1 + 0x11) = uVar1 | 0x40;
          *(ushort *)(param_1 + 0x11) = uVar1 | 0x48;
          _microtime(&_iuniqtime);
          if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
            param_1[0x1d] = _iuniqtime;
          }
          if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
            param_1[0x1f] = _iuniqtime;
          }
          if ((*(byte *)(param_1 + 0x11) & 0x40) != 0) {
            param_1[0x13] = 0;
            param_1[0x21] = _iuniqtime;
          }
          *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) & 0xb9;
        }
        if (((local_fc != 0) && (iVar5 = param_1[0x14], (*(byte *)(param_1 + 0x11) & 0x4e) != 0)) &&
           (*(char *)(iVar5 + 0xd2) == '\0')) {
          uVar6 = (uint)param_1[0x12] / *(uint *)(iVar5 + 0xb8);
          pbVar7 = (byte *)_bread(param_1[0x10],
                                  *(int *)(iVar5 + 0xbc) * uVar6 +
                                  (uVar6 & ~*(uint *)(iVar5 + 0x1c)) * *(int *)(iVar5 + 0x18) +
                                  *(int *)(iVar5 + 0x10) +
                                  ((int)(((ulonglong)(uint)param_1[0x12] %
                                         (ulonglong)*(uint *)(iVar5 + 0xb8)) /
                                        (ulonglong)*(uint *)(iVar5 + 0x78)) <<
                                  ((byte)*(undefined4 *)(iVar5 + 0x60) & 0x1f)) <<
                                  ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f),
                                  *(undefined4 *)(iVar5 + 0x30));
          if ((*pbVar7 & 4) == 0) {
            if ((*(byte *)(param_1 + 0x11) & 0x46) != 0) {
              _microtime(&_iuniqtime);
              if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
                param_1[0x1d] = _iuniqtime;
              }
              if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
                param_1[0x1f] = _iuniqtime;
              }
              if ((*(byte *)(param_1 + 0x11) & 0x40) != 0) {
                param_1[0x13] = 0;
                param_1[0x21] = _iuniqtime;
              }
            }
            uVar1 = *(ushort *)(param_1 + 0x11);
            *(ushort *)(param_1 + 0x11) = uVar1 & 0xffb1;
            iVar5 = ((uint)param_1[0x12] % *(uint *)(iVar5 + 0x78)) * 0x80 + *(int *)(pbVar7 + 0x20)
            ;
            *(ushort *)(param_1 + 0x11) = uVar1 & 0xfdb1;
            _byte_swap_inode_out(param_1,iVar5);
            if (*(short *)(param_1[0xc] + 0x124) != 0) {
              local_120 = (ushort)(byte)(*(short *)(param_1 + 0x39) >> 0xf) |
                          (short)(char)((ushort)*(short *)(param_1 + 0x39) >> 8) & 0xff00U;
              *(ushort *)(iVar5 + 4) = local_120;
              local_120 = (ushort)(byte)(*(short *)((int)param_1 + 0xe6) >> 0xf) |
                          (short)(char)((ushort)*(short *)((int)param_1 + 0xe6) >> 8) & 0xff00U;
              *(ushort *)(iVar5 + 6) = local_120;
            }
            _bwrite(pbVar7);
          }
          else {
            _brelse(pbVar7);
          }
        }
        return (int)*(char *)(DAT_001e875c + 0x68);
      }
      uVar8 = (param_2 + *(int *)(iVar2 + 0x30)) - 1 >> (bVar14 & 0x1f);
      iVar9 = uVar8 - 1;
      local_10[0] = uVar8 - 0xd;
      local_10[1] = local_10[0] - *(int *)(iVar2 + 0x74);
      local_10[2] = local_10[1] - *(int *)(iVar2 + 0x74) * *(int *)(iVar2 + 0x74);
      iVar10 = (**(code **)(param_1[10] + 0x80))(param_1 + 3);
      iVar3 = *(int *)(iVar2 + 0x30);
      uVar13 = param_1[0x1b];
      if (uVar6 == 0) {
        param_1[0x1b] = param_2;
      }
      else {
        iVar11 = _bmap(param_1,uVar15,0,uVar6,0);
        iVar11 = iVar11 << ((byte)*(undefined4 *)(iVar2 + 100) & 0x1f);
        if ((*(char *)(DAT_001e875c + 0x68) != '\0') || (iVar11 < 0)) {
          return (int)*(char *)(DAT_001e875c + 0x68);
        }
        param_1[0x1b] = param_2;
        if (((int)uVar15 < 0xc) &&
           (param_2 < uVar15 + 1 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f))) {
          uVar15 = ((~*(uint *)(iVar2 + 0x48) & param_2) + *(int *)(iVar2 + 0x34)) - 1 &
                   *(uint *)(iVar2 + 0x4c);
        }
        else {
          uVar15 = *(uint *)(iVar2 + 0x30);
        }
        uVar4 = param_1[0x10];
        if (*(int *)param_1[3] != 0) {
          _vnode_uncache(param_1 + 3);
        }
        if (iVar5 == 0) {
          pbVar7 = (byte *)_bread(uVar4,iVar11,uVar15);
          if ((*pbVar7 & 4) != 0) {
            *(undefined1 *)(DAT_001e875c + 0x68) = 5;
            param_1[0x1b] = uVar13;
            _brelse(pbVar7);
            return 5;
          }
          _bzero((void *)(uVar6 + *(int *)(pbVar7 + 0x20)),uVar15 - uVar6);
          _bdwrite(pbVar7);
        }
      }
      puVar16 = param_1;
      puVar17 = local_f8;
      for (iVar5 = 0x3a; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar17 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar17 = puVar17 + 1;
      }
      local_8c = uVar13;
      iVar5 = 2;
      do {
        if (local_10[iVar5] < 0) {
          param_1[iVar5 + 0x2f] = 0;
          local_10[iVar5] = -1;
        }
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
      iVar5 = 0xb;
      if (iVar9 < 0xb) {
        do {
          param_1[iVar5 + 0x23] = 0;
          iVar5 = iVar5 + -1;
        } while (iVar9 < iVar5);
      }
      param_1[0x1b] = param_2;
      *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 0x42;
      iVar5 = param_1[0x14];
      if (*(char *)(iVar5 + 0xd2) == '\0') {
        uVar6 = (uint)param_1[0x12] / *(uint *)(iVar5 + 0xb8);
        pbVar7 = (byte *)_bread(param_1[0x10],
                                *(int *)(iVar5 + 0xbc) * uVar6 +
                                (uVar6 & ~*(uint *)(iVar5 + 0x1c)) * *(int *)(iVar5 + 0x18) +
                                *(int *)(iVar5 + 0x10) +
                                ((int)(((ulonglong)(uint)param_1[0x12] %
                                       (ulonglong)*(uint *)(iVar5 + 0xb8)) /
                                      (ulonglong)*(uint *)(iVar5 + 0x78)) <<
                                ((byte)*(undefined4 *)(iVar5 + 0x60) & 0x1f)) <<
                                ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f),
                                *(undefined4 *)(iVar5 + 0x30));
        if ((*pbVar7 & 4) == 0) {
          if ((*(byte *)(param_1 + 0x11) & 0x46) != 0) {
            _microtime(&_iuniqtime);
            if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
              param_1[0x1d] = _iuniqtime;
            }
            if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
              param_1[0x1f] = _iuniqtime;
            }
            if ((*(byte *)(param_1 + 0x11) & 0x40) != 0) {
              param_1[0x13] = 0;
              param_1[0x21] = _iuniqtime;
            }
          }
          uVar1 = *(ushort *)(param_1 + 0x11);
          *(ushort *)(param_1 + 0x11) = uVar1 & 0xffb1;
          iVar5 = ((uint)param_1[0x12] % *(uint *)(iVar5 + 0x78)) * 0x80 + *(int *)(pbVar7 + 0x20);
          *(ushort *)(param_1 + 0x11) = uVar1 & 0xfdb1;
          _byte_swap_inode_out(param_1,iVar5);
          if (*(short *)(param_1[0xc] + 0x124) != 0) {
            local_120 = (ushort)(byte)(*(short *)(param_1 + 0x39) >> 0xf) |
                        (short)(char)((ushort)*(short *)(param_1 + 0x39) >> 8) & 0xff00U;
            *(ushort *)(iVar5 + 4) = local_120;
            local_120 = (ushort)(byte)(*(short *)((int)param_1 + 0xe6) >> 0xf) |
                        (short)(char)((ushort)*(short *)((int)param_1 + 0xe6) >> 8) & 0xff00U;
            *(ushort *)(iVar5 + 6) = local_120;
          }
          _bwrite(pbVar7);
        }
        else {
          _brelse(pbVar7);
        }
      }
      iVar5 = 2;
      do {
        iVar11 = aiStack_3c[iVar5];
        if (iVar11 != 0) {
          iVar12 = _indirtrunc(local_f8,iVar11,local_10[iVar5],iVar5);
          local_118 = local_118 + iVar12;
          if (local_10[iVar5] < 0) {
            aiStack_3c[iVar5] = 0;
            _free_block(local_f8,iVar11,*(undefined4 *)(iVar2 + 0x30));
            local_118 = local_118 + iVar3 / iVar10;
          }
        }
        if (-1 < local_10[iVar5]) goto LAB_00141c13;
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
      iVar5 = 0xb;
      if (iVar9 < 0xb) {
        do {
          iVar3 = aiStack_6c[iVar5];
          if (iVar3 != 0) {
            aiStack_6c[iVar5] = 0;
            if ((iVar5 < 0xc) &&
               (local_8c < (uint)(iVar5 + 1 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f)))) {
              uVar6 = ((local_8c & ~*(uint *)(iVar2 + 0x48)) + *(int *)(iVar2 + 0x34)) - 1 &
                      *(uint *)(iVar2 + 0x4c);
            }
            else {
              uVar6 = *(uint *)(iVar2 + 0x30);
            }
            _free_block(local_f8,iVar3,uVar6);
            uVar15 = (**(code **)(param_1[10] + 0x80))(param_1 + 3);
            local_118 = local_118 + uVar6 / uVar15;
          }
          iVar5 = iVar5 + -1;
        } while (iVar9 < iVar5);
      }
      if ((-1 < iVar9) && (aiStack_6c[iVar9] != 0)) {
        if ((iVar9 < 0xc) && (local_8c < uVar8 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f))) {
          uVar6 = ((local_8c & ~*(uint *)(iVar2 + 0x48)) + *(int *)(iVar2 + 0x34)) - 1 &
                  *(uint *)(iVar2 + 0x4c);
        }
        else {
          uVar6 = *(uint *)(iVar2 + 0x30);
        }
        local_8c = param_2;
        if ((iVar9 < 0xc) && (param_2 < uVar8 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f))) {
          uVar15 = ((~*(uint *)(iVar2 + 0x48) & param_2) + *(int *)(iVar2 + 0x34)) - 1 &
                   *(uint *)(iVar2 + 0x4c);
        }
        else {
          uVar15 = *(uint *)(iVar2 + 0x30);
        }
        if (uVar15 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_itrunc__newspace_001de033);
        }
        if (uVar6 != uVar15) {
          _free_block(local_f8,aiStack_6c[iVar9] +
                               (uVar15 >> ((byte)*(undefined4 *)(iVar2 + 0x54) & 0x1f)),
                      uVar6 - uVar15);
          uVar13 = (**(code **)(param_1[10] + 0x80))(param_1 + 3);
          local_118 = local_118 + (uVar6 - uVar15) / uVar13;
        }
      }
LAB_00141c13:
      iVar5 = 0;
      do {
        if (aiStack_3c[iVar5] != param_1[iVar5 + 0x2f]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_itrunc1_001de044);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
      iVar5 = 0;
      do {
        if (aiStack_6c[iVar5] != param_1[iVar5 + 0x23]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_itrunc2_001de04c);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0xc);
      iVar5 = param_1[0x33];
      param_1[0x33] = iVar5 - local_118;
      if (iVar5 - local_118 < 0) {
        param_1[0x33] = 0;
      }
      *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 0x40;
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 0x42;
    iVar5 = param_1[0x14];
    if (*(char *)(iVar5 + 0xd2) != '\0') {
      return 0;
    }
    uVar6 = (uint)param_1[0x12] / *(uint *)(iVar5 + 0xb8);
    pbVar7 = (byte *)_bread(param_1[0x10],
                            *(int *)(iVar5 + 0xbc) * uVar6 +
                            (uVar6 & ~*(uint *)(iVar5 + 0x1c)) * *(int *)(iVar5 + 0x18) +
                            *(int *)(iVar5 + 0x10) +
                            ((int)(((ulonglong)(uint)param_1[0x12] %
                                   (ulonglong)*(uint *)(iVar5 + 0xb8)) /
                                  (ulonglong)*(uint *)(iVar5 + 0x78)) <<
                            ((byte)*(undefined4 *)(iVar5 + 0x60) & 0x1f)) <<
                            ((byte)*(undefined4 *)(iVar5 + 100) & 0x1f),
                            *(undefined4 *)(iVar5 + 0x30));
    bVar14 = *pbVar7;
  }
  if ((bVar14 & 4) == 0) {
    if ((*(byte *)(param_1 + 0x11) & 0x46) != 0) {
      _microtime(&_iuniqtime);
      if ((*(byte *)(param_1 + 0x11) & 4) != 0) {
        param_1[0x1d] = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
        param_1[0x1f] = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x11) & 0x40) != 0) {
        param_1[0x13] = 0;
        param_1[0x21] = _iuniqtime;
      }
    }
    uVar1 = *(ushort *)(param_1 + 0x11);
    *(ushort *)(param_1 + 0x11) = uVar1 & 0xffb1;
    iVar5 = ((uint)param_1[0x12] % *(uint *)(iVar5 + 0x78)) * 0x80 + *(int *)(pbVar7 + 0x20);
    *(ushort *)(param_1 + 0x11) = uVar1 & 0xfdb1;
    _byte_swap_inode_out(param_1,iVar5);
    if (*(short *)(param_1[0xc] + 0x124) != 0) {
      local_120 = (ushort)(byte)(*(short *)(param_1 + 0x39) >> 0xf) |
                  (short)(char)((ushort)*(short *)(param_1 + 0x39) >> 8) & 0xff00U;
      *(ushort *)(iVar5 + 4) = local_120;
      local_120 = (ushort)(byte)(*(short *)((int)param_1 + 0xe6) >> 0xf) |
                  (short)(char)((ushort)*(short *)((int)param_1 + 0xe6) >> 8) & 0xff00U;
      *(ushort *)(iVar5 + 6) = local_120;
    }
    _bwrite(pbVar7);
  }
  else {
    _brelse(pbVar7);
  }
  return 0;
}

