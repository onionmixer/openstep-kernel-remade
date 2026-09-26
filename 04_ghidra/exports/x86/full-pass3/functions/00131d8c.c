/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131d8c */

int FUN_00131d8c(int param_1)

{
  int iVar1;
  int iVar2;
  int local_2c;
  undefined1 local_28 [36];
  
  iVar2 = 0;
  iVar1 = *(int *)(param_1 + 0x30);
  _rp_rmhash(iVar1);
  if (*(int *)(iVar1 + 0x7c) != 0) {
    *(byte *)(iVar1 + 0x60) = *(byte *)(iVar1 + 0x60) & 0xef;
    _rlock(*(undefined4 *)(*(int *)(iVar1 + 0x7c) + 0x30));
    _setdiropargs(local_28,*(undefined4 *)(iVar1 + 0x78),*(undefined4 *)(iVar1 + 0x7c));
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x7c) + 0x24) + 0x128),10,
                     _xdr_diropargs,local_28,_xdr_enum,&local_2c,*(undefined4 *)(iVar1 + 0x74));
    if (iVar2 == 0) {
      iVar2 = local_2c;
    }
    _runlock(*(undefined4 *)(*(int *)(iVar1 + 0x7c) + 0x30));
    _vn_rele(*(undefined4 *)(iVar1 + 0x7c));
    *(undefined4 *)(iVar1 + 0x7c) = 0;
    _kfree(*(undefined4 *)(iVar1 + 0x78),0xff);
    *(undefined4 *)(iVar1 + 0x78) = 0;
    _crfree(*(undefined4 *)(iVar1 + 0x74));
    *(undefined4 *)(iVar1 + 0x74) = 0;
  }
  _rfree(iVar1);
  return iVar2;
}

