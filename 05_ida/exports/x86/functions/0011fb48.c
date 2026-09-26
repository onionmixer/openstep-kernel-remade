/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fb48. */
int __cdecl sub_11FB48(int a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // ebx

  v1 = if_private(a1); /*0x11fb50*/
  v2 = if_getbuf(*(_DWORD *)(v1 + 12)); /*0x11fb5c*/
  v3 = v2; /*0x11fb61*/
  if ( !v2 ) /*0x11fb68*/
    return 0; /*0x11fb78*/
  nb_shrink_top(v2, 14); /*0x11fb6d*/
  return v3; /*0x11fb7a*/
}
