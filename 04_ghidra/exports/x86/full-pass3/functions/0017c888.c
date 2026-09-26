/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c888 */

kern_return_t
_vm_write(vm_map_t target_task,vm_address_t address,vm_offset_t data,mach_msg_type_number_t dataCnt)

{
  uint uVar1;
  kern_return_t kVar2;
  uint uVar3;
  
  uVar3 = _page_mask + address & ~_page_mask;
  if ((uVar3 == address) && (uVar1 = _page_mask + dataCnt & ~_page_mask, uVar1 == dataCnt)) {
    kVar2 = _vm_map_copy(target_task,_ipc_soft_map,uVar3,uVar1,data,0,1);
  }
  else {
    kVar2 = 4;
  }
  return kVar2;
}

