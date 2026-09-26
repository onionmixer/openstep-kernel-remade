/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a1a0. */
int __cdecl convert_port_to_task(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0; /*0x15a1a8*/
  if ( a1 && a1 != -1 ) /*0x15a1b1*/
  {
    do /*0x15a1c6*/
    {
      while ( *(_DWORD *)a1 ) /*0x15a1b4*/
        ; /*0x15a1b6*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x15a1c6*/
    v2 = *(_DWORD *)(a1 + 8); /*0x15a1c8*/
    if ( v2 < 0 && (_WORD)v2 == 2 ) /*0x15a1d3*/
    {
      v1 = *(_DWORD *)(a1 + 20); /*0x15a1d5*/
      task_reference(v1); /*0x15a1d9*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x15a1e0*/
  }
  return v1; /*0x15a1e7*/
}
