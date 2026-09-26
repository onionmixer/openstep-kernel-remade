/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bbec. */
int __cdecl ipc_object_copyin(int a1, unsigned int a2, int a3, int a4)
{
  int result; // eax
  int v5; // ebx
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int *v7; // [esp+10h] [ebp-4h] BYREF

  result = ipc_right_lookup_write(a1, a2, &v7); /*0x14bc01*/
  if ( !result ) /*0x14bc0d*/
  {
    v5 = ipc_right_copyin(a1, a2, v7, a3, 1, a4, &v6); /*0x14bc28*/
    if ( (*((_BYTE *)v7 + 2) & 0x1F) == 0 ) /*0x14bc34*/
      ipc_entry_dealloc((_DWORD *)a1, a2, v7); /*0x14bc39*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14bc43*/
    if ( !v5 ) /*0x14bc48*/
    {
      if ( v6 ) /*0x14bc4f*/
        ipc_notify_port_deleted(v6, a2); /*0x14bc53*/
    }
    return v5; /*0x14bc58*/
  }
  return result; /*0x14bc5d*/
}
