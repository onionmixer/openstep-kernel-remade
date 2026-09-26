/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161ef4. */
int __cdecl remqueue(int a1, _DWORD *a2)
{
  int result; // eax

  *(_DWORD *)(*a2 + 4) = a2[1]; /*0x161eff*/
  result = *a2; /*0x161f05*/
  *(_DWORD *)a2[1] = *a2; /*0x161f07*/
  return result; /*0x161f0b*/
}
