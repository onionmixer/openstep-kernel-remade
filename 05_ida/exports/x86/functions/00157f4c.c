/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157f4c. */
int __cdecl convert_port_to_host(int a1)
{
  int v1; // ecx

  v1 = 0; /*0x157f52*/
  if ( a1 && a1 != -1 ) /*0x157f5b*/
  {
    do /*0x157f72*/
    {
      while ( *(_DWORD *)a1 ) /*0x157f60*/
        ; /*0x157f62*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x157f72*/
    if ( *(int *)(a1 + 8) < 0 && (unsigned int)(unsigned __int16)*(_DWORD *)(a1 + 8) - 3 <= 1 ) /*0x157f86*/
      v1 = *(_DWORD *)(a1 + 20); /*0x157f88*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x157f8d*/
  }
  return v1; /*0x157f93*/
}
