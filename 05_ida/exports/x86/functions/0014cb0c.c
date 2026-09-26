/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cb0c. */
int __cdecl ipc_port_delete_compat(int a1, int a2, int a3)
{
  int v3; // ebx
  int v5; // [esp+Ch] [ebp-4h] BYREF

  if ( !ipc_right_lookup_write(a2, a3, &v5) ) /*0x14cb24*/
  {
    if ( *(_DWORD *)(v5 + 4) == a1 ) /*0x14cb36*/
    {
      v3 = ipc_port_copy_send(*(_DWORD *)(a2 + 68)); /*0x14cb41*/
      ipc_right_destroy(a2, a3, v5); /*0x14cb49*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x14cb56*/
      v3 = 0; /*0x14cb59*/
    }
    if ( v3 && v3 != -1 ) /*0x14cb62*/
      ipc_notify_port_deleted_compat(v3, a3); /*0x14cb66*/
  }
  return ipc_space_release(a2); /*0x14cb77*/
}
