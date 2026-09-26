/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119a20 */

int _vfs_getmajor(undefined4 param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < (int)(_vfsNVFS + -0x1db640) >> 3; iVar1 = iVar1 + 1) {
    (&DAT_001e58c8)[iVar1 >> 3] =
         (&DAT_001e58c8)[iVar1 >> 3] | (byte)(1 << ((char)iVar1 + (char)(iVar1 >> 3) * -8 & 0x1fU));
  }
  iVar1 = _vfs_getnum(&DAT_001e58c8,0x10);
  if (iVar1 == -1) {
    iVar1 = _vfs_fixedmajor(param_1);
  }
  else {
    iVar1 = iVar1 + 0x80;
  }
  return iVar1;
}

