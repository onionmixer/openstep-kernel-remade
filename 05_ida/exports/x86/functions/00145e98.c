/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145e98. */
int *__cdecl ipc_entry_lookup(_DWORD *a1, unsigned int a2)
{
  int *v2; // ebx
  int v3; // ecx

  if ( a1[6] <= a2 >> 8 ) /*0x145eac*/
  {
    if ( !a1[14] ) /*0x145ee8*/
      return nullptr; /*0x145ee8*/
    return (int *)ipc_splay_tree_lookup(a1 + 8, a2); /*0x145ef4*/
  }
  v2 = (int *)(16 * (a2 >> 8) + a1[5]); /*0x145eb4*/
  v3 = *v2; /*0x145eb6*/
  if ( (*v2 & 0xFF000000) == a2 << 24 ) /*0x145ec7*/
  {
    if ( (v3 & 0x1F0000) != 0 ) /*0x145ede*/
      return v2; /*0x145ede*/
    return nullptr; /*0x145ede*/
  }
  if ( (v3 & 0x800000) != 0 ) /*0x145ecf*/
    return (int *)ipc_splay_tree_lookup(a1 + 8, a2); /*0x145ecf*/
  return nullptr; /*0x145efb*/
}
