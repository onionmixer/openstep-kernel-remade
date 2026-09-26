
void _free_block(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  sword *psVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 auStack_c [2];
  
  iVar4 = *(int *)(param_1 + 0x4e);
  if ((*(uint *)(iVar4 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar4 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x44),*(uint *)(iVar4 + 0x30),param_3,
            iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aFreeBlockBadSi);
  }
  uVar14 = param_2 / *(int *)(iVar4 + 0xbc);
  iVar7 = _badblock(iVar4,param_2);
  if (iVar7 == 0) {
    iVar8 = _bread(*(undefined4 *)(param_1 + 0x3e),
                   *(int *)(iVar4 + 0xc) +
                   *(int *)(iVar4 + 0x18) * (uVar14 & ~*(uint *)(iVar4 + 0x1c)) +
                   *(int *)(iVar4 + 0xbc) * uVar14 << (*(uint *)(iVar4 + 100) & 0x3f),
                   *(undefined4 *)(iVar4 + 0xa0));
    iVar7 = *(int *)(iVar8 + 0x20);
    if (((*(byte *)(iVar8 + 3) & 4) == 0) && (*(int *)(iVar7 + 0x3d4) == 0x90255)) {
      _getthetime(auStack_c);
      *(undefined4 *)(iVar7 + 8) = auStack_c[0];
      uVar13 = param_2 % *(int *)(iVar4 + 0xbc);
      if (param_3 == *(uint *)(iVar4 + 0x30)) {
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,(int)uVar13 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        if (iVar9 != 0) {
          _printf(aDev0xXBlockDFs,(int)*(sword *)(param_1 + 0x44),uVar13,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
          _panic(aFreeBlockFreei);
        }
        _setblock(iVar4,iVar7 + 0x3d8,(int)uVar13 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
        *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
        piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 4 + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
        *piVar1 = *piVar1 + 1;
        iVar9 = *(int *)(iVar4 + 0x7c) * uVar13;
        iVar12 = iVar9 / *(int *)(iVar4 + 0xac);
        psVar2 = (sword *)(iVar7 + iVar12 * 0x10 + 0xd4 +
                          (((iVar9 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8) << 3) /
                          *(int *)(iVar4 + 0xa8)) * 2);
        *psVar2 = *psVar2 + 1;
        piVar1 = (int *)(iVar7 + 0x54 + iVar12 * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        uVar6 = uVar13 & -*(int *)(iVar4 + 0x38);
        uVar10 = uVar6;
        if ((int)uVar6 < 0) {
          uVar10 = uVar6 + 7;
        }
        _fragacct(iVar4,0xff >> (8U - *(int *)(iVar4 + 0x38) & 0x3f) &
                        (int)(uint)*(byte *)(iVar7 + ((int)uVar10 >> 3) + 0x3d8) >>
                        (uVar6 + ((int)uVar10 >> 3) * -8 & 0x3f),iVar7 + 0x34,0xffffffff);
        param_3 = param_3 >> (*(uint *)(iVar4 + 0x54) & 0x3f);
        iVar9 = 0;
        if (0 < (int)param_3) {
          do {
            iVar12 = iVar9 + uVar13;
            iVar11 = iVar12;
            if (iVar12 < 0) {
              iVar11 = iVar12 + 7;
            }
            iVar3 = iVar7 + (iVar11 >> 3);
            uVar10 = iVar12 + (iVar11 >> 3) * -8;
            if (((int)*(char *)(iVar3 + 0x3d8) & 1 << (uVar10 & 0x1f)) != 0) {
              _printf(aDev0xXBlockDFs,(int)*(sword *)(param_1 + 0x44),iVar12,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(aFreeBlockFreei_0);
            }
            pbVar5 = (byte *)(iVar3 + 0x3d8);
            *pbVar5 = *pbVar5 | '\x01' << (uVar10 & 7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)param_3);
        }
        *(int *)(iVar7 + 0x24) = iVar9 + *(int *)(iVar7 + 0x24);
        *(int *)(iVar4 + 0xcc) = iVar9 + *(int *)(iVar4 + 0xcc);
        piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
        *piVar1 = iVar9 + *piVar1;
        uVar13 = uVar6;
        if ((int)uVar6 < 0) {
          uVar13 = uVar6 + 7;
        }
        _fragacct(iVar4,0xff >> (8U - *(int *)(iVar4 + 0x38) & 0x3f) &
                        (int)(uint)*(byte *)(iVar7 + ((int)uVar13 >> 3) + 0x3d8) >>
                        (uVar6 + ((int)uVar13 >> 3) * -8 & 0x3f),iVar7 + 0x34,1);
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,(int)uVar6 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        if (iVar9 != 0) {
          *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) - *(int *)(iVar4 + 0x38);
          *(int *)(iVar4 + 0xcc) = *(int *)(iVar4 + 0xcc) - *(int *)(iVar4 + 0x38);
          piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 0xc + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 - *(int *)(iVar4 + 0x38);
          *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
          *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
          piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 4 + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 + 1;
          iVar9 = *(int *)(iVar4 + 0x7c) * uVar6;
          iVar12 = iVar9 / *(int *)(iVar4 + 0xac);
          psVar2 = (sword *)(iVar7 + iVar12 * 0x10 + 0xd4 +
                            (((iVar9 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8) << 3) /
                            *(int *)(iVar4 + 0xa8)) * 2);
          *psVar2 = *psVar2 + 1;
          piVar1 = (int *)(iVar7 + 0x54 + iVar12 * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
      *(char *)(iVar4 + 0xd0) = *(char *)(iVar4 + 0xd0) + '\x01';
      _bdwrite(iVar8);
      if (((*(byte *)(iVar4 + 0xd3) & 1) != 0) &&
         (*(int *)(iVar4 + 0x88) <
          *(int *)(iVar4 + 0xcc) + (*(int *)(iVar4 + 0xc4) << (*(uint *)(iVar4 + 0x60) & 0x3f)))) {
        _wakeup(iVar4 + 0xcc);
        *(byte *)(iVar4 + 0xd3) = *(byte *)(iVar4 + 0xd3) & 0xfe;
      }
    }
    else {
      _brelse(iVar8);
    }
  }
  else {
    _printf(aBadBlockDInoD,param_2,*(undefined4 *)(param_1 + 0x46));
  }
  return;
}
