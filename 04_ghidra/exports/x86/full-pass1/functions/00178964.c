/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178964 */

void _vm_alloc_from_regions(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = &_mem_region;
  if (&_mem_region < &_mem_region + _num_regions * 7) {
    puVar1 = &DAT_001f6e74;
    do {
      uVar2 = param_1 + ((*puVar1 - 1) + param_2 & -param_2);
      if (uVar2 <= puVar1[1]) {
        *puVar1 = uVar2;
        return;
      }
      puVar1 = puVar1 + 7;
      puVar3 = puVar3 + 7;
    } while (puVar3 < &_mem_region + _num_regions * 7);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_mem_alloc_from_regions_001e0b1c);
}

