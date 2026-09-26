/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a2c0. */
int __cdecl vm_pager_deallocate(_DWORD *a1)
{
  if ( !a1 ) /*0x17a2c9*/
    panic(aVmPagerDealloc); /*0x17a2d0*/
  if ( *a1 ) /*0x17a2d8*/
    return device_dealloc(a1); /*0x17a2de*/
  else
    return vnode_dealloc(a1); /*0x17a2e9*/
}
