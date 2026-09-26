/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c004 */

undefined4 _unix_pid(int param_1,int *param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x3c) != 0)) {
    *param_2 = (int)*(short *)(*(int *)(param_1 + 0x3c) + 0x30);
    return 0;
  }
  *param_2 = -1;
  return 5;
}

