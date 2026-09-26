/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a11c4. */
int __cdecl PCcopyBIOSData(unsigned int a1)
{
  if ( !a1 ) /*0x1a11cc*/
    return 4; /*0x1a11ce*/
  if ( copyout(nullptr, a1, 4096) ) /*0x1a11e0*/
    return 4; /*0x1a11f0*/
  return 0; /*0x1a11d5*/
}
