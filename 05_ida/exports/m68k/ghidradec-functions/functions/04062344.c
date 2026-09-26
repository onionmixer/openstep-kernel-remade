
int _vm_allocate_with_pager
              (int param_1,uint *param_2,int param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar2 = 4;
  }
  else {
    *param_2 = ~_page_mask & *param_2;
    uVar1 = ~_page_mask & _page_mask + param_3;
    _lock_write(&_vm_alloc_lock);
    iVar3 = _vm_object_lookup(param_5);
    dword_40C240C = dword_40C240C + 1;
    if (iVar3 == 0) {
      iVar3 = _vm_object_allocate(uVar1);
      if (param_5 != 0) {
        _vm_object_setpager(iVar3,param_5,0,1);
        _vm_object_enter(iVar3,param_5);
      }
    }
    else {
      dword_40C2410 = dword_40C2410 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    *(byte *)(iVar3 + 0x42) = *(byte *)(iVar3 + 0x42) & 0xf7;
    iVar2 = _vm_map_find(param_1,iVar3,param_6,param_2,uVar1,param_4);
    if (iVar2 != 0) {
      _vm_object_deallocate(iVar3);
    }
  }
  return iVar2;
}
