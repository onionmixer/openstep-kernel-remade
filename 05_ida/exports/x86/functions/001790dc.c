/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1790dc. */
__int32 vm_object_cache_trim()
{
  int v0; // ebx

  do /*0x1790f9*/
  {
    while ( vm_cache_lock ) /*0x1790e7*/
      ; /*0x1790e5*/
  }
  while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x1790f9*/
  while ( vm_object_cached > vm_cache_max ) /*0x17915e*/
  {
    v0 = vm_object_cached_list; /*0x179100*/
    _InterlockedExchange(&vm_cache_lock, 0); /*0x179108*/
    if ( v0 != vm_object_lookup(*(_DWORD *)(vm_object_cached_list + 40)) ) /*0x17911c*/
      panic(aVmObjectDeacti); /*0x179123*/
    vm_object_cache_object(v0, 0); /*0x17912e*/
    do /*0x179151*/
    {
      while ( vm_cache_lock ) /*0x17913f*/
        ; /*0x17913d*/
    }
    while ( _InterlockedExchange(&vm_cache_lock, 1) == 1 ); /*0x179151*/
  }
  return _InterlockedExchange(&vm_cache_lock, 0); /*0x179168*/
}
