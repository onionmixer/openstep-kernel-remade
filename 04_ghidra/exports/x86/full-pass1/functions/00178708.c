/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178708 */

kern_return_t
_vm_move(undefined4 param_1,uint param_2,vm_map_t param_3,int param_4,undefined4 param_5,
        int *param_6)

{
  kern_return_t kVar1;
  vm_size_t size;
  uint uVar2;
  vm_address_t local_8;
  
  if (param_4 == 0) {
    *param_6 = 0;
    kVar1 = 0;
  }
  else {
    uVar2 = param_2 & ~_page_mask;
    size = (param_4 + param_2 + _page_mask & ~_page_mask) - uVar2;
    local_8 = 0;
    kVar1 = _vm_allocate(param_3,&local_8,size,1);
    if (kVar1 == 0) {
      kVar1 = _vm_map_copy(param_3,param_1,local_8,size,uVar2,0,param_5);
      if (kVar1 == 0) {
        *param_6 = (param_2 - uVar2) + local_8;
      }
      else {
        _vm_deallocate(param_3,local_8,size);
      }
    }
  }
  return kVar1;
}

