/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0024. */
int __cdecl _strhash(_BYTE *a1)
{
  int v2; // ecx
  _BYTE *v3; // edx
  _BYTE *v4; // edx
  int v5; // eax
  _BYTE *v6; // edx

  v2 = 0; /*0x1d002a*/
  while ( *a1 ) /*0x1d002c*/
  {
    v2 ^= (unsigned __int8)*a1; /*0x1d0034*/
    v3 = a1 + 1; /*0x1d0036*/
    if ( !*v3 ) /*0x1d0037*/
      break; /*0x1d0037*/
    v2 ^= (unsigned __int8)*v3 << 8; /*0x1d0042*/
    v4 = v3 + 1; /*0x1d0044*/
    if ( !*v4 ) /*0x1d0045*/
      break; /*0x1d0045*/
    v5 = (unsigned __int8)*v4 << 16; /*0x1d004d*/
    v2 ^= v5; /*0x1d0050*/
    v6 = v4 + 1; /*0x1d0052*/
    if ( !*v6 ) /*0x1d0053*/
      break; /*0x1d0053*/
    LOBYTE(v5) = *v6; /*0x1d0058*/
    v2 ^= v5 << 24; /*0x1d005d*/
    a1 = v6 + 1; /*0x1d005f*/
  }
  return v2; /*0x1d0068*/
}
