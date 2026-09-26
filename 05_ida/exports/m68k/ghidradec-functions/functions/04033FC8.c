
uint _fragextend(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if (param_5 - param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f) <=
      *(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) +
               0xc + (~*(uint *)(iVar2 + 0x6c) & param_2) * 0x10)) {
    param_5 = param_5 >> (*(uint *)(iVar2 + 0x54) & 0x3f);
    uVar6 = *(int *)(iVar2 + 0x38) - 1;
    uVar5 = uVar6 & param_3;
    if ((int)uVar5 <= (int)(uVar6 & (param_3 - 1) + param_5)) {
      iVar8 = _bread(*(undefined4 *)(param_1 + 0x3e),
                     *(int *)(iVar2 + 0xc) +
                     *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
                     param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f),
                     *(undefined4 *)(iVar2 + 0xa0));
      iVar3 = *(int *)(iVar8 + 0x20);
      if (((*(byte *)(iVar8 + 3) & 4) == 0) && (*(int *)(iVar3 + 0x3d4) == 0x90255)) {
        _getthetime(auStack_c);
        *(undefined4 *)(iVar3 + 8) = auStack_c[0];
        iVar10 = (int)param_3 % *(int *)(iVar2 + 0xbc);
        for (iVar7 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f); iVar7 < param_5; iVar7 = iVar7 + 1
            ) {
          iVar11 = iVar7 + iVar10;
          iVar9 = iVar11;
          if (iVar11 < 0) {
            iVar9 = iVar11 + 7;
          }
          if (((int)*(char *)(iVar3 + (iVar9 >> 3) + 0x3d8) &
              1 << (iVar11 + (iVar9 >> 3) * -8 & 0x1fU)) == 0) goto loc_403407C;
        }
        for (iVar7 = param_5; iVar7 < (int)(*(int *)(iVar2 + 0x38) - uVar5); iVar7 = iVar7 + 1) {
          iVar11 = iVar7 + iVar10;
          iVar9 = iVar11;
          if (iVar11 < 0) {
            iVar9 = iVar11 + 7;
          }
          if (((int)*(char *)(iVar3 + (iVar9 >> 3) + 0x3d8) &
              1 << (iVar11 + (iVar9 >> 3) * -8 & 0x1fU)) == 0) break;
        }
        piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - (param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f))) * 4)
        ;
        *piVar1 = *piVar1 + -1;
        if (param_5 != iVar7) {
          piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - param_5) * 4);
          *piVar1 = *piVar1 + 1;
        }
        for (param_4 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f); param_4 < param_5;
            param_4 = param_4 + 1) {
          iVar7 = param_4 + iVar10;
          iVar9 = iVar7;
          if (iVar7 < 0) {
            iVar9 = iVar7 + 7;
          }
          pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
          *pbVar4 = ~(byte)(1 << (iVar7 + (iVar9 >> 3) * -8 & 0x3fU)) & *pbVar4;
          *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + -1;
          *(int *)(iVar2 + 0xcc) = *(int *)(iVar2 + 0xcc) + -1;
          piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 + -1;
        }
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        _bdwrite(iVar8);
        return param_3;
      }
loc_403407C:
      _brelse(iVar8);
    }
  }
  return 0;
}
