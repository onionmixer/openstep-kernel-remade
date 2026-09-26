/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123640. */
int __cdecl in_localaddr(unsigned int a1)
{
  unsigned __int32 v1; // ecx
  _DWORD *v2; // edx
  _DWORD *v4; // edx

  v1 = _byteswap_ulong(a1); /*0x123648*/
  if ( subnetsarelocal ) /*0x123651*/
  {
    v2 = (_DWORD *)in_ifaddr; /*0x123653*/
    if ( in_ifaddr ) /*0x12365b*/
    {
      while ( v2[10] != (v2[11] & v1) ) /*0x123668*/
      {
        v2 = (_DWORD *)v2[16]; /*0x12366a*/
        if ( !v2 ) /*0x12366f*/
          return 0; /*0x12366f*/
      }
      return 1; /*0x12367c*/
    }
  }
  else
  {
    v4 = (_DWORD *)in_ifaddr; /*0x123680*/
    if ( in_ifaddr ) /*0x123688*/
    {
      while ( v4[12] != (v4[13] & v1) ) /*0x123694*/
      {
        v4 = (_DWORD *)v4[16]; /*0x123696*/
        if ( !v4 ) /*0x12369b*/
          return 0; /*0x12369b*/
      }
      return 1; /*0x123694*/
    }
  }
  return 0; /*0x12367b*/
}
