/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121654. */
int rawintr()
{
  int v0; // ebx
  int result; // eax
  int i; // edi
  __int16 v3; // ax
  int **v4; // eax
  int v5; // ebx
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  while ( 1 ) /*0x121662*/
  {
    v0 = splimp(); /*0x121662*/
    v8 = rawintrq; /*0x12166a*/
    if ( rawintrq ) /*0x12166f*/
    {
      rawintrq = *(_DWORD *)(rawintrq + 124); /*0x121674*/
      if ( !rawintrq ) /*0x12167b*/
        dword_1E8A74 = 0; /*0x12167d*/
      *(_DWORD *)(v8 + 124) = 0; /*0x12168a*/
      --dword_1E8A78; /*0x121691*/
    }
    result = splx(v0); /*0x121698*/
    if ( !v8 ) /*0x1216a4*/
      break; /*0x1216a4*/
    v7 = *(_DWORD *)(v8 + 4) + v8; /*0x1216b0*/
    v6 = 0; /*0x1216b3*/
    for ( i = rawcb; (int *)i != &rawcb; i = *(_DWORD *)i ) /*0x1216c6*/
    {
      if ( *(_WORD *)(i + 44) == *(_WORD *)v7 ) /*0x1216d6*/
      {
        v3 = *(_WORD *)(i + 46); /*0x1216dc*/
        if ( (!v3 || *(_WORD *)(v7 + 2) == v3) /*0x121721*/
          && ((*(_BYTE *)(i + 76) & 1) == 0 || !bcmp((const void *)(i + 28), (const void *)(v7 + 4), 0x10u))
          && ((*(_BYTE *)(i + 76) & 2) == 0 || !bcmp((const void *)(i + 12), (const void *)(v7 + 20), 0x10u)) )
        {
          if ( v6 ) /*0x121731*/
          {
            v4 = (int **)m_copy(*(int **)v8, 0, 1000000000); /*0x121740*/
            v5 = (int)v4; /*0x121745*/
            if ( v4 ) /*0x12174c*/
            {
              if ( sbappendaddr((unsigned __int16 *)(v6 + 36), (int *)(v7 + 20), v4, 0) ) /*0x12175f*/
                sowakeup(v6, v6 + 36); /*0x12177d*/
              else
                m_freem(v5); /*0x12176c*/
            }
          }
          v6 = *(_DWORD *)(i + 8); /*0x121788*/
        }
      }
    }
    if ( v6 ) /*0x12179d*/
    {
      if ( sbappendaddr((unsigned __int16 *)(v6 + 36), (int *)(v7 + 20), *(int ***)v8, 0) ) /*0x1217b5*/
        sowakeup(v6, v6 + 36); /*0x1217d9*/
      else
        m_freem(*(_DWORD *)v8); /*0x1217c7*/
      m_free(v8); /*0x1217e5*/
    }
    else
    {
      m_freem(v8); /*0x1217f8*/
    }
  }
  return result; /*0x12180b*/
}
