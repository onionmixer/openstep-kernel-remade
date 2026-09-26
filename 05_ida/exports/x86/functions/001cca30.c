/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cca30. */
int __cdecl _mapStrHash(int a1, _BYTE *a2)
{
  int v2; // ecx
  _BYTE *v3; // edx
  _BYTE *v4; // edx
  _BYTE *v5; // edx
  int v6; // eax
  _BYTE *v7; // edx

  v2 = 0; /*0x1cca33*/
  v3 = a2; /*0x1cca35*/
  if ( a2 && *a2 ) /*0x1cca3c*/
  {
    do /*0x1cca73*/
    {
      v2 ^= (unsigned __int8)*v3; /*0x1cca47*/
      v4 = v3 + 1; /*0x1cca49*/
      if ( !*v4 ) /*0x1cca4a*/
        break; /*0x1cca4d*/
      v2 ^= (unsigned __int8)*v4 << 8; /*0x1cca55*/
      v5 = v4 + 1; /*0x1cca57*/
      if ( !*v5 ) /*0x1cca58*/
        break; /*0x1cca5b*/
      v6 = (unsigned __int8)*v5 << 16; /*0x1cca60*/
      v2 ^= v6; /*0x1cca63*/
      v7 = v5 + 1; /*0x1cca65*/
      if ( !*v7 ) /*0x1cca66*/
        break; /*0x1cca69*/
      LOBYTE(v6) = *v7; /*0x1cca6b*/
      v2 ^= v6 << 24; /*0x1cca70*/
      v3 = v7 + 1; /*0x1cca72*/
    }
    while ( *v3 ); /*0x1cca73*/
  }
  return v2; /*0x1cca7c*/
}
