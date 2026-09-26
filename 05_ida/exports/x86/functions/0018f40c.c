/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f40c. */
int __cdecl sub_18F40C(int *a1)
{
  int v1; // edi
  unsigned __int16 v2; // cx
  unsigned __int8 v3; // dl
  int v5; // ebx
  int result; // eax
  unsigned int v7; // esi
  int v8; // ebx
  _BYTE *v9; // eax
  _DWORD *v10; // eax
  unsigned int v11; // eax

  v1 = pd_free_queue; /*0x18f415*/
  if ( (int *)pd_free_queue == &pd_free_queue ) /*0x18f421*/
    v1 = 0; /*0x18f423*/
  if ( v1 ) /*0x18f427*/
  {
    v2 = *(_WORD *)(v1 + 24) + 1; /*0x18f42f*/
    *(_WORD *)(v1 + 24) = v2; /*0x18f431*/
    if ( ptes_per_vm_page == v2 ) /*0x18f442*/
    {
      *(_DWORD *)(*(_DWORD *)v1 + 4) = *(_DWORD *)(v1 + 4); /*0x18f449*/
      **(_DWORD **)(v1 + 4) = *(_DWORD *)v1; /*0x18f451*/
      --pd_free_count; /*0x18f453*/
    }
    v3 = *(_BYTE *)(v1 + 28); /*0x18f459*/
    if ( !_BitScanForward((unsigned int *)&v5, ~v3) ) /*0x18f461*/
      v5 = -1; /*0x18f466*/
    *(_BYTE *)(v1 + 28) = (1 << v5) | v3; /*0x18f476*/
    result = *(_DWORD *)(*(_DWORD *)(v1 + 8) + 8) + (v5 << 12); /*0x18f481*/
    *a1 = result; /*0x18f484*/
  }
  else
  {
    if ( kmem_alloc_wired(kernel_map, a1, page_size) ) /*0x18f49b*/
      panic(aPmapAllocPd); /*0x18f4ac*/
    ++pd_alloc_count; /*0x18f4b4*/
    v7 = *a1; /*0x18f4ba*/
    v8 = zalloc(pg_exten_zone); /*0x18f4c8*/
    v9 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (v7 >> 22)); /*0x18f4d8*/
    if ( (*v9 & 1) != 0 /*0x18f4f8*/
      && (v10 = (_DWORD *)((*(_DWORD *)v9 & 0xFFFFF000) + ((v7 >> 10) & 0xFFC))) != nullptr
      && (*(_BYTE *)v10 & 1) != 0 )
    {
      v11 = (*v10 & 0xFFFFF000) + (v7 & 0xFFF); /*0x18f50f*/
    }
    else
    {
      v11 = 0; /*0x18f4fa*/
    }
    *(_DWORD *)(v8 + 12) = v11; /*0x18f511*/
    result = pg_desc_tbl + 20 * ((v11 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x18f52f*/
    *(_DWORD *)(result + 12) = v8; /*0x18f532*/
    *(_DWORD *)(v8 + 8) = result; /*0x18f535*/
    *(_BYTE *)(v8 + 28) = 0; /*0x18f538*/
    *(_BYTE *)(v8 + 29) = 0; /*0x18f53c*/
    *(_WORD *)(v8 + 26) = 0; /*0x18f540*/
    *(_WORD *)(v8 + 24) = 0; /*0x18f546*/
    *(_WORD *)(v8 + 24) = 1; /*0x18f54e*/
    if ( (unsigned int)ptes_per_vm_page > 1 ) /*0x18f55b*/
    {
      *(_DWORD *)v8 = pd_free_queue; /*0x18f563*/
      *(_DWORD *)(v8 + 4) = &pd_free_queue; /*0x18f565*/
      result = *(_DWORD *)v8; /*0x18f56c*/
      *(_DWORD *)(*(_DWORD *)v8 + 4) = v8; /*0x18f56e*/
      pd_free_queue = v8; /*0x18f571*/
      ++pd_free_count; /*0x18f577*/
    }
    *(_BYTE *)(v8 + 28) |= 1u; /*0x18f57d*/
  }
  return result; /*0x18f584*/
}
