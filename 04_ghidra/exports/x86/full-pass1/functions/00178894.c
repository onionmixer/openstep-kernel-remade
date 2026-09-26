/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178894 */

int _vm_phys_to_vm_page(uint param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = &_mem_region;
  if (&_mem_region < &_mem_region + _num_regions * 7) {
    piVar1 = &DAT_001f6e64;
    do {
      if (((uint)piVar1[4] <= param_1) && (param_1 < (uint)piVar1[5])) {
        return ((param_1 >> ((byte)_page_shift & 0x1f)) - *piVar1) * 0x30 + *piVar2;
      }
      piVar1 = piVar1 + 7;
      piVar2 = piVar2 + 7;
    } while (piVar2 < &_mem_region + _num_regions * 7);
  }
  return 0;
}

