/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a11fc */

int _PCsizeBIOSExtData(void)

{
  int iVar1;
  
  iVar1 = _bios_extdata_addr();
  return 0xa0000 - iVar1;
}

