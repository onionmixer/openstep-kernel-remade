/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14c7ec. */
__int32 __cdecl ipc_port_set_seqno(int a1, int a2)
{
  int v2; // ebx
  volatile __int32 *v3; // edx
  volatile __int32 *v4; // edx
  int v5; // eax
  volatile __int32 *v6; // edx

  if ( *(_DWORD *)(a1 + 48) ) /*0x14c7f4*/
  {
    v2 = *(_DWORD *)(a1 + 48); /*0x14c7fb*/
    do /*0x14c812*/
    {
      while ( *(_DWORD *)v2 ) /*0x14c800*/
        ; /*0x14c802*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x14c812*/
    if ( *(int *)(v2 + 8) < 0 ) /*0x14c818*/
    {
      v3 = (volatile __int32 *)(v2 + 16); /*0x14c81a*/
      do /*0x14c832*/
      {
        while ( *v3 ) /*0x14c820*/
          ; /*0x14c822*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14c832*/
      _InterlockedExchange((volatile __int32 *)v2, 0); /*0x14c836*/
      v4 = (volatile __int32 *)(v2 + 16); /*0x14c838*/
      goto LABEL_16; /*0x14c83b*/
    }
    ipc_pset_remove(v2, a1); /*0x14c842*/
    v5 = *(_DWORD *)(v2 + 4); /*0x14c84a*/
    _InterlockedExchange((volatile __int32 *)v2, 0); /*0x14c84f*/
    if ( !v5 ) /*0x14c853*/
      zfree(ipc_object_zones[*(_WORD *)(v2 + 10) & 0x7FFF], v2); /*0x14c867*/
  }
  v6 = (volatile __int32 *)(a1 + 64); /*0x14c86c*/
  do /*0x14c882*/
  {
    while ( *v6 ) /*0x14c870*/
      ; /*0x14c872*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x14c882*/
  v4 = (volatile __int32 *)(a1 + 64); /*0x14c884*/
LABEL_16:
  *(_DWORD *)(a1 + 52) = a2; /*0x14c887*/
  return _InterlockedExchange(v4, 0); /*0x14c894*/
}
