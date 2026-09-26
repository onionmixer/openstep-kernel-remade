/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191810. */
void __cdecl pmap_page_protect(unsigned int a1, int a2)
{
  if ( a2 == 5 ) /*0x19181c*/
    goto LABEL_7; /*0x19181c*/
  if ( a2 > 5 ) /*0x19181e*/
  {
    if ( a2 == 7 ) /*0x19182b*/
      return; /*0x19182b*/
    goto LABEL_8; /*0x19182b*/
  }
  if ( a2 == 1 ) /*0x191823*/
  {
LABEL_7:
    pmap_copy_on_write(a1); /*0x191831*/
    return; /*0x191839*/
  }
LABEL_8:
  pmap_remove_all(a1); /*0x19183c*/
}
