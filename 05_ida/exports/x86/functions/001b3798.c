/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3798. */
int __cdecl EventCoalesceDisplayCmd(int a1, char a2)
{
  int v2; // edx

  v2 = a1; /*0x1b379b*/
  if ( a1 <= 3 ) /*0x1b37a1*/
    return byte_1D5DC8[4 * (a2 & 3) + (a1 & 3)]; /*0x1b37b3*/
  return v2; /*0x1b37ba*/
}
