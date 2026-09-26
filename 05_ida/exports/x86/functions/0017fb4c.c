/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fb4c. */
int __cdecl KernBusInterruptSuspend(int a1)
{
  int v1; // edx
  int result; // eax

  if ( a1 ) /*0x17fb58*/
  {
    KernLockAcquire(*(_DWORD *)(a1 + 36)); /*0x17fb5e*/
    v1 = *(_DWORD *)(a1 + 32); /*0x17fb63*/
    *(_DWORD *)(a1 + 32) = v1 + 1; /*0x17fb69*/
    if ( v1 + 1 < 0 ) /*0x17fb74*/
      *(_DWORD *)(a1 + 32) = v1; /*0x17fb76*/
    return KernLockRelease(*(_DWORD *)(a1 + 36)); /*0x17fb7d*/
  }
  return result; /*0x17fb85*/
}
