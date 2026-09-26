
uint _uncompress_data(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  
  uVar4 = param_4 + 3U >> 2;
  puVar8 = (undefined4 *)(param_1 + 4 + (param_4 + 3U >> 5));
  uVar3 = 0;
  iVar6 = 0;
  pcVar9 = (char *)(param_1 + 4);
  if (uVar4 != 0) {
    do {
      cVar2 = *pcVar9;
      uVar1 = 0;
      puVar5 = param_3;
      puVar7 = puVar8;
      do {
        if ((int)uVar4 <= iVar6) {
          return uVar4;
        }
        puVar8 = puVar7;
        if (cVar2 < '\0') {
          puVar8 = puVar7 + 1;
          uVar3 = *puVar7;
        }
        param_3 = puVar5 + 1;
        *puVar5 = uVar3;
        cVar2 = cVar2 << 1;
        uVar1 = uVar1 + 1;
        iVar6 = iVar6 + 1;
        puVar5 = param_3;
        puVar7 = puVar8;
      } while (uVar1 < 8);
      pcVar9 = pcVar9 + 1;
    } while (iVar6 < (int)uVar4);
  }
  return uVar4;
}
