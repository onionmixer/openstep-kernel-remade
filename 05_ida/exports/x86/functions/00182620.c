/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182620. */
int __cdecl kern_IOMapDeviceMemory(id a1, int a2, unsigned int a3, int a4, unsigned int *a5, char a6, int a7)
{
  id v8; // eax
  char *i; // ebx
  id v10; // eax
  id v11; // eax
  int v12; // edx
  unsigned int v13; // ebx
  int v14; // edi
  char *v15; // [esp+10h] [ebp-18h]
  id v16; // [esp+14h] [ebp-14h]
  int v17; // [esp+18h] [ebp-10h]
  int j; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h]

  if ( !a1 ) /*0x182634*/
    return -705; /*0x18263b*/
  v19 = *(_DWORD *)(a2 + 12); /*0x182643*/
  if ( a7 ) /*0x182659*/
    v17 = a7 == 1; /*0x18265f*/
  else
    v17 = 2; /*0x182664*/
  v8 = objc_msgSend(a1, sel_deviceDescription); /*0x18268b*/
  v16 = objc_msgSend(v8, sel_resourcesForKey_, aMemoryMaps_1); /*0x1826a2*/
  v15 = (char *)objc_msgSend(v16, sel_count); /*0x1826b5*/
  for ( i = nullptr; (int)v15 > (int)i; ++i ) /*0x1826bf*/
  {
    v10 = objc_msgSend(v16, sel_objectAt_, i); /*0x1826d7*/
    v11 = objc_msgSend(v10, sel_range); /*0x1826e0*/
    if ( a3 >= (unsigned int)v11 && (unsigned int)v11 + v12 >= a4 + a3 ) /*0x1826f7*/
      break; /*0x1826f7*/
  }
  if ( v15 == i ) /*0x182702*/
    return -705; /*0x182709*/
  if ( a6 ) /*0x182714*/
    *a5 = *(_DWORD *)(v19 + 20); /*0x18271f*/
  else
    *a5 &= ~page_mask; /*0x18272f*/
  if ( kernel_map != v19 || a6 || *a5 > 0xFFFFF ) /*0x18274b*/
  {
    if ( vm_map_find(v19, 0, 0, a5, a4, a6) ) /*0x182762*/
      return -731; /*0x182773*/
    v13 = *a5 & ~page_mask; /*0x182787*/
    v14 = (a4 + page_mask) & ~page_mask; /*0x18278d*/
    vm_map_inherit(v19, v13, v14 + v13, 2u); /*0x18279a*/
    for ( j = ~page_mask & a3; v14; j += page_size ) /*0x1827af*/
    {
      pmap_enter_cache_spec(*(_DWORD *)(v19 + 36), v13, j, 3, 1, v17); /*0x1827c8*/
      v13 += page_size; /*0x1827d3*/
      v14 -= page_size; /*0x1827d5*/
    }
  }
  return 0; /*0x1827e6*/
}
