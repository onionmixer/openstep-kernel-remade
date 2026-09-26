/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1162f8. */
int __cdecl soqinsque(int a1, _DWORD *a2, int a3)
{
  int result; // eax
  int v4; // edx

  result = a3; /*0x116303*/
  v4 = a1; /*0x116306*/
  a2[4] = a1; /*0x116308*/
  if ( a3 ) /*0x11630d*/
  {
    ++*(_WORD *)(a1 + 32); /*0x11632c*/
    if ( *(_DWORD *)(a1 + 28) != a1 ) /*0x116333*/
    {
      do /*0x11633e*/
        v4 = *(_DWORD *)(v4 + 28); /*0x116338*/
      while ( *(_DWORD *)(v4 + 28) != a1 ); /*0x11633e*/
    }
    a2[7] = *(_DWORD *)(v4 + 28); /*0x116343*/
    *(_DWORD *)(v4 + 28) = a2; /*0x116346*/
  }
  else
  {
    ++*(_WORD *)(a1 + 24); /*0x11630f*/
    if ( *(_DWORD *)(a1 + 20) != a1 ) /*0x116316*/
    {
      do /*0x11631e*/
        v4 = *(_DWORD *)(v4 + 20); /*0x116318*/
      while ( *(_DWORD *)(v4 + 20) != a1 ); /*0x11631e*/
    }
    a2[5] = *(_DWORD *)(v4 + 20); /*0x116323*/
    *(_DWORD *)(v4 + 20) = a2; /*0x116326*/
  }
  return result; /*0x11634c*/
}
