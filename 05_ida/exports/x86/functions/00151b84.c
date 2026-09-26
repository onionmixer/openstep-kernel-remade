/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151b84. */
int __cdecl ipc_table_realloc(int a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-4h] BYREF

  if ( kmem_realloc(kalloc_map, a2, a1, &v4, a3) ) /*0x151ba1*/
    return 0; /*0x151baa*/
  return v4; /*0x151bb4*/
}
