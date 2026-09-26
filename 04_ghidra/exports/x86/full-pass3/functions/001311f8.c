/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001311f8 */

int FUN_001311f8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_44 [24];
  undefined4 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = 0;
  if ((_nfs_cto != 0) ||
     ((*(byte *)(*(int *)(*(int *)(*param_1 + 0x24) + 0x128) + 0x14) & 0x20) == 0)) {
    iVar1 = _nfs_getattr_otw(*param_1,local_44,param_3);
    if (iVar1 == 0) {
      _nfs_cache_check(*param_1,local_1c,local_18,local_2c,0);
      _nfs_attrcache_va(*param_1,local_44);
    }
    else if (iVar1 == 0x46) {
      *(undefined1 *)(DAT_001e875c + 0x69) = 2;
    }
  }
  return iVar1;
}

