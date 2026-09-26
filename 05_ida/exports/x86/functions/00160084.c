/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160084. */
int __cdecl vm_set_vnode_size(int *a1, int a2)
{
  int result; // eax

  result = *a1; /*0x16008a*/
  *(_DWORD *)(*a1 + 20) = a2; /*0x16008f*/
  return result; /*0x160094*/
}
