/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ef18. */
__int32 __cdecl mfs_map_remove(__int32 a1, int a2, int a3, int a4)
{
  __int32 result; // eax
  int v5; // ebx
  volatile __int32 *v6; // edx

  if ( a4 ) /*0x15ef23*/
    vmp_push(a1); /*0x15ef26*/
  lock_write((int)mfs_alloc_lock_data); /*0x15ef33*/
  vm_map_remove(mfs_map, a2, a3); /*0x15ef47*/
  if ( mfs_alloc_wanted ) /*0x15ef56*/
  {
    mfs_alloc_wanted = 0; /*0x15ef58*/
    thread_wakeup_prim(&mfs_map, 0, 0); /*0x15ef6b*/
  }
  result = lock_done((int)mfs_alloc_lock_data); /*0x15ef78*/
  v5 = *(_DWORD *)(a1 + 36); /*0x15ef7d*/
  if ( v5 ) /*0x15ef85*/
  {
    v6 = (volatile __int32 *)(v5 + 16); /*0x15ef87*/
    do /*0x15ef9e*/
    {
      while ( *v6 ) /*0x15ef8c*/
        ; /*0x15ef8e*/
    }
    while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15ef9e*/
    vm_object_deactivate_pages((_DWORD *)v5); /*0x15efa1*/
    return _InterlockedExchange((volatile __int32 *)(v5 + 16), 0); /*0x15efa8*/
  }
  return result; /*0x15efab*/
}
