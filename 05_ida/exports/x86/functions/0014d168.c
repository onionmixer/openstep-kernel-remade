/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d168. */
int __cdecl ipc_port_release_receive(int a1)
{
  int v1; // ebx
  int result; // eax

  do /*0x14d182*/
  {
    while ( *(_DWORD *)a1 ) /*0x14d170*/
      ; /*0x14d172*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14d182*/
  v1 = *(_DWORD *)(a1 + 12); /*0x14d184*/
  result = ipc_port_destroy(a1); /*0x14d188*/
  if ( v1 ) /*0x14d192*/
    return ipc_object_release(v1); /*0x14d195*/
  return result; /*0x14d19a*/
}
