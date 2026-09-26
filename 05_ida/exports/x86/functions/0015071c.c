/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15071c. */
int __cdecl ipc_space_create(unsigned int *a1, _DWORD *a2)
{
  _DWORD *v2; // ebx
  char *v4; // edi
  unsigned int v5; // esi
  unsigned int i; // edx
  char *v7; // eax

  v2 = (_DWORD *)zalloc(ipc_space_zone); /*0x15072e*/
  if ( !v2 ) /*0x150735*/
    return 6; /*0x150737*/
  v4 = (char *)ipc_table_alloc(16 * *a1); /*0x150752*/
  if ( v4 ) /*0x150759*/
  {
    v5 = *a1; /*0x150777*/
    bzero(v4, 16 * *a1); /*0x150780*/
    for ( i = 0; i < v5; *((_DWORD *)v7 + 2) = i ) /*0x15078c*/
    {
      v7 = &v4[16 * i]; /*0x150795*/
      *(_DWORD *)v7 = -16777216; /*0x150797*/
      ++i; /*0x15079d*/
    }
    *(_DWORD *)&v4[16 * v5 - 8] = 0; /*0x1507aa*/
    *v2 = 0; /*0x1507b2*/
    v2[1] = 2; /*0x1507b8*/
    v2[2] = 0; /*0x1507bf*/
    v2[3] = 1; /*0x1507c6*/
    v2[4] = 0; /*0x1507cd*/
    v2[5] = v4; /*0x1507d4*/
    v2[6] = v5; /*0x1507d7*/
    v2[7] = a1 + 1; /*0x1507e0*/
    ipc_splay_tree_init(v2 + 8); /*0x1507e7*/
    v2[14] = 0; /*0x1507ec*/
    v2[15] = 0; /*0x1507f3*/
    v2[16] = 0; /*0x1507fa*/
    v2[17] = 0; /*0x150801*/
    *a2 = v2; /*0x15080b*/
    return 0; /*0x15080d*/
  }
  else
  {
    zfree(ipc_space_zone, v2); /*0x150763*/
    return 6; /*0x150768*/
  }
}
