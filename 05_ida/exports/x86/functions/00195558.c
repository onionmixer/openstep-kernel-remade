/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195558. */
int __cdecl createEventShmem(int a1, int a2, int *a3, unsigned int *a4, int *a5)
{
  int v5; // eax
  int v6; // ebx
  int v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned int v11; // eax

  *a3 = 0; /*0x195567*/
  v5 = IOGetKernPort(a1); /*0x19556e*/
  v6 = v5; /*0x195573*/
  if ( !v5 ) /*0x19557a*/
    return 4; /*0x19557c*/
  v8 = convert_port_to_map(v5); /*0x19558e*/
  if ( v8 ) /*0x195595*/
  {
    port_release(v6); /*0x1955a9*/
    v9 = ~page_mask & (page_mask + a2); /*0x1955bc*/
    if ( kmem_alloc_wired(kernel_map, a5, v9) ) /*0x1955ca*/
    {
      vm_map_deallocate(v8); /*0x1955d7*/
      return 3; /*0x1955dc*/
    }
    else
    {
      *a4 = *(_DWORD *)(v8 + 20); /*0x1955ee*/
      if ( vm_map_find(v8, 0, 0, a4, v9, 1) ) /*0x1955f9*/
      {
        IOLog(aCreateeventshm); /*0x19560b*/
        vm_map_deallocate(v8); /*0x195611*/
        return 3; /*0x195616*/
      }
      else
      {
        v10 = 0; /*0x195658*/
        if ( v9 ) /*0x19565c*/
        {
          while ( 1 ) /*0x19566f*/
          {
            v11 = pmap_extract(kernel_pmap, v10 + *a5); /*0x19566f*/
            if ( !v11 ) /*0x195679*/
              break; /*0x195679*/
            pmap_enter(*(_DWORD **)(v8 + 36), v10 + *a4, v11, 3, 1); /*0x19568c*/
            v10 += page_size; /*0x195694*/
            if ( v10 >= v9 ) /*0x19569c*/
              goto LABEL_13; /*0x19569c*/
          }
          IOLog(aCreateeventshm_0); /*0x19562d*/
          kmem_free(kernel_map, *a5, a2); /*0x195643*/
          vm_map_deallocate(v8); /*0x195649*/
          return 3; /*0x19564e*/
        }
        else
        {
LABEL_13:
          *a3 = v8; /*0x19569e*/
          return 0; /*0x1956a3*/
        }
      }
    }
  }
  else
  {
    port_release(v6); /*0x195598*/
    return 4; /*0x19559d*/
  }
}
