/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001236a4 */

undefined4 _in_canforward(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << 0x18;
  if (((uVar1 & 0xe0000000) != 0xe0000000) &&
     (((int)(param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | uVar1) < 0 ||
      ((uVar1 != 0 && (uVar1 != 0x7f)))))) {
    return 1;
  }
  return 0;
}

