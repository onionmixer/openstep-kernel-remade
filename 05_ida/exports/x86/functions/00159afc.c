/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159afc. */
int __cdecl retrieve_thread_reply(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // ebx

  v1 = (volatile __int32 *)(a1 + 168); /*0x159b04*/
  do /*0x159b1e*/
  {
    while ( *v1 ) /*0x159b0c*/
      ; /*0x159b0e*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159b1e*/
  if ( *(_DWORD *)(a1 + 172) ) /*0x159b20*/
  {
    v2 = *(_DWORD *)(a1 + 184); /*0x159b29*/
    if ( v2 && v2 != -1 ) /*0x159b36*/
      ipc_object_reference(*(_DWORD *)(a1 + 184)); /*0x159b39*/
  }
  else
  {
    v2 = 0; /*0x159b40*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x159b44*/
  return v2; /*0x159b4f*/
}
