/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192ce0. */
__int16 __cdecl byte_swap_disklabel_in(int a1)
{
  int i; // eax
  unsigned __int32 v2; // eax
  int v3; // esi
  unsigned int *v4; // edx

  for ( i = 6681; i >= 0; --i ) /*0x192ce8*/
    *(_BYTE *)(a1 + i + 576) = *(_BYTE *)(a1 + i + 558); /*0x192cf7*/
  *(_DWORD *)a1 = _byteswap_ulong(*(_DWORD *)a1); /*0x192d05*/
  *(_DWORD *)(a1 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x192d0c*/
  *(_DWORD *)(a1 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x192d14*/
  *(_DWORD *)(a1 + 36) = _byteswap_ulong(*(_DWORD *)(a1 + 36)); /*0x192d1c*/
  *(_DWORD *)(a1 + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x192d24*/
  *(_WORD *)(a1 + 7256) = __ROR2__(*(_WORD *)(a1 + 7256), 8); /*0x192d32*/
  byte_swap_disktab_in(a1 + 44); /*0x192d3d*/
  if ( *(int *)a1 <= 1684821554 ) /*0x192d48*/
  {
    v3 = 0; /*0x192d60*/
    v4 = (unsigned int *)(a1 + 576); /*0x192d62*/
    do /*0x192d78*/
    {
      v2 = _byteswap_ulong(*v4); /*0x192d6a*/
      *v4++ = v2; /*0x192d6c*/
      ++v3; /*0x192d71*/
    }
    while ( v3 < 1670 ); /*0x192d78*/
  }
  else
  {
    LOWORD(v2) = __ROR2__(*(_WORD *)(a1 + 576), 8); /*0x192d51*/
    *(_WORD *)(a1 + 576) = v2; /*0x192d55*/
  }
  return v2; /*0x192d7d*/
}
