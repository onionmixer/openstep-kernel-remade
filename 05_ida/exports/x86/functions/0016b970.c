/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b970. */
__int32 zone_gc()
{
  int v0; // edi
  int v1; // ebx
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // eax

  do /*0x16b991*/
  {
    while ( all_zones_lock ) /*0x16b97f*/
      ; /*0x16b97d*/
  }
  while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16b991*/
  v0 = num_zones; /*0x16b993*/
  v1 = first_zone; /*0x16b999*/
  _InterlockedExchange(&all_zones_lock, 0); /*0x16b9a1*/
  do /*0x16b9c1*/
  {
    while ( zget_space_lock ) /*0x16b9af*/
      ; /*0x16b9ad*/
  }
  while ( _InterlockedExchange(&zget_space_lock, 1) == 1 ); /*0x16b9c1*/
  v2 = 0; /*0x16b9c3*/
  if ( num_zones > 0 ) /*0x16b9c7*/
  {
    do /*0x16ba70*/
    {
      if ( (*(_BYTE *)(v1 + 44) & 1) != 0 ) /*0x16b9d4*/
      {
        lock_write(v1 + 48); /*0x16b9da*/
      }
      else
      {
        v3 = splhigh(); /*0x16b9e9*/
        do /*0x16b9fe*/
        {
          while ( *(_DWORD *)v1 ) /*0x16b9ec*/
            ; /*0x16b9ee*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v1, 1) == 1 ); /*0x16b9fe*/
        *(_DWORD *)(v1 + 4) = v3; /*0x16ba00*/
      }
      if ( (*(_BYTE *)(v1 + 44) & 1) != 0 ) /*0x16ba07*/
        goto LABEL_18; /*0x16ba07*/
      v4 = *(_DWORD **)(v1 + 60); /*0x16ba09*/
      if ( v4 && v4 != _zone_default_space ) /*0x16ba15*/
        zone_collect((_DWORD *)v1); /*0x16ba18*/
      if ( (*(_BYTE *)(v1 + 44) & 1) != 0 ) /*0x16ba24*/
      {
LABEL_18:
        lock_done(v1 + 48); /*0x16ba2a*/
      }
      else
      {
        v5 = *(_DWORD *)(v1 + 4); /*0x16ba34*/
        _InterlockedExchange((volatile __int32 *)v1, 0); /*0x16ba39*/
        splx(v5); /*0x16ba3c*/
      }
      do /*0x16ba60*/
      {
        while ( all_zones_lock ) /*0x16ba4e*/
          ; /*0x16ba4c*/
      }
      while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16ba60*/
      v1 = *(_DWORD *)(v1 + 64); /*0x16ba62*/
      _InterlockedExchange(&all_zones_lock, 0); /*0x16ba67*/
      ++v2; /*0x16ba6d*/
    }
    while ( v2 < v0 ); /*0x16ba70*/
  }
  return zone_free_space_reclaim(); /*0x16ba7e*/
}
