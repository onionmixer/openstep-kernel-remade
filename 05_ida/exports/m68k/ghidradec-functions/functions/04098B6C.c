
void _pmap_collect(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (param_1 != _kernel_pmap)) && (*(int *)(param_1 + 0x10) == 0)) {
    iVar2 = _m68k_pt1_elemsize * _m68k_pt1_entries;
    iVar1 = sub_4096FD0(_pt_zone);
    if (iVar1 != 0) {
      if (_active_threads != 0) {
        _pflush_user();
      }
      _pmap_remove_range(param_1,0,0xfffffffc);
      _bcopy(*(undefined4 *)(param_1 + 8),iVar1,iVar2);
      _bzero(*(undefined4 *)(param_1 + 8),iVar2);
      _pmap_free_maps(param_1,iVar1);
    }
  }
  return;
}
