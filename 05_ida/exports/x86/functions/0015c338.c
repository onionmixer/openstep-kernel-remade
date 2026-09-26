/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c338. */
_DWORD *getmachheaders()
{
  _DWORD *result; // eax

  result = malloc(8u); /*0x15c33d*/
  *result = &dword_100000; /*0x15c342*/
  result[1] = 0; /*0x15c348*/
  return result; /*0x15c351*/
}
