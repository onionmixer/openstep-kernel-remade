/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125c80 */

int _ifptoia(int param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 0x20) == param_1) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}

