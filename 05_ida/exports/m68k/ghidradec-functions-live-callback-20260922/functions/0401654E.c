
undefined4 _unp_internalize(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  uVar3 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  iVar2 = 0;
  puVar4 = (undefined4 *)(*(int *)(param_1 + 4) + param_1);
  if (uVar3 != 0) {
    do {
      iVar1 = _getf(*puVar4);
      if (iVar1 == 0) {
        return 9;
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < (int)uVar3);
  }
  iVar2 = 0;
  piVar5 = (int *)(*(int *)(param_1 + 4) + param_1);
  if (uVar3 != 0) {
    do {
      iVar1 = _getf(*piVar5);
      *piVar5 = iVar1;
      *(sword *)(iVar1 + 0xe) = *(sword *)(iVar1 + 0xe) + 1;
      *(sword *)(iVar1 + 0x10) = *(sword *)(iVar1 + 0x10) + 1;
      _unp_rights = _unp_rights + 1;
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < (int)uVar3);
  }
  return 0;
}

