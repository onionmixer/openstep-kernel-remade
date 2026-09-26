/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001877f8 */

uint _checksum_16(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 + (ushort)(uVar1 >> 8 | uVar1 << 8);
  }
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  if (0xffff < uVar2) {
    uVar2 = uVar2 - 0xffff;
  }
  return uVar2 & 0xffff;
}

