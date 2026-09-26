/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131cb0 */

int FUN_00131cb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x28) == 5) {
    local_8 = _kalloc(0x400);
    iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),5,_xdr_fhandle,
                     *(int *)(param_1 + 0x30) + 0x40,_xdr_rdlnres,&local_10,param_3);
    if (iVar1 == 0) {
      if (local_10 == 0) {
        iVar1 = _uiomove(local_8,local_c,0,param_2);
      }
      else {
        iVar1 = local_10;
        if (local_10 == 0x46) {
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
        }
      }
    }
    _kfree(local_8,0x400);
  }
  else {
    iVar1 = 6;
  }
  return iVar1;
}

