
undefined4 _vm_pager_get(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    _vm_page_zero_fill(param_2);
    uVar1 = 0;
  }
  else {
    if (*param_1 != 0) {
                    /* WARNING: Subroutine does not return */
      _device_pagein(param_2);
    }
    uVar1 = _vnode_pagein(param_2,param_3);
  }
  return uVar1;
}

