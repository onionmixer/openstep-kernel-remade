/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190ca8 */

int _pmap_resident_extract(int *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 0x16) * 4 + *param_1);
  if ((((*puVar1 & 1) != 0) &&
      (puVar1 = (uint *)((param_2 >> 10 & 0xffc) + (*puVar1 & 0xfffff000)), puVar1 != (uint *)0x0))
     && ((*puVar1 & 1) != 0)) {
    return (param_2 & 0xfff) + (*puVar1 & 0xfffff000);
  }
  return 0;
}

