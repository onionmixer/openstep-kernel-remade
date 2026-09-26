
undefined4 _vnode_alloc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _vswap_allocate();
  if (iVar1 != 0) {
    uVar2 = _pagerfile_pager_create(iVar1,param_1);
  }
  return uVar2;
}
