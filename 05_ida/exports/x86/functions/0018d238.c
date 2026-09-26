/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d238. */
int __cdecl stack_detach(int a1)
{
  int v1; // edx

  v1 = *(_DWORD *)(a1 + 44); /*0x18d23e*/
  *(_DWORD *)(a1 + 44) = 0; /*0x18d241*/
  return v1; /*0x18d24c*/
}
