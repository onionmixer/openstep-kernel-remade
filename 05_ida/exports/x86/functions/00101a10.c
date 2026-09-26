/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101a10. */
char *__cdecl strchr(const char *__s, int __c)
{
  char v3; // cl

  while ( 1 ) /*0x101a1c*/
  {
    v3 = *__s; /*0x101a1c*/
    if ( *__s == __c ) /*0x101a23*/
      break; /*0x101a23*/
    ++__s; /*0x101a25*/
    if ( !v3 ) /*0x101a28*/
      return nullptr; /*0x101a2c*/
  }
  return (char *)__s; /*0x101a32*/
}
