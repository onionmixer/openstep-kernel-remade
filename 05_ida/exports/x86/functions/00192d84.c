/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192d84. */
unsigned int __cdecl byte_swap_disklabel_out(int a1)
{
  int v1; // esi
  unsigned int *v2; // edx
  unsigned int result; // eax

  if ( *(int *)a1 <= 1684821554 ) /*0x192d92*/
  {
    v1 = 0; /*0x192da8*/
    v2 = (unsigned int *)(a1 + 576); /*0x192daa*/
    do /*0x192dc0*/
    {
      *v2 = _byteswap_ulong(*v2); /*0x192db4*/
      ++v2; /*0x192db6*/
      ++v1; /*0x192db9*/
    }
    while ( v1 < 1670 ); /*0x192dc0*/
  }
  else
  {
    *(_WORD *)(a1 + 576) = __ROR2__(*(_WORD *)(a1 + 576), 8); /*0x192d9f*/
  }
  *(_DWORD *)a1 = _byteswap_ulong(*(_DWORD *)a1); /*0x192dc6*/
  *(_DWORD *)(a1 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x192dcd*/
  *(_DWORD *)(a1 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x192dd5*/
  *(_DWORD *)(a1 + 36) = _byteswap_ulong(*(_DWORD *)(a1 + 36)); /*0x192ddd*/
  *(_DWORD *)(a1 + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x192de5*/
  *(_WORD *)(a1 + 7256) = __ROR2__(*(_WORD *)(a1 + 7256), 8); /*0x192df3*/
  byte_swap_disktab_out(a1 + 44); /*0x192dfe*/
  for ( result = 0; result <= 0x1A19; ++result ) /*0x192e03*/
    *(_BYTE *)(a1 + result + 558) = *(_BYTE *)(a1 + result + 576); /*0x192e0f*/
  return result; /*0x192e21*/
}
