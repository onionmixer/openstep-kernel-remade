/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1800e0. */
int __cdecl KernDeviceInterruptMsgRelease(int a1)
{
  char v1; // al
  char v2; // al

  ipc_object_reference(*(_DWORD *)(a1 + 44)); /*0x1800ee*/
  KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x1800f7*/
  v1 = *(_BYTE *)(a1 + 84); /*0x1800fc*/
  *(_BYTE *)(a1 + 84) = v1 & 0xFE; /*0x180104*/
  if ( (v1 & 4) == 0 ) /*0x18010c*/
    return KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180174*/
  KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180112*/
  KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x18011e*/
  v2 = *(_BYTE *)(a1 + 84); /*0x180123*/
  if ( (v2 & 3) != 0 ) /*0x18012b*/
  {
    *(_BYTE *)(a1 + 84) = v2 | 4; /*0x18012f*/
    return KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x180136*/
  }
  else
  {
    KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x18013c*/
    ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x180145*/
    ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x18014e*/
    objc_msgSend(*(id *)(a1 + 48), sel_free); /*0x18015e*/
    return kfree(a1, 0x58u); /*0x180166*/
  }
}
