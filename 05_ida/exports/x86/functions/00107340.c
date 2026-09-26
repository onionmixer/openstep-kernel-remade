/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107340. */
int __cdecl inferior(int a1)
{
  int v1; // edx

  v1 = a1; /*0x107343*/
  if ( a1 == *(_DWORD *)active_u ) /*0x10734f*/
    return 1; /*0x10736b*/
  while ( *(_WORD *)(v1 + 50) ) /*0x107359*/
  {
    v1 = *(_DWORD *)(v1 + 68); /*0x107364*/
    if ( v1 == *(_DWORD *)active_u ) /*0x107369*/
      return 1; /*0x107369*/
  }
  return 0; /*0x10735f*/
}
