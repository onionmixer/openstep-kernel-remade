/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c97c. */
int __cdecl pn_alloc(int *a1)
{
  int result; // eax

  result = kalloc(0x400u); /*0x11c988*/
  *a1 = result; /*0x11c98d*/
  a1[1] = result; /*0x11c98f*/
  a1[2] = 0; /*0x11c992*/
  return result; /*0x11c999*/
}
