/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0e48. */
int __cdecl PCcreate(int a1, unsigned int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  _DWORD *v7; // ebx
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h] BYREF
  unsigned int v10; // [esp+18h] [ebp-4h] BYREF

  v8 = *(_DWORD *)(active_threads + 12); /*0x1a0e59*/
  if ( !suser() ) /*0x1a0e5c*/
    return 5; /*0x1a0e6a*/
  if ( a3 ) /*0x1a0e74*/
  {
    v10 = *(_DWORD *)(*(_DWORD *)(v8 + 12) + 20); /*0x1a0ea1*/
  }
  else
  {
    if ( copyin(a2, (unsigned int)&v10, 4) ) /*0x1a0e80*/
      return 4; /*0x1a0ee0*/
    v10 &= ~page_mask; /*0x1a0e93*/
  }
  if ( !object_copyin(v8, a1, 6, 0, (int)&v9) ) /*0x1a0eb4*/
    return 4; /*0x1a0eb4*/
  v4 = convert_port_to_thread(v9); /*0x1a0ec9*/
  port_release(v9); /*0x1a0ecf*/
  if ( !v4 ) /*0x1a0ed9*/
    return 4; /*0x1a0ed9*/
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 40) + 236); /*0x1a0eeb*/
  if ( v5 ) /*0x1a0ef3*/
  {
    if ( a3 ) /*0x1a0ef9*/
    {
      v10 = *(_DWORD *)(v5 + 8); /*0x1a0efe*/
      v6 = 0; /*0x1a0f13*/
      if ( copyout((unsigned __int16 *)&v10, a2, 4) ) /*0x1a0f0b*/
        v6 = 4; /*0x1a0f19*/
    }
    else
    {
      v6 = v10 != *(_DWORD *)(v5 + 8); /*0x1a0f2d*/
    }
    goto LABEL_17; /*0x1a0f1e*/
  }
  v6 = vm_map_find(*(_DWORD *)(v8 + 12), 0, 0, &v10, ~page_mask & (page_mask + 1308), a3); /*0x1a0f67*/
  if ( v6 ) /*0x1a0f6e*/
  {
LABEL_17:
    thread_deallocate(v4); /*0x1a0f70*/
    return v6; /*0x1a0f78*/
  }
  if ( a3 && copyout((unsigned __int16 *)&v10, a2, 4) ) /*0x1a0f90*/
  {
    thread_deallocate(v4); /*0x1a0f9d*/
    return 4; /*0x1a0fa2*/
  }
  else
  {
    vm_map_reference(*(_DWORD *)(v8 + 12)); /*0x1a0fb3*/
    v7 = (_DWORD *)kalloc(0xCu); /*0x1a0fbf*/
    memset(v7, 0, 0xCu); /*0x1a0fc6*/
    *v7 = 0; /*0x1a0fce*/
    kmem_alloc_wired(kernel_map, v7, 1308); /*0x1a0fe1*/
    v7[1] = *(_DWORD *)(v8 + 12); /*0x1a0fec*/
    v7[2] = v10; /*0x1a0ff2*/
    pmap_enter_shared_range(*(_DWORD **)(v7[1] + 36), v10, 1308, *v7); /*0x1a1008*/
    *(_DWORD *)*v7 = 15; /*0x1a100f*/
    *(_DWORD *)(*v7 + 1192) = 1; /*0x1a1017*/
    *(_DWORD *)(*(_DWORD *)(v4 + 40) + 236) = v7; /*0x1a1024*/
    thread_deallocate(v4); /*0x1a102e*/
    return 0; /*0x1a1033*/
  }
}
