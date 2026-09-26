/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197104. */
int kmgetc_silent()
{
  int result; // eax

  if ( !kmId ) /*0x19710e*/
    return 0; /*0x197110*/
  result = (int)objc_msgSend(kmId, sel_kmGetc); /*0x197120*/
  if ( result == 13 ) /*0x197128*/
    return 10; /*0x19712a*/
  return result; /*0x197114*/
}
