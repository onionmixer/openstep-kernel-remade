/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c4f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _vm_allocate_with_pager
              (int param_1,uint *param_2,int param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    iVar1 = 4;
  }
  else {
    *param_2 = *param_2 & ~_page_mask;
    uVar3 = _page_mask + param_3 & ~_page_mask;
    _lock_write(&_vm_alloc_lock);
    iVar2 = _vm_object_lookup(param_5);
    _DAT_001f651c = _DAT_001f651c + 1;
    if (iVar2 == 0) {
      iVar2 = _vm_object_allocate(uVar3);
      if (param_5 != 0) {
        _vm_object_setpager(iVar2,param_5,0,1);
        _vm_object_enter(iVar2,param_5);
      }
    }
    else {
      _DAT_001f6520 = _DAT_001f6520 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    *(byte *)(iVar2 + 0x46) = *(byte *)(iVar2 + 0x46) & 0xef;
    iVar1 = _vm_map_find(param_1,iVar2,param_6,param_2,uVar3,param_4);
    if (iVar1 != 0) {
      _vm_object_deallocate(iVar2);
    }
  }
  return iVar1;
}

