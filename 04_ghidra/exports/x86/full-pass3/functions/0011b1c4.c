/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b1c4 */

int _geterror(byte *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (((*param_1 & 4) != 0) && (iVar1 = (int)*(short *)(param_1 + 0x1c), iVar1 == 0)) {
    return 5;
  }
  return iVar1;
}

