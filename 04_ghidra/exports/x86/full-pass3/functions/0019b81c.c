/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019b81c */

void FUN_0019b81c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (*(int *)(iVar1 + 0x100) != 0) {
    _IOFree(*(undefined4 *)(iVar1 + 0xc4),0x30000);
  }
  _IOFree(iVar1,0x104);
  _IOFree(param_1,0x20);
  return;
}

