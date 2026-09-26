/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1600b8. */
int __cdecl vm_set_error(int *a1, int a2)
{
  int result; // eax

  result = *a1; /*0x1600be*/
  *(_DWORD *)(*a1 + 52) = a2; /*0x1600c3*/
  return result; /*0x1600c8*/
}
