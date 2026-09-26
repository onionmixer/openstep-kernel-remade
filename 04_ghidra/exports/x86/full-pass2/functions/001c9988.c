/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9988 */

undefined4 FUN_001c9988(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (param_3 < *(uint *)(param_1 + 8)) {
    puVar5 = (undefined4 *)(param_3 * 4 + *(int *)(param_1 + 4));
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 4);
    uVar4 = *puVar5;
    puVar3 = puVar5;
    while (puVar3 = puVar3 + 1, puVar3 < (undefined4 *)(iVar1 * 4 + iVar2)) {
      *puVar5 = *puVar3;
      puVar5 = puVar5 + 1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

