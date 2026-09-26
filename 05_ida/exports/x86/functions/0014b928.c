/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b928. */
int __cdecl ipc_object_alloc_dead(int a1, _DWORD *a2)
{
  int result; // eax
  int *v3; // [esp+4h] [ebp-4h] BYREF

  result = ipc_entry_alloc(a1, a2, &v3); /*0x14b93b*/
  if ( !result ) /*0x14b942*/
  {
    *v3 |= 0x100001u; /*0x14b947*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14b94f*/
    return 0; /*0x14b952*/
  }
  return result; /*0x14b954*/
}
