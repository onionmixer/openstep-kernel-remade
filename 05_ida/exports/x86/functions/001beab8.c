/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1beab8. */
int __cdecl audio_shortToMulaw(__int16 a1)
{
  return *(unsigned __int8 *)(dword_1E53CC + (a1 >> 2) + 0x2000); /*0x1bead7*/
}
