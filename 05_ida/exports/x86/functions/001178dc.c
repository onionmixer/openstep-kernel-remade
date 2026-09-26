/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1178dc. */
void __cdecl recvit(int a1, _DWORD *a2, char a3, int a4, int a5)
{
  _DWORD *v5; // edi
  int v6; // edx
  _DWORD *v7; // ebx
  int v8; // eax
  int v9; // edx
  int v10; // [esp+Ch] [ebp-2Ch]
  int v11; // [esp+10h] [ebp-28h]
  int v12; // [esp+14h] [ebp-24h] BYREF
  int v13; // [esp+18h] [ebp-20h] BYREF
  int v14; // [esp+1Ch] [ebp-1Ch] BYREF
  _DWORD v15[5]; // [esp+20h] [ebp-18h] BYREF
  int v16; // [esp+34h] [ebp-4h]

  v11 = getsock(a1); /*0x1178ee*/
  if ( v11 ) /*0x1178f6*/
  {
    v15[0] = a2[2]; /*0x117902*/
    v15[1] = a2[3]; /*0x11790b*/
    v15[3] = 0; /*0x11790e*/
    v15[2] = 0; /*0x117915*/
    v16 = 0; /*0x11791c*/
    v5 = (_DWORD *)a2[2]; /*0x117926*/
    v6 = 0; /*0x117929*/
    if ( (int)a2[3] > 0 ) /*0x11792e*/
    {
      v7 = v5 + 1; /*0x117930*/
      do /*0x117934*/
      {
        if ( (int)*v7 < 0 ) /*0x117938*/
        {
          *(_BYTE *)(dword_1E875C + 104) = 22; /*0x117a31*/
          return; /*0x117a35*/
        }
        if ( *v7 ) /*0x117934*/
        {
          v10 = v6; /*0x117946*/
          v8 = useracc(*v5, *v7, 0); /*0x117949*/
          v6 = v10; /*0x117951*/
          if ( !v8 ) /*0x117956*/
          {
            *(_BYTE *)(dword_1E875C + 104) = 14; /*0x117a3d*/
            return; /*0x117a41*/
          }
          v16 += *v7; /*0x11795e*/
        }
        ++v6; /*0x117961*/
        v7 += 2; /*0x117962*/
        v5 += 2; /*0x117965*/
      }
      while ( a2[3] > v6 ); /*0x117934*/
    }
    v12 = v16; /*0x117970*/
    *(_BYTE *)(dword_1E875C + 104) = soreceive(*(_DWORD *)(v11 + 24), &v14, (int)v15, a3, &v13); /*0x117999*/
    *(_DWORD *)(dword_1E875C + 96) = v12 - v16; /*0x1179a7*/
    if ( *a2 ) /*0x1179b0*/
    {
      v9 = a2[1]; /*0x1179b5*/
      v12 = v9; /*0x1179b8*/
      if ( v9 > 0 && v14 ) /*0x1179c4*/
      {
        if ( v9 > *(__int16 *)(v14 + 8) ) /*0x1179d6*/
          v12 = *(__int16 *)(v14 + 8); /*0x1179d8*/
        copyout(*(_DWORD *)(v14 + 4) + v14, *a2, v12); /*0x1179e9*/
      }
      else
      {
        v12 = 0; /*0x1179c6*/
      }
      copyout(&v12, a4, 4); /*0x1179fb*/
    }
    if ( a2[4] ) /*0x117a06*/
    {
      v12 = a2[5]; /*0x117a0f*/
      if ( v12 > 0 && v13 ) /*0x117a1e*/
      {
        if ( v12 > *(__int16 *)(v13 + 8) ) /*0x117a4a*/
          v12 = *(__int16 *)(v13 + 8); /*0x117a4c*/
        copyout(*(_DWORD *)(v13 + 4) + v13, a2[4], v12); /*0x117a5e*/
      }
      else
      {
        v12 = 0; /*0x117a20*/
      }
      copyout(&v12, a5, 4); /*0x117a70*/
    }
    if ( v13 ) /*0x117a7d*/
      m_freem(v13); /*0x117a80*/
    if ( v14 ) /*0x117a8d*/
      m_freem(v14); /*0x117a90*/
  }
}
