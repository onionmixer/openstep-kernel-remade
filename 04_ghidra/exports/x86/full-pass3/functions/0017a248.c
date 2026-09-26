/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a248 */

undefined4 _vm_pager_get(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    _vm_page_zero_fill(param_2);
    return 0;
  }
  if (*param_1 != 0) {
    uVar1 = _device_pagein(param_2);
    return uVar1;
  }
  uVar1 = _vnode_pagein(param_2,param_3);
  return uVar1;
}

