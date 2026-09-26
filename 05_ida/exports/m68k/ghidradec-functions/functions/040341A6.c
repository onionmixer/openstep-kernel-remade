
int _alloccg(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iStack_40;
  int iStack_3c;
  undefined4 *puStack_38;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if ((*(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) + 4
               + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10) == 0) &&
     (param_4 == *(int *)(iVar2 + 0x30))) {
    return 0;
  }
  puStack_38 = *(undefined4 **)(iVar2 + 0xa0);
  iStack_3c = *(int *)(iVar2 + 0xc) +
              *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
              param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f);
  iStack_40 = *(int *)(param_1 + 0x3e);
  iVar6 = _bread();
  iVar3 = *(int *)(iVar6 + 0x20);
  if ((((*(byte *)(iVar6 + 3) & 4) == 0) && (*(int *)(iVar3 + 0x3d4) == 0x90255)) &&
     ((*(int *)(iVar3 + 0x1c) != 0 || (param_4 != *(int *)(iVar2 + 0x30))))) {
    puStack_38 = auStack_c;
    iStack_3c = 0x4034258;
    _getthetime();
    *(undefined4 *)(iVar3 + 8) = auStack_c[0];
    iStack_3c = iVar3;
    if (param_4 == *(int *)(iVar2 + 0x30)) {
      puStack_38 = (undefined4 *)param_3;
      piVar11 = &iStack_40;
      iStack_40 = iVar2;
      iVar7 = _alloccgblk();
loc_4034326:
      *(int *)((int)piVar11 + -4) = iVar6;
      *(undefined4 *)((int)piVar11 + -8) = 0x403432e;
      _bdwrite();
      return iVar7;
    }
    param_4 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f);
    for (iVar7 = param_4;
        (iVar7 < *(int *)(iVar2 + 0x38) && (*(int *)(iVar3 + 0x34 + iVar7 * 4) == 0));
        iVar7 = iVar7 + 1) {
    }
    if (iVar7 == *(int *)(iVar2 + 0x38)) {
      if (*(int *)(iVar3 + 0x1c) != 0) {
        puStack_38 = (undefined4 *)param_3;
        iStack_40 = iVar2;
        iVar7 = _alloccgblk();
        iVar8 = *(int *)(iVar2 + 0xbc);
        piVar11 = (int *)&stack0xffffffcc;
        iVar10 = param_4;
        if (param_4 < *(int *)(iVar2 + 0x38)) {
          do {
            iVar5 = iVar10 + iVar7 % iVar8;
            iVar9 = iVar5;
            if (iVar5 < 0) {
              iVar9 = iVar5 + 7;
            }
            pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
            *pbVar4 = (byte)(1 << (iVar5 + (iVar9 >> 3) * -8 & 0x3fU)) | *pbVar4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(iVar2 + 0x38));
        }
        param_4 = *(int *)(iVar2 + 0x38) - param_4;
        *(int *)(iVar3 + 0x24) = param_4 + *(int *)(iVar3 + 0x24);
        *(int *)(iVar2 + 0xcc) = param_4 + *(int *)(iVar2 + 0xcc);
        piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
        *piVar1 = param_4 + *piVar1;
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        piVar1 = (int *)(iVar3 + 0x34 + param_4 * 4);
        *piVar1 = *piVar1 + 1;
        goto loc_4034326;
      }
    }
    else {
      iStack_3c = param_3;
      iStack_40 = iVar3;
      puStack_38 = (undefined4 *)iVar7;
      iVar8 = _mapsearch(iVar2);
      if (-1 < iVar8) {
        iVar10 = 0;
        if (0 < param_4) {
          do {
            iVar5 = iVar10 + iVar8;
            iVar9 = iVar5;
            if (iVar5 < 0) {
              iVar9 = iVar5 + 7;
            }
            pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
            *pbVar4 = ~(byte)(1 << (iVar5 + (iVar9 >> 3) * -8 & 0x3fU)) & *pbVar4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < param_4);
        }
        *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) - param_4;
        *(int *)(iVar2 + 0xcc) = *(int *)(iVar2 + 0xcc) - param_4;
        piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
        *piVar1 = *piVar1 - param_4;
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        piVar1 = (int *)(iVar3 + 0x34 + iVar7 * 4);
        *piVar1 = *piVar1 + -1;
        if (iVar7 != param_4) {
          piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - param_4) * 4);
          *piVar1 = *piVar1 + 1;
        }
        iStack_3c = 0x40343ca;
        puStack_38 = (undefined4 *)iVar6;
        _bdwrite();
        return iVar8 + *(int *)(iVar2 + 0xbc) * param_2;
      }
    }
  }
  iStack_3c = 0x4034352;
  puStack_38 = (undefined4 *)iVar6;
  _brelse();
  return 0;
}
