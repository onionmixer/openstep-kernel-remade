/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cb84. */
int __cdecl pn_free(int *a1)
{
  int result; // eax

  result = kfree(*a1, 0x400u); /*0x11cb93*/
  *a1 = 0; /*0x11cb98*/
  return result; /*0x11cb9e*/
}
