/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b270c */

int FUN_001b270c(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x1d3) != '\x01') ||
     (iVar1 = *(int *)(param_1 + 0x1c8), *(int *)(param_1 + 0x1cc) <= iVar1)) {
    iVar1 = *(int *)(param_1 + 0x1cc);
  }
  return iVar1;
}

