
int _indirtrunc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  
  iVar7 = *(int *)(param_1 + 0x4e);
  iVar10 = 0;
  iVar11 = 1;
  iVar8 = 0;
  if (0 < param_4) {
    do {
      iVar11 = *(int *)(iVar7 + 0x74) * iVar11;
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_4);
  }
  iVar8 = param_3;
  if (0 < param_3) {
    iVar8 = param_3 / iVar11;
  }
  iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
  iVar2 = *(int *)(iVar7 + 0x30);
  iVar4 = _geteblk(*(undefined4 *)(iVar7 + 0x30));
  iVar5 = _bread(*(undefined4 *)(param_1 + 0x3e),param_2 << (*(uint *)(iVar7 + 100) & 0x3f),
                 *(undefined4 *)(iVar7 + 0x30));
  if ((*(byte *)(iVar5 + 3) & 4) == 0) {
    iVar9 = *(int *)(iVar5 + 0x20);
    _bcopy(iVar9,*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar7 + 0x30));
    _bzero(iVar9 + 4 + iVar8 * 4,((*(int *)(iVar7 + 0x74) + -1) - iVar8) * 4);
    _bwrite(iVar5);
    iVar5 = *(int *)(iVar4 + 0x20);
    iVar9 = *(int *)(iVar7 + 0x74) + -1;
    if (iVar8 < iVar9) {
      piVar12 = (int *)(iVar5 + iVar9 * 4);
      do {
        iVar1 = *piVar12;
        if (iVar1 != 0) {
          if (0 < param_4) {
            iVar6 = _indirtrunc(param_1,iVar1,0xffffffff,param_4 + -1);
            iVar10 = iVar6 + iVar10;
          }
          _free_block(param_1,iVar1,*(undefined4 *)(iVar7 + 0x30));
          iVar10 = iVar2 / iVar3 + iVar10;
        }
        piVar12 = piVar12 + -1;
        iVar9 = iVar9 + -1;
      } while (iVar8 < iVar9);
    }
    if ((0 < param_4) && (-1 < param_3)) {
      iVar7 = *(int *)(iVar5 + iVar9 * 4);
      if (iVar7 != 0) {
        iVar7 = _indirtrunc(param_1,iVar7,param_3 % iVar11,param_4 + -1);
        iVar10 = iVar7 + iVar10;
      }
    }
    _brelse(iVar4);
  }
  else {
    _brelse(iVar4);
    _brelse(iVar5);
    iVar10 = 0;
  }
  return iVar10;
}

