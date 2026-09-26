/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ecc0. */
int __cdecl sub_18ECC0(int a1)
{
  _BYTE *v1; // ebx
  unsigned int v2; // eax
  _BYTE *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // edx
  int v6; // ecx
  int result; // eax
  void *v8; // [esp+8h] [ebp-4h] BYREF

  v1 = (_BYTE *)(4 * ((a1 & (unsigned int)-section_size) >> 22) + *(_DWORD *)kernel_pmap); /*0x18ece0*/
  if ( (*v1 & 1) != 0 ) /*0x18ece5*/
    panic(aPmapKernelPtAl); /*0x18ecec*/
  if ( pmap_initialized ) /*0x18ecfb*/
  {
    if ( kmem_alloc_wired(kernel_map, &v8, page_size) ) /*0x18ed4a*/
      panic(aPmapKernelPtAl_1); /*0x18ed5b*/
    v3 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * ((unsigned int)v8 >> 22)); /*0x18ed71*/
    if ( (*v3 & 1) != 0 /*0x18ed91*/
      && (v4 = (_DWORD *)((*(_DWORD *)v3 & 0xFFFFF000) + (((unsigned int)v8 >> 10) & 0xFFC))) != nullptr
      && (*(_BYTE *)v4 & 1) != 0 )
    {
      v2 = (*v4 & 0xFFFFF000) + ((unsigned __int16)v8 & 0xFFF); /*0x18eda7*/
    }
    else
    {
      v2 = 0; /*0x18ed93*/
    }
  }
  else
  {
    v8 = alloc_pages(page_size); /*0x18ed09*/
    if ( !v8 ) /*0x18ed11*/
      panic(aPmapKernelPtAl_0); /*0x18ed18*/
    bzero(v8, page_size); /*0x18ed2b*/
    v2 = (unsigned int)v8; /*0x18ed30*/
  }
  v5 = v2 & 0xFFFFF000; /*0x18edae*/
  LOBYTE(v5) = 3; /*0x18edb0*/
  v6 = ptes_per_vm_page; /*0x18edb3*/
  while ( 1 ) /*0x18edd5*/
  {
    result = v6--; /*0x18edd5*/
    if ( result <= 0 ) /*0x18edda*/
      break; /*0x18edda*/
    *(_DWORD *)v1 = v5; /*0x18edbc*/
    v5 = ((v5 & 0xFFFFF000) + 4096) | v5 & 0xFFF; /*0x18edd0*/
    v1 += 4; /*0x18edd2*/
  }
  return result; /*0x18eddf*/
}
