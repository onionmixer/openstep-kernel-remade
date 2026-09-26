/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c8e0 */

kern_return_t
_vm_copy(vm_map_t target_task,vm_address_t source_address,vm_size_t size,vm_address_t dest_address)

{
  uint uVar1;
  kern_return_t kVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = ~_page_mask;
  uVar1 = _page_mask + source_address & uVar4;
  if (((uVar1 == source_address) &&
      (uVar3 = _page_mask + dest_address & uVar4, uVar3 == dest_address)) &&
     (uVar4 = size + _page_mask & uVar4, size == uVar4)) {
    kVar2 = _vm_map_copy(target_task,target_task,uVar3,uVar4,uVar1,0,0);
  }
  else {
    kVar2 = 4;
  }
  return kVar2;
}

