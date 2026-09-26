/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a244. */
int __cdecl convert_port_to_map(int a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0; /*0x15a24c*/
  if ( a1 && a1 != -1 ) /*0x15a255*/
  {
    do /*0x15a26a*/
    {
      while ( *(_DWORD *)a1 ) /*0x15a258*/
        ; /*0x15a25a*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x15a26a*/
    v2 = *(_DWORD *)(a1 + 8); /*0x15a26c*/
    if ( v2 < 0 && (_WORD)v2 == 2 ) /*0x15a277*/
    {
      v1 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12); /*0x15a27c*/
      vm_map_reference(v1); /*0x15a280*/
    }
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x15a287*/
  }
  return v1; /*0x15a28e*/
}
