/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146908. */
int __cdecl ipc_hash_lookup(int a1, int a2, int a3, int a4)
{
  int v4; // esi

  v4 = 0; /*0x146914*/
  if ( ipc_hash_local_lookup(a1, a2, a3, a4) || *(_DWORD *)(a1 + 64) && ipc_hash_global_lookup(a1, a2, a3, a4) ) /*0x14693c*/
    return 1; /*0x146945*/
  return v4; /*0x14694f*/
}
