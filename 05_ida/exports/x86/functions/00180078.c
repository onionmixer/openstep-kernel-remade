/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180078. */
int __cdecl sub_180078(int a1)
{
  char v1; // al

  KernLockAcquire(*(_DWORD *)(a1 + 48)); /*0x180083*/
  v1 = *(_BYTE *)(a1 + 84); /*0x180088*/
  if ( (v1 & 3) != 0 ) /*0x180090*/
  {
    *(_BYTE *)(a1 + 84) = v1 | 4; /*0x180094*/
    return KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x18009b*/
  }
  else
  {
    KernLockRelease(*(_DWORD *)(a1 + 48)); /*0x1800a8*/
    ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x1800b1*/
    ipc_object_release(*(_DWORD *)(a1 + 44)); /*0x1800ba*/
    objc_msgSend(*(id *)(a1 + 48), sel_free); /*0x1800ca*/
    return kfree(a1, 0x58u); /*0x1800d2*/
  }
}
