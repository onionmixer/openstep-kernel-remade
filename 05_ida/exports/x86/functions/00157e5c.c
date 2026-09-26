/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157e5c. */
__int32 __cdecl ipc_pset_disable(int a1)
{
  volatile __int32 *v1; // edx

  ipc_kobject_set(*(_DWORD *)(a1 + 348), 0, 0); /*0x157e6e*/
  ipc_kobject_set(*(_DWORD *)(a1 + 352), 0, 0); /*0x157e7e*/
  v1 = (volatile __int32 *)(a1 + 328); /*0x157e83*/
  do /*0x157e9e*/
  {
    while ( *v1 ) /*0x157e8c*/
      ; /*0x157e8e*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x157e9e*/
  *(_DWORD *)(a1 + 324) -= 2; /*0x157ea0*/
  return _InterlockedExchange((volatile __int32 *)(a1 + 328), 0); /*0x157eaf*/
}
