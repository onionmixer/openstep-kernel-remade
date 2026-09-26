/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c428. */
int gc_control()
{
  _BYTE *v0; // ebx
  int result; // eax

  v0 = *(_BYTE **)(dword_1E875C + 36); /*0x17c431*/
  result = suser(); /*0x17c434*/
  if ( result ) /*0x17c43b*/
  {
    do /*0x17c45d*/
    {
      while ( gc_lock ) /*0x17c44b*/
        ; /*0x17c449*/
    }
    while ( _InterlockedExchange(&gc_lock, 1) == 1 ); /*0x17c45d*/
    if ( !gc_active ) /*0x17c466*/
    {
      gc_active = 1; /*0x17c468*/
      _InterlockedExchange(&gc_lock, 0); /*0x17c474*/
      if ( (*v0 & 1) != 0 ) /*0x17c47d*/
      {
        mfs_cache_clear(); /*0x17c47f*/
        vm_object_cache_clear(); /*0x17c484*/
        inode_cache_clear(); /*0x17c489*/
        rnode_cache_clear(); /*0x17c48e*/
        proc_cache_clear(); /*0x17c493*/
      }
      if ( (*v0 & 2) != 0 ) /*0x17c49b*/
        zone_gc(); /*0x17c49d*/
      if ( (*v0 & 4) != 0 ) /*0x17c4a5*/
        zone_reclaim(); /*0x17c4a7*/
      do /*0x17c4c5*/
      {
        while ( gc_lock ) /*0x17c4b3*/
          ; /*0x17c4b1*/
      }
      while ( _InterlockedExchange(&gc_lock, 1) == 1 ); /*0x17c4c5*/
      gc_active = 0; /*0x17c4c7*/
    }
    return _InterlockedExchange(&gc_lock, 0); /*0x17c4d3*/
  }
  return result; /*0x17c4d9*/
}
