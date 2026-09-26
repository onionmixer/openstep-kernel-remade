/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108120. */
int __cdecl setgroups(int a1, const gid_t *a2)
{
  _DWORD *v2; // ebx
  int result; // eax
  _WORD *v4; // ecx
  _WORD *i; // edx
  int v6; // edx
  int v7; // eax
  _WORD *j; // edx
  int v9; // [esp+Ch] [ebp-44h]
  _WORD v10[32]; // [esp+10h] [ebp-40h] BYREF

  v2 = *(_DWORD **)(dword_1E875C + 36); /*0x10812e*/
  result = suser(); /*0x108131*/
  if ( result ) /*0x108138*/
  {
    if ( *v2 <= 0x10u ) /*0x108141*/
    {
      v9 = crdup(*(_DWORD *)(active_u + 28)); /*0x108162*/
      *(_BYTE *)(dword_1E875C + 104) = copyin(v2[1], v10, 4 * *v2); /*0x108183*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x10818e*/
      {
        return crfree(v9); /*0x108198*/
      }
      else
      {
        v4 = v10; /*0x1081a0*/
        for ( i = (_WORD *)(v9 + 10); v4 < &v10[2 * *v2]; ++i ) /*0x1081b5*/
        {
          *i = *v4; /*0x1081bb*/
          v4 += 2; /*0x1081be*/
        }
        v6 = *(_DWORD *)(active_u + 28); /*0x1081d8*/
        *(_DWORD *)(active_u + 28) = v9; /*0x1081de*/
        crfree(v6); /*0x1081e2*/
        v7 = *(_DWORD *)(active_u + 28); /*0x1081f2*/
        for ( j = (_WORD *)(v7 + 2 * *v2 + 10); ; ++j ) /*0x1081f5*/
        {
          result = v7 + 42; /*0x10820c*/
          if ( (unsigned int)j >= result ) /*0x108211*/
            break; /*0x108211*/
          *j = -1; /*0x1081fc*/
          v7 = *(_DWORD *)(active_u + 28); /*0x108209*/
        }
      }
    }
    else
    {
      result = dword_1E875C; /*0x108143*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x108148*/
    }
  }
  return result; /*0x108216*/
}
