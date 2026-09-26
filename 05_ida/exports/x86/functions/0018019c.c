/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18019c. */
int __cdecl KernDeviceInterruptDispatchShared(int a1, int a2)
{
  int (__cdecl *v2)(int, int, _DWORD); // edi

  v2 = *(int (__cdecl **)(int, int, _DWORD))(a1 + 12); /*0x1801a8*/
  IODisableInterrupt(a1); /*0x1801ac*/
  return v2(a1, a2, *(_DWORD *)(a1 + 16)); /*0x1801bc*/
}
