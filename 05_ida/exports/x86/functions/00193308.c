/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x193308. */
int __cdecl byte_swap_dir_block_in(int a1, int a2)
{
  int v2; // ecx
  int v3; // edx
  int result; // eax

  v2 = 0; /*0x193313*/
  if ( a2 > 0 ) /*0x193317*/
  {
    do /*0x19334e*/
    {
      v3 = v2 + a1; /*0x19331c*/
      *(_DWORD *)v3 = _byteswap_ulong(*(_DWORD *)(v2 + a1)); /*0x193323*/
      *(_WORD *)(v3 + 4) = __ROR2__(*(_WORD *)(v2 + a1 + 4), 8); /*0x19332d*/
      *(_WORD *)(v3 + 6) = __ROR2__(*(_WORD *)(v2 + a1 + 6), 8); /*0x193339*/
      LOWORD(v3) = *(_WORD *)(v2 + a1 + 4); /*0x19333d*/
      result = (unsigned __int16)v3; /*0x193341*/
      v2 += (unsigned __int16)v3; /*0x193344*/
    }
    while ( (unsigned __int16)v3 > 0xBu && v2 < a2 ); /*0x19334e*/
  }
  return result; /*0x193353*/
}
