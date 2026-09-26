/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d6c0. */
__int32 __cdecl ipc_pset_add(int a1, int a2)
{
  volatile __int32 *v2; // edx
  volatile __int32 *v3; // edx

  *(_DWORD *)(a2 + 48) = a1; /*0x14d6cc*/
  ++*(_DWORD *)(a1 + 4); /*0x14d6cf*/
  v2 = (volatile __int32 *)(a2 + 64); /*0x14d6d2*/
  do /*0x14d6ea*/
  {
    while ( *v2 ) /*0x14d6d8*/
      ; /*0x14d6da*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x14d6ea*/
  v3 = (volatile __int32 *)(a1 + 16); /*0x14d6ec*/
  do /*0x14d702*/
  {
    while ( *v3 ) /*0x14d6f0*/
      ; /*0x14d6f2*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14d702*/
  ipc_mqueue_move(a1 + 16, a2 + 64, a2); /*0x14d70d*/
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x14d717*/
  ipc_mqueue_changed(a2 + 64, 268451846); /*0x14d720*/
  return _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14d72d*/
}
