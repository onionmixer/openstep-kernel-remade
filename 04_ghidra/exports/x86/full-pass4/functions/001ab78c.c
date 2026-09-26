/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab78c */

void FUN_001ab78c(int param_1)

{
  if ((*(int *)(param_1 + 0x158) != 0) || (*(int *)(param_1 + 0x15c) != 0)) {
    _ns_untimeout(FUN_001aaea0,param_1);
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  return;
}

