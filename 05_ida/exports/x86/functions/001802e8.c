/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1802e8. */
int __cdecl sub_1802E8(int a1)
{
  int result; // eax
  char v2; // al
  char v3; // al

  KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x1802f3*/
  *(_BYTE *)(a1 + 84) = *(_BYTE *)(a1 + 84) & 0xFC | 1; /*0x1802ff*/
  KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180306*/
  result = ipc_mqueue_send(a1, 65552, 0, 0); /*0x180315*/
  if ( result ) /*0x18031f*/
  {
    ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x180329*/
    ipc_object_reference(*(_DWORD *)(a1 + 44)); /*0x180335*/
    KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x18033e*/
    v2 = *(_BYTE *)(a1 + 84); /*0x180343*/
    *(_BYTE *)(a1 + 84) = v2 & 0xFE; /*0x18034b*/
    if ( (v2 & 4) != 0 ) /*0x180353*/
    {
      KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180359*/
      KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x180365*/
      v3 = *(_BYTE *)(a1 + 84); /*0x18036a*/
      if ( (v3 & 3) == 0 ) /*0x180372*/
      {
        KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180378*/
        ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x180381*/
        ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x18038a*/
        objc_msgSend(*(id *)(a1 + 48), sel_free); /*0x18039a*/
        return kfree(a1, 0x58u); /*0x1803a7*/
      }
      *(_BYTE *)(a1 + 84) = v3 | 4; /*0x1803ae*/
    }
    return KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x1803b5*/
  }
  return result; /*0x1803ba*/
}
