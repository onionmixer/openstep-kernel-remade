/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1086e4. */
int __cdecl setpriority(int a1, id_t a2, int a3)
{
  int *v3; // esi
  int v4; // edi
  int result; // eax
  int v6; // ebx
  unsigned int i; // ebx
  unsigned int j; // ebx

  v3 = *(int **)(dword_1E875C + 36); /*0x1086ef*/
  v4 = 0; /*0x1086f2*/
  result = *v3; /*0x1086f4*/
  if ( *v3 == 1 ) /*0x1086f9*/
  {
    if ( !v3[1] ) /*0x108748*/
    {
      result = *(__int16 *)(*(_DWORD *)active_u + 46); /*0x108755*/
      v3[1] = result; /*0x108759*/
    }
    for ( i = allproc; i; i = *(_DWORD *)(i + 8) ) /*0x108764*/
    {
      result = *(__int16 *)(i + 46); /*0x108768*/
      if ( v3[1] == result ) /*0x10876f*/
      {
        result = donice(i, v3[2]); /*0x108776*/
        ++v4; /*0x10877b*/
      }
    }
  }
  else if ( *v3 > 1 ) /*0x1086fb*/
  {
    if ( result != 2 ) /*0x10870b*/
      goto LABEL_26; /*0x10870b*/
    if ( !v3[1] ) /*0x108788*/
    {
      result = *(__int16 *)(*(_DWORD *)(active_u + 28) + 2); /*0x108796*/
      v3[1] = result; /*0x10879a*/
    }
    for ( j = allproc; j; j = *(_DWORD *)(j + 8) ) /*0x1087a5*/
    {
      result = *(__int16 *)(j + 44); /*0x1087a8*/
      if ( v3[1] == result ) /*0x1087af*/
      {
        result = donice(j, v3[2]); /*0x1087b6*/
        ++v4; /*0x1087bb*/
      }
    }
  }
  else
  {
    if ( result ) /*0x1086ff*/
    {
LABEL_26:
      result = dword_1E875C; /*0x1087c8*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1087cd*/
      return result; /*0x1087d1*/
    }
    if ( v3[1] ) /*0x108714*/
    {
      result = pfind(v3[1]); /*0x108725*/
      v6 = result; /*0x10872a*/
    }
    else
    {
      result = active_u; /*0x10871b*/
      v6 = *(_DWORD *)active_u; /*0x108720*/
    }
    if ( v6 ) /*0x108731*/
    {
      result = donice(v6, v3[2]); /*0x10873c*/
      v4 = 1; /*0x108741*/
    }
  }
  if ( !v4 ) /*0x1087d6*/
  {
    result = dword_1E875C; /*0x1087d8*/
    *(_BYTE *)(dword_1E875C + 104) = 3; /*0x1087dd*/
  }
  return result; /*0x1087e4*/
}
