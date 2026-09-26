/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001180e8 */

int _getsock(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _getf(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(short *)(iVar1 + 0xc) != 2) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x26;
    iVar1 = 0;
  }
  return iVar1;
}

