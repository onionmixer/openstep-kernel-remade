/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106db4. */
int __cdecl uarea_init(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 132); /*0x106dba*/
  *(_DWORD *)(result + 36) = result + 4; /*0x106dc3*/
  return result; /*0x106dc8*/
}
