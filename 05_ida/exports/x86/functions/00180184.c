/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180184. */
int __cdecl KernDeviceInterruptDispatch(int a1, int a2)
{
  return (*(int (__stdcall **)(int, int, _DWORD))(a1 + 12))(a1, a2, *(_DWORD *)(a1 + 16)); /*0x18019a*/
}
