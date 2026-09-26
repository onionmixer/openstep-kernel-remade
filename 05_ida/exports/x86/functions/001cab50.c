/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cab50. */
int __cdecl _NXAddAltHandler(int a1, int a2)
{
  thread_act_t v2; // edx
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  void *v5; // eax
  _DWORD *v6; // edx
  int v7; // eax

  v2 = current_thread_EXTERNAL(); /*0x1cab5a*/
  v3 = &unk_1E551C; /*0x1cab5c*/
  if ( &unk_1E551C ) /*0x1cab63*/
  {
    while ( v3[4] != v2 ) /*0x1cab6b*/
    {
      v3 = (_DWORD *)v3[5]; /*0x1cab6d*/
      if ( !v3 ) /*0x1cab72*/
        goto LABEL_4; /*0x1cab72*/
    }
    v4 = v3; /*0x1cabb8*/
  }
  else
  {
LABEL_4:
    v4 = sub_1CA960(v2); /*0x1cab74*/
  }
  if ( v4[2] == v4[3] ) /*0x1cab85*/
  {
    if ( (_UNKNOWN *)v4[1] == &unk_1E545C ) /*0x1cab8e*/
    {
      ++v4[2]; /*0x1cab90*/
      v5 = malloc(12 * v4[2]); /*0x1cab9d*/
      v4[1] = v5; /*0x1caba2*/
      bcopy(&unk_1E545C, v5, 0xC0u); /*0x1cabb0*/
    }
    else
    {
      ++v4[2]; /*0x1cabbc*/
      v4[1] = realloc((void *)v4[1], 12 * v4[2]); /*0x1cabd2*/
    }
  }
  v6 = (_DWORD *)(v4[1] + 12 * v4[3]++); /*0x1cabe2*/
  *v6 = *v4; /*0x1cabea*/
  v7 = (-1431655765 * ((int)v6 - v4[1])) >> 1; /*0x1cac0c*/
  LOBYTE(v7) = v7 | 1; /*0x1cac0e*/
  *v4 = v7; /*0x1cac10*/
  v6[1] = a1; /*0x1cac15*/
  v6[2] = a2; /*0x1cac1b*/
  return *v4; /*0x1cac23*/
}
