
void _vm_info_free(undefined4 *param_1)

{
  _mfs_uncache(param_1);
  _zfree(_vm_info_zone,*param_1);
  return;
}
