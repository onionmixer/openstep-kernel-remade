
byte _en_setaddr(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  word *pwVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  
  iVar1 = (&_en_softc)[param_2 * 0x14b];
  cVar5 = '\0';
  _bcopy(param_1,(int)&unk_40C8F38 + param_2 * 0x52c,6);
  uVar2 = *(uint *)(&DAT_40c9136 + param_2 * 0x14b);
  *(uint *)(&DAT_40c9136 + param_2 * 0x14b) = uVar2 | 4;
  bVar4 = (uVar2 & 1) == 0;
  if (bVar4) {
    bVar9 = cVar5 << 4 | ((int)(uVar2 | 4) < 0) << 3 | bVar4 << 2;
  }
  else {
    *(uint *)(&DAT_40c9136 + param_2 * 0x14b) = uVar2 & 0xfffffffe | 4;
    pwVar3 = (word *)(iVar1 + 0xc);
    *pwVar3 = *pwVar3 & 0xffbe;
    iVar1 = (&_en_softc)[param_2 * 0x14b];
    cVar6 = iVar1 < 0;
    cVar7 = iVar1 == 0;
    cVar8 = '\0';
    bVar9 = 0;
    _eninit(iVar1);
    bVar9 = cVar5 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar9;
  }
  return bVar9;
}

