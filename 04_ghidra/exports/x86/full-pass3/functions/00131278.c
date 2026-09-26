/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131278 */

int FUN_00131278(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (param_3 < 2) {
    iVar1 = *(int *)(param_1 + 0x30);
    if ((*(int *)(iVar1 + 0x7c) == 0) && (*(short *)(iVar1 + 0x62) == 0)) {
      if ((param_2 & 2) == 0) {
        return 0;
      }
      if ((_nfs_cto != 0) ||
         ((*(byte *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x14) & 0x20) == 0)) {
        _sync_vp(param_1);
      }
    }
    else {
      _sync_vp(param_1);
      _nfs_purge_caches(param_1,param_2);
    }
    if ((param_2 & 2) != 0) {
      return (int)*(short *)(iVar1 + 0x62);
    }
  }
  return 0;
}

