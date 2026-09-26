/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccb5c. */
const char *__cdecl object_getClassName(id a1)
{
  if ( a1 ) /*0x1ccb64*/
    return *(const char **)(*(_DWORD *)a1 + 8); /*0x1ccb68*/
  else
    return "nil"; /*0x1ccb70*/
}
