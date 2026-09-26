
int _dirpref(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar6 = *(int *)(param_1 + 0xb8);
  uVar7 = 0;
  uVar5 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = *(int *)(param_1 + ((int)uVar5 >> (*(uint *)(param_1 + 0x70) & 0x3f)) * 4 + 0x2d8);
      iVar4 = (~*(uint *)(param_1 + 0x6c) & uVar5) * 0x10;
      iVar3 = *(int *)(iVar2 + iVar4);
      if ((iVar3 < iVar6) && (*(int *)(param_1 + 200) / iVar1 <= *(int *)(iVar2 + 8 + iVar4))) {
        iVar6 = iVar3;
        uVar7 = uVar5;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < iVar1);
  }
  return uVar7 * *(int *)(param_1 + 0xb8);
}
