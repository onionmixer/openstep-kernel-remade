/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c784. */
kern_return_t __cdecl vm_read(
        vm_map_t target_task,
        vm_address_t address,
        vm_size_t size,
        vm_offset_t *data,
        mach_msg_type_number_t *dataCnt)
{
  int v6; // [esp+Ch] [ebp-Ch]
  kern_return_t v7; // [esp+Ch] [ebp-Ch]
  unsigned int v8; // [esp+14h] [ebp-4h] BYREF

  if ( (~page_mask & (page_mask + address)) != address || (~page_mask & (page_mask + size)) != size ) /*0x17c7b0*/
    return 4; /*0x17c7b7*/
  if ( !ipc_soft_map )
  {
    v6 = 4; /*0x17c7c8*/
LABEL_9:
    printf("vm_read: kernel error %d\n", v6);
    return 6; /*0x17c815*/
  }
  if ( size ) /*0x17c7d6*/
  {
    v8 = *(_DWORD *)(ipc_soft_map + 20); /*0x17c7e7*/
    v6 = vm_map_find(ipc_soft_map, 0, 0, &v8, size, 1); /*0x17c7f8*/
    if ( v6 ) /*0x17c800*/
      goto LABEL_9; /*0x17c800*/
  }
  else
  {
    v8 = 0; /*0x17c7d8*/
  }
  v7 = vm_map_copy(ipc_soft_map, target_task, v8, size, address, 0, 0); /*0x17c832*/
  if ( v7 ) /*0x17c83a*/
  {
    if ( ipc_soft_map ) /*0x17c85a*/
    {
      if ( size ) /*0x17c85e*/
        vm_map_remove((_DWORD *)ipc_soft_map, v8 & ~page_mask, ~page_mask & (page_mask + size + v8)); /*0x17c874*/
    }
  }
  else
  {
    *data = v8; /*0x17c842*/
    *dataCnt = size; /*0x17c847*/
  }
  return v7; /*0x17c87f*/
}
