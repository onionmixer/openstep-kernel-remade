/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9368. */
int __cdecl IOMapPhysicalIntoIOTask(int a1, vm_size_t size, vm_address_t *address)
{
  vm_map_t v3; // eax
  vm_address_t v5; // ebx
  vm_size_t v6; // esi
  unsigned int i; // edi
  int v8; // eax
  _DWORD *v9; // eax

  v3 = _io_vm_task_self(); /*0x1a937b*/
  if ( vm_allocate(v3, address, size, 1) ) /*0x1a9381*/
    return -731; /*0x1a938d*/
  v5 = ~page_mask & *address; /*0x1a939f*/
  v6 = ~page_mask & (size + page_mask); /*0x1a93a5*/
  for ( i = ~page_mask & a1; v6; i += page_size ) /*0x1a93ab*/
  {
    v8 = _io_vm_task_self(); /*0x1a93b6*/
    v9 = (_DWORD *)_io_vm_task_pmap(v8); /*0x1a93bc*/
    pmap_enter(v9, v5, i, 3, 1); /*0x1a93c5*/
    v5 += page_size; /*0x1a93cf*/
    v6 -= page_size; /*0x1a93d1*/
  }
  return 0; /*0x1a93e1*/
}
