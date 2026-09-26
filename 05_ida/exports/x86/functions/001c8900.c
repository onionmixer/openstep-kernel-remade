/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8900. */
int __cdecl sub_1C8900(unsigned int a1)
{
  if ( a1 <= 1 ) /*0x1c8909*/
    return 0; /*0x1c8918*/
  else
    return sub_1C8900(a1 >> 1) + 1; /*0x1c8913*/
}
