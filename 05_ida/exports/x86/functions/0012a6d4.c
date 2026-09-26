/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a6d4. */
int __cdecl tcp_drop(int a1, int a2)
{
  __int16 v2; // bx
  int v3; // edi

  v2 = a2; /*0x12a6dd*/
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 28); /*0x12a6e3*/
  if ( *(__int16 *)(a1 + 8) <= 2 ) /*0x12a6eb*/
  {
    ++dword_1EED80; /*0x12a704*/
  }
  else
  {
    *(_WORD *)(a1 + 8) = 0; /*0x12a6ed*/
    tcp_output(a1); /*0x12a6f4*/
    ++dword_1EED7C; /*0x12a6f9*/
  }
  if ( a2 == 60 && *(_WORD *)(a1 + 106) ) /*0x12a70f*/
    v2 = *(_WORD *)(a1 + 106); /*0x12a718*/
  *(_WORD *)(v3 + 86) = v2; /*0x12a71b*/
  return tcp_close(a1); /*0x12a728*/
}
