
byte _ttyselwait(int param_1,uint param_2)

{
  word wVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  
  cVar6 = 1 < param_2;
  if (param_2 == 1) {
    iVar2 = _selthreadcache(param_1 + 0x28);
    bVar5 = false;
    bVar7 = false;
    bVar3 = iVar2 < 0;
    bVar4 = iVar2 == 0;
    if (!bVar4) {
      bVar5 = false;
      bVar7 = false;
      wVar1 = *(word *)(param_1 + 0x40) | 0x800;
      *(word *)(param_1 + 0x40) = wVar1;
      bVar3 = (sword)wVar1 < 0;
      bVar4 = wVar1 == 0;
    }
  }
  else {
    cVar6 = 2 < param_2;
    bVar5 = SBORROW4(2,param_2);
    bVar3 = (int)(2 - param_2) < 0;
    if (param_2 == 2) {
      iVar2 = _selthreadcache(param_1 + 0x2c);
      bVar5 = false;
      bVar7 = false;
      bVar3 = iVar2 < 0;
      bVar4 = iVar2 == 0;
      if (!bVar4) {
        bVar5 = false;
        bVar7 = false;
        wVar1 = *(word *)(param_1 + 0x40) | 0x1000;
        *(word *)(param_1 + 0x40) = wVar1;
        bVar3 = (sword)wVar1 < 0;
        bVar4 = wVar1 == 0;
      }
    }
    else {
      bVar4 = false;
      bVar7 = (bool)cVar6;
    }
  }
  return cVar6 << 4 | bVar3 << 3 | bVar4 << 2 | bVar5 << 1 | bVar7;
}
