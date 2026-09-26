/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a284. */
int __cdecl vm_pager_put(_DWORD *a1, int a2)
{
  if ( !a1 ) /*0x17a291*/
    panic(aVmPagerPutNull); /*0x17a298*/
  if ( *a1 ) /*0x17a2a0*/
    device_pageout(a2); /*0x17a2a6*/
  return vnode_pageout(a2); /*0x17a2b9*/
}
