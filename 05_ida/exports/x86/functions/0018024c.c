/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18024c. */
int __cdecl IOSendInterrupt(int a1, int a2, int a3)
{
  int v3; // ebx
  int result; // eax
  char v5; // al

  v3 = *(_DWORD *)(a1 + 20); /*0x180255*/
  result = curipl(); /*0x180258*/
  if ( result <= 6 ) /*0x180260*/
  {
    KernLockAcquire(*(_DWORD *)(v3 + 48)); /*0x180266*/
    v5 = *(_BYTE *)(v3 + 84); /*0x18026b*/
    if ( (v5 & 3) != 0 ) /*0x180273*/
    {
      return KernLockRelease(*(_DWORD *)(v3 + 48)); /*0x180279*/
    }
    else
    {
      *(_BYTE *)(v3 + 84) = v5 | 1; /*0x180282*/
      KernLockRelease(*(_DWORD *)(v3 + 48)); /*0x180289*/
      qmemcpy((void *)(v3 + 20), &unk_1E0FD0, 0x18u); /*0x18029c*/
      *(_DWORD *)(v3 + 40) = a3; /*0x1802a1*/
      *(_DWORD *)(v3 + 28) = *(_DWORD *)(v3 + 44); /*0x1802a7*/
      result = ipc_mqueue_send_interrupt(v3); /*0x1802ab*/
      if ( result ) /*0x1802b5*/
      {
        KernLockAcquire(*(_DWORD *)(v3 + 48)); /*0x1802bb*/
        *(_BYTE *)(v3 + 84) = *(_BYTE *)(v3 + 84) & 0xFC | 2; /*0x1802c7*/
        KernLockRelease(*(_DWORD *)(v3 + 48)); /*0x1802ce*/
        return calloutEntryDispatch(v3 + 52); /*0x1802d7*/
      }
    }
  }
  return result; /*0x1802df*/
}
