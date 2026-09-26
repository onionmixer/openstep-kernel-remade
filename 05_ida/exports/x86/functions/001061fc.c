/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1061fc. */
int __cdecl wait1(char a1, void *a2, int *a3, int a4)
{
  int i; // ebx
  int v5; // eax
  int v6; // eax
  const void *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // [esp+Ch] [ebp-4h]

  if ( *(char *)(dword_1E875C + 104) >= 0 ) /*0x106214*/
  {
    *(_DWORD *)(dword_1E875C + 136) = 0; /*0x106268*/
  }
  else if ( (unsigned int)(thread_wait_result() - 2) > 1 ) /*0x106221*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 0; /*0x106261*/
  }
  else
  {
    if ( ((*(int *)(active_u + 320) >> (*(_BYTE *)(*(_DWORD *)active_u + 23) - 1)) & 1) != 0 ) /*0x10623b*/
      unix_syscall_return(4); /*0x10623f*/
    *(_BYTE *)(dword_1E875C + 105) = 2; /*0x10624c*/
    unix_syscall_return(0); /*0x106252*/
  }
  v20 = *(_DWORD *)active_u; /*0x106279*/
  for ( i = *(_DWORD *)(*(_DWORD *)active_u + 72); i; i = *(_DWORD *)(i + 76) ) /*0x10627c*/
  {
    if ( !a4 || a4 == *(__int16 *)(i + 48) ) /*0x106292*/
    {
      ++*(_DWORD *)(dword_1E875C + 136); /*0x10629d*/
      v5 = *(_DWORD *)(i + 104); /*0x1062a3*/
      if ( v5 ) /*0x1062a8*/
      {
        if ( *(int *)(v5 + 68) > 0 && *(_BYTE *)(i + 19) == 6 ) /*0x1063de*/
        {
          v13 = *(_DWORD *)(i + 40); /*0x1063e0*/
          if ( (v13 & 0x20) == 0 && ((v13 & 0x10) != 0 || (a1 & 2) != 0) ) /*0x1063f1*/
          {
            v14 = *(_DWORD *)(i + 124); /*0x1063f3*/
            if ( !v14 || v20 == v14 ) /*0x1063fd*/
            {
              LOBYTE(v13) = v13 | 0x20; /*0x1063ff*/
              *(_DWORD *)(i + 40) = v13; /*0x106402*/
              *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(i + 48); /*0x10640e*/
              LOBYTE(v15) = *(_BYTE *)(i + 23); /*0x106411*/
              if ( (_BYTE)v15 ) /*0x106416*/
                goto LABEL_48; /*0x106416*/
              v15 = *(_DWORD *)(i + 60); /*0x10641c*/
              goto LABEL_49; /*0x10641f*/
            }
          }
        }
      }
      else
      {
        v6 = *(_DWORD *)(i + 124); /*0x1062ae*/
        if ( !v6 || v20 == v6 ) /*0x1062b8*/
        {
          *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(i + 48); /*0x1062c7*/
          *a3 = *(unsigned __int16 *)(i + 52); /*0x1062ce*/
          *(_WORD *)(i + 52) = 0; /*0x1062d0*/
          if ( a2 ) /*0x1062da*/
          {
            v7 = *(const void **)(i + 56); /*0x1062dc*/
            if ( v7 ) /*0x1062e1*/
            {
              qmemcpy(a2, v7, 0x48u); /*0x1062ec*/
              goto LABEL_17; /*0x1062ec*/
            }
          }
          else
          {
LABEL_17:
            if ( *(_DWORD *)(i + 56) ) /*0x1062ee*/
            {
              ruadd(active_u + 440, *(_DWORD *)(i + 56)); /*0x106301*/
              kfree(*(_DWORD *)(i + 56), 0x48u); /*0x10630c*/
              *(_DWORD *)(i + 56) = 0; /*0x106311*/
            }
          }
          leavepgrp(i); /*0x10631c*/
          delete_posix_proc(i); /*0x106322*/
          *(_BYTE *)(i + 19) = 0; /*0x106327*/
          *(_WORD *)(i + 48) = 0; /*0x10632b*/
          *(_WORD *)(i + 50) = 0; /*0x106331*/
          v8 = *(_DWORD *)(i + 8); /*0x10633a*/
          **(_DWORD **)(i + 12) = v8; /*0x10633d*/
          if ( v8 ) /*0x106341*/
            *(_DWORD *)(*(_DWORD *)(i + 8) + 12) = *(_DWORD *)(i + 12); /*0x106349*/
          *(_DWORD *)(i + 8) = freeproc; /*0x106352*/
          freeproc = i; /*0x106355*/
          v9 = *(_DWORD *)(i + 80); /*0x10635b*/
          if ( v9 ) /*0x106360*/
            *(_DWORD *)(v9 + 76) = *(_DWORD *)(i + 76); /*0x106365*/
          v10 = *(_DWORD *)(i + 76); /*0x106368*/
          if ( v10 ) /*0x10636d*/
            *(_DWORD *)(v10 + 80) = *(_DWORD *)(i + 80); /*0x106372*/
          v11 = *(_DWORD *)(i + 68); /*0x106375*/
          if ( *(_DWORD *)(v11 + 72) == i ) /*0x10637b*/
            *(_DWORD *)(v11 + 72) = *(_DWORD *)(i + 76); /*0x106380*/
          *(_DWORD *)(i + 68) = 0; /*0x106383*/
          *(_DWORD *)(i + 80) = 0; /*0x10638a*/
          *(_DWORD *)(i + 76) = 0; /*0x106391*/
          *(_DWORD *)(i + 72) = 0; /*0x106398*/
          *(_DWORD *)(i + 24) = 0; /*0x10639f*/
          *(_DWORD *)(i + 36) = 0; /*0x1063a6*/
          *(_DWORD *)(i + 32) = 0; /*0x1063ad*/
          *(_DWORD *)(i + 28) = 0; /*0x1063b4*/
          *(_WORD *)(i + 46) = 0; /*0x1063bb*/
          *(_DWORD *)(i + 40) = 0; /*0x1063c1*/
          *(_BYTE *)(i + 23) = 0; /*0x1063c8*/
          return 0; /*0x1063ce*/
        }
      }
    }
  }
  v16 = *(_DWORD *)(v20 + 128); /*0x10642f*/
  if ( !v16 ) /*0x10643a*/
    goto LABEL_57; /*0x10643a*/
  v17 = *(_DWORD *)(v20 + 128); /*0x10643c*/
  ++*(_DWORD *)(dword_1E875C + 136); /*0x106443*/
  v18 = *(_DWORD *)(v16 + 104); /*0x106449*/
  if ( !v18 ) /*0x10644e*/
  {
    *(_DWORD *)(v17 + 124) = 0; /*0x106450*/
    *(_DWORD *)(v17 + 40) &= ~0x10u; /*0x106457*/
    wakeup(*(_DWORD *)(v17 + 68)); /*0x10645f*/
    return 0; /*0x106466*/
  }
  if ( *(int *)(v18 + 68) > 0 /*0x106489*/
    && *(_BYTE *)(v17 + 19) == 6
    && (v15 = *(_DWORD *)(v17 + 40), (v15 & 0x20) == 0)
    && ((v15 & 0x10) != 0 || (a1 & 2) != 0) )
  {
    LOBYTE(v15) = v15 | 0x20; /*0x10648b*/
    *(_DWORD *)(v17 + 40) = v15; /*0x10648d*/
    *(_DWORD *)(dword_1E875C + 96) = *(__int16 *)(v17 + 48); /*0x106499*/
    LOBYTE(v15) = *(_BYTE *)(v17 + 23); /*0x10649c*/
    if ( (_BYTE)v15 ) /*0x1064a1*/
LABEL_48:
      v15 = (char)v15; /*0x1064a8*/
    else
      v15 = *(_DWORD *)(v17 + 60); /*0x1064a3*/
LABEL_49:
    v19 = v15 << 8; /*0x1064ab*/
    LOBYTE(v19) = v19 | 0x7F; /*0x1064ae*/
    *a3 = v19; /*0x1064b0*/
    return 0; /*0x1064b2*/
  }
  else
  {
LABEL_57:
    if ( *(_DWORD *)(dword_1E875C + 136) ) /*0x1064bd*/
    {
      if ( (a1 & 1) != 0 ) /*0x1064d6*/
      {
        *(_DWORD *)(dword_1E875C + 96) = 0; /*0x1064d8*/
        return 0; /*0x1064df*/
      }
      else
      {
        *(_BYTE *)(dword_1E875C + 104) = -1; /*0x1064e4*/
        return sleep_with_continuation(*(_DWORD *)active_u); /*0x1064f6*/
      }
    }
    else
    {
      return 10; /*0x1064c6*/
    }
  }
}
