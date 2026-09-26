/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1398f4. */
_BOOL4 __cdecl stillopen(__int16 a1, int a2)
{
  int v2; // ecx
  int i; // eax

  v2 = 0; /*0x1398fc*/
  for ( i = stable[((_BYTE)a1 + HIBYTE(a1)) & 0xF]; i; i = *(_DWORD *)i ) /*0x139917*/
  {
    if ( *(_WORD *)(i + 66) == a1 && *(_DWORD *)(i + 44) == a2 ) /*0x139925*/
      v2 += *(_DWORD *)(i + 100); /*0x139927*/
  }
  return v2 != 0; /*0x13993d*/
}
