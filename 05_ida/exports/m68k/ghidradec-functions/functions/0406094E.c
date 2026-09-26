
void _vm_pager_has_page(int *param_1,undefined4 param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    _vnode_has_page(param_1,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmPagerHasPage);
}
