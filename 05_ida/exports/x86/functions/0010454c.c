/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10454c. */
int __cdecl fioctl(int a1, int a2, int a3)
{
  return (*(int (__stdcall **)(int, int, int))(*(_DWORD *)(a1 + 20) + 4))(a1, a2, a3); /*0x104565*/
}
