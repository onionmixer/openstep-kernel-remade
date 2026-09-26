/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9e18 */

int _IOAddToVfsswAt(int param_1,undefined *param_2,undefined *param_3)

{
  if ((((param_1 < 0) || ((int)(_vfsNVFS + -0x1db640) >> 3 <= param_1)) ||
      ((&_vfssw)[param_1 * 2] != (undefined *)0x0)) ||
     ((&PTR__ufs_vfsops_001db644)[param_1 * 2] != (undefined *)0x0)) {
    param_1 = -1;
  }
  else {
    (&_vfssw)[param_1 * 2] = param_2;
    (&PTR__ufs_vfsops_001db644)[param_1 * 2] = param_3;
  }
  return param_1;
}

