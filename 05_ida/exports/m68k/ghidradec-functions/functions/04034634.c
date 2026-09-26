
int _ialloccg(int param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if (*(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) + 8
              + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10) == 0) {
    return 0;
  }
  iVar5 = _bread(*(undefined4 *)(param_1 + 0x3e),
                 *(int *)(iVar2 + 0xc) +
                 *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
                 param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f),
                 *(undefined4 *)(iVar2 + 0xa0));
  iVar3 = *(int *)(iVar5 + 0x20);
  if ((((*(byte *)(iVar5 + 3) & 4) != 0) || (*(int *)(iVar3 + 0x3d4) != 0x90255)) ||
     (*(int *)(iVar3 + 0x20) == 0)) {
    _brelse(iVar5);
    return 0;
  }
  _getthetime(auStack_c);
  *(undefined4 *)(iVar3 + 8) = auStack_c[0];
  if (param_3 != 0) {
    uVar7 = param_3 % *(int *)(iVar2 + 0xb8);
    uVar6 = uVar7;
    if ((int)uVar7 < 0) {
      uVar6 = uVar7 + 7;
    }
    if (((int)*(char *)(iVar3 + ((int)uVar6 >> 3) + 0x2d4) &
        1 << (uVar7 + ((int)uVar6 >> 3) * -8 & 0x1f)) == 0) goto loc_40347EC;
  }
  iVar10 = *(int *)(iVar3 + 0x30);
  iVar9 = iVar10;
  if (iVar10 < 0) {
    iVar9 = iVar10 + 7;
  }
  iVar9 = iVar9 >> 3;
  iVar10 = *(int *)(iVar2 + 0xb8) - iVar10;
  iVar8 = iVar10 + 7;
  if (iVar8 < 0) {
    iVar8 = iVar10 + 0xe;
  }
  iVar8 = iVar8 >> 3;
  iVar10 = _skpc(0xff,iVar8,iVar3 + iVar9 + 0x2d4);
  if (iVar10 == 0) {
    iVar8 = iVar9 + 1;
    iVar9 = 0;
    iVar10 = _skpc(0xff,iVar8,iVar3 + 0x2d4);
    if (iVar10 == 0) {
      _printf(aCgSIrotorDFsS,param_2,*(undefined4 *)(iVar3 + 0x30),iVar2 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIalloccgMapCor);
    }
  }
  iVar10 = (iVar8 + iVar9) - iVar10;
  uVar7 = iVar10 * 8;
  uVar6 = 1;
  while ((uVar6 & (int)*(char *)(iVar3 + iVar10 + 0x2d4)) != 0) {
    uVar6 = uVar6 * 2;
    uVar7 = uVar7 + 1;
    if (0xff < (int)uVar6) {
      _printf(aFsS,iVar2 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIalloccgBlockN);
    }
  }
  *(uint *)(iVar3 + 0x30) = uVar7;
loc_40347EC:
  uVar6 = uVar7;
  if ((int)uVar7 < 0) {
    uVar6 = uVar7 + 7;
  }
  pbVar4 = (byte *)(iVar3 + ((int)uVar6 >> 3) + 0x2d4);
  *pbVar4 = *pbVar4 | '\x01' << (uVar7 & 7);
  *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + -1;
  *(int *)(iVar2 + 200) = *(int *)(iVar2 + 200) + -1;
  piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8)
                   + 8 + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
  *piVar1 = *piVar1 + -1;
  *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
  if ((param_4 & 0xf000) == 0x4000) {
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
    *(int *)(iVar2 + 0xc0) = *(int *)(iVar2 + 0xc0) + 1;
    piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8
                             ) + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
    *piVar1 = *piVar1 + 1;
  }
  _bdwrite(iVar5);
  return uVar7 + *(int *)(iVar2 + 0xb8) * param_2;
}
