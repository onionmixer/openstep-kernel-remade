/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138580. */
int __cdecl xdrmbuf_getpos(int a1)
{
  return *(_DWORD *)(a1 + 12) - (*(_DWORD *)(*(_DWORD *)(a1 + 16) + 4) + *(_DWORD *)(a1 + 16)); /*0x138595*/
}
