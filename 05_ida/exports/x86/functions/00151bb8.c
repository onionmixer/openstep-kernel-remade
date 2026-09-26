/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151bb8. */
int __cdecl ipc_table_free(unsigned int a1, int a2)
{
  if ( page_size <= a1 ) /*0x151bc7*/
    return kmem_free(kalloc_map, a2, a1); /*0x151bdd*/
  else
    return kfree(a2, a1); /*0x151bcb*/
}
