/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1087ec. */
int __cdecl donice(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  __int16 v4; // si
  __int16 v5; // dx
  __int16 v6; // ax
  int result; // eax
  int v8; // esi
  int v9; // edi
  _DWORD *i; // ebx

  v2 = a2; /*0x1087f2*/
  v3 = *(_DWORD *)(active_u + 28); /*0x1087fa*/
  v4 = *(_WORD *)(v3 + 2); /*0x1087fd*/
  if ( !v4 || (v5 = *(_WORD *)(v3 + 6)) == 0 || (v6 = *(_WORD *)(a1 + 44), v4 == v6) || v5 == v6 ) /*0x10881e*/
  {
    if ( a2 > 20 ) /*0x108833*/
      v2 = 20; /*0x108835*/
    if ( v2 < -20 ) /*0x10883d*/
      v2 = -20; /*0x10883f*/
    if ( v2 >= *(char *)(a1 + 21) || suser() ) /*0x10884f*/
    {
      v8 = *(_DWORD *)(a1 + 104); /*0x10887b*/
      v9 = *(_DWORD *)(v8 + 72) + *(char *)(a1 + 21) / 2 - v2 / 2; /*0x10889a*/
      *(_BYTE *)(a1 + 21) = v2; /*0x10889c*/
      task_priority(v8, v9, 0); /*0x1088a3*/
      do /*0x1088be*/
      {
        while ( *(_DWORD *)v8 ) /*0x1088ac*/
          ; /*0x1088ae*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x1088be*/
      for ( i = *(_DWORD **)(v8 + 28); (_DWORD *)(v8 + 28) != i; i = (_DWORD *)i[4] ) /*0x1088c0*/
      {
        if ( i[21] < v9 ) /*0x1088cb*/
          thread_max_priority(i, i[96], v9); /*0x1088d6*/
        if ( thread_priority(i, v9, 1) ) /*0x1088e2*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 1; /*0x10886d*/
          return _InterlockedExchange((volatile __int32 *)v8, 0); /*0x108871*/
        }
      }
      return _InterlockedExchange((volatile __int32 *)v8, 0); /*0x1088fc*/
    }
    else
    {
      result = dword_1E875C; /*0x108858*/
      *(_BYTE *)(dword_1E875C + 104) = 13; /*0x10885d*/
    }
  }
  else
  {
    result = dword_1E875C; /*0x108820*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x108825*/
  }
  return result; /*0x108903*/
}
