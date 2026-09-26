/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fbb4. */
_BOOL4 __cdecl SRIsEqual(int a1, int a2, int a3)
{
  int v3; // edx

  v3 = 0; /*0x11fbbe*/
  if ( *(_DWORD *)a2 == *(_DWORD *)a3 ) /*0x11fbc4*/
    return *(_WORD *)(a2 + 4) == *(_WORD *)(a3 + 4); /*0x11fbd0*/
  return v3; /*0x11fbd3*/
}
