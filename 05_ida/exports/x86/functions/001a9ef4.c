/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9ef4. */
unsigned int __cdecl IORemoveFromVfssw(int a1)
{
  unsigned int result; // eax

  result = 8 * a1; /*0x1a9efa*/
  (&vfssw)[result / 4] = nullptr; /*0x1a9f01*/
  *(_UNKNOWN **)((char *)&off_1DB644 + result) = nullptr; /*0x1a9f0b*/
  return result; /*0x1a9f17*/
}
