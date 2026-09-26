/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1795f8. */
__int32 __cdecl vm_object_setpager(int a1, int a2, int a3)
{
  volatile __int32 *v3; // edx

  v3 = (volatile __int32 *)(a1 + 16); /*0x1795ff*/
  do /*0x179616*/
  {
    while ( *v3 ) /*0x179604*/
      ; /*0x179606*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x179616*/
  *(_DWORD *)(a1 + 40) = a2; /*0x17961b*/
  *(_DWORD *)(a1 + 44) = a3; /*0x179621*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179629*/
}
