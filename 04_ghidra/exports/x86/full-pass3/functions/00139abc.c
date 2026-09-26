/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139abc */

void _smark(int param_1,ushort param_2)

{
  undefined4 local_c;
  undefined4 local_8;
  
  _microtime(&local_c);
  *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | param_2;
  if ((param_2 & 4) != 0) {
    *(undefined4 *)(param_1 + 0x4c) = local_c;
    *(undefined4 *)(param_1 + 0x50) = local_8;
  }
  if ((param_2 & 2) != 0) {
    *(undefined4 *)(param_1 + 0x54) = local_c;
    *(undefined4 *)(param_1 + 0x58) = local_8;
  }
  if ((param_2 & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x5c) = local_c;
    *(undefined4 *)(param_1 + 0x60) = local_8;
  }
  return;
}

