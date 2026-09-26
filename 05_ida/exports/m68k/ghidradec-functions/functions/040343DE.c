
int _alloccgblk(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  sword *psVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  sword *psVar12;
  
  if (param_3 == 0) {
    iVar7 = *(int *)(param_2 + 0x28);
  }
  else {
    iVar7 = (int)(-*(int *)(param_1 + 0x38) & param_3) % *(int *)(param_1 + 0xbc);
    iVar8 = _isblock(param_1,param_2 + 0x3d8,iVar7 >> (*(uint *)(param_1 + 0x60) & 0x3f));
    if (iVar8 != 0) goto loc_40345A8;
    iVar8 = *(int *)(param_1 + 0x7c);
    iVar11 = *(int *)(param_1 + 0xac);
    iVar10 = (iVar8 * iVar7) / iVar11;
    if (*(int *)(param_2 + 0x54 + iVar10 * 4) != 0) {
      if (*(int *)(param_1 + 0x358) == 0) {
        iVar7 = (iVar10 * iVar11 + -1 + iVar8) / iVar8;
      }
      else {
        psVar2 = (sword *)(param_2 + iVar10 * 0x10 + 0xd4);
        iVar11 = (((iVar8 * iVar7) % iVar11) % *(int *)(param_1 + 0xa8) << 3) /
                 *(int *)(param_1 + 0xa8);
        iVar8 = iVar11;
        if (iVar11 < 8) {
          psVar12 = psVar2 + iVar11;
          do {
            if (0 < *psVar12) break;
            psVar12 = psVar12 + 1;
            iVar8 = iVar8 + 1;
          } while (iVar8 < 8);
        }
        if ((iVar8 == 8) && (iVar8 = 0, psVar12 = psVar2, 0 < iVar11)) {
          do {
            if (0 < *psVar12) goto loc_40344C4;
            iVar8 = iVar8 + 1;
            psVar12 = psVar12 + 1;
          } while (iVar8 < iVar11);
        }
        if (0 < psVar2[iVar8]) {
loc_40344C4:
          iVar9 = iVar10 % *(int *)(param_1 + 0x358);
          iVar5 = *(int *)(param_1 + 0xac);
          iVar11 = *(int *)(param_1 + 0x7c);
          uVar3 = *(uint *)(param_1 + 0x60);
          iVar7 = param_1 + iVar9 * 0x10 + 0x35c;
          if (*(sword *)(iVar7 + iVar8 * 2) == -1) {
            _printf(aPosDIDFsS,iVar9,iVar8,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
            _panic(aAlloccgblkCylG);
          }
          iVar8 = (int)*(sword *)(iVar7 + iVar8 * 2);
          while( true ) {
            iVar7 = iVar8 + (iVar5 * (iVar10 - iVar9)) / (iVar11 << (uVar3 & 0x3f));
            iVar6 = _isblock(param_1,param_2 + 0x3d8,iVar7);
            if (iVar6 != 0) break;
            bVar4 = *(byte *)(param_1 + iVar8 + 0x560);
            if ((bVar4 == 0) || (0x1a9eU - iVar8 < (uint)bVar4)) {
              _printf(aPosDIDFsS,iVar9,iVar8,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(aAlloccgblkCanT);
            }
            iVar8 = (uint)bVar4 + iVar8;
          }
          iVar7 = iVar7 << (*(uint *)(param_1 + 0x60) & 0x3f);
          goto loc_40345A8;
        }
      }
    }
  }
  iVar7 = _mapsearch(param_1,param_2,iVar7,*(undefined4 *)(param_1 + 0x38));
  if (iVar7 < 0) {
    return 0;
  }
  *(int *)(param_2 + 0x28) = iVar7;
loc_40345A8:
  _clrblock(param_1,param_2 + 0x3d8,iVar7 >> (*(uint *)(param_1 + 0x60) & 0x3f));
  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
  piVar1 = (int *)(*(int *)(param_1 + ((int)*(uint *)(param_2 + 0xc) >>
                                      (*(uint *)(param_1 + 0x70) & 0x3f)) * 4 + 0x2d8) + 4 +
                  (~*(uint *)(param_1 + 0x6c) & *(uint *)(param_2 + 0xc)) * 0x10);
  *piVar1 = *piVar1 + -1;
  iVar8 = *(int *)(param_1 + 0x7c) * iVar7;
  iVar11 = iVar8 / *(int *)(param_1 + 0xac);
  psVar2 = (sword *)(param_2 + iVar11 * 0x10 + 0xd4 +
                    (((iVar8 % *(int *)(param_1 + 0xac)) % *(int *)(param_1 + 0xa8) << 3) /
                    *(int *)(param_1 + 0xa8)) * 2);
  *psVar2 = *psVar2 + -1;
  piVar1 = (int *)(param_2 + 0x54 + iVar11 * 4);
  *piVar1 = *piVar1 + -1;
  *(char *)(param_1 + 0xd0) = *(char *)(param_1 + 0xd0) + '\x01';
  return iVar7 + *(int *)(param_1 + 0xbc) * *(int *)(param_2 + 0xc);
}
