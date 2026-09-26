/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1234ac. */
unsigned __int32 __cdecl in_makeaddr(int a1, int a2)
{
  int v2; // ecx
  _DWORD *v3; // edx

  if ( a1 < 0 ) /*0x1234b8*/
  {
    v2 = 255; /*0x1234d3*/
    if ( (a1 & 0xC0000000) == 0x80000000 ) /*0x1234d8*/
      v2 = 0xFFFF; /*0x1234df*/
  }
  else
  {
    v2 = 0xFFFFFF; /*0x1234ba*/
  }
  v3 = (_DWORD *)in_ifaddr; /*0x1234e4*/
  if ( in_ifaddr ) /*0x1234ec*/
  {
    while ( v3[10] != (a1 & v3[11]) ) /*0x1234f8*/
    {
      v3 = (_DWORD *)v3[16]; /*0x1234fa*/
      if ( !v3 ) /*0x1234ff*/
        return _byteswap_ulong(a1 | v2 & a2); /*0x1234ff*/
    }
    v2 = ~v3[13]; /*0x1234c7*/
  }
  return _byteswap_ulong(a1 | v2 & a2); /*0x12350d*/
}
