/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178844 */

undefined4 _vm_valid_page(uint param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  puVar2 = &_mem_region;
  if (&_mem_region < &_mem_region + _num_regions * 7) {
    puVar1 = &DAT_001f6e78;
    do {
      if ((puVar1[-1] <= param_1) && (param_1 < *puVar1)) {
        return 1;
      }
      puVar1 = puVar1 + 7;
      puVar2 = puVar2 + 7;
    } while (puVar2 < &_mem_region + _num_regions * 7);
  }
  return 0;
}

