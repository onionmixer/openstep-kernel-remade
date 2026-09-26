/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c978. */
int __cdecl vnode_pager_vget(int a1)
{
  do /*0x17c999*/
  {
    while ( vstruct_lock ) /*0x17c987*/
      ; /*0x17c985*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17c999*/
  ++*(_WORD *)(a1 + 14); /*0x17c99b*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17c9a1*/
  return *(_DWORD *)(a1 + 20); /*0x17c9ac*/
}
