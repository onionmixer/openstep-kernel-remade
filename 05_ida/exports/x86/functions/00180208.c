/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180208. */
int __cdecl IODisableInterrupt(int a1)
{
  int v1; // esi
  int result; // eax
  char v3; // [esp+8h] [ebp-4h]

  KernLockAcquire(*(_DWORD *)(a1 + 8)); /*0x180217*/
  v1 = *(_DWORD *)(a1 + 4); /*0x18021c*/
  v3 = *(_BYTE *)(a1 + 24); /*0x180222*/
  *(_BYTE *)(a1 + 24) = 1; /*0x180225*/
  result = KernLockRelease(*(_DWORD *)(a1 + 8)); /*0x18022d*/
  if ( !v3 ) /*0x180239*/
    return KernBusInterruptSuspend(v1); /*0x18023c*/
  return result; /*0x180244*/
}
