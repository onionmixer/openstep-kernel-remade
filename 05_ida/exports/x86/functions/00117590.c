/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117590. */
void __cdecl sendit(int a1, _DWORD *a2, char a3)
{
  _DWORD *v3; // edi
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD v11[4]; // [esp+18h] [ebp-18h] BYREF
  __int16 v12; // [esp+28h] [ebp-8h]
  int v13; // [esp+2Ch] [ebp-4h]

  v8 = getsock(a1); /*0x1175a2*/
  if ( v8 ) /*0x1175aa*/
  {
    v11[0] = a2[2]; /*0x1175b6*/
    v11[1] = a2[3]; /*0x1175bf*/
    v11[3] = 0; /*0x1175c2*/
    v11[2] = 0; /*0x1175c9*/
    v13 = 0; /*0x1175d0*/
    v12 = 0; /*0x1175d7*/
    v3 = (_DWORD *)a2[2]; /*0x1175e0*/
    v4 = 0; /*0x1175e3*/
    if ( (int)a2[3] > 0 ) /*0x1175e8*/
    {
      v5 = v3 + 1; /*0x1175ea*/
      do /*0x1175f0*/
      {
        if ( (int)*v5 < 0 ) /*0x1175f4*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1176a1*/
          return; /*0x1176a5*/
        }
        if ( *v5 ) /*0x1175f0*/
        {
          if ( !useracc(*v3, *v5, 1) ) /*0x11760c*/
          {
            *(_BYTE *)(dword_1E875C + 104) = 14; /*0x1176ad*/
            return; /*0x1176b1*/
          }
          v13 += *v5; /*0x117614*/
        }
        ++v4; /*0x117617*/
        v5 += 2; /*0x117618*/
        v3 += 2; /*0x11761b*/
      }
      while ( a2[3] > v4 ); /*0x1175f0*/
    }
    if ( *a2 ) /*0x117629*/
    {
      *(_BYTE *)(dword_1E875C + 104) = sockargs(&v10, *a2, a2[1], 8); /*0x117646*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x117651*/
        return; /*0x117655*/
    }
    else
    {
      v10 = 0; /*0x117660*/
    }
    v6 = a2[4]; /*0x11766a*/
    if ( v6 ) /*0x11766f*/
    {
      *(_BYTE *)(dword_1E875C + 104) = sockargs(&v9, v6, a2[5], 12); /*0x117688*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x117693*/
      {
LABEL_21:
        if ( v10 ) /*0x117709*/
          m_freem(v10); /*0x11770c*/
        return; /*0x11770c*/
      }
    }
    else
    {
      v9 = 0; /*0x1176b4*/
    }
    v7 = v13; /*0x1176bb*/
    *(_BYTE *)(dword_1E875C + 104) = sosend(*(_DWORD *)(v8 + 24), v10, (int)v11, a3, v9); /*0x1176e3*/
    *(_DWORD *)(dword_1E875C + 96) = v7 - v13; /*0x1176ee*/
    if ( v9 ) /*0x1176f9*/
      m_freem(v9); /*0x1176fc*/
    goto LABEL_21; /*0x1176fc*/
  }
}
