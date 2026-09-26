/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1924e0. */
unsigned int __cdecl sub_1924E0(int a1)
{
  int v1; // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int result; // eax

  v1 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x1924f1*/
  if ( v1 ) /*0x1924f6*/
    v2 = v1 + 132; /*0x1924f8*/
  else
    v2 = thread_user_state(active_threads); /*0x192506*/
  v3 = a1 + 68; /*0x192508*/
  *(_DWORD *)(v2 + 52) = *(_DWORD *)(a1 + 52); /*0x19250e*/
  result = v2 + 12; /*0x192511*/
  if ( a1 + 68 <= v2 + 12 ) /*0x192516*/
  {
    result = v2 + 8; /*0x19255c*/
    if ( v3 <= v2 + 8 ) /*0x192561*/
    {
      result = v2 + 4; /*0x192578*/
      if ( v3 <= v2 + 4 ) /*0x19257d*/
      {
        if ( v3 <= v2 ) /*0x19258e*/
          return result; /*0x19258e*/
      }
      else
      {
        *(_WORD *)(v2 + 4) = *(_WORD *)(a1 + 4); /*0x192583*/
      }
    }
    else
    {
      *(_WORD *)(v2 + 8) = *(_WORD *)(a1 + 8); /*0x192567*/
      *(_WORD *)(v2 + 4) = *(_WORD *)(a1 + 4); /*0x19256f*/
    }
  }
  else
  {
    *(_DWORD *)(v2 + 44) = *(_DWORD *)(a1 + 44); /*0x19251b*/
    *(_DWORD *)(v2 + 40) = *(_DWORD *)(a1 + 40); /*0x192521*/
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a1 + 36); /*0x192527*/
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a1 + 32); /*0x19252d*/
    *(_DWORD *)(v2 + 24) = *(_DWORD *)(a1 + 24); /*0x192533*/
    *(_DWORD *)(v2 + 20) = *(_DWORD *)(a1 + 20); /*0x192539*/
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a1 + 16); /*0x19253f*/
    *(_WORD *)(v2 + 12) = *(_WORD *)(a1 + 12); /*0x192546*/
    *(_WORD *)(v2 + 8) = *(_WORD *)(a1 + 8); /*0x19254e*/
    *(_WORD *)(v2 + 4) = *(_WORD *)(a1 + 4); /*0x192556*/
  }
  *(_WORD *)v2 = *(_WORD *)a1; /*0x192593*/
  return result; /*0x192599*/
}
