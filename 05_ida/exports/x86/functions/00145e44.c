/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145e44. */
int __cdecl ipc_entry_tree_collision(int a1, unsigned int a2)
{
  unsigned int v2; // edx
  int v3; // ecx
  unsigned int v5; // [esp+4h] [ebp-8h] BYREF
  unsigned int v6; // [esp+8h] [ebp-4h] BYREF

  ipc_splay_tree_bounds(a1 + 32, a2, &v6, &v5); /*0x145e5e*/
  v2 = a2 >> 8; /*0x145e65*/
  v3 = 0; /*0x145e68*/
  if ( v6 != -1 && v6 >> 8 == v2 || v5 && v5 >> 8 == v2 ) /*0x145e85*/
    return 1; /*0x145e87*/
  return v3; /*0x145e8e*/
}
