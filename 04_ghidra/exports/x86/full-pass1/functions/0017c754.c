/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c754 */

kern_return_t
_vm_machine_attribute
          (vm_map_t target_task,vm_address_t address,vm_size_t size,vm_machine_attribute_t attribute
          ,vm_machine_attribute_val_t *value)

{
  kern_return_t kVar1;
  
  if (target_task != 0) {
    kVar1 = _vm_map_machine_attribute(target_task,address,size,attribute,value);
    return kVar1;
  }
  return 4;
}

