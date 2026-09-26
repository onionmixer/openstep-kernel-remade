/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1584d4. */
int __cdecl mach_msg_abort_rpc(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx
  int result; // eax

  v1 = 0; /*0x1584dc*/
  v2 = (volatile __int32 *)(a1 + 168); /*0x1584de*/
  do /*0x1584f6*/
  {
    while ( *v2 ) /*0x1584e4*/
      ; /*0x1584e6*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x1584f6*/
  if ( *(_DWORD *)(a1 + 172) ) /*0x1584f8*/
  {
    v1 = *(_DWORD *)(a1 + 192); /*0x158501*/
    *(_DWORD *)(a1 + 192) = 0; /*0x158507*/
  }
  result = _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x158513*/
  if ( v1 ) /*0x15851b*/
    return ipc_port_dealloc_special(v1); /*0x158525*/
  return result; /*0x15852d*/
}
