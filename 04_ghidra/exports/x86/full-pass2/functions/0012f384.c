/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f384 */

void _vattr_to_sattr(int param_1,uint *param_2)

{
  if (*(ushort *)(param_1 + 4) == 0xffff) {
    *param_2 = 0xffffffff;
  }
  else {
    *param_2 = (uint)*(ushort *)(param_1 + 4);
  }
  if (*(short *)(param_1 + 6) == -1) {
    param_2[1] = 0xffffffff;
  }
  else {
    param_2[1] = (int)*(short *)(param_1 + 6);
  }
  if (*(short *)(param_1 + 8) == -1) {
    param_2[2] = 0xffffffff;
  }
  else {
    param_2[2] = (int)*(short *)(param_1 + 8);
  }
  param_2[3] = *(uint *)(param_1 + 0x18);
  param_2[4] = *(uint *)(param_1 + 0x20);
  param_2[5] = *(uint *)(param_1 + 0x24);
  param_2[6] = *(uint *)(param_1 + 0x28);
  param_2[7] = *(uint *)(param_1 + 0x2c);
  return;
}

