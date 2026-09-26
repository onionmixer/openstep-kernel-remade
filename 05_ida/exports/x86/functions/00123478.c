/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123478. */
_BOOL4 __cdecl inet_netmatch(int a1, int a2)
{
  int v2; // esi

  v2 = in_netof(*(_DWORD *)(a1 + 4)); /*0x12348c*/
  return v2 == in_netof(*(_DWORD *)(a2 + 4)); /*0x1234a4*/
}
