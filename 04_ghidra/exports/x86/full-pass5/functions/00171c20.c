/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171c20 */

void FUN_00171c20(int *param_1,int param_2)

{
  processor_set_t pset;
  kern_return_t kVar1;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    pset = _convert_port_to_pset_name(param_1[2]);
    kVar1 = _processor_set_stack_usage
                      (pset,(uint *)(param_2 + 0x24),(vm_size_t *)(param_2 + 0x2c),
                       (vm_size_t *)(param_2 + 0x34),(vm_size_t *)(param_2 + 0x3c),
                       (vm_offset_t *)(param_2 + 0x44));
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _pset_deallocate(pset);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x48;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e07bc;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e07c0;
      *(undefined4 *)(param_2 + 0x30) = DAT_001e07c4;
      *(undefined4 *)(param_2 + 0x38) = DAT_001e07c8;
      *(undefined4 *)(param_2 + 0x40) = DAT_001e07cc;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

