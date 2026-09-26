/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f4a0. */
int __cdecl locontrol(int a1, char *__s1, int a3)
{
  int v3; // ebx
  __int16 v4; // ax

  v3 = 0; /*0x11f4ac*/
  if ( !strcmp(__s1, "setaddr") ) /*0x11f4b4*/
  {
    v4 = if_flags(a1); /*0x11f4c4*/
    LOBYTE(v4) = v4 | 0x41; /*0x11f4c9*/
    if_flags_set(a1, v4); /*0x11f4d0*/
  }
  else if ( !strcmp(__s1, "add-multicast") || !strcmp(__s1, "add-multicast") ) /*0x11f4f0*/
  {
    if ( *(_WORD *)(a3 + 16) != 2 ) /*0x11f4fe*/
      return 47; /*0x11f500*/
  }
  else
  {
    return 22; /*0x11f508*/
  }
  return v3; /*0x11f512*/
}
