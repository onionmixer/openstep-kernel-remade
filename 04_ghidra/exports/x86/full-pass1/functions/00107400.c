/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107400 */

void _proc_cache_clear(void)

{
  int iVar1;
  
  iVar1 = _freeproc;
  while (iVar1 != 0) {
    DAT_001e56c0 = DAT_001e56c0 + -1;
    _freeproc = *(int *)(iVar1 + 8);
    _zfree(_proc_zone,iVar1);
    iVar1 = _freeproc;
  }
  _freeproc = iVar1;
  return;
}

