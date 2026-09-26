/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbf14. */
int __cdecl sub_1CBF14(unsigned int a1)
{
  if ( a1 <= 1 ) /*0x1cbf1d*/
    return 0; /*0x1cbf2c*/
  else
    return sub_1CBF14(a1 >> 1) + 1; /*0x1cbf27*/
}
