/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111180 */

undefined4 _ttcheckwakeup(int *param_1)

{
  if ((((*(byte *)((int *)*param_1 + 0xf) & 0x22) != 0) &&
      (*(int *)*param_1 < (int)(uint)*(byte *)((int)param_1 + 0x15))) &&
     (*(char *)((int)param_1 + 0x16) == '\0')) {
    return 0;
  }
  return 1;
}

