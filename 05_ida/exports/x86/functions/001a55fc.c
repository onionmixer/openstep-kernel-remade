/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a55fc. */
int __cdecl IOAlignmentToSize(int a1)
{
  int v1; // edx
  int result; // eax

  v1 = a1; /*0x1a55ff*/
  for ( result = 1; v1; --v1 ) /*0x1a5609*/
    result *= 2; /*0x1a560c*/
  return result; /*0x1a5613*/
}
