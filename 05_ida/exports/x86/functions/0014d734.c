/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d734. */
__int32 __cdecl ipc_pset_remove(int a1, int a2)
{
  volatile __int32 *v2; // edx
  volatile __int32 *v3; // edx

  *(_DWORD *)(a2 + 48) = 0; /*0x14d73f*/
  --*(_DWORD *)(a1 + 4); /*0x14d746*/
  v2 = (volatile __int32 *)(a2 + 64); /*0x14d749*/
  do /*0x14d75e*/
  {
    while ( *v2 ) /*0x14d74c*/
      ; /*0x14d74e*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x14d75e*/
  v3 = (volatile __int32 *)(a1 + 16); /*0x14d760*/
  do /*0x14d776*/
  {
    while ( *v3 ) /*0x14d764*/
      ; /*0x14d766*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14d776*/
  ipc_mqueue_move(a2 + 64, a1 + 16, a2); /*0x14d781*/
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x14d788*/
  return _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14d793*/
}
