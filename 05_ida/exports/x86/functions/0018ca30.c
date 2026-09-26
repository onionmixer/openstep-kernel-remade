/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ca30. */
unsigned __int16 __cdecl outw(unsigned __int16 a1, unsigned __int16 a2)
{
  unsigned __int16 result; // ax

  result = a2; /*0x18ca37*/
  __outword(a1, a2); /*0x18ca3b*/
  _InterlockedIncrement(&dword_1E7728); /*0x18ca3d*/
  return result; /*0x18ca46*/
}
