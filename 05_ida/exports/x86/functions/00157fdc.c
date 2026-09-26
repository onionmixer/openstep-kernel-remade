/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157fdc. */
int __cdecl convert_port_to_processor(int a1)
{
  int v1; // ecx
  int v2; // eax

  v1 = 0; /*0x157fe2*/
  if ( a1 && a1 != -1 ) /*0x157feb*/
  {
    do /*0x158002*/
    {
      while ( *(_DWORD *)a1 ) /*0x157ff0*/
        ; /*0x157ff2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x158002*/
    v2 = *(_DWORD *)(a1 + 8); /*0x158004*/
    if ( v2 < 0 && (_WORD)v2 == 5 ) /*0x15800f*/
      v1 = *(_DWORD *)(a1 + 20); /*0x158011*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x158016*/
  }
  return v1; /*0x15801c*/
}
