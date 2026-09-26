/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fb8c. */
void __cdecl KernBusInterruptResume(int a1)
{
  int v1; // eax

  if ( a1 ) /*0x17fb98*/
  {
    KernLockAcquire(*(_DWORD *)(a1 + 36)); /*0x17fb9e*/
    v1 = *(_DWORD *)(a1 + 32); /*0x17fba3*/
    if ( v1 > 0 ) /*0x17fbab*/
      *(_DWORD *)(a1 + 32) = v1 - 1; /*0x17fbae*/
    KernLockRelease(*(_DWORD *)(a1 + 36)); /*0x17fbb5*/
  }
}
