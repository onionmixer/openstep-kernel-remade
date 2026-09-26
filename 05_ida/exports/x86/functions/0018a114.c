/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a114. */
int __cdecl copyoutstr(unsigned __int8 *a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // eax

  *(_DWORD *)(active_threads + 116) = &loc_18A168; /*0x18a12b*/
  v6 = a3 - 1; /*0x18a132*/
  if ( a3 > 0 ) /*0x18a137*/
  {
    do /*0x18a14c*/
    {
      v7 = *a1; /*0x18a13c*/
      __writefsbyte(a2++, *a1++); /*0x18a13e*/
      if ( !v7 ) /*0x18a145*/
        break; /*0x18a145*/
      v8 = v6--; /*0x18a147*/
    }
    while ( v8 > 0 ); /*0x18a14c*/
  }
  if ( a4 ) /*0x18a150*/
    *a4 = a3 - v6; /*0x18a154*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a15b*/
  return 0; /*0x18a17c*/
}
