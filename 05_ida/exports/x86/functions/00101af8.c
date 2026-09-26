/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x101af8. */
size_t __cdecl strlen(const char *__s)
{
  const char *v1; // edx

  v1 = __s; /*0x101afb*/
  do /*0x101b33*/
  {
    if ( !*v1++ ) /*0x101b35*/
      break; /*0x101b3a*/
    if ( !*v1++ ) /*0x101b04*/
      break; /*0x101b09*/
    if ( !*v1++ ) /*0x101b0b*/
      break; /*0x101b10*/
    if ( !*v1++ ) /*0x101b12*/
      break; /*0x101b17*/
    if ( !*v1++ ) /*0x101b19*/
      break; /*0x101b1e*/
    if ( !*v1++ ) /*0x101b20*/
      break; /*0x101b25*/
    if ( !*v1++ ) /*0x101b27*/
      break; /*0x101b2c*/
  }
  while ( *v1++ ); /*0x101b33*/
  return v1 - __s - 1; /*0x101b43*/
}
