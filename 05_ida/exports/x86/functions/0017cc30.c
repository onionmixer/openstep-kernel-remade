/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17cc30. */
int *__cdecl pagerfile_pager_create(int a1, int a2)
{
  int *v2; // ebx
  unsigned int v4; // eax
  int v5; // eax
  void *v6; // edx
  int v7; // ecx
  int v8; // edx

  v2 = zalloc_noblock(vstruct_zone); /*0x17cc45*/
  if ( !v2 ) /*0x17cc4c*/
    return nullptr; /*0x17cc50*/
  v4 = (~page_mask & (unsigned int)(page_mask + a2)) >> page_shift; /*0x17cc6e*/
  v2[4] = v4; /*0x17cc70*/
  if ( v4 ) /*0x17cc75*/
  {
    if ( 4 * v4 <= 0x40 ) /*0x17cc8e*/
      v5 = kalloc_noblock(4 * v4); /*0x17cca1*/
    else
      v5 = kalloc_noblock(4 * ((v4 - 1) >> 4) + 4); /*0x17cc9c*/
    v2[2] = v5; /*0x17cca6*/
    v6 = (void *)v2[2]; /*0x17ccac*/
    if ( !v6 ) /*0x17ccb1*/
    {
      zfree(vstruct_zone, v2); /*0x17ccbb*/
      return nullptr; /*0x17ccc2*/
    }
    v7 = v2[4]; /*0x17ccc8*/
    if ( (unsigned int)(4 * v7) <= 0x40 ) /*0x17ccd5*/
    {
      v8 = 0; /*0x17ccf0*/
      if ( v7 > 0 ) /*0x17ccf4*/
      {
        do /*0x17cd03*/
          *(_BYTE *)(v2[2] + 4 * v8++) = 0; /*0x17ccfb*/
        while ( v2[4] > v8 ); /*0x17cd03*/
      }
    }
    else
    {
      bzero(v6, 4 * ((unsigned int)(v7 - 1) >> 4) + 4); /*0x17cce6*/
    }
  }
  else
  {
    v2[2] = 0; /*0x17cc77*/
  }
  *v2 = 0; /*0x17cd05*/
  *((_WORD *)v2 + 7) = 1; /*0x17cd0b*/
  v2[5] = *(_DWORD *)(a1 + 8); /*0x17cd14*/
  *((_BYTE *)v2 + 12) |= 1u; /*0x17cd17*/
  v2[1] = a1; /*0x17cd1b*/
  ++*(_DWORD *)(a1 + 12); /*0x17cd1e*/
  do /*0x17cd3d*/
  {
    while ( vstruct_lock ) /*0x17cd2b*/
      ; /*0x17cd29*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17cd3d*/
  --*((_WORD *)v2 + 7); /*0x17cd3f*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17cd45*/
  return v2; /*0x17cd50*/
}
