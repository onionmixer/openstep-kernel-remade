/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b830. */
int __cdecl sub_11B830(int a1)
{
  int result; // eax

  *(_DWORD *)(*(_DWORD *)(a1 + 12) + 8) = *(_DWORD *)(a1 + 8); /*0x11b83d*/
  *(_DWORD *)(*(_DWORD *)(a1 + 8) + 12) = *(_DWORD *)(a1 + 12); /*0x11b846*/
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4); /*0x11b84e*/
  **(_DWORD **)(a1 + 4) = *(_DWORD *)a1; /*0x11b856*/
  vn_rele(*(_DWORD *)(a1 + 20)); /*0x11b85c*/
  *(_DWORD *)(a1 + 20) = 0; /*0x11b861*/
  vn_rele(*(_DWORD *)(a1 + 16)); /*0x11b86c*/
  *(_DWORD *)(a1 + 16) = 0; /*0x11b871*/
  if ( *(_DWORD *)(a1 + 60) ) /*0x11b87b*/
  {
    crfree(*(_WORD **)(a1 + 60)); /*0x11b883*/
    *(_DWORD *)(a1 + 60) = 0; /*0x11b888*/
  }
  if ( *(_BYTE *)(a1 + 68) ) /*0x11b892*/
  {
    kfree(*(_DWORD *)(a1 + 64), *(__int16 *)(a1 + 70)); /*0x11b8a1*/
    *(_BYTE *)(a1 + 68) = 0; /*0x11b8a6*/
    *(_WORD *)(a1 + 70) = 0; /*0x11b8aa*/
  }
  result = dword_1E9BE8; /*0x11b8b0*/
  dword_1E9BE8 = a1; /*0x11b8b5*/
  *(_DWORD *)(a1 + 8) = result; /*0x11b8bb*/
  *(_DWORD *)(result + 12) = a1; /*0x11b8be*/
  *(_DWORD *)(a1 + 12) = &nc_lru; /*0x11b8c1*/
  *(_DWORD *)(a1 + 4) = a1; /*0x11b8c8*/
  *(_DWORD *)a1 = a1; /*0x11b8cb*/
  --dword_1E9C20; /*0x11b8cd*/
  return result; /*0x11b8d3*/
}
