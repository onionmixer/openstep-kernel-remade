/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165784. */
kern_return_t __cdecl map_fd(int fd, vm_offset_t offset, vm_offset_t *addr, boolean_t find_space, vm_size_t numbytes)
{
  int v5; // eax
  vm_size_t v6; // edi
  kern_return_t result; // eax
  vm_address_t v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  kern_return_t v12; // ebx
  vm_map_t target_task; // [esp+Ch] [ebp-10h]
  _DWORD *v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h] BYREF
  vm_address_t address; // [esp+18h] [ebp-4h] BYREF

  target_task = *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12); /*0x165798*/
  v5 = getf(fd); /*0x16579f*/
  if ( !v5 ) /*0x1657a9*/
    return 4; /*0x1657a9*/
  v14 = *(_DWORD **)(v5 + 24); /*0x1657b2*/
  if ( *(_WORD *)(v5 + 12) != 1 || v14[10] != 1 ) /*0x1657c7*/
    return 4; /*0x1657c7*/
  v6 = ~page_mask & (page_mask + numbytes); /*0x1657db*/
  if ( !find_space ) /*0x1657e1*/
  {
    if ( copyin(addr, &address, 4) ) /*0x16583e*/
      return 1; /*0x16584f*/
    v8 = address & ~page_mask; /*0x16585f*/
    if ( v8 == address && vm_map_check_protection(target_task, address & ~page_mask, v6 + v8, 3) ) /*0x165870*/
      goto LABEL_13; /*0x16587a*/
    return 4; /*0x165881*/
  }
  result = vm_allocate(target_task, &address, numbytes, 1); /*0x1657f1*/
  if ( result ) /*0x1657fd*/
    return result; /*0x1657fd*/
  if ( copyout(&address, addr, 4) ) /*0x16580a*/
  {
    vm_deallocate(target_task, address, numbytes); /*0x165822*/
    return 1; /*0x16582c*/
  }
LABEL_13:
  if ( !numbytes ) /*0x16588c*/
    return 0; /*0x16588e*/
  v9 = vnode_pager_setup((int)v14, 0, 0); /*0x1658a5*/
  v10 = pmap_create(v6); /*0x1658ad*/
  v11 = vm_map_create(v10, 0, v6, 1); /*0x1658bb*/
  v15 = 0; /*0x1658bd*/
  v12 = vm_allocate_with_pager(v11, &v15, v6, 0, v9, offset); /*0x1658d6*/
  if ( v12 || (v12 = vm_map_copy(target_task, v11, address, v6, 0, 0, 0)) != 0 ) /*0x1658fb*/
  {
    if ( find_space ) /*0x165901*/
      vm_deallocate(target_task, address, v6); /*0x16590c*/
  }
  vm_map_deallocate(v11); /*0x165915*/
  if ( !*(_DWORD *)(*v14 + 48) ) /*0x16591f*/
  {
    ++**(_WORD **)(active_u + 28); /*0x16592d*/
    *(_DWORD *)(*v14 + 48) = *(_DWORD *)(active_u + 28); /*0x16593a*/
  }
  return v12; /*0x165942*/
}
