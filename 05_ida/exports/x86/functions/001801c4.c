/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1801c4. */
void __cdecl IOEnableInterrupt(int a1)
{
  int v1; // esi
  char v2; // [esp+8h] [ebp-4h]

  KernLockAcquire(*(_DWORD *)(a1 + 8)); /*0x1801d3*/
  v1 = *(_DWORD *)(a1 + 4); /*0x1801d8*/
  v2 = *(_BYTE *)(a1 + 24); /*0x1801de*/
  *(_BYTE *)(a1 + 24) = 0; /*0x1801e1*/
  KernLockRelease(*(_DWORD *)(a1 + 8)); /*0x1801e9*/
  if ( v2 ) /*0x1801f5*/
    KernBusInterruptResume(v1); /*0x1801f8*/
}
