/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132f68 */

int FUN_00132f68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int local_50;
  undefined1 local_4c [36];
  undefined4 local_28;
  undefined1 local_24 [32];
  
  _setdiropargs(local_4c,param_2,param_1);
  _vattr_to_sattr(param_3,local_24);
  local_28 = param_4;
  iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0xd,_xdr_slargs,local_4c,
                   _xdr_enum,&local_50,param_5);
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  if ((iVar1 == 0) && (iVar1 = local_50, local_50 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
  }
  return iVar1;
}

