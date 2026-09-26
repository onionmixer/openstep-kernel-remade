/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1932bc. */
__int16 __cdecl byte_swap_dir_block_out(int a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // ecx
  __int16 result; // ax

  v1 = 0; /*0x1932c4*/
  if ( *(int *)(a1 + 20) > 0 ) /*0x1932c9*/
  {
    do /*0x1932fd*/
    {
      v2 = v1 + *(_DWORD *)(a1 + 32); /*0x1932cf*/
      v3 = *(unsigned __int16 *)(v2 + 4); /*0x1932d1*/
      v1 += v3; /*0x1932d5*/
      *(_DWORD *)v2 = _byteswap_ulong(*(_DWORD *)v2); /*0x1932db*/
      *(_WORD *)(v2 + 4) = __ROR2__(*(_WORD *)(v2 + 4), 8); /*0x1932e5*/
      result = __ROR2__(*(_WORD *)(v2 + 6), 8); /*0x1932ed*/
      *(_WORD *)(v2 + 6) = result; /*0x1932f1*/
    }
    while ( v3 > 11 && *(_DWORD *)(a1 + 20) > v1 ); /*0x1932fd*/
  }
  return result; /*0x193302*/
}
