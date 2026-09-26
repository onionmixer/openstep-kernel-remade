/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107374 */

int _pfind(uint param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&_pidhash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if ((int)*(short *)(iVar1 + 0x30) == param_1) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}

