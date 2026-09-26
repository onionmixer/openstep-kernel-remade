/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c28c. */
int __cdecl device_dealloc(_DWORD *a1)
{
  int *i; // ebx

  for ( i = (int *)a1[1]; (int *)*i != i; vm_page_remove(*i) ) /*0x17c294*/
    ; /*0x17c29f*/
  return kfree(a1[2], a1[3]); /*0x17c2bb*/
}
