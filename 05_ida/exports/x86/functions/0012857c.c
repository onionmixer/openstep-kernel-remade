/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12857c. */
int __cdecl tcp_reass(int **a1, int a2, int *a3)
{
  int *v3; // ecx
  int *i; // ebx
  int v5; // eax
  int **v6; // ebx
  int v7; // edx
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  __int16 v13; // dx
  int *v14; // esi
  int v15; // ebx
  int v16; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+14h] [ebp-4h]

  v3 = a3; /*0x128588*/
  v18 = a1[8][7]; /*0x128594*/
  if ( a2 ) /*0x128599*/
  {
    for ( i = *a1; a1 != (int **)i; i = (int *)*i ) /*0x1285a3*/
    {
      if ( i[6] - *(_DWORD *)(a2 + 24) > 0 ) /*0x1285af*/
        break; /*0x1285af*/
    }
    v5 = i[1]; /*0x1285b8*/
    if ( a1 != (int **)v5 ) /*0x1285be*/
    {
      v6 = (int **)i[1]; /*0x1285c0*/
      v7 = *(_DWORD *)(v5 + 24) + *(__int16 *)(v5 + 10) - *(_DWORD *)(a2 + 24); /*0x1285cb*/
      if ( v7 > 0 ) /*0x1285d0*/
      {
        if ( v7 >= *(__int16 *)(a2 + 10) ) /*0x1285d8*/
        {
          ++dword_1EEDEC; /*0x1285da*/
          dword_1EEDF0 += *(__int16 *)(a2 + 10); /*0x1285e4*/
          m_freem((int)a3); /*0x1285eb*/
          return 0; /*0x1285f2*/
        }
        v17 = *(_DWORD *)(v5 + 24) + *(__int16 *)(v5 + 10) - *(_DWORD *)(a2 + 24); /*0x128612*/
        m_adj(a3, v7); /*0x128618*/
        *(_WORD *)(a2 + 10) -= v17; /*0x128620*/
        *(_DWORD *)(a2 + 24) += v17; /*0x128624*/
        v3 = a3; /*0x12862a*/
      }
      i = *v6; /*0x12862d*/
    }
    ++dword_1EEDFC; /*0x12862f*/
    dword_1EEE00 += *(__int16 *)(a2 + 10); /*0x128639*/
    *(_DWORD *)(a2 + 20) = v3; /*0x12863f*/
    while ( a1 != (int **)i ) /*0x128645*/
    {
      v9 = *(_DWORD *)(a2 + 24) + *(__int16 *)(a2 + 10) - i[6]; /*0x128654*/
      if ( v9 <= 0 ) /*0x128658*/
        break; /*0x128658*/
      if ( v9 < *((__int16 *)i + 5) ) /*0x128660*/
      {
        i[6] = *(_DWORD *)(a2 + 24) + *(__int16 *)(a2 + 10); /*0x1285fa*/
        *((_WORD *)i + 5) -= v9; /*0x1285fd*/
        m_adj((int *)i[5], v9); /*0x128606*/
        break; /*0x12860e*/
      }
      i = (int *)*i; /*0x128662*/
      v10 = (_DWORD *)i[1]; /*0x128664*/
      v11 = v10[5]; /*0x128667*/
      *(_DWORD *)(*v10 + 4) = v10[1]; /*0x12866f*/
      *(_DWORD *)v10[1] = *v10; /*0x128677*/
      m_freem(v11); /*0x12867a*/
    }
    v12 = i[1]; /*0x128687*/
    *(_DWORD *)a2 = *(_DWORD *)v12; /*0x12868c*/
    *(_DWORD *)(a2 + 4) = v12; /*0x12868e*/
    *(_DWORD *)(*(_DWORD *)v12 + 4) = a2; /*0x128693*/
    *(_DWORD *)v12 = a2; /*0x128696*/
  }
  v13 = *((_WORD *)a1 + 4); /*0x12869b*/
  if ( v13 <= 2 ) /*0x1286a3*/
    return 0; /*0x1286a3*/
  v14 = *a1; /*0x1286a8*/
  if ( *a1 == (int *)a1 || (int *)v14[6] != a1[16] || v13 == 3 && *((_WORD *)v14 + 5) ) /*0x1286bc*/
    return 0; /*0x1286c3*/
  do /*0x12871e*/
  {
    a1[16] = (int *)((char *)a1[16] + *((__int16 *)v14 + 5)); /*0x1286cf*/
    v15 = *((_BYTE *)v14 + 33) & 1; /*0x1286d5*/
    *(_DWORD *)(*v14 + 4) = v14[1]; /*0x1286dd*/
    *(_DWORD *)v14[1] = *v14; /*0x1286e5*/
    v16 = v14[5]; /*0x1286e7*/
    v14 = (int *)*v14; /*0x1286ea*/
    if ( (*(_BYTE *)(v18 + 6) & 0x20) != 0 ) /*0x1286f3*/
      m_freem(v16); /*0x1286f6*/
    else
      sbappend(v18 + 36, v16); /*0x128708*/
  }
  while ( a1 != (int **)v14 && (int *)v14[6] == a1[16] ); /*0x12871e*/
  sowakeup(v18, v18 + 36); /*0x12872b*/
  return v15; /*0x128735*/
}
