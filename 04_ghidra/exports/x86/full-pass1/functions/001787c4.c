/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001787c4 */

int _vm_mem_ppi(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *local_c;
  
  iVar2 = 0;
  local_c = &_mem_region;
  if (&_mem_region < &_mem_region + _num_regions * 7) {
    piVar1 = &DAT_001f6e6c;
    do {
      if (((uint)piVar1[2] <= param_1) && (param_1 < (uint)piVar1[3])) {
        return (param_1 - piVar1[2] >> ((byte)_page_shift & 0x1f)) + iVar2;
      }
      iVar2 = iVar2 + *piVar1;
      piVar1 = piVar1 + 7;
      local_c = local_c + 7;
    } while (local_c < &_mem_region + _num_regions * 7);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_mem_ppi_001e0b14);
}

