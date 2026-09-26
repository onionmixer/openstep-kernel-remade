/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119a94 */

int _vfs_fixedmajor(int param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = &_vfssw;
  if (&_vfssw < _vfsNVFS) {
    do {
      if (ppuVar1[1] == *(undefined **)(param_1 + 4)) break;
      ppuVar1 = ppuVar1 + 2;
    } while (ppuVar1 < _vfsNVFS);
  }
  return ((int)(ppuVar1 + -0x76d90) >> 3) + 0x80;
}

