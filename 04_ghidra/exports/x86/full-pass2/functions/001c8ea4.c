/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8ea4 */

undefined4 FUN_001c8ea4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x14);
  iVar1 = FUN_001c8938(*(undefined4 *)(param_1 + 8),param_3,*(undefined4 *)(param_1 + 0x10));
  iVar3 = *(int *)(iVar2 + iVar1 * 8);
  puVar4 = *(undefined4 **)(iVar2 + 4 + iVar1 * 8);
  if (iVar3 != 0) {
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      iVar2 = FUN_001c89c8(*(undefined4 *)(param_1 + 8),param_3,*puVar4);
      if (iVar2 != 0) {
        return 1;
      }
      puVar4 = puVar4 + 2;
    }
  }
  return 0;
}

