/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a034. */
int __cdecl copystr(char *a1, _BYTE *a2, int a3, _DWORD *a4)
{
  int v6; // edx
  char v7; // al
  int v8; // eax

  *(_DWORD *)(active_threads + 116) = &loc_18A088; /*0x18a04b*/
  v6 = a3 - 1; /*0x18a052*/
  if ( a3 > 0 ) /*0x18a057*/
  {
    do /*0x18a06b*/
    {
      v7 = *a1; /*0x18a05c*/
      *a2++ = *a1++; /*0x18a05e*/
      if ( !v7 ) /*0x18a064*/
        break; /*0x18a064*/
      v8 = v6--; /*0x18a066*/
    }
    while ( v8 > 0 ); /*0x18a06b*/
  }
  if ( a4 ) /*0x18a06f*/
    *a4 = a3 - v6; /*0x18a073*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a07a*/
  return 0; /*0x18a09c*/
}
