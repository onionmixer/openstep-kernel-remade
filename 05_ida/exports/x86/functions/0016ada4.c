/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16ada4. */
int *__cdecl zget_space(_DWORD *a1, unsigned int a2, int a3)
{
  _DWORD *v3; // edi
  int v4; // eax
  int *v5; // ebx
  int *v7; // eax
  int *v8; // esi
  unsigned int v9; // eax
  int v10; // eax
  int *v11; // edx
  int v12; // eax
  signed int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  size_t v16; // eax
  size_t v17; // [esp+14h] [ebp-8h]
  unsigned int v18; // [esp+18h] [ebp-4h] BYREF
  int v19; // [esp+28h] [ebp+Ch]

  v3 = a1; /*0x16adad*/
  v18 = 0; /*0x16adb0*/
  if ( !a1 ) /*0x16adb9*/
    v3 = &_zone_default_space; /*0x16adbb*/
  if ( a2 <= 0x10 ) /*0x16adc4*/
  {
    v19 = 16; /*0x16ae00*/
  }
  else
  {
    v4 = a2 + 15; /*0x16adc9*/
    LOBYTE(v4) = (a2 + 15) & 0xF0; /*0x16adcc*/
    v19 = v4; /*0x16adce*/
  }
  do /*0x16ae21*/
  {
    while ( zget_space_lock ) /*0x16ae0f*/
      ; /*0x16ae0d*/
  }
  while ( _InterlockedExchange(&zget_space_lock, 1) == 1 ); /*0x16ae21*/
  while ( 1 ) /*0x16ae29*/
  {
    v7 = sub_16A360(v3, v19); /*0x16ae29*/
    v5 = v7; /*0x16ae2e*/
    if ( v7 ) /*0x16ae35*/
      break; /*0x16ae35*/
    if ( v18 ) /*0x16aeb9*/
    {
      v5 = zone_free_space_add(v3, v19, v18, v17); /*0x16af33*/
      v18 = 0; /*0x16af35*/
      goto LABEL_29; /*0x16af35*/
    }
    v17 = ~page_mask & (page_mask + v19); /*0x16aec9*/
    v16 = zdata_size; /*0x16aecc*/
    if ( zdata_size >= v17 ) /*0x16aed3*/
    {
      zdata_size -= v17; /*0x16add7*/
      v5 = zone_free_space_add(v3, v19, zdata + v16 - v17, v17); /*0x16adf1*/
      goto LABEL_29; /*0x16adf3*/
    }
    _InterlockedExchange(&zget_space_lock, 0); /*0x16aedb*/
    if ( kmem_alloc_zone(zone_map, &v18, v17, a3) ) /*0x16aef4*/
      return nullptr; /*0x16adfa*/
    do /*0x16af1d*/
    {
      while ( zget_space_lock ) /*0x16af0b*/
        ; /*0x16af09*/
    }
    while ( _InterlockedExchange(&zget_space_lock, 1) == 1 ); /*0x16af1d*/
  }
  v8 = (int *)v7[2]; /*0x16ae37*/
  v9 = v7[1] - v19; /*0x16ae40*/
  if ( v9 > 0xF ) /*0x16ae46*/
  {
    v11 = (int *)((char *)v5 + v19); /*0x16ae63*/
    v11[1] = v9; /*0x16ae65*/
    v12 = *v5; /*0x16ae68*/
    *v11 = *v5; /*0x16ae6a*/
    if ( v12 ) /*0x16ae6e*/
      *(_DWORD *)(v12 + 8) = v11; /*0x16ae70*/
    v11[2] = (int)v8; /*0x16ae76*/
    *v8 = (int)v11; /*0x16ae79*/
    v13 = (unsigned int)v11[1] >> v3[4]; /*0x16ae8b*/
    if ( v3[6] < v13 ) /*0x16ae90*/
      v13 = v3[6]; /*0x16ae92*/
    v14 = 16 * v13 + v3[5]; /*0x16ae9b*/
    v15 = *(_DWORD *)(v14 - 16); /*0x16ae9d*/
    if ( !v15 || (unsigned int)v11 < v15 ) /*0x16aea6*/
      *(_DWORD *)(v14 - 16) = v11; /*0x16aeac*/
  }
  else
  {
    v10 = *v5; /*0x16ae48*/
    *v8 = *v5; /*0x16ae4a*/
    if ( v10 ) /*0x16ae4e*/
      *(_DWORD *)(*v5 + 8) = v8; /*0x16ae52*/
    --v3[3]; /*0x16ae55*/
  }
LABEL_29:
  _InterlockedExchange(&zget_space_lock, 0); /*0x16af3f*/
  if ( v18 ) /*0x16af4c*/
    kmem_free(zone_map, v18, v17); /*0x16af5a*/
  return v5; /*0x16af64*/
}
