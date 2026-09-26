/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c6a0. */
int __cdecl ipc_port_nsrequest(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v4; // esi
  unsigned int v5; // ecx
  int result; // eax

  v4 = *(_DWORD *)(a1 + 36); /*0x14c6af*/
  v5 = *(_DWORD *)(a1 + 24); /*0x14c6b2*/
  if ( *(_DWORD *)(a1 + 28) || a2 > v5 || !a3 ) /*0x14c6c2*/
  {
    *(_DWORD *)(a1 + 36) = a3; /*0x14c6d8*/
    result = _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c6dd*/
  }
  else
  {
    *(_DWORD *)(a1 + 36) = 0; /*0x14c6c4*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14c6cd*/
    result = ipc_notify_no_senders(a3, v5); /*0x14c6d1*/
  }
  *a4 = v4; /*0x14c6df*/
  return result; /*0x14c6e4*/
}
