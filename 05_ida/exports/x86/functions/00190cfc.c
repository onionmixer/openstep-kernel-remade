/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190cfc. */
int __cdecl sub_190CFC(_DWORD *a1, unsigned int a2)
{
  int *v2; // edx
  int *v3; // eax
  int v4; // ebx
  int result; // eax
  unsigned int v6; // esi
  _BYTE *v7; // eax
  _DWORD *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  _BYTE *v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // ebx
  int v15; // edx
  int v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-4h] BYREF

  if ( (_DWORD *)kernel_pmap == a1 ) /*0x190d0e*/
    panic(aPmapExpand); /*0x190d15*/
  v2 = (int *)pt_free_queue; /*0x190d1d*/
  if ( (int *)pt_free_queue == &pt_free_queue ) /*0x190d29*/
  {
    v3 = nullptr; /*0x190d2b*/
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)pt_free_queue + 4) = &pt_free_queue; /*0x190d32*/
    pt_free_queue = *v2; /*0x190d3b*/
    v3 = v2; /*0x190d41*/
    if ( v2 ) /*0x190d45*/
      --pt_free_count; /*0x190d47*/
  }
  v4 = (int)v3; /*0x190d4d*/
  if ( v3 ) /*0x190d51*/
  {
    v17 = *(_DWORD *)(v3[2] + 8); /*0x190d59*/
  }
  else
  {
    result = kmem_alloc_wired(kernel_map, &v17, page_size); /*0x190d76*/
    if ( result ) /*0x190d80*/
      return result; /*0x190d80*/
    ++pt_alloc_count; /*0x190d86*/
    v6 = v17; /*0x190d8c*/
    v4 = zalloc(pg_exten_zone); /*0x190d9b*/
    v7 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v6 >> 22)); /*0x190dae*/
    if ( (*v7 & 1) != 0 /*0x190dce*/
      && (v8 = (_DWORD *)((*(_DWORD *)v7 & 0xFFFFF000) + ((v6 >> 10) & 0xFFC))) != nullptr
      && (*(_BYTE *)v8 & 1) != 0 )
    {
      v9 = (*v8 & 0xFFFFF000) + (v6 & 0xFFF); /*0x190de3*/
    }
    else
    {
      v9 = 0; /*0x190dd0*/
    }
    *(_DWORD *)(v4 + 12) = v9; /*0x190de5*/
    v10 = pg_desc_tbl + 20 * ((v9 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x190e03*/
    *(_DWORD *)(v10 + 12) = v4; /*0x190e06*/
    *(_DWORD *)(v4 + 8) = v10; /*0x190e09*/
    *(_BYTE *)(v4 + 28) = 0; /*0x190e0c*/
    *(_BYTE *)(v4 + 29) = 0; /*0x190e10*/
    *(_WORD *)(v4 + 26) = 0; /*0x190e14*/
    *(_WORD *)(v4 + 24) = 0; /*0x190e1a*/
  }
  v11 = splvm(); /*0x190e25*/
  v12 = (_BYTE *)(*a1 + 4 * (a2 >> 22)); /*0x190e33*/
  if ( (*v12 & 1) != 0 && ((a2 >> 10) & 0xFFC) + (*(_DWORD *)v12 & 0xFFFFF000) ) /*0x190e4d*/
  {
    splx(v11); /*0x190e52*/
    *(_DWORD *)(*(_DWORD *)(v4 + 8) + 12) = 0; /*0x190e5d*/
    zfree(pg_exten_zone, (_DWORD *)v4); /*0x190e6c*/
    result = kmem_free(kernel_map, v17, page_size); /*0x190e86*/
    --pt_alloc_count; /*0x190e8b*/
  }
  else
  {
    *(_DWORD *)(v4 + 20) = a2 & -section_size; /*0x190ea2*/
    *(_DWORD *)(v4 + 16) = a1; /*0x190ea8*/
    *(_BYTE *)(v4 + 29) = 0; /*0x190eab*/
    *(_DWORD *)v4 = &pt_active_queue; /*0x190eaf*/
    *(_DWORD *)(v4 + 4) = dword_1F7ACC; /*0x190ebb*/
    **(_DWORD **)(v4 + 4) = v4; /*0x190ec1*/
    dword_1F7ACC = v4; /*0x190ec3*/
    ++pt_active_count; /*0x190ec9*/
    v13 = *(_DWORD *)(v4 + 12) & 0xFFFFF000; /*0x190ed7*/
    LOBYTE(v13) = 7; /*0x190ed9*/
    v14 = (unsigned int *)(4 * (*(_DWORD *)(v4 + 20) >> 22) + *a1); /*0x190eea*/
    v15 = ptes_per_vm_page; /*0x190eec*/
    while ( 1 ) /*0x190f0d*/
    {
      v16 = v15--; /*0x190f0d*/
      if ( v16 <= 0 ) /*0x190f12*/
        break; /*0x190f12*/
      *v14 = v13; /*0x190ef4*/
      v13 = ((v13 & 0xFFFFF000) + 4096) | v13 & 0xFFF; /*0x190f08*/
      ++v14; /*0x190f0a*/
    }
    return splx(v11); /*0x190f15*/
  }
  return result; /*0x190f1d*/
}
