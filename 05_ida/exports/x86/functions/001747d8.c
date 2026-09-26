/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1747d8. */
void __cdecl vm_map_deallocate(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // ecx

  if ( a1 ) /*0x1747e1*/
  {
    v1 = (volatile __int32 *)(a1 + 52); /*0x1747e3*/
    do /*0x1747fa*/
    {
      while ( *v1 ) /*0x1747e8*/
        ; /*0x1747ea*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1747fa*/
    v2 = *(_DWORD *)(a1 + 48) - 1; /*0x1747ff*/
    *(_DWORD *)(a1 + 48) = v2; /*0x174802*/
    _InterlockedExchange((volatile __int32 *)(a1 + 52), 0); /*0x174808*/
    if ( v2 <= 0 ) /*0x17480d*/
    {
      lock_write(a1); /*0x174810*/
      ++*(_DWORD *)(a1 + 76); /*0x174815*/
      vm_map_delete(a1, *(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 24)); /*0x174824*/
      pmap_destroy(*(_DWORD *)(a1 + 36)); /*0x17482d*/
      zfree(vm_map_zone, (_DWORD *)a1); /*0x17483a*/
    }
  }
}
