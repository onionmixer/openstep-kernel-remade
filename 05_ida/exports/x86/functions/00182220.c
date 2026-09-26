/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x182220. */
int __cdecl kern_dev_map_phys(id a1, int a2, unsigned int a3, int a4, unsigned int *a5, int a6, int a7)
{
  id v7; // eax
  char *i; // ebx
  id v9; // eax
  id v10; // eax
  int v11; // edx
  unsigned int v13; // ebx
  int v14; // edi
  char *v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  id v17; // [esp+18h] [ebp-4h]
  int j; // [esp+2Ch] [ebp+10h]

  if ( a7 ) /*0x182231*/
    v16 = a7 == 1; /*0x182236*/
  else
    v16 = 2; /*0x18223c*/
  v7 = objc_msgSend(a1, sel_deviceDescription); /*0x182266*/
  v17 = objc_msgSend(v7, sel_resourcesForKey_, aMemoryMaps_1); /*0x18227d*/
  v15 = (char *)objc_msgSend(v17, sel_count); /*0x182290*/
  for ( i = nullptr; (int)v15 > (int)i; ++i ) /*0x18229a*/
  {
    v9 = objc_msgSend(v17, sel_objectAt_, i); /*0x1822af*/
    v10 = objc_msgSend(v9, sel_range); /*0x1822b8*/
    if ( a3 >= (unsigned int)v10 && (unsigned int)v10 + v11 >= a4 + a3 ) /*0x1822cf*/
      break; /*0x1822cf*/
  }
  if ( v15 == i ) /*0x1822da*/
    return -705; /*0x1822e1*/
  if ( a6 ) /*0x1822ec*/
    *a5 = *(_DWORD *)(a2 + 20); /*0x1822f7*/
  else
    *a5 &= ~page_mask; /*0x182307*/
  if ( kernel_map != a2 || a6 || *a5 > 0xFFFFF ) /*0x182323*/
  {
    if ( vm_map_find(a2, 0, 0, a5, a4, a6) ) /*0x18233a*/
      return -731; /*0x18234b*/
    v13 = *a5 & ~page_mask; /*0x18235f*/
    v14 = (a4 + page_mask) & ~page_mask; /*0x182365*/
    vm_map_inherit(a2, v13, v14 + v13, 2u); /*0x182372*/
    for ( j = ~page_mask & a3; v14; j += page_size ) /*0x182387*/
    {
      pmap_enter_cache_spec(*(_DWORD *)(a2 + 36), v13, j, 3, 1, v16); /*0x1823a0*/
      v13 += page_size; /*0x1823ab*/
      v14 -= page_size; /*0x1823ad*/
    }
  }
  return 0; /*0x1823be*/
}
