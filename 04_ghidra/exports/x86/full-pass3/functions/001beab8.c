/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001beab8 */

undefined1 _audio_shortToMulaw(short param_1)

{
  param_1 = param_1 >> 2;
  if (0x1fff < param_1) {
    return DAT_001e53cc[0x3fff];
  }
  if (-0x2001 < param_1) {
    return DAT_001e53cc[param_1 + 0x2000];
  }
  return *DAT_001e53cc;
}

