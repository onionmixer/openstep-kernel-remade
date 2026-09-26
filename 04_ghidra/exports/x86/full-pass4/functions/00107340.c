/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107340 */

undefined4 _inferior(int param_1)

{
  while( true ) {
    if (param_1 == *_active_u) {
      return 1;
    }
    if (*(short *)(param_1 + 0x32) == 0) break;
    param_1 = *(int *)(param_1 + 0x44);
  }
  return 0;
}

