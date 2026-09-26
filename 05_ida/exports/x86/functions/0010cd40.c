/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cd40. */
unsigned int __cdecl max(unsigned int a1, unsigned int a2)
{
  unsigned int result; // eax

  result = a1; /*0x10cd46*/
  if ( a1 < a2 ) /*0x10cd4b*/
    return a2; /*0x10cd4d*/
  return result; /*0x10cd51*/
}
