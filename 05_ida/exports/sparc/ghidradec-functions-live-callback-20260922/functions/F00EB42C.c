
undefined4 -[List removeObjectAt:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (param_3 < *(uint *)(param_1 + 8)) {
    iVar3 = *(int *)(param_1 + 4);
    puVar5 = (undefined4 *)(param_3 * 4 + iVar3);
    iVar2 = *(int *)(param_1 + 8);
    uVar4 = *(undefined4 *)(param_3 * 4 + iVar3);
    puVar1 = puVar5;
    while (puVar1 = puVar1 + 1, puVar1 < (undefined4 *)(iVar2 * 4 + iVar3)) {
      *puVar5 = *puVar1;
      puVar5 = puVar5 + 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

