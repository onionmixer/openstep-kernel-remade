/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15efb4. */
int __cdecl vnode_size(int a1)
{
  _BYTE v2[24]; // [esp+0h] [ebp-40h] BYREF
  int v3; // [esp+18h] [ebp-28h]

  (*(void (__stdcall **)(int, _BYTE *, _DWORD))(*(_DWORD *)(a1 + 28) + 20))(a1, v2, *(_DWORD *)(active_u + 28)); /*0x15efd1*/
  return v3; /*0x15efd6*/
}
