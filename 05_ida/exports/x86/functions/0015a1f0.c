/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a1f0. */
int __cdecl convert_port_to_space(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0; /*0x15a1f8*/
  if ( a1 && a1 != -1 ) /*0x15a201*/
  {
    do /*0x15a216*/
    {
      while ( *(_DWORD *)a1 ) /*0x15a204*/
        ; /*0x15a206*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x15a216*/
    v2 = *(_DWORD *)(a1 + 8); /*0x15a218*/
    if ( v2 < 0 && (_WORD)v2 == 2 ) /*0x15a223*/
    {
      v1 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 136); /*0x15a228*/
      ipc_space_reference(v1); /*0x15a22f*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x15a236*/
  }
  return v1; /*0x15a23d*/
}
