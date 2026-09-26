/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18c9dc. */
int __cdecl inb(unsigned __int16 a1)
{
  int result; // eax

  LOBYTE(result) = __inbyte(a1); /*0x18c9e3*/
  return (unsigned __int8)result; /*0x18c9eb*/
}
