/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b600 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long _gethostid(void)

{
  long lVar1;
  
  lVar1 = DAT_001e875c;
  *(undefined4 *)(DAT_001e875c + 0x60) = _hostid;
  return lVar1;
}

