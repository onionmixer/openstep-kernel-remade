/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6b80 */

undefined4 FUN_001b6b80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x174);
  if (*(char *)(iVar1 + 0x10) != '\0') {
    return 0x1e;
  }
  if (((*(char *)(iVar1 + 0x11) == '\0') && (*(char *)(iVar1 + 0x12) == '\0')) &&
     (*(char *)(iVar1 + 0x13) == '\0')) {
    if (*(char *)(iVar1 + 0x14) == '\0') {
      return 0;
    }
    return 0x22;
  }
  return 0x21;
}

