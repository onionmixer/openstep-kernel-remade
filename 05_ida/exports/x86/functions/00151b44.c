/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151b44. */
int __cdecl ipc_table_alloc(vm_size_t a1)
{
  int v2; // [esp+0h] [ebp-4h] BYREF

  if ( page_size > a1 ) /*0x151b53*/
    return kalloc(a1); /*0x151b5b*/
  if ( kmem_alloc(kalloc_map, &v2, a1) ) /*0x151b6c*/
    return 0; /*0x151b75*/
  return v2; /*0x151b7f*/
}
