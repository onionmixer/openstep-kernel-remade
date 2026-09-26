/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117adc. */
int __cdecl setsockopt(int a1, int a2, int a3, const void *a4, socklen_t a5)
{
  _DWORD *v5; // esi
  int *v6; // ebx
  int result; // eax
  int v8; // edi
  char v9; // dl

  v5 = *(_DWORD **)(dword_1E875C + 36); /*0x117ae7*/
  v6 = nullptr; /*0x117aea*/
  result = getsock(*v5); /*0x117aef*/
  v8 = result; /*0x117af4*/
  if ( result ) /*0x117afb*/
  {
    if ( (int)v5[4] > 112 ) /*0x117b05*/
    {
      result = dword_1E875C; /*0x117b07*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x117b0c*/
      return result; /*0x117b10*/
    }
    if ( v5[3] ) /*0x117b14*/
    {
      v6 = m_get(1, 10); /*0x117b23*/
      if ( !v6 ) /*0x117b2a*/
      {
        result = dword_1E875C; /*0x117b2c*/
        *(_BYTE *)(dword_1E875C + 104) = 55; /*0x117b31*/
        return result; /*0x117b35*/
      }
      *(_BYTE *)(dword_1E875C + 104) = copyin(v5[3], (char *)v6 + v6[1], v5[4]); /*0x117b52*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x117b5d*/
        return m_free((int)v6); /*0x117b69*/
      *((_WORD *)v6 + 4) = *((_WORD *)v5 + 8); /*0x117b70*/
    }
    v9 = sosetopt(*(_DWORD *)(v8 + 24), v5[1], v5[2], (int)v6); /*0x117b86*/
    result = dword_1E875C; /*0x117b88*/
    *(_BYTE *)(dword_1E875C + 104) = v9; /*0x117b8d*/
  }
  return result; /*0x117b93*/
}
