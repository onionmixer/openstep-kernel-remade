/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a19e8 */

void FUN_001a19e8(int param_1)

{
  if ((*(byte *)(param_1 + 0x7c) & 4) != 0) {
    *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) | 4;
    *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xfffffffb;
  }
  return;
}

