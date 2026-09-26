/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cd2c. */
unsigned int __cdecl min(unsigned int a1, unsigned int a2)
{
  unsigned int result; // eax

  result = a1; /*0x10cd32*/
  if ( a1 > a2 ) /*0x10cd37*/
    return a2; /*0x10cd39*/
  return result; /*0x10cd3d*/
}
