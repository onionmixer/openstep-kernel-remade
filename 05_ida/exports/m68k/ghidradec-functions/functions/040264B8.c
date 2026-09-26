
int _nfsgetattr(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = sub_402637E(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = _nfs_getattr_otw(param_1,param_2,param_3);
    if (iVar1 == 0) {
      _nfs_cache_check(param_1,*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x28),
                       *(undefined4 *)(param_2 + 0x14),param_4);
      _nfs_attrcache_va(param_1,param_2);
    }
  }
  else {
    iVar1 = 0;
  }
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x2e) + 0x90);
  return iVar1;
}
