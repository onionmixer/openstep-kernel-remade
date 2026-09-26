/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca8a0 */

int FUN_001ca8a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      iVar1 = *(int *)(param_1 + 8 + iVar3 * 4);
      if (*(int *)(iVar1 + 0xc) != 0) {
        iVar2 = FUN_001ca868(*(undefined4 *)(iVar1 + 0xc),param_2);
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar1 = *(int *)(param_1 + 8 + iVar3 * 4);
      if (*(int *)(iVar1 + 8) != 0) {
        iVar2 = FUN_001ca8a0(*(undefined4 *)(iVar1 + 8),param_2);
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return 0;
}

