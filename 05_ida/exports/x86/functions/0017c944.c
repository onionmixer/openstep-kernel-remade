/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c944. */
__int32 __cdecl vnode_pager_vput(int a1)
{
  do /*0x17c965*/
  {
    while ( vstruct_lock ) /*0x17c953*/
      ; /*0x17c951*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17c965*/
  --*(_WORD *)(a1 + 14); /*0x17c967*/
  return _InterlockedExchange(&vstruct_lock, 0); /*0x17c975*/
}
