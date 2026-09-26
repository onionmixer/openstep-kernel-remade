/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018414c */

undefined4 FUN_0018414c(byte param_1)

{
  if (param_1 >> 3 < 0x11) {
    return *(undefined4 *)(&DAT_001e7324 + (uint)(param_1 >> 3) * 0x24);
  }
  return 0;
}

