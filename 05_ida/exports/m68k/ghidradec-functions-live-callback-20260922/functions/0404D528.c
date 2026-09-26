
void _mfs_get(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  _vmp_get(iVar1);
  if (_mfs_max_window < param_3) {
    param_3 = _mfs_max_window;
  }
  if (*(uint *)(iVar1 + 0xc) < param_3) {
    _remap_vnode(param_1,param_2,param_3);
  }
  return;
}

