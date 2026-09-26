/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a308. */
int __cdecl vm_pager_has_page(_DWORD *a1, int a2)
{
  if ( !a1 || *a1 ) /*0x17a313*/
    panic(aVmPagerHasPage); /*0x17a31d*/
  return vnode_has_page(a1, a2); /*0x17a32f*/
}
