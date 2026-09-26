
byte _kmoutput(int param_1)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  undefined4 uVar12;
  byte abStack_54 [80];
  
  iVar2 = _ttynty(param_1);
  uVar4 = 0xffffffff;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      if ((((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
          ((*(uint *)(iVar2 + 0x10) & 0x10000000) != 0)) &&
         ((*(uint *)(iVar2 + 0x10) & 0x300) != 0x300)) {
        uVar12 = 0x80;
      }
      else {
        uVar12 = 0;
      }
      uVar3 = _ndqb(param_1 + 0x18,uVar12);
      if (uVar3 == 0) goto loc_406F5FC;
      uVar4 = 0x50;
      if (uVar3 < 0x50) {
        uVar4 = uVar3;
      }
      _q_to_b(param_1 + 0x18,abStack_54,uVar4);
      for (pbVar6 = abStack_54; pbVar6 < abStack_54 + uVar4; pbVar6 = pbVar6 + 1) {
        _kmpaint(*pbVar6 & 0x7f);
      }
    } while (0 < *(int *)(param_1 + 0x18));
  }
  if (uVar4 == 0) {
loc_406F5FC:
    uVar4 = _getc(param_1 + 0x18);
    _timeout(_ttrstrt,param_1,uVar4 & 0x7f);
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 1;
  }
  else if (0 < *(int *)(param_1 + 0x18)) {
    _callout_dispatch(0,_kmoutput,param_1);
  }
  uVar4 = *(uint *)(param_1 + 0x3e);
  *(uint *)(param_1 + 0x3e) = uVar4 & 0xffffffdf;
  uVar5 = (uint)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  uVar3 = *(uint *)(param_1 + 0x18);
  cVar10 = uVar5 < uVar3;
  bVar9 = SBORROW4(uVar5,uVar3);
  bVar7 = (int)(uVar5 - uVar3) < 0;
  bVar8 = uVar5 == uVar3;
  bVar11 = (bool)cVar10;
  if ((int)uVar3 <= (int)uVar5) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x3e) = uVar4 & 0xffffff9f;
      _wakeup(param_1 + 0x18);
    }
    iVar2 = *(int *)(param_1 + 0x2c);
    bVar7 = iVar2 < 0;
    bVar8 = iVar2 == 0;
    bVar9 = false;
    bVar11 = false;
    if (!bVar8) {
      _selwakeup(iVar2,*(uint *)(param_1 + 0x3e) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      bVar9 = false;
      bVar11 = false;
      wVar1 = *(word *)(param_1 + 0x40) & 0xefff;
      *(word *)(param_1 + 0x40) = wVar1;
      bVar7 = (int)((uint)wVar1 << 0x10) < 0;
      bVar8 = wVar1 == 0;
    }
  }
  return cVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 | bVar11;
}
