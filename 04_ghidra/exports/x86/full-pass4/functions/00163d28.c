/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163d28 */

void _compute_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) == 2) {
    iVar1 = *(int *)(param_1 + 0x50);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (-1 < *(int *)(param_1 + 100)) {
      *(int *)(param_1 + 100) = iVar1;
      return;
    }
  }
  _set_pri(param_1,iVar1,param_2);
  return;
}

