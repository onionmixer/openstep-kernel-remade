/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001beb1c */

undefined4 FUN_001beb1c(int *param_1,int *param_2)

{
  if (*(short *)(*param_2 + 2) < *(short *)(*param_1 + 2)) {
    return 1;
  }
  if (*(short *)(*param_1 + 2) != *(short *)(*param_2 + 2)) {
    return 0xffffffff;
  }
  return 0;
}

