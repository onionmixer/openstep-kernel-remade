/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a1f4. */
unsigned int __cdecl timer_normalize(_DWORD *a1)
{
  unsigned int v1; // ecx
  unsigned int result; // eax

  v1 = *a1 / 0xF4240u; /*0x16a209*/
  a1[2] += v1; /*0x16a20e*/
  result = *a1 / 0xF4240u; /*0x16a217*/
  *a1 %= 0xF4240u; /*0x16a21c*/
  a1[1] += v1; /*0x16a21e*/
  return result; /*0x16a224*/
}
