/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ca48. */
__int16 __cdecl outl(unsigned __int16 a1, __int16 a2)
{
  __int16 result; // ax

  result = a2; /*0x18ca4f*/
  __outdword(a1, a2); /*0x18ca53*/
  _InterlockedIncrement(&dword_1E772C); /*0x18ca54*/
  return result; /*0x18ca5d*/
}
