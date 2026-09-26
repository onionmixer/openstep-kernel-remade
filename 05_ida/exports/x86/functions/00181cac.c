/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181cac. */
int __cdecl convert_port_to_dev(int a1)
{
  int v1; // ecx

  v1 = 0; /*0x181caf*/
  if ( !a1 ) /*0x181cb6*/
    return 0; /*0x181cb8*/
  do /*0x181cd2*/
  {
    while ( *(_DWORD *)a1 ) /*0x181cc0*/
      ; /*0x181cc2*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x181cd2*/
  if ( *(_WORD *)(a1 + 8) == 12 ) /*0x181cd9*/
    v1 = *(_DWORD *)(a1 + 20); /*0x181cdb*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x181ce0*/
  return v1; /*0x181cbc*/
}
