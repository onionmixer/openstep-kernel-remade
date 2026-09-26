/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119794 */

int _vfs_add(int param_1,undefined4 *param_2,ushort param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _vfs_lock(param_2);
  if (iVar2 == 0) {
    if (param_1 == 0) {
      _rootvfs = param_2;
      *param_2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0) {
        _vfs_unlock(param_2);
        return 0x10;
      }
      if ((short)param_3 < 0) {
        param_2[0x48] = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = param_2;
        _microtime(param_1 + 0x14);
      }
      else {
        *(undefined4 **)(param_1 + 0xc) = param_2;
      }
      puVar1 = _rootvfs;
      *param_2 = *_rootvfs;
      *puVar1 = param_2;
    }
    param_2[2] = param_1;
    if ((param_3 & 1) == 0) {
      param_2[3] = param_2[3] & 0xfffffffe;
    }
    else {
      *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 1;
    }
    if ((param_3 & 2) == 0) {
      param_2[3] = param_2[3] & 0xfffffff7;
    }
    else {
      *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 8;
    }
    if ((param_3 & 8) == 0) {
      param_2[3] = param_2[3] & 0xffffffef;
    }
    else {
      *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x10;
    }
    if ((param_3 & 0x20) == 0) {
      param_2[3] = param_2[3] & 0xffffffdf;
    }
    else {
      *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) | 0x20;
    }
    param_2[3] = param_2[3] & 0xffffff7f;
    iVar2 = 0;
  }
  return iVar2;
}

