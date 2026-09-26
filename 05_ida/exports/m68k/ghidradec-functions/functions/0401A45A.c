
int _getfakedirentries(int param_1,int param_2)

{
  int iVar1;
  word *pwVar2;
  int iVar3;
  word wVar6;
  undefined4 *puVar4;
  undefined2 uVar7;
  int iVar5;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if (iVar5 != 0) {
    iVar1 = *(int *)(param_2 + 0x12);
    uVar11 = -*(int *)(param_2 + 8) - 0x400;
    if (iVar1 != 0) {
      uVar8 = 0;
      if (uVar11 != 0) {
        do {
          if (iVar5 == 0) {
            return 0;
          }
          wVar6 = _strlen(iVar5 + 0x20);
          iVar9 = (wVar6 + 4 & 0xfffffffc) + 8;
          if (iVar9 + (uVar8 & 0xfffffc00) < 0x401) {
            uVar8 = iVar9 + uVar8;
          }
          else {
            uVar8 = (uVar8 & 0xfffffc00) + 0x400;
          }
          iVar5 = *(int *)(iVar5 + 0x120);
        } while (uVar8 < uVar11);
      }
      if (iVar5 != 0) {
        puVar4 = (undefined4 *)_kalloc(iVar1);
        iVar9 = 0;
        puVar12 = puVar4;
        for (iVar3 = iVar1; iVar10 = 0, iVar3 != 0; iVar3 = iVar3 - (uint)*pwVar2) {
          *puVar12 = 0xffffffff;
          uVar7 = _strlen(iVar5 + 0x20);
          *(undefined2 *)((int)puVar12 + 6) = uVar7;
          _strcpy(puVar12 + 2,iVar5 + 0x20);
          iVar5 = *(int *)(iVar5 + 0x120);
          if (iVar5 == 0) {
            wVar6 = 0x400 - (sword)iVar9;
            *(word *)(puVar12 + 1) = wVar6;
            iVar10 = iVar3 - (uint)wVar6;
            uVar11 = wVar6 + uVar11;
            break;
          }
          wVar6 = _strlen(iVar5 + 0x20);
          if ((*(word *)((int)puVar12 + 6) + 4 & 0xfffffffc) +
              (wVar6 + 4 & 0xfffffffc) + 0x10 + iVar9 < 0x401) {
            *(word *)(puVar12 + 1) = (*(word *)((int)puVar12 + 6) + 4 & 0xfffc) + 8;
            iVar9 = iVar9 + 8 + (*(word *)((int)puVar12 + 6) + 4 & 0xfffffffc);
          }
          else {
            *(sword *)(puVar12 + 1) = 0x400 - (sword)iVar9;
            iVar9 = 0;
          }
          pwVar2 = (word *)(puVar12 + 1);
          uVar11 = *pwVar2 + uVar11;
          puVar12 = (undefined4 *)((uint)*(word *)(puVar12 + 1) + (int)puVar12);
        }
        iVar5 = _uiomove(puVar4,*(int *)(param_2 + 0x12) - iVar10,0,param_2);
        _kfree(puVar4,iVar1);
        if (iVar5 != 0) {
          return iVar5;
        }
        *(uint *)(param_2 + 8) = -(uVar11 + 0x400);
      }
    }
  }
  return 0;
}
