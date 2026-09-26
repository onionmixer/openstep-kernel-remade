
int _nfs_getattr_otw(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(0x48);
  iVar2 = _rfscall(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x126),1,_xdr_fhandle,
                   *(int *)(param_1 + 0x2e) + 0x3e,_xdr_attrstat,piVar1,param_3);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      _nattr_to_vattr(param_1,piVar1 + 1,param_2);
      *(uint *)(param_2 + 10) =
           *(uint *)(*(int *)(*(int *)(param_1 + 0x24) + 0x126) + 0x26) | 0xff00;
    }
    else if (iVar2 == 0x46) {
      _btrash(param_1);
      _nfs_invalidate_caches(param_1);
    }
  }
  _kfree(piVar1,0x48);
  return iVar2;
}
