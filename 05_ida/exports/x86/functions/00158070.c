/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158070. */
int __cdecl convert_port_to_pset_name(int a1)
{
  int v1; // esi

  v1 = 0; /*0x158078*/
  if ( a1 && a1 != -1 ) /*0x158081*/
  {
    do /*0x158096*/
    {
      while ( *(_DWORD *)a1 ) /*0x158084*/
        ; /*0x158086*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x158096*/
    if ( *(int *)(a1 + 8) < 0 && (unsigned int)(unsigned __int16)*(_DWORD *)(a1 + 8) - 6 <= 1 ) /*0x1580aa*/
    {
      v1 = *(_DWORD *)(a1 + 20); /*0x1580ac*/
      pset_reference(v1); /*0x1580b0*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1580b7*/
  }
  return v1; /*0x1580be*/
}
