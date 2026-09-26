/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bda48 */

uint _checksum16(ushort *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = uVar1 + (ushort)(*param_1 >> 8 | *param_1 << 8);
    param_1 = param_1 + 1;
  }
  uVar1 = (uVar1 & 0xffff) + (uVar1 >> 0x10);
  if (0xffff < uVar1) {
    uVar1 = uVar1 - 0xffff;
  }
  return uVar1 & 0xffff;
}

