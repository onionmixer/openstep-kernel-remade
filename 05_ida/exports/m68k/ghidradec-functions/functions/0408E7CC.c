
byte _en_antijam(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar3 = '\0';
  uVar2 = *(uint *)(param_1 + 0x202);
  bVar5 = (uVar2 & 8) == 0;
  if (bVar5) {
    bVar8 = ((int)uVar2 < 0) << 3 | bVar5 << 2;
  }
  else {
    *(uint *)(param_1 + 0x202) = uVar2 & 0xfffffff7;
    cVar4 = (int)(uVar2 & 0xfffffff7) < 0;
    cVar7 = '\0';
    bVar8 = 0;
    cVar6 = '\0';
    if ((uVar2 & 2) == 0) {
      uVar2 = (param_1 + -0x40c8f34) * -0x40317f9d;
      cVar3 = (uVar2 >> 1 & 1) != 0;
      iVar1 = (int)uVar2 >> 2;
      cVar4 = iVar1 < 0;
      cVar6 = iVar1 == 0;
      cVar7 = '\0';
      bVar8 = 0;
      _enstart(iVar1);
    }
    bVar8 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8;
  }
  return bVar8;
}
