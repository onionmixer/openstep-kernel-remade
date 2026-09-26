
undefined4 _ttselwakeup(int param_1)

{
  int iVar1;
  word wVar2;
  undefined2 extraout_D0u;
  undefined2 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar4 = '\0';
  iVar1 = *(int *)(param_1 + 0x28);
  cVar5 = iVar1 < 0;
  cVar6 = iVar1 == 0;
  cVar7 = '\0';
  bVar8 = 0;
  uVar3 = 0;
  if (!(bool)cVar6) {
    _selwakeup(iVar1,*(uint *)(param_1 + 0x3e) & 0x800);
    cVar7 = '\0';
    bVar8 = 0;
    wVar2 = *(word *)(param_1 + 0x40) & 0xf7ff;
    *(word *)(param_1 + 0x40) = wVar2;
    cVar5 = (int)((uint)wVar2 << 0x10) < 0;
    cVar6 = wVar2 == 0;
    _selthreadclear(param_1 + 0x28);
    uVar3 = extraout_D0u;
  }
  return CONCAT22(uVar3,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
