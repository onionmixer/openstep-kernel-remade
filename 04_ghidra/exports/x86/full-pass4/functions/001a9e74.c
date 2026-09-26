/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9e74 */

int _IOAddToVfssw(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  ppuVar2 = &_vfssw;
  iVar3 = 0;
  if (&_vfssw < _vfsNVFS) {
    iVar1 = 0;
    do {
      if ((*ppuVar2 == (undefined *)0x0) && (ppuVar2[1] == (undefined *)0x0)) {
        if (iVar3 < 0) {
          return -1;
        }
        if ((int)(_vfsNVFS + -0x1db640) >> 3 <= iVar3) {
          return -1;
        }
        if (*(int *)((int)&_vfssw + iVar1) != 0) {
          return -1;
        }
        if (*(int *)((int)&PTR__ufs_vfsops_001db644 + iVar1) != 0) {
          return -1;
        }
        *(undefined4 *)((int)&_vfssw + iVar1) = param_1;
        *(undefined4 *)((int)&PTR__ufs_vfsops_001db644 + iVar1) = param_2;
        return iVar3;
      }
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 2;
    } while (ppuVar2 < _vfsNVFS);
  }
  return -1;
}

