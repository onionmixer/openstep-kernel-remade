/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15fb28. */
void __cdecl vmp_invalidate(int a1)
{
  int *v1; // esi
  volatile __int32 *v2; // edx
  int v3; // ebx
  int v4; // edi
  char v5; // al
  volatile __int32 *v6; // edx

  v1 = *(int **)(a1 + 36); /*0x15fb31*/
  if ( v1 ) /*0x15fb36*/
  {
    do /*0x15fb55*/
    {
      while ( vm_page_queue_lock ) /*0x15fb43*/
        ; /*0x15fb41*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fb55*/
    v2 = v1 + 4; /*0x15fb57*/
    do /*0x15fb6e*/
    {
      while ( *v2 ) /*0x15fb5c*/
        ; /*0x15fb5e*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x15fb6e*/
    if ( *(int **)(a1 + 36) == v1 ) /*0x15fb73*/
    {
      v3 = *v1; /*0x15fb79*/
      while ( 1 ) /*0x15fb8a*/
      {
        while ( 1 ) /*0x15fb7b*/
        {
          if ( v1 == (int *)v3 ) /*0x15fb7d*/
          {
            _InterlockedExchange(v1 + 4, 0); /*0x15fc42*/
            _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fc47*/
            return; /*0x15fc47*/
          }
          v4 = *(_DWORD *)(v3 + 8); /*0x15fb83*/
          if ( (*(_BYTE *)(v3 + 33) & 8) == 0 ) /*0x15fb8a*/
            break; /*0x15fb8a*/
LABEL_24:
          v3 = v4; /*0x15fc37*/
        }
        v5 = *(_BYTE *)(v3 + 32); /*0x15fb90*/
        if ( (v5 & 1) == 0 ) /*0x15fb95*/
        {
          if ( !*(_WORD *)(v3 + 28) ) /*0x15fbf4*/
          {
            pmap_remove_all(*(_DWORD *)(v3 + 36)); /*0x15fbff*/
            if ( (*(_BYTE *)(v3 + 30) & 0x20) != 0 && !pmap_is_modified(*(_DWORD *)(v3 + 36)) ) /*0x15fc1b*/
            {
              ++mfs_mclean; /*0x15fc28*/
              vm_page_free(v3); /*0x15fc2f*/
            }
            else
            {
              ++mfs_mdirty; /*0x15fc1d*/
            }
          }
          goto LABEL_24; /*0x15fc23*/
        }
        *(_BYTE *)(v3 + 32) = v5 | 2; /*0x15fb99*/
        assert_wait(v3, 0); /*0x15fb9f*/
        _InterlockedExchange(v1 + 4, 0); /*0x15fba9*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x15fbae*/
        thread_block(); /*0x15fbb4*/
        do /*0x15fbd5*/
        {
          while ( vm_page_queue_lock ) /*0x15fbc3*/
            ; /*0x15fbc1*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x15fbd5*/
        v6 = v1 + 4; /*0x15fbd7*/
        do /*0x15fbee*/
        {
          while ( *v6 ) /*0x15fbdc*/
            ; /*0x15fbde*/
        }
        while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15fbee*/
      }
    }
  }
}
