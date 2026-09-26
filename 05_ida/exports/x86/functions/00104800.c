/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104800. */
int falloc()
{
  int v0; // ebx
  int v1; // eax
  int v3; // edx
  int v4; // eax

  v0 = 0; /*0x104804*/
  while ( 1 ) /*0x104815*/
  {
    expand_fdlist(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 56), v0); /*0x104815*/
    if ( !*(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v0) ) /*0x104828*/
      break; /*0x104828*/
    if ( ++v0 > 255 ) /*0x104877*/
    {
      *(_BYTE *)(dword_1E875C + 104) = 24; /*0x10487e*/
      v1 = -1; /*0x104882*/
      goto LABEL_8; /*0x104882*/
    }
  }
  *(_DWORD *)(dword_1E875C + 96) = v0; /*0x104833*/
  *(_BYTE *)(v0 + *(_DWORD *)(active_u + 340)) = 0; /*0x104841*/
  if ( *(_DWORD *)(active_u + 344) < v0 ) /*0x104850*/
    *(_DWORD *)(active_u + 344) = v0; /*0x104852*/
  *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v0) = -65536; /*0x104863*/
  v1 = v0; /*0x10486a*/
LABEL_8:
  if ( v1 < 0 ) /*0x104889*/
    return 0; /*0x10488b*/
  v3 = zalloc(file_zone); /*0x10489c*/
  v4 = dword_1E89DC; /*0x10489e*/
  if ( (int *)dword_1E89DC == &file_list ) /*0x1048a8*/
    file_list = v3; /*0x1048aa*/
  else
    *(_DWORD *)dword_1E89DC = v3; /*0x1048b4*/
  *(_DWORD *)(v3 + 4) = v4; /*0x1048b6*/
  *(_DWORD *)v3 = &file_list; /*0x1048b9*/
  dword_1E89DC = v3; /*0x1048bf*/
  *(_WORD *)(v3 + 14) = 1; /*0x1048c5*/
  *(_DWORD *)(v3 + 24) = 0; /*0x1048cb*/
  *(_DWORD *)(v3 + 28) = 0; /*0x1048d2*/
  *(_DWORD *)(v3 + 20) = 0; /*0x1048d9*/
  ++**(_WORD **)(active_u + 28); /*0x1048e8*/
  *(_DWORD *)(v3 + 32) = *(_DWORD *)(active_u + 28); /*0x1048f3*/
  return v3; /*0x1048f8*/
}
