/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a248. */
int __cdecl vm_pager_get(_DWORD *a1, int a2, _DWORD *a3)
{
  if ( a1 ) /*0x17a253*/
  {
    if ( *a1 ) /*0x17a264*/
      device_pagein(a2); /*0x17a26a*/
    return vnode_pagein(a2, a3); /*0x17a279*/
  }
  else
  {
    vm_page_zero_fill(a2); /*0x17a256*/
    return 0; /*0x17a25b*/
  }
}
