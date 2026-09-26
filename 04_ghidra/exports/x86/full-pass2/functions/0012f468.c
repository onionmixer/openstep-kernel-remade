/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f468 */

uint _setdirmode(int param_1,uint param_2)

{
  param_2 = param_2 & 0xfffffbff;
  if ((*(byte *)(*(int *)(param_1 + 0x30) + 0x85) & 4) != 0) {
    param_2 = param_2 | 0x400;
  }
  return param_2;
}

