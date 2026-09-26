
undefined4 _busdone(int *param_1)

{
  int iVar1;
  int *piVar2;
  sword sVar3;
  undefined2 extraout_D0u;
  undefined2 uVar4;
  undefined4 uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  
  piVar2 = (int *)param_1[3];
  if ((*(byte *)(*param_1 + 0x31) & 1) != 0) {
    *(undefined2 *)((int)piVar2 + 10) = 0;
  }
  sVar3 = *(sword *)(piVar2 + 2);
  cVar9 = sVar3 == 0;
  *(sword *)(piVar2 + 2) = sVar3 + -1;
  iVar1 = *piVar2;
  cVar6 = iVar1 < 0;
  cVar7 = iVar1 == 0;
  cVar8 = '\0';
  bVar10 = 0;
  uVar4 = 0;
  if (!(bool)cVar7) {
    cVar6 = iVar1 < 0;
    cVar7 = iVar1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _busgo(iVar1);
    uVar4 = extraout_D0u;
  }
  uVar5 = CONCAT22(uVar4,(word)(byte)(cVar9 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar10));
  if (*(code **)(*param_1 + 0x10) != (code *)0x0) {
    uVar5 = (**(code **)(*param_1 + 0x10))(param_1);
  }
  return uVar5;
}

