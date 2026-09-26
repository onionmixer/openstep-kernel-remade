/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178708. */
kern_return_t __cdecl vm_move(int a1, int a2, vm_map_t target_task, int a4, int a5, _DWORD *a6)
{
  unsigned int v7; // edi
  vm_size_t v8; // esi
  kern_return_t v9; // ebx
  vm_address_t address; // [esp+Ch] [ebp-4h] BYREF

  if ( a4 ) /*0x178716*/
  {
    v7 = ~page_mask & a2; /*0x178733*/
    v8 = (~page_mask & (page_mask + a2 + a4)) - v7; /*0x178742*/
    address = 0; /*0x178744*/
    v9 = vm_allocate(target_task, &address, v8, 1); /*0x17875b*/
    if ( !v9 ) /*0x178762*/
    {
      v9 = vm_map_copy(target_task, a1, address, v8, v7, 0, a5); /*0x17877d*/
      if ( v9 ) /*0x178784*/
        vm_deallocate(target_task, address, v8); /*0x1787a1*/
      else
        *a6 = address + a2 - v7; /*0x178791*/
    }
    return v9; /*0x1787a6*/
  }
  else
  {
    *a6 = 0; /*0x17871b*/
    return 0; /*0x178721*/
  }
}
