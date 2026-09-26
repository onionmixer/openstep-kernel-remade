/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14b95c. */
int __cdecl ipc_object_alloc_dead_name(unsigned int a1, unsigned int a2)
{
  int result; // eax
  unsigned int *v3; // [esp+8h] [ebp-4h] BYREF

  result = ipc_entry_alloc_name(a1, a2, &v3); /*0x14b970*/
  if ( !result ) /*0x14b97a*/
  {
    if ( ipc_right_inuse(a1, a2, v3) ) /*0x14b982*/
    {
      return 13; /*0x14b9a0*/
    }
    else
    {
      *v3 |= 0x100001u; /*0x14b98e*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14b996*/
      return 0; /*0x14b999*/
    }
  }
  return result; /*0x14b9a8*/
}
