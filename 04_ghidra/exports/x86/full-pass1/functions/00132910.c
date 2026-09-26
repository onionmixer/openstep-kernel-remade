/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00132910 */

int FUN_00132910(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_50;
  int local_4c;
  undefined4 local_48 [8];
  undefined1 local_28 [36];
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))(param_1,&local_4c);
  if (iVar1 == 0) {
    param_1 = local_4c;
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x30) + 0x40);
  puVar3 = local_48;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _setdiropargs(local_28,param_3,param_2);
  _rlock(*(undefined4 *)(param_2 + 0x30));
  iVar1 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x128),0xc,_xdr_linkargs,local_48,
                   _xdr_enum,&local_50,param_4);
  *(undefined4 *)(*(int *)(param_2 + 0x30) + 0xc0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc0) = 0;
  _runlock(*(undefined4 *)(param_2 + 0x30));
  if ((iVar1 == 0) && (iVar1 = local_50, local_50 == 0x46)) {
    _btrash(param_1);
    _nfs_invalidate_caches(param_1);
    _btrash(param_2);
    _nfs_invalidate_caches(param_2);
  }
  return iVar1;
}

