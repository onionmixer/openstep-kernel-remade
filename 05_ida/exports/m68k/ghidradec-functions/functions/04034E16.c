
int _mapsearch(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x2c);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  else {
    param_3 = param_3 % *(int *)(param_1 + 0xbc);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  param_3 = param_3 >> 3;
  iVar6 = *(int *)(param_1 + 0xbc) + 7;
  if (iVar6 < 0) {
    iVar6 = *(int *)(param_1 + 0xbc) + 0xe;
  }
  iVar6 = (iVar6 >> 3) - param_3;
  iVar2 = _scanc(iVar6,param_2 + param_3 + 0x3d8,
                 *(undefined4 *)(_fragtbl + *(int *)(param_1 + 0x38) * 4),
                 1 << (param_4 + -1 + *(int *)(param_1 + 0x38) % 8 & 0x3fU));
  if (iVar2 == 0) {
    iVar6 = param_3 + 1;
    param_3 = 0;
    iVar2 = _scanc(iVar6,param_2 + 0x3d8,*(undefined4 *)(_fragtbl + *(int *)(param_1 + 0x38) * 4),
                   1 << (param_4 + -1 + *(int *)(param_1 + 0x38) % 8 & 0x3fU));
    if (iVar2 == 0) {
      _printf(aStartDLenDFsS,0,iVar6,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aAlloccgMapCorr);
    }
  }
  iVar2 = ((iVar6 + param_3) - iVar2) * 8;
  *(int *)(param_2 + 0x2c) = iVar2;
  iVar6 = iVar2 + 8;
  do {
    if (iVar6 <= iVar2) {
      _printf(aBnoDFsS,iVar2,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aAlloccgBlockNo);
    }
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = iVar2 + 7;
    }
    uVar5 = (&_around)[param_4];
    uVar4 = (&_inside)[param_4];
    iVar7 = 0;
    iVar1 = *(int *)(param_1 + 0x38) - param_4;
    if (-1 < iVar1) {
      do {
        if (uVar4 == (uVar5 & (0xff >> (8U - *(int *)(param_1 + 0x38) & 0x3f) &
                              (int)(uint)*(byte *)((iVar3 >> 3) + param_2 + 0x3d8) >>
                              (iVar2 + (iVar3 >> 3) * -8 & 0x3fU)) * 2)) {
          return iVar7 + iVar2;
        }
        uVar5 = uVar5 * 2;
        uVar4 = uVar4 * 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 <= iVar1);
    }
    iVar2 = *(int *)(param_1 + 0x38) + iVar2;
  } while( true );
}
