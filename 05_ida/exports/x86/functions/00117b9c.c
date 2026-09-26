/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117b9c. */
int __cdecl getsockopt(int a1, int a2, int a3, void *a4, socklen_t *a5)
{
  _DWORD *v5; // ebx
  int result; // eax
  int v7; // esi
  int *v8; // [esp+Ch] [ebp-8h] BYREF
  int v9; // [esp+10h] [ebp-4h] BYREF

  v5 = *(_DWORD **)(dword_1E875C + 36); /*0x117baa*/
  v8 = nullptr; /*0x117bad*/
  result = getsock(*v5); /*0x117bb7*/
  v7 = result; /*0x117bbc*/
  if ( result ) /*0x117bc3*/
  {
    if ( v5[3] ) /*0x117bc9*/
    {
      *(_BYTE *)(dword_1E875C + 104) = copyin(v5[4], &v9, 4); /*0x117be5*/
      result = dword_1E875C; /*0x117be8*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x117bf0*/
        return result; /*0x117bf4*/
    }
    else
    {
      v9 = 0; /*0x117bfc*/
    }
    *(_BYTE *)(dword_1E875C + 104) = sogetopt(*(__int16 **)(v7 + 24), v5[1], v5[2], &v8); /*0x117c1f*/
    if ( !*(_BYTE *)(dword_1E875C + 104) && v5[3] && v9 ) /*0x117c3b*/
    {
      result = (int)v8; /*0x117c3d*/
      if ( !v8 ) /*0x117c42*/
        return result; /*0x117c42*/
      if ( v9 > *((__int16 *)v8 + 4) ) /*0x117c4a*/
        v9 = *((__int16 *)v8 + 4); /*0x117c4c*/
      *(_BYTE *)(dword_1E875C + 104) = copyout((char *)v8 + v8[1], v5[3], v9); /*0x117c67*/
      if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117c72*/
        *(_BYTE *)(dword_1E875C + 104) = copyout(&v9, v5[4], 4); /*0x117c8e*/
    }
    result = (int)v8; /*0x117c94*/
    if ( v8 ) /*0x117c99*/
      return m_free((int)v8); /*0x117c9c*/
  }
  return result; /*0x117ca4*/
}
