/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ca18. */
unsigned __int8 __cdecl outb(unsigned __int16 a1, unsigned __int8 a2)
{
  unsigned __int8 result; // al

  result = a2; /*0x18ca1f*/
  __outbyte(a1, a2); /*0x18ca22*/
  _InterlockedIncrement(&dword_1E7724); /*0x18ca23*/
  return result; /*0x18ca2c*/
}
