/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001956b0 */

int _destroyEventShmem(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    iVar1 = 4;
  }
  else {
    uVar3 = param_3 + _page_mask & ~_page_mask;
    uVar2 = 0;
    if (uVar3 != 0) {
      do {
        _pmap_remove(*(undefined4 *)(param_2 + 0x24),param_4 + uVar2,param_4 + uVar2 + _page_size);
        uVar2 = uVar2 + _page_size;
      } while (uVar2 < uVar3);
    }
    iVar1 = _vm_map_remove(param_2,param_4,param_4 + uVar3);
    if (iVar1 != 0) {
      _IOLog(s_destroyEventShmem__vm_map_remove_001e3765,iVar1);
    }
    _kmem_free(_kernel_map,param_5,uVar3);
    _vm_map_deallocate(param_2);
  }
  return iVar1;
}

