/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a54f8. */
int __cdecl IOGetTimestamp(int *a1)
{
  int result; // eax
  int v2; // edx

  result = clock_value(1); /*0x1a5501*/
  *a1 = result; /*0x1a5506*/
  a1[1] = v2; /*0x1a5508*/
  return result; /*0x1a550b*/
}
