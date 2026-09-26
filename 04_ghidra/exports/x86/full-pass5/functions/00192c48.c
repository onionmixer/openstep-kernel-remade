/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192c48 */

void _byte_swap_shorts(ushort *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      *param_1 = *param_1 >> 8 | *param_1 << 8;
      param_1 = param_1 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return;
}

