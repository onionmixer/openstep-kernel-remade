/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b644 */

undefined4 FUN_0013b644(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(param_1 + 0x30) + 0x78);
  if (cVar1 != '\0') {
    *(char *)(*(int *)(param_1 + 0x30) + 0x78) = cVar1 + -1;
  }
  return 0;
}

