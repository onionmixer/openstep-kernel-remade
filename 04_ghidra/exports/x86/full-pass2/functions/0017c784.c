/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c784 */

kern_return_t
_vm_read(vm_map_t target_task,vm_address_t address,vm_size_t size,vm_offset_t *data,
        mach_msg_type_number_t *dataCnt)

{
  kern_return_t kVar1;
  int local_10;
  uint local_8;
  
  if (((_page_mask + address & ~_page_mask) != address) ||
     ((_page_mask + size & ~_page_mask) != size)) {
    return 4;
  }
  if (_ipc_soft_map == 0) {
    local_10 = 4;
LAB_0017c802:
    _printf(s_vm_read__kernel_error__d_001e0e3d,local_10);
    kVar1 = 6;
  }
  else {
    if (size == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(uint *)(_ipc_soft_map + 0x14);
      local_10 = _vm_map_find(_ipc_soft_map,0,0,&local_8,size,1);
      if (local_10 != 0) goto LAB_0017c802;
    }
    kVar1 = _vm_map_copy(_ipc_soft_map,target_task,local_8,size,address,0,0);
    if (kVar1 == 0) {
      *data = local_8;
      *dataCnt = size;
    }
    else if ((_ipc_soft_map != 0) && (size != 0)) {
      _vm_map_remove(_ipc_soft_map,~_page_mask & local_8,local_8 + size + _page_mask & ~_page_mask);
    }
  }
  return kVar1;
}

