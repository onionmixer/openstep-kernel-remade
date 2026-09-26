/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001318d4 */

int FUN_001318d4(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 param_6,
                undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_ac;
  undefined4 local_a8 [8];
  int local_88;
  undefined1 local_84 [68];
  int local_40;
  int local_3c;
  undefined4 local_30 [8];
  int local_10;
  int local_c;
  int local_8;
  
  while( true ) {
    local_ac = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x1c);
    if (param_4 < local_ac) {
      local_ac = param_4;
    }
    local_3c = param_2;
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x30) + 0x40);
    puVar5 = local_30;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    local_10 = param_3;
    local_8 = local_ac;
    local_c = local_ac;
    iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),6,_xdr_readargs,local_30,
                     _xdr_rdresult,&local_88,param_6);
    iVar2 = local_88;
    if (iVar1 != 0) break;
    if (local_88 == 0x46) {
      _printf(s_NFS_read_error_ESTALE_to_host__1_001dcb19,
              *(int *)(*(int *)(param_1 + 0x24) + 0x128) + 0x34);
      _bcopy((void *)(*(int *)(param_1 + 0x30) + 0x40),local_a8,0x20);
      uVar3 = 0;
      do {
        _printf((char *)&PTR_DAT_001dcb15,local_a8[uVar3]);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
      _printf(&DAT_001dcb40);
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
    iVar1 = iVar2;
    if (iVar2 != 0) break;
    param_4 = param_4 - local_40;
    param_2 = param_2 + local_40;
    param_3 = param_3 + local_40;
    if ((param_4 == 0) || (local_ac != local_40)) break;
  }
  *param_5 = param_4;
  if (iVar1 == 0) {
    _nattr_to_vattr(param_1,local_84,param_7);
  }
  return iVar1;
}

