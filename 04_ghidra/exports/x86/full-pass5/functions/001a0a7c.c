/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0a7c */

void FUN_001a0a7c(int param_1,undefined4 param_2,int param_3)

{
  *(int *)(param_1 + 0x134) = param_3;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x134) = 0x48;
  }
  *(int *)(param_1 + 0x138) = (int)(0x4800 / (ulonglong)*(uint *)(param_1 + 0x134));
  return;
}

