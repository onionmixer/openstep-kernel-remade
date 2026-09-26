/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101fc4. */
char *__cdecl index(const char *a1, int a2)
{
  char v3; // cl

  while ( 1 ) /*0x101fd0*/
  {
    v3 = *a1; /*0x101fd0*/
    if ( *a1 == a2 ) /*0x101fd7*/
      break; /*0x101fd7*/
    ++a1; /*0x101fd9*/
    if ( !v3 ) /*0x101fdc*/
      return nullptr; /*0x101fe0*/
  }
  return (char *)a1; /*0x101fe6*/
}
