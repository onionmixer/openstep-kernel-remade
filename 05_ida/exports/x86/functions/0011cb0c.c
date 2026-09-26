/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cb0c. */
int __cdecl pn_getcomponent(int a1, _BYTE *a2)
{
  char *v3; // ecx
  int v4; // edx
  int i; // esi
  char v6; // al

  v3 = *(char **)(a1 + 4); /*0x11cb18*/
  v4 = *(_DWORD *)(a1 + 8); /*0x11cb1b*/
  for ( i = 255; v4 > 0; --v4 ) /*0x11cb25*/
  {
    v6 = *v3; /*0x11cb28*/
    if ( *v3 == 47 ) /*0x11cb2c*/
      break; /*0x11cb2c*/
    if ( --i < 0 ) /*0x11cb2f*/
      return 63; /*0x11cb36*/
    ++v3; /*0x11cb38*/
    *a2++ = v6; /*0x11cb39*/
  }
  *(_DWORD *)(a1 + 4) = v3; /*0x11cb41*/
  *(_DWORD *)(a1 + 8) = v4; /*0x11cb44*/
  *a2 = 0; /*0x11cb47*/
  return 0; /*0x11cb4f*/
}
