/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bea9c. */
int audio_freeIMuLawTab()
{
  int result; // eax

  result = dword_1E53CC; /*0x1bea9f*/
  if ( dword_1E53CC ) /*0x1beaa6*/
    return IOFree(dword_1E53CC, 0x4000); /*0x1beaae*/
  return result; /*0x1beab5*/
}
