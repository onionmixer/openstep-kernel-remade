/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c9f0. */
int __cdecl inw(unsigned __int16 a1)
{
  int result; // eax

  LOWORD(result) = __inword(a1); /*0x18c9f7*/
  return (unsigned __int16)result; /*0x18ca00*/
}
