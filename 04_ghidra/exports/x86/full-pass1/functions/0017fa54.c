/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017fa54 */

void FUN_0017fa54(int param_1)

{
  vm_size_t size;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_mappedRange_001f92b0);
  if (*(int *)(param_1 + 0x10) != 0) {
    _vm_deallocate(*(vm_map_t *)(*(int *)(param_1 + 0x10) + 0xc),*(vm_address_t *)(param_1 + 0x14),
                   size);
  }
  local_c = param_1;
  local_8 = PTR_s_KernBusRangeMapping_001f9f00;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

