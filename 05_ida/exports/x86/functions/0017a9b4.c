/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a9b4. */
int vm_set_page_size()
{
  int result; // eax

  page_mask = page_size - 1; /*0x17a9c0*/
  if ( ((page_size - 1) & page_size) != 0 ) /*0x17a9c7*/
    panic(aVmSetPageSizeP); /*0x17a9ce*/
  page_shift = 0; /*0x17a9d3*/
  result = page_size; /*0x17a9dd*/
  if ( page_size != 1 ) /*0x17a9e5*/
  {
    do /*0x17aa01*/
      result = 1 << ++page_shift; /*0x17a9fd*/
    while ( 1 << page_shift != page_size ); /*0x17aa01*/
  }
  return result; /*0x17aa05*/
}
