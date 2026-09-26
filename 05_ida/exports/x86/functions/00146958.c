/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146958. */
int __cdecl ipc_hash_insert(int a1, int a2, unsigned int a3, int a4)
{
  if ( *(_DWORD *)(a1 + 24) > a3 >> 8 && a4 == *(_DWORD *)(a1 + 20) + 16 * (a3 >> 8) ) /*0x14697e*/
    return ipc_hash_local_insert(a1, a2, a3 >> 8); /*0x146984*/
  else
    return ipc_hash_global_insert(a1, a2, a3, a4); /*0x146990*/
}
