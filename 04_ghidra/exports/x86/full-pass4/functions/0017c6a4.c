/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c6a4 */

kern_return_t
_vm_protect(vm_map_t target_task,vm_address_t address,vm_size_t size,boolean_t set_maximum,
           vm_prot_t new_protection)

{
  kern_return_t kVar1;
  
  if (target_task == 0) {
    kVar1 = 4;
  }
  else {
    kVar1 = _vm_map_protect(target_task,~_page_mask & address,
                            address + size + _page_mask & ~_page_mask,new_protection,set_maximum);
  }
  return kVar1;
}

