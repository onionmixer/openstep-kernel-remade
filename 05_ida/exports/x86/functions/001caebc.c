/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1caebc. */
int __cdecl sub_1CAEBC(unsigned int a1)
{
  if ( a1 <= 1 ) /*0x1caec5*/
    return 0; /*0x1caed4*/
  else
    return sub_1CAEBC(a1 >> 1) + 1; /*0x1caecf*/
}
