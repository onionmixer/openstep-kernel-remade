/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cfa4. */
int __cdecl ipc_port_copy_send(int a1)
{
  int v2; // ecx

  if ( !a1 || a1 == -1 ) /*0x14cfb1*/
    return a1; /*0x14cfb3*/
  do /*0x14cfce*/
  {
    while ( *(_DWORD *)a1 ) /*0x14cfbc*/
      ; /*0x14cfbe*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14cfce*/
  if ( *(int *)(a1 + 8) >= 0 ) /*0x14cfd4*/
  {
    v2 = -1; /*0x14cfe0*/
  }
  else
  {
    ++*(_DWORD *)(a1 + 4); /*0x14cfd6*/
    ++*(_DWORD *)(a1 + 28); /*0x14cfd9*/
    v2 = a1; /*0x14cfdc*/
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14cfe7*/
  return v2; /*0x14cfb7*/
}
