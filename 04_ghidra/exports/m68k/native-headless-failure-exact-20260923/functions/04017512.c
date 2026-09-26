
int _vfs_fixedmajor(int param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = &_vfssw;
  if (&_vfssw < _vfsNVFS) {
    do {
      if (*(undefined **)(param_1 + 4) == ppuVar1[1]) break;
      ppuVar1 = ppuVar1 + 2;
    } while (ppuVar1 < _vfsNVFS);
  }
  return ((int)((int)ppuVar1 + -0x40ae796) >> 3) + 0x80;
}

