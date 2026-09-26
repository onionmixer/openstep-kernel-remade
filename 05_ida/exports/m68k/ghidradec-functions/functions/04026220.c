
void _nfs_cache_check(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((-1 < *(char *)(iVar1 + 0x11)) &&
     (((param_2 != *(int *)(iVar1 + 0xa0) || (param_3 != *(int *)(iVar1 + 0xa4))) ||
      (param_4 != *(int *)(iVar1 + 0x90))))) {
    _nfs_purge_caches(param_1,param_5);
  }
  return;
}
