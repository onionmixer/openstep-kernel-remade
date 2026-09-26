/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001073d0 */

undefined4 _getproc(void)

{
  undefined4 uVar1;
  
  if (DAT_001e56c0 < _max_proc) {
    DAT_001e56c0 = DAT_001e56c0 + 1;
    uVar1 = _zalloc(_proc_zone);
    return uVar1;
  }
  return 0;
}

