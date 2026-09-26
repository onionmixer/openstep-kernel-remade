/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13de14. */
int __cdecl brelse_and_swap(int a1)
{
  int result; // eax

  if ( a1 ) /*0x13de1d*/
  {
    byte_swap_dir_block_out(a1); /*0x13de20*/
    return brelse(a1); /*0x13de26*/
  }
  return result; /*0x13de2b*/
}
