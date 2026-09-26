
undefined4 _ttstart(int param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar4 = '\0';
  cVar7 = '\0';
  bVar8 = 0;
  uVar2 = *(uint *)(param_1 + 0x3e) & 0x4000121;
  uVar3 = (undefined2)(uVar2 >> 0x10);
  cVar5 = '\0';
  cVar6 = '\0';
  if (uVar2 == 0) {
    pcVar1 = *(code **)(param_1 + 0x24);
    cVar7 = '\0';
    bVar8 = 0;
    cVar5 = (int)pcVar1 < 0;
    cVar6 = pcVar1 == (code *)0x0;
    if (!(bool)cVar6) {
      cVar5 = param_1 < 0;
      cVar6 = param_1 == 0;
      cVar7 = '\0';
      bVar8 = 0;
      (*pcVar1)(param_1);
      uVar3 = extraout_D0u;
    }
  }
  return CONCAT22(uVar3,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
