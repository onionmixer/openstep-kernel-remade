/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132ff8 */

int FUN_00132ff8(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_44 [4];
  int local_40;
  int local_3c;
  size_t local_38;
  int local_34;
  void *local_30;
  undefined1 local_2c [32];
  int local_c;
  size_t local_8;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (((*(byte *)(iVar1 + 0x60) & 8) == 0) || (*(int *)(iVar1 + 0x98) != param_2[2])) {
    if (param_2[1] == 1) {
      uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x1c);
      if (*(uint *)(*param_2 + 4) < uVar3) {
        uVar3 = *(uint *)(*param_2 + 4);
      }
      local_c = param_2[2];
      local_8 = uVar3;
      _bcopy((void *)(*(int *)(param_1 + 0x30) + 0x40),local_2c,0x20);
      local_38 = uVar3;
      local_30 = (void *)_kalloc(uVar3);
      _bzero(local_30,uVar3);
      iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0x10,_xdr_rddirargs,
                       local_2c,_xdr_getrddirres,local_44,param_3);
      if (iVar2 == 0) {
        if (local_40 == 0x46) {
          _btrash(param_1);
          _nfs_invalidate_caches(param_1);
        }
        iVar2 = local_40;
        if (local_40 == 0) {
          if (local_38 != 0) {
            local_40 = _uiomove(local_30,local_38,0,param_2);
            local_c = local_3c;
            param_2[2] = local_3c;
          }
          iVar2 = local_40;
          if (local_34 != 0) {
            *(byte *)(iVar1 + 0x60) = *(byte *)(iVar1 + 0x60) | 8;
            *(int *)(iVar1 + 0x98) = param_2[2];
          }
        }
      }
      _kfree(local_30,uVar3);
    }
    else {
      iVar2 = 0x16;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

