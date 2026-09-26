
void _vm_pager_put(int *param_1,undefined4 param_2)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPagerPutNull);
  }
  if (*param_1 == 0) {
    _vnode_pageout(param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _device_pageout(param_2);
}
