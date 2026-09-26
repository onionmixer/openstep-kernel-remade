/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10daa0. */
int __cdecl soo_stat(int a1, void *a2)
{
  bzero(a2, 0x40u); /*0x10daae*/
  return (*(int (__cdecl **)(int, int, void *, _DWORD, _DWORD))(*(_DWORD *)(a1 + 12) + 28))(a1, 12, a2, 0, 0); /*0x10dac6*/
}
