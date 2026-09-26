
int _compress_data(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  
  uVar5 = param_2 + 3U >> 2;
  piVar7 = (int *)((int)param_3 + (param_2 + 3U >> 5) + 4);
  bVar3 = 0;
  iVar4 = 0;
  iVar8 = 0;
  pbVar9 = (byte *)(param_3 + 1);
  if (uVar5 != 0) {
    do {
      uVar2 = 0;
      piVar6 = piVar7;
      do {
        piVar7 = piVar6;
        if ((int)uVar5 <= iVar8) break;
        bVar3 = bVar3 << 1;
        iVar1 = *param_1;
        if (iVar1 != iVar4) {
          bVar3 = bVar3 | 1;
          piVar7 = piVar6 + 1;
          *piVar6 = iVar1;
          iVar4 = iVar1;
          if (param_2 == (int)piVar7 - (int)param_3) {
            return param_2;
          }
        }
        param_1 = param_1 + 1;
        uVar2 = uVar2 + 1;
        iVar8 = iVar8 + 1;
        piVar6 = piVar7;
      } while (uVar2 < 8);
      *pbVar9 = bVar3;
      pbVar9 = pbVar9 + 1;
    } while (iVar8 < (int)uVar5);
  }
  *param_3 = param_2;
  return (int)piVar7 - (int)param_3;
}
