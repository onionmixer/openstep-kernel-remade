/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1745b4. */
__int32 __cdecl kmem_free_wakeup(int a1, int a2, int a3)
{
  lock_write(a1); /*0x1745c4*/
  ++*(_DWORD *)(a1 + 76); /*0x1745c9*/
  vm_map_delete(a1, ~page_mask & a2, ~page_mask & (page_mask + a2 + a3)); /*0x1745e1*/
  thread_wakeup_prim(a1, 0, 0); /*0x1745eb*/
  return lock_done(a1); /*0x1745f9*/
}
