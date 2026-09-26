/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001caebc */

int FUN_001caebc(uint param_1)

{
  int iVar1;
  
  if (1 < param_1) {
    iVar1 = FUN_001caebc(param_1 >> 1);
    return iVar1 + 1;
  }
  return 0;
}

