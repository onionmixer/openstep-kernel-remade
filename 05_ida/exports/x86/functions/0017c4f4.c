/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c4f4. */
int __cdecl vm_allocate_with_pager(int a1, unsigned int *a2, int a3, int a4, int a5, int a6)
{
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // esi

  if ( !a1 ) /*0x17c504*/
    return 4; /*0x17c506*/
  *a2 &= ~page_mask; /*0x17c51a*/
  v7 = ~page_mask & (page_mask + a3); /*0x17c528*/
  lock_write((int)vm_alloc_lock); /*0x17c52f*/
  v8 = vm_object_lookup(a5); /*0x17c53a*/
  ++dword_1F651C; /*0x17c53c*/
  if ( v8 ) /*0x17c547*/
  {
    ++dword_1F6520; /*0x17c570*/
  }
  else
  {
    v9 = vm_object_allocate(v7); /*0x17c54a*/
    v8 = v9; /*0x17c54f*/
    if ( a5 ) /*0x17c556*/
    {
      vm_object_setpager(v9, a5, 0); /*0x17c55e*/
      vm_object_enter(v8, a5); /*0x17c565*/
    }
  }
  lock_done((int)vm_alloc_lock); /*0x17c57b*/
  *(_BYTE *)(v8 + 70) &= ~0x10u; /*0x17c580*/
  v10 = vm_map_find(a1, v8, a6, a2, v7, a4); /*0x17c59b*/
  if ( v10 ) /*0x17c5a2*/
    vm_object_deallocate(v8); /*0x17c5a5*/
  return v10; /*0x17c5af*/
}
