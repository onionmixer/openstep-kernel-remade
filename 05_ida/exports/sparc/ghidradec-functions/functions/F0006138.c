
int _memcmp(uint *param_1,uint *param_2,uint param_3)

{
  word wVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  if (param_1 == param_2) {
    return 0;
  }
  if ((int)param_3 < 8) {
    pbVar3 = (byte *)((int)param_2 - (int)param_1);
    bVar11 = SBORROW4(param_3,1);
    iVar4 = param_3 - 1;
    bVar10 = iVar4 < 0;
  }
  else {
    uVar5 = (uint)param_1 & 3;
    if (uVar5 != 0) {
      if (uVar5 == 2) {
loc_F000618C:
        wVar1 = *(word *)param_1;
        param_1 = (uint *)((int)param_1 + 2);
        iVar8 = (int)(char)*(byte *)param_2;
        iVar7 = (int)(sword)wVar1 >> 8;
        if (iVar7 != iVar8) goto locret_F000625C;
        iVar8 = (int)(char)*(byte *)((int)param_2 + 1);
        param_2 = (uint *)((int)param_2 + 2);
        param_3 = param_3 - 2;
        iVar7 = (int)(char)wVar1;
        bVar10 = iVar7 == iVar8;
      }
      else {
        iVar7 = (int)(char)*(byte *)param_1;
        param_1 = (uint *)((int)param_1 + 1);
        iVar8 = (int)(char)*(byte *)param_2;
        param_2 = (uint *)((int)param_2 + 1);
        param_3 = param_3 - 1;
        bVar10 = iVar7 == iVar8;
        if (uVar5 != 3) {
          if (!bVar10) goto locret_F000625C;
          goto loc_F000618C;
        }
      }
      if (!bVar10) goto locret_F000625C;
    }
    uVar6 = (uint)param_2 & 3;
    uVar5 = param_3 & 0xfffffffc;
    param_3 = param_3 & 3;
    if (uVar6 == 0) {
      pbVar3 = (byte *)((int)param_2 - (int)param_1);
      uVar9 = *(uint *)((int)param_1 + (int)pbVar3);
      while( true ) {
        uVar6 = *param_1;
        param_1 = param_1 + 1;
        uVar5 = uVar5 - 4;
        if (uVar6 != uVar9) break;
        if (uVar5 == 0) {
          bVar11 = SBORROW4(param_3,1);
          iVar4 = param_3 - 1;
          bVar10 = iVar4 < 0;
          goto loc_F00061F4;
        }
        uVar9 = *(uint *)((int)param_1 + (int)pbVar3);
      }
loc_F0006204:
      iVar4 = (int)uVar6 >> 0x18;
      iVar7 = (int)uVar9 >> 0x18;
      if (iVar4 == iVar7) {
        iVar4 = (int)(uVar6 << 8) >> 0x18;
        iVar7 = (int)(uVar9 << 8) >> 0x18;
        if (iVar4 == iVar7) {
          iVar4 = (int)(uVar6 << 0x10) >> 0x18;
          iVar7 = (int)(uVar9 << 0x10) >> 0x18;
          if (iVar4 == iVar7) {
            iVar4 = (int)(char)uVar6;
            iVar7 = (int)(char)uVar9;
          }
        }
      }
      return iVar4 - iVar7;
    }
    if (uVar6 == 2) {
      uVar2 = (uint)*(word *)param_2;
      pbVar3 = (byte *)((int)param_2 + (2 - (int)param_1));
      do {
        uVar9 = uVar2 << 0x10;
        uVar2 = *(uint *)((int)param_1 + (int)pbVar3);
        uVar6 = *param_1;
        param_1 = param_1 + 1;
        uVar9 = uVar2 >> 0x10 | uVar9;
        uVar5 = uVar5 - 4;
        if (uVar6 != uVar9) goto loc_F0006204;
      } while (uVar5 != 0);
      pbVar3 = pbVar3 + -2;
      bVar11 = SBORROW4(param_3,1);
      iVar4 = param_3 - 1;
      bVar10 = iVar4 < 0;
    }
    else {
      uVar9 = (uint)*(byte *)param_2 << 0x18;
      if (uVar6 == 1) {
        uVar9 = uVar9 | (uint)*(word *)((int)param_2 + 1) << 8;
        pbVar3 = (byte *)((int)param_2 + (3 - (int)param_1));
        do {
          uVar2 = *(uint *)((int)param_1 + (int)pbVar3);
          uVar6 = *param_1;
          param_1 = param_1 + 1;
          uVar9 = uVar2 >> 0x18 | uVar9;
          uVar5 = uVar5 - 4;
          if (uVar6 != uVar9) goto loc_F0006204;
          uVar9 = uVar2 << 8;
        } while (uVar5 != 0);
        pbVar3 = pbVar3 + -3;
        bVar11 = SBORROW4(param_3,1);
        iVar4 = param_3 - 1;
        bVar10 = iVar4 < 0;
      }
      else {
        iVar4 = ((int)param_2 + 1) - (int)param_1;
        do {
          uVar2 = *(uint *)((int)param_1 + iVar4);
          uVar6 = *param_1;
          param_1 = param_1 + 1;
          uVar9 = uVar2 >> 8 | uVar9;
          uVar5 = uVar5 - 4;
          if (uVar6 != uVar9) goto loc_F0006204;
          uVar9 = uVar2 << 0x18;
        } while (uVar5 != 0);
        pbVar3 = (byte *)(iVar4 + -1);
        bVar11 = SBORROW4(param_3,1);
        iVar4 = param_3 - 1;
        bVar10 = iVar4 < 0;
      }
    }
  }
loc_F00061F4:
  while( true ) {
    if (bVar10 != bVar11) {
      return 0;
    }
    iVar7 = (int)(char)*(byte *)param_1;
    iVar8 = (int)(char)*(byte *)((int)param_1 + (int)pbVar3);
    param_1 = (uint *)((int)param_1 + 1);
    if (iVar7 != iVar8) break;
    bVar11 = SBORROW4(iVar4,1);
    iVar4 = iVar4 + -1;
    bVar10 = iVar4 < 0;
  }
locret_F000625C:
  return iVar7 - iVar8;
}
