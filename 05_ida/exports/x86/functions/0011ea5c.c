/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ea5c. */
_BOOL4 __cdecl isrofile(int a1)
{
  int v1; // ecx
  int v2; // edx

  v1 = 0; /*0x11ea63*/
  v2 = *(_DWORD *)(a1 + 40); /*0x11ea65*/
  if ( (unsigned int)(v2 - 3) > 1 && v2 != 8 ) /*0x11ea73*/
    return (*(_BYTE *)(*(_DWORD *)(a1 + 36) + 12) & 1) != 0; /*0x11ea7e*/
  return v1; /*0x11ea81*/
}
