/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cec5c */

uint FUN_001cec5c(undefined4 param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  pbVar2 = *(byte **)(param_2 + 8);
  uVar1 = 0;
  while( true ) {
    if (*pbVar2 == 0) {
      return uVar1;
    }
    if (pbVar2[1] == 0) {
      return uVar1 ^ *pbVar2;
    }
    uVar1 = uVar1 ^ *pbVar2 ^ (uint)pbVar2[1] << 8;
    if (pbVar2[2] == 0) {
      return uVar1;
    }
    uVar1 = uVar1 ^ (uint)pbVar2[2] << 0x10;
    if (pbVar2[3] == 0) break;
    uVar1 = uVar1 ^ (uint)pbVar2[3] << 0x18;
    pbVar2 = pbVar2 + 4;
  }
  return uVar1;
}

