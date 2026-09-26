/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1970c4. */
int kmgetc()
{
  int v1; // ebx

  if ( !kmId ) /*0x1970cf*/
    return 0; /*0x1970d1*/
  v1 = (int)objc_msgSend(kmId, sel_kmGetc); /*0x1970e5*/
  if ( v1 == 13 ) /*0x1970ed*/
    v1 = 10; /*0x1970ef*/
  cnputc(); /*0x1970f5*/
  return v1; /*0x1970fc*/
}
