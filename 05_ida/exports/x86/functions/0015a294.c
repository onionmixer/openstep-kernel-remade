/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a294. */
int __cdecl convert_port_to_thread(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0; /*0x15a29c*/
  if ( a1 && a1 != -1 ) /*0x15a2a5*/
  {
    do /*0x15a2ba*/
    {
      while ( *(_DWORD *)a1 ) /*0x15a2a8*/
        ; /*0x15a2aa*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x15a2ba*/
    v2 = *(_DWORD *)(a1 + 8); /*0x15a2bc*/
    if ( v2 < 0 && (_WORD)v2 == 1 ) /*0x15a2c7*/
    {
      v1 = *(_DWORD *)(a1 + 20); /*0x15a2c9*/
      thread_reference(v1); /*0x15a2cd*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x15a2d4*/
  }
  return v1; /*0x15a2db*/
}
