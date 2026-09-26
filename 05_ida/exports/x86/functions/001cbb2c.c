/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbb2c. */
uintptr_t __cdecl NXStrHash(const void *info, const void *data)
{
  uintptr_t v2; // ecx
  _BYTE *v3; // edx
  _BYTE *v4; // edx
  _BYTE *v5; // edx
  int v6; // eax
  _BYTE *v7; // edx

  v2 = 0; /*0x1cbb2f*/
  v3 = data; /*0x1cbb31*/
  if ( data && *(_BYTE *)data ) /*0x1cbb38*/
  {
    do /*0x1cbb6f*/
    {
      v2 ^= (unsigned __int8)*v3; /*0x1cbb43*/
      v4 = v3 + 1; /*0x1cbb45*/
      if ( !*v4 ) /*0x1cbb46*/
        break; /*0x1cbb49*/
      v2 ^= (unsigned __int8)*v4 << 8; /*0x1cbb51*/
      v5 = v4 + 1; /*0x1cbb53*/
      if ( !*v5 ) /*0x1cbb54*/
        break; /*0x1cbb57*/
      v6 = (unsigned __int8)*v5 << 16; /*0x1cbb5c*/
      v2 ^= v6; /*0x1cbb5f*/
      v7 = v5 + 1; /*0x1cbb61*/
      if ( !*v7 ) /*0x1cbb62*/
        break; /*0x1cbb65*/
      LOBYTE(v6) = *v7; /*0x1cbb67*/
      v2 ^= v6 << 24; /*0x1cbb6c*/
      v3 = v7 + 1; /*0x1cbb6e*/
    }
    while ( *v3 ); /*0x1cbb6f*/
  }
  return v2; /*0x1cbb78*/
}
