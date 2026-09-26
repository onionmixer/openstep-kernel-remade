/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ed58. */
int (__cdecl **null_init())(int, int)
{
  int (__cdecl **result)(int, int); // eax

  for ( result = &afswitch; result < (int (__cdecl **)(int, int))&ifqmaxlen; result += 2 ) /*0x11ed65*/
  {
    if ( !*result ) /*0x11ed68*/
    {
      *result = null_hash; /*0x11ed6d*/
      *result = *result; /*0x11ed75*/
    }
  }
  return result; /*0x11ed83*/
}
