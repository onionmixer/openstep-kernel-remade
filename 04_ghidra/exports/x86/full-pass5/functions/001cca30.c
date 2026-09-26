/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cca30 */

uint __mapStrHash(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    while (bVar1 != 0) {
      if (param_2[1] == 0) {
        return uVar2 ^ *param_2;
      }
      uVar2 = uVar2 ^ *param_2 ^ (uint)param_2[1] << 8;
      if (param_2[2] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[2] << 0x10;
      if (param_2[3] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[3] << 0x18;
      param_2 = param_2 + 4;
      bVar1 = *param_2;
    }
  }
  return uVar2;
}

