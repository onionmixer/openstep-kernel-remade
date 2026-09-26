/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161ec8 */

int _dequeue_tail(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == param_1) {
    iVar1 = 0;
  }
  else {
    **(int **)(iVar1 + 4) = param_1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 4);
  }
  return iVar1;
}

