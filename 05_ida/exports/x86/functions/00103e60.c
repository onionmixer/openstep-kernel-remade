/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103e60. */
int __cdecl dup(int a1)
{
  unsigned int *v1; // esi
  unsigned int v2; // edx
  int result; // eax
  int v4; // ebx
  int v5; // edx
  unsigned int v6; // esi
  int v7; // eax
  int v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+4h] [ebp-4h]

  v1 = *(unsigned int **)(dword_1E875C + 36); /*0x103e6a*/
  v2 = *v1; /*0x103e6d*/
  if ( (*v1 & 0xFFFFFFC0) != 0 ) /*0x103e75*/
  {
    *v1 &= 0x3Fu; /*0x103e7a*/
    return dup2(v8, v9); /*0x103e81*/
  }
  if ( *(_DWORD *)(active_u + 348) <= v2 ) /*0x103e8f*/
    goto LABEL_9; /*0x103e8f*/
  v4 = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v2); /*0x103e97*/
  if ( !v4 || v4 == -65536 ) /*0x103ea4*/
    goto LABEL_9; /*0x103ea4*/
  result = ufalloc(0); /*0x103ea8*/
  v5 = result; /*0x103ead*/
  if ( result < 0 ) /*0x103eb4*/
    return result; /*0x103eb4*/
  v6 = *v1; /*0x103ebc*/
  v7 = *(_DWORD *)(active_u + 336); /*0x103ebe*/
  if ( *(_DWORD *)(v7 + 4 * v6) != v4 ) /*0x103ec7*/
  {
    *(_DWORD *)(v7 + 4 * v5) = 0; /*0x103ec9*/
LABEL_9:
    result = dword_1E875C; /*0x103ed0*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x103ed5*/
    return result; /*0x103ed9*/
  }
  return dupit(v5, v4, *(_BYTE *)(v6 + *(_DWORD *)(active_u + 340))); /*0x103ef1*/
}
