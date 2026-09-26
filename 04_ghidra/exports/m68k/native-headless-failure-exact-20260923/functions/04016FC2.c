
undefined ** _vfssw_lookup(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &_vfssw;
  if (&_vfssw < _vfsNVFS) {
    do {
      iVar1 = _strcmp(param_1,*ppuVar2);
      if (iVar1 == 0) {
        return ppuVar2;
      }
      ppuVar2 = ppuVar2 + 2;
    } while (ppuVar2 < _vfsNVFS);
  }
  return (undefined **)0x0;
}

