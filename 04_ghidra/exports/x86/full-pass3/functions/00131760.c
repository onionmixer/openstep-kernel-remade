/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131760 */

int _nfswrite(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_84;
  undefined1 local_80 [68];
  undefined4 local_3c [8];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  do {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x20);
    if (param_4 < iVar2) {
      iVar2 = param_4;
    }
    local_c = param_2;
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x30) + 0x40);
    puVar4 = local_3c;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    local_1c = param_3;
    local_18 = param_3;
    local_14 = iVar2;
    local_10 = iVar2;
    iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),8,_xdr_writeargs,local_3c,
                     _xdr_attrstat,&local_84,param_5);
    if ((iVar1 == 0) && (iVar1 = local_84, local_84 == 0x46)) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    param_4 = param_4 - iVar2;
    param_2 = param_2 + iVar2;
    param_3 = param_3 + iVar2;
    if (iVar1 != 0) goto LAB_00131823;
  } while (param_4 != 0);
  _nfs_attrcache(param_1,local_80);
LAB_00131823:
  if (iVar1 == 0x1c) {
    _printf(s_NFS_write_error__on_host__s_remo_001dcabc,
            *(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x34);
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else if (iVar1 == 0x45) {
      return 0x45;
    }
    _printf(s_NFS_write_error__d_on_host__s_fh_001dcaf1,iVar1,
            *(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x34);
    FUN_00131898(*(int *)(param_1 + 0x30) + 0x40);
    _printf(&DAT_001dcb13);
  }
  return iVar1;
}

