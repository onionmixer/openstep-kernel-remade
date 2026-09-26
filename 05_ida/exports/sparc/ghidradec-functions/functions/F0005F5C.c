
undefined4 _bcmp(uint *param_1,word *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  word wVar4;
  word wVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  if ((int)param_3 < 8) {
    pbVar6 = (byte *)((int)param_2 - (int)param_1);
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
    goto loc_F0006008;
  }
  uVar8 = (uint)param_1 & 3;
  if (uVar8 != 0) {
    if (uVar8 == 2) {
loc_F0005FA8:
      wVar4 = *(word *)param_1;
      param_1 = (uint *)((int)param_1 + 2);
      if (wVar4 >> 8 != (word)*(byte *)param_2) {
        return 1;
      }
      wVar5 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 2;
      bVar12 = (wVar4 & 0xff) == (word)(byte)wVar5;
    }
    else {
      bVar3 = *(byte *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      bVar2 = *(byte *)param_2;
      param_2 = (word *)((int)param_2 + 1);
      param_3 = param_3 - 1;
      bVar12 = bVar3 == bVar2;
      if (uVar8 != 3) {
        if (!bVar12) {
          return 1;
        }
        goto loc_F0005FA8;
      }
    }
    if (!bVar12) {
      return 1;
    }
  }
  uVar9 = (uint)param_2 & 3;
  uVar8 = param_3 & 0xfffffffc;
  param_3 = param_3 & 3;
  if (uVar9 == 0) {
    pbVar6 = (byte *)((int)param_2 - (int)param_1);
    uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
    while( true ) {
      uVar11 = *param_1;
      param_1 = param_1 + 1;
      uVar8 = uVar8 - 4;
      if (uVar11 != uVar9) {
        return 1;
      }
      if (uVar8 == 0) break;
      uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
    }
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
  }
  else if (uVar9 == 2) {
    uVar9 = (uint)*param_2;
    pbVar6 = (byte *)((int)param_2 + (2 - (int)param_1));
    do {
      uVar10 = uVar9 << 0x10;
      uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
      uVar11 = *param_1;
      param_1 = param_1 + 1;
      uVar8 = uVar8 - 4;
      if (uVar11 != (uVar9 >> 0x10 | uVar10)) {
        return 1;
      }
    } while (uVar8 != 0);
    pbVar6 = pbVar6 + -2;
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
  }
  else {
    uVar11 = (uint)*(byte *)param_2 << 0x18;
    if (uVar9 == 1) {
      uVar11 = uVar11 | (uint)*(word *)((int)param_2 + 1) << 8;
      pbVar6 = (byte *)((int)param_2 + (3 - (int)param_1));
      do {
        uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
        uVar10 = *param_1;
        param_1 = param_1 + 1;
        uVar8 = uVar8 - 4;
        if (uVar10 != (uVar9 >> 0x18 | uVar11)) {
          return 1;
        }
        uVar11 = uVar9 << 8;
      } while (uVar8 != 0);
      pbVar6 = pbVar6 + -3;
      bVar13 = SBORROW4(param_3,1);
      iVar7 = param_3 - 1;
      bVar12 = iVar7 < 0;
    }
    else {
      iVar7 = ((int)param_2 + 1) - (int)param_1;
      do {
        uVar9 = *(uint *)((int)param_1 + iVar7);
        uVar10 = *param_1;
        param_1 = param_1 + 1;
        uVar8 = uVar8 - 4;
        if (uVar10 != (uVar9 >> 8 | uVar11)) {
          return 1;
        }
        uVar11 = uVar9 << 0x18;
      } while (uVar8 != 0);
      pbVar6 = (byte *)(iVar7 + -1);
      bVar13 = SBORROW4(param_3,1);
      iVar7 = param_3 - 1;
      bVar12 = iVar7 < 0;
    }
  }
loc_F0006008:
  while( true ) {
    if (bVar12 != bVar13) {
      return 0;
    }
    bVar3 = *(byte *)param_1;
    pbVar1 = (byte *)((int)param_1 + (int)pbVar6);
    param_1 = (uint *)((int)param_1 + 1);
    if (bVar3 != *pbVar1) break;
    bVar13 = SBORROW4(iVar7,1);
    iVar7 = iVar7 + -1;
    bVar12 = iVar7 < 0;
  }
  return 1;
}
