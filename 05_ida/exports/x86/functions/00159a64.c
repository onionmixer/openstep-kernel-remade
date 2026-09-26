/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159a64. */
int mach_reply_port()
{
  volatile __int32 *v1; // [esp+0h] [ebp-8h] BYREF
  int v2; // [esp+4h] [ebp-4h] BYREF

  if ( ipc_port_alloc(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 136), &v2, &v1) ) /*0x159a81*/
    return 0; /*0x159a94*/
  _InterlockedExchange(v1, 0); /*0x159a8f*/
  return v2; /*0x159a9e*/
}
