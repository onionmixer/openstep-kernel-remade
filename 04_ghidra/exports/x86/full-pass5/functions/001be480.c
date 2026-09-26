/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be480 */

void _audio_convertLinear8ToLinear16(byte *param_1,short *param_2,int param_3)

{
  while (param_3 = param_3 + -1, param_3 != -1) {
    *param_2 = (ushort)*param_1 << 8;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}

