
undefined4 _vnode_pager_setup(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 != 0) {
    *(word *)(param_1 + 1) = *(word *)(param_1 + 1) | 2;
  }
  if (*(int *)*param_1 == 0) {
    puVar2 = dword_40B4DF4;
    if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
      do {
        if (param_1 == (undefined4 *)puVar2[2]) {
          return 0;
        }
        puVar2 = (undefined4 *)*puVar2;
      } while ((undefined4 **)puVar2 != &dword_40B4DF4);
    }
    _vnode_pager_create(param_1);
    if (param_3 != 0) {
      uVar1 = _vm_object_lookup(*(undefined4 *)*param_1,1);
      _vm_object_cache_object(uVar1);
    }
  }
  uVar1 = _zalloc(_vstruct_zone);
  _zfree(_vstruct_zone,uVar1);
  return *(undefined4 *)*param_1;
}

