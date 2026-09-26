/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157dd4. */
__int32 __cdecl ipc_pset_enable(int a1)
{
  volatile __int32 *v1; // edx
  volatile __int32 *v2; // edx

  v1 = (volatile __int32 *)(a1 + 344); /*0x157ddb*/
  do /*0x157df6*/
  {
    while ( *v1 ) /*0x157de4*/
      ; /*0x157de6*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x157df6*/
  if ( *(_DWORD *)(a1 + 340) ) /*0x157df8*/
  {
    ipc_kobject_set(*(_DWORD *)(a1 + 348), a1, 6); /*0x157e0b*/
    ipc_kobject_set(*(_DWORD *)(a1 + 352), a1, 7); /*0x157e1a*/
    v2 = (volatile __int32 *)(a1 + 328); /*0x157e1f*/
    do /*0x157e3a*/
    {
      while ( *v2 ) /*0x157e28*/
        ; /*0x157e2a*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x157e3a*/
    *(_DWORD *)(a1 + 324) += 2; /*0x157e3c*/
    _InterlockedExchange((volatile __int32 *)(a1 + 328), 0); /*0x157e45*/
  }
  return _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x157e53*/
}
