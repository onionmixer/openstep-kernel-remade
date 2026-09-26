/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151f60. */
kern_return_t __cdecl mach_port_space_info(
        ipc_space_inspect_t task,
        ipc_info_space_t *space_info,
        ipc_info_name_array_t *table_info,
        mach_msg_type_number_t *table_infoCnt,
        ipc_info_tree_name_array_t *tree_info,
        mach_msg_type_number_t *tree_infoCnt)
{
  mach_msg_type_number_t v7; // esi
  mach_msg_type_number_t v8; // ebx
  unsigned int v9; // esi
  ipc_info_name_t *v10; // ecx
  unsigned int *v11; // ebx
  unsigned int v12; // edx
  unsigned int *v13; // ebx
  ipc_info_tree_name_t *v14; // esi
  ipc_info_tree_name_t *v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edx
  int v19; // esi
  int v20; // ebx
  int v21; // esi
  int v22; // ebx
  volatile __int32 *v23; // [esp+10h] [ebp-34h]
  int v24; // [esp+10h] [ebp-34h]
  unsigned int v25; // [esp+18h] [ebp-2Ch]
  unsigned int v26; // [esp+1Ch] [ebp-28h]
  mach_msg_type_number_t v27; // [esp+20h] [ebp-24h]
  ipc_info_tree_name_t *v28; // [esp+24h] [ebp-20h]
  unsigned int v29; // [esp+28h] [ebp-1Ch]
  mach_msg_type_number_t v30; // [esp+2Ch] [ebp-18h]
  ipc_info_name_t *v31; // [esp+30h] [ebp-14h]
  int v32; // [esp+34h] [ebp-10h] BYREF
  int v33; // [esp+38h] [ebp-Ch] BYREF
  int v34; // [esp+3Ch] [ebp-8h] BYREF
  int v35; // [esp+40h] [ebp-4h] BYREF

  v29 = 0; /*0x151f69*/
  v26 = 0; /*0x151f70*/
  if ( task ) /*0x151f7b*/
  {
    v31 = *table_info; /*0x151f8d*/
    v7 = *table_infoCnt; /*0x151f93*/
    v28 = *tree_info; /*0x151f9a*/
    v8 = *tree_infoCnt; /*0x151fa0*/
    v23 = (volatile __int32 *)(task + 8); /*0x151fa8*/
    while ( 1 ) /*0x151fc4*/
    {
      do /*0x151fc4*/
      {
        while ( *v23 ) /*0x151faf*/
          ; /*0x151fb1*/
      }
      while ( _InterlockedExchange(v23, 1) == 1 ); /*0x151fc4*/
      if ( !*(_DWORD *)(task + 12) ) /*0x151fc9*/
        break; /*0x151fc9*/
      v30 = *(_DWORD *)(task + 24); /*0x152022*/
      v27 = *(_DWORD *)(task + 56); /*0x15202b*/
      if ( v30 <= v7 && *(_DWORD *)(task + 56) <= v8 ) /*0x152034*/
      {
        space_info->iis_genno_mask = 255; /*0x152177*/
        space_info->iis_table_size = *(_DWORD *)(task + 24); /*0x152183*/
        space_info->iis_table_next = **(_DWORD **)(task + 28); /*0x152191*/
        space_info->iis_tree_size = *(_DWORD *)(task + 56); /*0x15219d*/
        space_info->iis_tree_small = *(_DWORD *)(task + 60); /*0x1521a9*/
        space_info->iis_tree_hash = *(_DWORD *)(task + 64); /*0x1521b5*/
        v25 = *(_DWORD *)(task + 24); /*0x1521c1*/
        v9 = 0; /*0x1521c4*/
        if ( v25 ) /*0x1521c8*/
        {
          v10 = v31; /*0x1521ca*/
          v24 = 0; /*0x1521cd*/
          v11 = *(unsigned int **)(task + 20); /*0x1521d4*/
          do /*0x15223c*/
          {
            v12 = *v11; /*0x1521d8*/
            v10->iin_name = v24 | HIBYTE(*v11); /*0x1521e2*/
            v10->iin_collision = (v12 >> 23) & 1; /*0x1521ec*/
            v10->iin_type = (v12 >> 22) & 1; /*0x1521f7*/
            v10->iin_urefs = (v12 >> 21) & 1; /*0x152202*/
            v10->iin_object = v12 & 0x1F0000; /*0x15220d*/
            v10->iin_next = (unsigned __int16)v12; /*0x152216*/
            v10->iin_hash = v11[1]; /*0x15221c*/
            v10[1].iin_name = v11[2]; /*0x152222*/
            v10[1].iin_collision = v11[3]; /*0x152228*/
            v10 = (ipc_info_name_t *)((char *)v10 + 36); /*0x15222b*/
            v24 += 256; /*0x15222e*/
            v11 += 4; /*0x152235*/
            ++v9; /*0x152238*/
          }
          while ( v25 > v9 ); /*0x15223c*/
        }
        v13 = (unsigned int *)ipc_splay_traverse_start(task + 32); /*0x15224a*/
        if ( v13 ) /*0x152251*/
        {
          v14 = v28; /*0x152257*/
          do /*0x1522f3*/
          {
            v15 = v14; /*0x15225c*/
            v14 = (ipc_info_tree_name_t *)((char *)v14 + 44); /*0x15225e*/
            v16 = *v13; /*0x152261*/
            v15->iitn_name.iin_name = v13[4]; /*0x152266*/
            v15->iitn_name.iin_collision = (v16 >> 23) & 1; /*0x152270*/
            v15->iitn_name.iin_type = (v16 >> 22) & 1; /*0x15227b*/
            v15->iitn_name.iin_urefs = (v16 >> 21) & 1; /*0x152286*/
            v15->iitn_name.iin_object = v16 & 0x1F0000; /*0x152291*/
            v15->iitn_name.iin_next = (unsigned __int16)v16; /*0x15229a*/
            v15->iitn_name.iin_hash = v13[1]; /*0x1522a0*/
            v15->iitn_lchild = v13[2]; /*0x1522a6*/
            v15->iitn_rchild = v13[3]; /*0x1522ac*/
            v17 = v13[6]; /*0x1522af*/
            if ( v17 ) /*0x1522b4*/
              v15[1].iitn_name.iin_name = *(_DWORD *)(v17 + 16); /*0x1522c3*/
            else
              v15[1].iitn_name.iin_name = 0; /*0x1522b6*/
            v18 = v13[7]; /*0x1522c6*/
            if ( v18 ) /*0x1522cb*/
              v15[1].iitn_name.iin_collision = *(_DWORD *)(v18 + 16); /*0x1522db*/
            else
              v15[1].iitn_name.iin_collision = 0; /*0x1522cd*/
            v13 = ipc_splay_traverse_next((_DWORD *)(task + 32), 0); /*0x1522ec*/
          }
          while ( v13 ); /*0x1522f3*/
        }
        ipc_splay_traverse_finish((_DWORD *)(task + 32)); /*0x152300*/
        _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x15230d*/
        if ( *table_info == v31 ) /*0x152318*/
        {
          *table_infoCnt = v30; /*0x152320*/
        }
        else if ( v30 ) /*0x15232c*/
        {
          v19 = 36 * v30; /*0x15235a*/
          v20 = (36 * v30 + page_mask) & ~page_mask; /*0x152373*/
          if ( v29 != v20 ) /*0x152378*/
            kmem_free(ipc_kernel_map, v20 + v35, v29 - v20); /*0x15238c*/
          if ( v19 != v20 ) /*0x152396*/
            bzero((void *)(v19 + v35), v20 - v19); /*0x1523a3*/
          vm_move(ipc_kernel_map, v35, ipc_soft_map, v20, 1, (int)&v33); /*0x1523c2*/
          *table_info = (ipc_info_name_array_t)v33; /*0x1523cd*/
          *table_infoCnt = v30; /*0x1523d5*/
        }
        else
        {
          kmem_free(ipc_kernel_map, v35, v29); /*0x15233c*/
          *table_infoCnt = 0; /*0x152344*/
        }
        if ( *tree_info != v28 ) /*0x1523e2*/
        {
          if ( !v27 ) /*0x1523ec*/
          {
            kmem_free(ipc_kernel_map, v34, v26); /*0x1523fd*/
            *tree_infoCnt = 0; /*0x152405*/
            return 0; /*0x152499*/
          }
          v21 = 44 * v27; /*0x15241c*/
          v22 = (44 * v27 + page_mask) & ~page_mask; /*0x152435*/
          if ( v26 != v22 ) /*0x15243a*/
            kmem_free(ipc_kernel_map, v22 + v34, v26 - v22); /*0x15244e*/
          if ( v21 != v22 ) /*0x152458*/
            bzero((void *)(v21 + v34), v22 - v21); /*0x152465*/
          vm_move(ipc_kernel_map, v34, ipc_soft_map, v22, 1, (int)&v32); /*0x152484*/
          *tree_info = (ipc_info_tree_name_array_t)v32; /*0x15248f*/
        }
        *tree_infoCnt = v27; /*0x152497*/
        return 0; /*0x152497*/
      }
      _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x15203f*/
      if ( v30 > v7 ) /*0x152045*/
      {
        if ( *table_info != v31 ) /*0x152053*/
          kmem_free(ipc_kernel_map, v35, v29); /*0x152063*/
        v29 = (page_mask + 36 * v30) & ~page_mask; /*0x15207e*/
        if ( kmem_alloc(ipc_kernel_map, &v35, v29) ) /*0x15208c*/
        {
          if ( *tree_info != v28 ) /*0x1520a2*/
            kmem_free(ipc_kernel_map, v34, v26); /*0x1520b7*/
          return 6; /*0x152151*/
        }
        v31 = (ipc_info_name_t *)v35; /*0x1520bf*/
        v7 = v29 / 0x24; /*0x1520ce*/
      }
      if ( v27 > v8 ) /*0x1520d3*/
      {
        if ( *tree_info != v28 ) /*0x1520e1*/
          kmem_free(ipc_kernel_map, v34, v26); /*0x1520f1*/
        v26 = (page_mask + 44 * v27) & ~page_mask; /*0x152112*/
        if ( kmem_alloc(ipc_kernel_map, &v34, v26) ) /*0x152121*/
        {
          if ( *table_info != v31 ) /*0x152137*/
            kmem_free(ipc_kernel_map, v35, v29); /*0x152147*/
          return 6; /*0x152147*/
        }
        v28 = (ipc_info_tree_name_t *)v34; /*0x15215b*/
        v8 = v26 / 0x2C; /*0x15216a*/
      }
    }
    _InterlockedExchange((volatile __int32 *)(task + 8), 0); /*0x151fd1*/
    if ( *table_info != v31 ) /*0x151fdc*/
      kmem_free(ipc_kernel_map, v35, v29); /*0x151fec*/
    if ( *tree_info != v28 ) /*0x151ffc*/
      kmem_free(ipc_kernel_map, v34, v26); /*0x152011*/
  }
  return 16; /*0x15249e*/
}
