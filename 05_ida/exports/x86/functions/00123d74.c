/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123d74. */
_BOOL4 __cdecl in_broadcast(unsigned int a1)
{
  _DWORD *v1; // edx
  unsigned __int32 v2; // eax

  v1 = (_DWORD *)in_ifaddr; /*0x123d7a*/
  if ( in_ifaddr ) /*0x123d82*/
  {
    do /*0x123d84*/
    {
      if ( (*(_BYTE *)(v1[8] + 12) & 2) != 0 ) /*0x123d8b*/
      {
        if ( v1[5] == a1 ) /*0x123d90*/
          return 1; /*0x123d9e*/
        v2 = _byteswap_ulong(a1); /*0x123d94*/
        if ( v1[12] == v2 || v1[10] == v2 ) /*0x123d9e*/
          return 1; /*0x123d9e*/
      }
      v1 = (_DWORD *)v1[16]; /*0x123dac*/
    }
    while ( v1 ); /*0x123d84*/
  }
  return a1 == -1 || !a1; /*0x123da7*/
}
