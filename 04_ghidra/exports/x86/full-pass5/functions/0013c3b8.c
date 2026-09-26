/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c3b8 */

uint _fragextend(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_c [2];
  
  iVar3 = *(int *)(param_1 + 0x50);
  bVar8 = (byte)*(undefined4 *)(iVar3 + 0x54);
  if (param_5 - param_4 >> (bVar8 & 0x1f) <=
      *(int *)(*(int *)(iVar3 + 0x2d8 +
                       ((int)param_2 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) * 4) + 0xc +
              (~*(uint *)(iVar3 + 0x6c) & param_2) * 0x10)) {
    param_5 = param_5 >> (bVar8 & 0x1f);
    uVar10 = *(int *)(iVar3 + 0x38) - 1;
    uVar9 = param_3 & uVar10;
    if ((int)uVar9 <= (int)(param_5 + -1 + param_3 & uVar10)) {
      pbVar6 = (byte *)_bread(*(undefined4 *)(param_1 + 0x40),
                              (~*(uint *)(iVar3 + 0x1c) & param_2) * *(int *)(iVar3 + 0x18) +
                              param_2 * *(int *)(iVar3 + 0xbc) + *(int *)(iVar3 + 0xc) <<
                              ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),
                              *(undefined4 *)(iVar3 + 0xa0));
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
      if (bVar5) {
        _getthetime(local_c);
        *(undefined4 *)(iVar4 + 8) = local_c[0];
        iVar11 = (int)param_3 % *(int *)(iVar3 + 0xbc);
        for (iVar13 = param_4 >> ((byte)*(undefined4 *)(iVar3 + 0x54) & 0x1f); iVar13 < param_5;
            iVar13 = iVar13 + 1) {
          iVar12 = iVar11 + iVar13;
          iVar7 = iVar12;
          if (iVar12 < 0) {
            iVar7 = iVar12 + 7;
          }
          if (((uint)(int)*(char *)(iVar4 + 0x3d8 + (iVar7 >> 3)) >>
               (iVar12 + (iVar7 >> 3) * -8 & 0x1fU) & 1) == 0) {
            _byte_swap_cylgroup(*(undefined4 *)(pbVar6 + 0x20));
            _brelse(pbVar6);
            return 0;
          }
        }
        for (iVar13 = param_5; iVar13 < (int)(*(int *)(iVar3 + 0x38) - uVar9); iVar13 = iVar13 + 1)
        {
          iVar12 = iVar11 + iVar13;
          iVar7 = iVar12;
          if (iVar12 < 0) {
            iVar7 = iVar12 + 7;
          }
          if (((uint)(int)*(char *)(iVar4 + 0x3d8 + (iVar7 >> 3)) >>
               (iVar12 + (iVar7 >> 3) * -8 & 0x1fU) & 1) == 0) break;
        }
        piVar1 = (int *)(iVar4 + 0x34 +
                        (iVar13 - (param_4 >> ((byte)*(undefined4 *)(iVar3 + 0x54) & 0x1f))) * 4);
        *piVar1 = *piVar1 + -1;
        if (param_5 != iVar13) {
          piVar1 = (int *)(iVar4 + 0x34 + (iVar13 - param_5) * 4);
          *piVar1 = *piVar1 + 1;
        }
        for (param_4 = param_4 >> ((byte)*(undefined4 *)(iVar3 + 0x54) & 0x1f); param_4 < param_5;
            param_4 = param_4 + 1) {
          iVar7 = iVar11 + param_4;
          iVar13 = iVar7;
          if (iVar7 < 0) {
            iVar13 = iVar7 + 7;
          }
          bVar8 = (char)iVar7 + (char)(iVar13 >> 3) * -8 & 0x1f;
          pbVar2 = (byte *)(iVar4 + 0x3d8 + (iVar13 >> 3));
          *pbVar2 = *pbVar2 & ((byte)(-2 << bVar8) | (byte)(0xfffffffe >> 0x20 - bVar8));
          *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + -1;
          *(int *)(iVar3 + 0xcc) = *(int *)(iVar3 + 0xcc) + -1;
          piVar1 = (int *)(*(int *)(iVar3 + 0x2d8 +
                                   ((int)param_2 >> ((byte)*(undefined4 *)(iVar3 + 0x70) & 0x1f)) *
                                   4) + 0xc + (~*(uint *)(iVar3 + 0x6c) & param_2) * 0x10);
          *piVar1 = *piVar1 + -1;
        }
        *(char *)(iVar3 + 0xd0) = *(char *)(iVar3 + 0xd0) + '\x01';
        _byte_swap_cylgroup(*(undefined4 *)(pbVar6 + 0x20));
        _bdwrite(pbVar6);
        return param_3;
      }
    }
  }
  return 0;
}

