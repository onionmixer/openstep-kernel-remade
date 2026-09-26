/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1469a0. */
int __cdecl ipc_hash_delete(int a1, int a2, unsigned int a3, int a4)
{
  if ( *(_DWORD *)(a1 + 24) > a3 >> 8 && a4 == *(_DWORD *)(a1 + 20) + 16 * (a3 >> 8) ) /*0x1469c6*/
    return ipc_hash_local_delete(a1, a2, a3 >> 8); /*0x1469cc*/
  else
    return ipc_hash_global_delete(a1, a2, a3, a4); /*0x1469d8*/
}
