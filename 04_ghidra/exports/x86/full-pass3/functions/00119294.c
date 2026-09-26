/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119294 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _sync(void)

{
  undefined **ppuVar1;
  
  _mfs_sync();
  ppuVar1 = &_vfssw;
  if (&_vfssw < _vfsNVFS) {
    do {
      if (ppuVar1[1] != (undefined *)0x0) {
        (**(code **)(ppuVar1[1] + 0x10))(0);
      }
      ppuVar1 = ppuVar1 + 2;
    } while (ppuVar1 < _vfsNVFS);
  }
  return;
}

