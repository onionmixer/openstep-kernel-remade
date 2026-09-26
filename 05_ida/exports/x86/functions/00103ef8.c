/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103ef8. */
int __cdecl dup2(int a1, int a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  int result; // eax
  int v5; // ecx
  int v6; // eax

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x103f03*/
  if ( *(_DWORD *)(active_u + 348) <= *v2 /*0x103f30*/
    || (v3 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *v2)) == 0
    || v3 == -65536 )
  {
LABEL_14:
    result = dword_1E875C; /*0x103fee*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x103ff3*/
    return result; /*0x103ff7*/
  }
  result = v2[1]; /*0x103f36*/
  if ( (unsigned int)result > 0xFF ) /*0x103f3e*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x103f40*/
    return result; /*0x103f44*/
  }
  *(_DWORD *)(dword_1E875C + 96) = result; /*0x103f4c*/
  result = v2[1]; /*0x103f4f*/
  if ( *v2 != result ) /*0x103f54*/
  {
    expand_fdlist(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 56), v2[1]); /*0x103f67*/
    v5 = *(_DWORD *)(active_u + 336); /*0x103f73*/
    if ( *(_DWORD *)(v5 + 4 * *v2) != v3 ) /*0x103f7f*/
      goto LABEL_14; /*0x103f7f*/
    v6 = *(_DWORD *)(v5 + 4 * v2[1]); /*0x103f84*/
    if ( v6 == -65536 ) /*0x103f8c*/
      goto LABEL_14; /*0x103f8c*/
    if ( v6 ) /*0x103f90*/
    {
      vno_lockrelease(*(_DWORD *)(v5 + 4 * v2[1])); /*0x103f93*/
      if ( (*(_BYTE *)(v2[1] + *(_DWORD *)(active_u + 340)) & 2) != 0 ) /*0x103fad*/
        munmapfd(v2[1]); /*0x103fb0*/
      closef(*(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v2[1])); /*0x103fca*/
      *(_BYTE *)(dword_1E875C + 104) = 0; /*0x103fd4*/
    }
    if ( *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *v2) != v3 ) /*0x103fec*/
      goto LABEL_14; /*0x103fec*/
    return dupit(v2[1], v3, *(_BYTE *)(*v2 + *(_DWORD *)(active_u + 340))); /*0x10400c*/
  }
  return result; /*0x104014*/
}
