/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cf74. */
int __cdecl ipc_port_make_send(int a1)
{
  do /*0x14cf8e*/
  {
    while ( *(_DWORD *)a1 ) /*0x14cf7c*/
      ; /*0x14cf7e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14cf8e*/
  ++*(_DWORD *)(a1 + 24); /*0x14cf90*/
  ++*(_DWORD *)(a1 + 28); /*0x14cf93*/
  ++*(_DWORD *)(a1 + 4); /*0x14cf96*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14cf9b*/
  return a1; /*0x14cfa1*/
}
