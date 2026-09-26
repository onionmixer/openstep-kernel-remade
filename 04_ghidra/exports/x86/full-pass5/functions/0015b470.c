/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b470 */

void _stack_free(int param_1)

{
  int iVar1;
  
  iVar1 = _stack_detach(param_1);
  if (*(int *)(param_1 + 0x30) != iVar1) {
    _freeStack(iVar1);
  }
  return;
}

