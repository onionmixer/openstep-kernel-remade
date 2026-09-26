/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192f90. */
int __cdecl byte_swap_partition(int a1)
{
  *(_DWORD *)a1 = _byteswap_ulong(*(_DWORD *)a1); /*0x192f9a*/
  *(_DWORD *)(a1 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x192fa1*/
  *(_WORD *)(a1 + 8) = __ROR2__(*(_WORD *)(a1 + 8), 8); /*0x192fac*/
  *(_WORD *)(a1 + 10) = __ROR2__(*(_WORD *)(a1 + 10), 8); /*0x192fb8*/
  *(_WORD *)(a1 + 14) = __ROR2__(*(_WORD *)(a1 + 14), 8); /*0x192fc4*/
  *(_WORD *)(a1 + 16) = __ROR2__(*(_WORD *)(a1 + 16), 8); /*0x192fd0*/
  return a1; /*0x192fd6*/
}
