
uint _bcmp(int *param_1,int *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  sword sVar6;
  word wVar7;
  bool bVar8;
  
  if (((0x40 < (int)param_3) && ((((uint)param_1 ^ (uint)param_2) & 3) == 0)) &&
     (uVar5 = -(int)param_1 & 3, uVar5 != 0)) {
    param_3 = param_3 - uVar5;
    uVar5 = uVar5 - 1;
    do {
      cVar1 = *(char *)param_1;
      param_1 = (int *)((int)param_1 + 1);
      cVar2 = *(char *)param_2;
      param_2 = (int *)((int)param_2 + 1);
      if (cVar2 != cVar1) break;
      wVar7 = (sword)uVar5 - 1;
      uVar5 = (uint)wVar7;
    } while (wVar7 != 0xffff);
    if (cVar2 != cVar1) {
      return 1;
    }
  }
  while( true ) {
    uVar5 = param_3 >> 2;
    bVar8 = true;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    if ((int)uVar5 < 0x10000) goto loc_4092CE6;
    sVar6 = -1;
    do {
      iVar3 = *param_1;
      param_1 = param_1 + 1;
      iVar4 = *param_2;
      param_2 = param_2 + 1;
      if (iVar4 != iVar3) break;
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    if (iVar4 != iVar3) {
      return 1;
    }
    param_3 = param_3 - 0x40000;
  }
  goto loc_4092D02;
  while (wVar7 = (sword)uVar5 - 1, uVar5 = (uint)wVar7, wVar7 != 0xffff) {
loc_4092CE6:
    iVar3 = *param_1;
    param_1 = param_1 + 1;
    iVar4 = *param_2;
    param_2 = param_2 + 1;
    if (iVar4 != iVar3) break;
  }
  if (iVar4 != iVar3) {
    return 1;
  }
  param_3 = param_3 & 3;
  uVar5 = 0;
  bVar8 = true;
loc_4092D02:
  while ((bVar8 && (wVar7 = (sword)param_3 - 1, param_3 = (uint)wVar7, wVar7 != 0xffff))) {
    cVar1 = *(char *)param_1;
    param_1 = (int *)((int)param_1 + 1);
    cVar2 = *(char *)param_2;
    param_2 = (int *)((int)param_2 + 1);
    bVar8 = cVar2 == cVar1;
  }
  if (!bVar8) {
    return 1;
  }
  return uVar5;
}
