/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132ed8 */

int FUN_00132ed8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_2c;
  undefined1 local_28 [36];
  
  _setdiropargs(local_28,param_2,param_1);
  _rlock(*(undefined4 *)(param_1 + 0x30));
  _dnlc_purge_vp(param_1);
  iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0xf,_xdr_diropargs,local_28,
                   _xdr_enum,&local_2c,param_3);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_1 + 0x30));
  if ((iVar1 == 0) && (iVar1 = local_2c, local_2c == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
  }
  return iVar1;
}

