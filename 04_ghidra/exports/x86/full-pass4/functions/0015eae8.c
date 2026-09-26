/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015eae8 */

void _mfs_uncache(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x38) & 0x10) != 0) && (*(short *)(iVar1 + 4) == 0)) {
    _mfs_memfree(iVar1,0);
  }
  return;
}

