/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1af8 */

void _PCcancelAllTimers(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x28) + 0xec);
  local_8 = 0;
  if (piVar2 != (int *)0x0) {
    local_8 = *piVar2;
  }
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar1 = local_8 + 0x88 + iVar3;
    _calloutRemove(FUN_001a19c8,iVar1);
    _calloutRemove(FUN_001a19e8,iVar1);
    iVar3 = iVar3 + 0x84;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

