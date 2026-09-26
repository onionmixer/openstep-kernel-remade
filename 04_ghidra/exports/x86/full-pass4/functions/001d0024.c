/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d0024 */

uint __strhash(byte *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return uVar1;
    }
    if (param_1[1] == 0) {
      return uVar1 ^ *param_1;
    }
    uVar1 = uVar1 ^ *param_1 ^ (uint)param_1[1] << 8;
    if (param_1[2] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)param_1[2] << 0x10;
    if (param_1[3] == 0) break;
    uVar1 = uVar1 ^ (uint)param_1[3] << 0x18;
    param_1 = param_1 + 4;
  }
  return uVar1;
}

