/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157f98. */
int __cdecl convert_port_to_host_priv(int a1)
{
  int v1; // ecx
  int v2; // eax

  v1 = 0; /*0x157f9e*/
  if ( a1 && a1 != -1 ) /*0x157fa7*/
  {
    do /*0x157fbe*/
    {
      while ( *(_DWORD *)a1 ) /*0x157fac*/
        ; /*0x157fae*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x157fbe*/
    v2 = *(_DWORD *)(a1 + 8); /*0x157fc0*/
    if ( v2 < 0 && (_WORD)v2 == 4 ) /*0x157fcb*/
      v1 = *(_DWORD *)(a1 + 20); /*0x157fcd*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x157fd2*/
  }
  return v1; /*0x157fd8*/
}
