/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c640 */

int _alloccg(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  bool bVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_24;
  byte local_20;
  undefined4 local_c [2];
  
  iVar7 = *(int *)(param_1 + 0x50);
  if ((*(int *)(*(int *)(iVar7 + 0x2d8 +
                        ((int)param_2 >> ((byte)*(undefined4 *)(iVar7 + 0x70) & 0x1f)) * 4) + 4 +
               (~*(uint *)(iVar7 + 0x6c) & param_2) * 0x10) != 0) ||
     (*(int *)(iVar7 + 0x30) != param_4)) {
    pbVar6 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                            (~*(uint *)(iVar7 + 0x1c) & param_2) * *(int *)(iVar7 + 0x18) +
                            param_2 * *(int *)(iVar7 + 0xbc) + *(int *)(iVar7 + 0xc) <<
                            ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),
                            *(undefined4 *)(iVar7 + 0xa0));
    iVar3 = *(int *)(pbVar6 + 0x20);
    if ((*pbVar6 & 4) == 0) {
      _byte_swap_cylgroup(iVar3);
      if (*(int *)(iVar3 + 0x3d4) == 0x90255) {
        bVar5 = true;
      }
      else {
        _byte_swap_cylgroup(iVar3);
        _brelse(pbVar6);
        bVar5 = false;
      }
    }
    else {
      _brelse(pbVar6);
      bVar5 = false;
    }
    if (bVar5) {
      if ((*(int *)(iVar3 + 0x1c) == 0) && (*(int *)(iVar7 + 0x30) == param_4)) {
        _byte_swap_cylgroup(iVar3);
        _brelse(pbVar6);
        return 0;
      }
      _getthetime(local_c);
      *(undefined4 *)(iVar3 + 8) = local_c[0];
      if (*(int *)(iVar7 + 0x30) == param_4) {
        iVar7 = _alloccgblk(iVar7,iVar3,param_3);
        _byte_swap_cylgroup(iVar3);
        _bdwrite(pbVar6);
        return iVar7;
      }
      param_4 = param_4 >> ((byte)*(undefined4 *)(iVar7 + 0x54) & 0x1f);
      for (iVar11 = param_4;
          (iVar11 < *(int *)(iVar7 + 0x38) && (*(int *)(iVar3 + 0x34 + iVar11 * 4) == 0));
          iVar11 = iVar11 + 1) {
      }
      if (*(int *)(iVar7 + 0x38) == iVar11) {
        if (*(int *)(iVar3 + 0x1c) == 0) {
          _byte_swap_cylgroup(iVar3);
          _brelse(pbVar6);
          return 0;
        }
        iVar8 = _alloccgblk(iVar7,iVar3,param_3);
        iVar11 = *(int *)(iVar7 + 0xbc);
        local_24 = param_4;
        if (param_4 < *(int *)(iVar7 + 0x38)) {
          do {
            iVar10 = iVar8 % iVar11 + local_24;
            iVar9 = iVar10;
            if (iVar10 < 0) {
              iVar9 = iVar10 + 7;
            }
            local_20 = (byte)(1 << ((char)iVar10 + (char)(iVar9 >> 3) * -8 & 0x1fU));
            pbVar2 = (byte *)(iVar3 + 0x3d8 + (iVar9 >> 3));
            *pbVar2 = *pbVar2 | local_20;
            local_24 = local_24 + 1;
          } while (local_24 < *(int *)(iVar7 + 0x38));
        }
        param_4 = *(int *)(iVar7 + 0x38) - param_4;
        *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + param_4;
        *(int *)(iVar7 + 0xcc) = *(int *)(iVar7 + 0xcc) + param_4;
        piVar1 = (int *)(*(int *)(iVar7 + 0x2d8 +
                                 ((int)param_2 >> ((byte)*(undefined4 *)(iVar7 + 0x70) & 0x1f)) * 4)
                         + 0xc + (~*(uint *)(iVar7 + 0x6c) & param_2) * 0x10);
        *piVar1 = *piVar1 + param_4;
        *(char *)(iVar7 + 0xd0) = *(char *)(iVar7 + 0xd0) + '\x01';
        piVar1 = (int *)(iVar3 + 0x34 + param_4 * 4);
        *piVar1 = *piVar1 + 1;
        _byte_swap_cylgroup(iVar3);
        _bdwrite(pbVar6);
        return iVar8;
      }
      iVar8 = _mapsearch(iVar7,iVar3,param_3,iVar11);
      if (iVar8 < 0) {
        _byte_swap_cylgroup(iVar3);
        _brelse(pbVar6);
        return 0;
      }
      local_24 = 0;
      if (0 < param_4) {
        do {
          iVar10 = iVar8 + local_24;
          iVar9 = iVar10;
          if (iVar10 < 0) {
            iVar9 = iVar10 + 7;
          }
          bVar4 = (char)iVar10 + (char)(iVar9 >> 3) * -8 & 0x1f;
          pbVar2 = (byte *)(iVar3 + 0x3d8 + (iVar9 >> 3));
          *pbVar2 = *pbVar2 & ((byte)(-2 << bVar4) | (byte)(0xfffffffe >> 0x20 - bVar4));
          local_24 = local_24 + 1;
        } while (local_24 < param_4);
      }
      *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) - param_4;
      *(int *)(iVar7 + 0xcc) = *(int *)(iVar7 + 0xcc) - param_4;
      piVar1 = (int *)(*(int *)(iVar7 + 0x2d8 +
                               ((int)param_2 >> ((byte)*(undefined4 *)(iVar7 + 0x70) & 0x1f)) * 4) +
                       0xc + (~*(uint *)(iVar7 + 0x6c) & param_2) * 0x10);
      *piVar1 = *piVar1 - param_4;
      *(char *)(iVar7 + 0xd0) = *(char *)(iVar7 + 0xd0) + '\x01';
      piVar1 = (int *)(iVar3 + 0x34 + iVar11 * 4);
      *piVar1 = *piVar1 + -1;
      if (param_4 != iVar11) {
        piVar1 = (int *)(iVar3 + 0x34 + (iVar11 - param_4) * 4);
        *piVar1 = *piVar1 + 1;
      }
      _byte_swap_cylgroup(iVar3);
      _bdwrite(pbVar6);
      return param_2 * *(int *)(iVar7 + 0xbc) + iVar8;
    }
  }
  return 0;
}

