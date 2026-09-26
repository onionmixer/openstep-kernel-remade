/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b7b8. */
_DWORD *__cdecl zget(int a1)
{
  int v1; // edx
  _DWORD *v2; // esi
  int v3; // eax

  if ( !a1 ) /*0x16b7c2*/
    panic(aZallocNullZone_0); /*0x16b7c9*/
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b7d5*/
  {
    lock_write(a1 + 48); /*0x16b7db*/
  }
  else
  {
    v1 = splhigh(); /*0x16b7ed*/
    do /*0x16b802*/
    {
      while ( *(_DWORD *)a1 ) /*0x16b7f0*/
        ; /*0x16b7f2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b802*/
    *(_DWORD *)(a1 + 4) = v1; /*0x16b804*/
  }
  v2 = *(_DWORD **)(a1 + 16); /*0x16b807*/
  if ( v2 ) /*0x16b80c*/
  {
    ++*(_DWORD *)(a1 + 8); /*0x16b80e*/
    *(_DWORD *)(a1 + 16) = *v2; /*0x16b813*/
    if ( *(_DWORD **)(a1 + 12) == v2 ) /*0x16b819*/
      *(_DWORD *)(a1 + 12) = 0; /*0x16b81b*/
  }
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b826*/
  {
    lock_done(a1 + 48); /*0x16b82c*/
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 4); /*0x16b834*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b839*/
    splx(v3); /*0x16b83c*/
  }
  return v2; /*0x16b846*/
}
