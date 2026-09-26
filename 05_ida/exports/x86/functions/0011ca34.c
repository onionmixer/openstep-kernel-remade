/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ca34. */
int __cdecl pn_set(int *a1, int a2)
{
  int v2; // ecx
  int result; // eax

  v2 = *a1; /*0x11ca3e*/
  a1[1] = *a1; /*0x11ca40*/
  result = copystr(a2, v2, 1024, a1 + 2); /*0x11ca4e*/
  --a1[2]; /*0x11ca53*/
  return result; /*0x11ca56*/
}
