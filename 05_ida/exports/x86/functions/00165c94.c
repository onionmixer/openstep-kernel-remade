/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165c94. */
void __cdecl task_reference(int a1)
{
  if ( a1 ) /*0x165c9c*/
  {
    do /*0x165cb2*/
    {
      while ( *(_DWORD *)a1 ) /*0x165ca0*/
        ; /*0x165ca2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x165cb2*/
    ++*(_DWORD *)(a1 + 4); /*0x165cb4*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x165cb9*/
  }
}
