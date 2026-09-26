/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b098 */

undefined4 _canSwap(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 & ~_page_mask;
  iVar1 = 0;
  if (0 < DAT_001e5ba4) {
    do {
      if (*(int *)(param_1 + 8) == 2) {
        return 0;
      }
      param_1 = param_1 + DAT_001e5ba0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_001e5ba4);
  }
  return 1;
}

