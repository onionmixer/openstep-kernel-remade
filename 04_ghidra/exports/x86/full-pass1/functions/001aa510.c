/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa510 */

void FUN_001aa510(int param_1)

{
  if ((*(int *)(param_1 + 0x130) != 0) || (*(int *)(param_1 + 0x134) != 0)) {
    _ns_untimeout(FUN_001a9f1c,param_1);
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0;
  }
  return;
}

