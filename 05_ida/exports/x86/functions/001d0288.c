/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0288. */
SEL __cdecl sel_registerName(const char *str)
{
  SEL result; // eax
  char *v2; // eax

  result = sel_getUid(str); /*0x1d0290*/
  if ( !result ) /*0x1d029a*/
  {
    v2 = (char *)NXUniqueString(str); /*0x1d029d*/
    return _sel_registerName(v2); /*0x1d02a3*/
  }
  return result; /*0x1d02a8*/
}
