/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016af6c */

void FUN_0016af6c(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = &DAT_001f6e04;
  if ((*(int *)(param_1 + 0x14) == 0) && (iVar3 = 1, 1 < _zone_free_space_count)) {
    do {
      iVar1 = *(int *)*piVar4;
      uVar2 = *(int *)(param_1 + 0x1c) + -1 + iVar1 & -iVar1;
      if (uVar2 <= (uint)((int *)*piVar4)[1]) {
        *(uint *)(param_1 + 0x1c) = uVar2;
        *(int *)(param_1 + 0x3c) = *piVar4;
        return;
      }
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < _zone_free_space_count);
  }
  return;
}

