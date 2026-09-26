/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150a1c. */
_BOOL4 __cdecl ipc_splay_tree_pick(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // eax

  v3 = *(_DWORD *)(a1 + 4); /*0x150a29*/
  if ( v3 ) /*0x150a2e*/
  {
    *a2 = *(_DWORD *)(v3 + 16); /*0x150a33*/
    *a3 = v3; /*0x150a35*/
  }
  return v3 != 0; /*0x150a41*/
}
