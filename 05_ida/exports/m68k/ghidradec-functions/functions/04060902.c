
void _vm_pager_deallocate(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPagerDealloc);
  }
  if (*param_1 == 0) {
    _vnode_dealloc(param_1);
  }
  else {
    _device_dealloc(param_1);
  }
  return;
}
