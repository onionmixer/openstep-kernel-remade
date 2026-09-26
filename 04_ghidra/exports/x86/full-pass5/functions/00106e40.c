/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106e40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getpagesize(void)

{
  int iVar1;
  
  iVar1 = DAT_001e875c;
  *(undefined4 *)(DAT_001e875c + 0x60) = _page_size;
  return iVar1;
}

