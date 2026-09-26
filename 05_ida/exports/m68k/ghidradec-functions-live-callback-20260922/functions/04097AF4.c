
void _pmap_destroy(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) &&
     (iVar1 = *(int *)(param_1 + 0xc), *(int *)(param_1 + 0xc) = iVar1 + -1, iVar1 == 1)) {
    _pmap_free_maps(param_1,*(undefined4 *)(param_1 + 8));
    _zfree(_pmap_zone,param_1);
  }
  return;
}

