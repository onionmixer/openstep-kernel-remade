/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab654 */

void FUN_001ab654(int param_1,undefined4 param_2,byte param_3)

{
  *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) & 0xfe | param_3 & 1;
  return;
}

