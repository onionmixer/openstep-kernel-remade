/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e474 */

int _vn_close(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[10] == 1) {
    _unmap_vnode(param_1);
  }
  iVar1 = (**(code **)(param_1[7] + 4))(param_1,param_2,param_3,*(undefined4 *)(_active_u + 0x1c));
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 0x34), iVar3 != 0)) {
    *(undefined4 *)(iVar2 + 0x34) = 0;
    *(char *)(DAT_001e875c + 0x68) = (char)iVar3;
    do {
      iVar2 = _fspause(param_2 & 0x1000);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = *(int *)(*param_1 + 0x34);
      *(undefined4 *)(*param_1 + 0x34) = 0;
      *(char *)(DAT_001e875c + 0x68) = (char)iVar3;
      _mfs_fsync(param_1);
      iVar1 = 0;
    } while (iVar3 != 0);
  }
  return iVar1;
}

