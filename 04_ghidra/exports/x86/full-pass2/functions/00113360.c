/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113360 */

uint _nextc(int *param_1,int param_2)

{
  uint uVar1;
  
  if ((*param_1 != 0) && (uVar1 = param_2 + 1, param_1[2] != uVar1)) {
    if ((uVar1 & 0x3f) == 0) {
      return *(int *)(param_2 + -0x3f) + 0xc;
    }
    return uVar1;
  }
  return 0;
}

