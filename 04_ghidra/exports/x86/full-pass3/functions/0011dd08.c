/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dd08 */

int _fsync(int param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  iVar1 = _getvnodefp(**(undefined4 **)(DAT_001e875c + 0x24),&local_8);
  if (iVar1 == 0) {
    iVar1 = _mfs_fsync(*(undefined4 *)(local_8 + 0x18));
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(local_8 + 0x18) + 0x1c) + 0x48))
                        (*(int *)(local_8 + 0x18),*(undefined4 *)(local_8 + 0x20));
    }
  }
  iVar2 = DAT_001e875c;
  *(char *)(DAT_001e875c + 0x68) = (char)iVar1;
  return iVar2;
}

