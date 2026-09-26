/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158020. */
int __cdecl convert_port_to_pset(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0; /*0x158028*/
  if ( a1 && a1 != -1 ) /*0x158031*/
  {
    do /*0x158046*/
    {
      while ( *(_DWORD *)a1 ) /*0x158034*/
        ; /*0x158036*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x158046*/
    v2 = *(_DWORD *)(a1 + 8); /*0x158048*/
    if ( v2 < 0 && (_WORD)v2 == 6 ) /*0x158053*/
    {
      v1 = *(_DWORD *)(a1 + 20); /*0x158055*/
      pset_reference(v1); /*0x158059*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x158060*/
  }
  return v1; /*0x158067*/
}
