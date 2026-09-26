/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f69c. */
void __cdecl ttcooked(int a1, int a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // edx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  char v11; // al
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // ebx
  char v20; // al
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int v24; // ebx
  int v25; // eax
  int i; // ebx
  char v27; // al
  long double v28; // [esp-Ch] [ebp-30h]
  char *v29; // [esp-4h] [ebp-28h]
  int v30; // [esp+10h] [ebp-14h]
  int v31; // [esp+14h] [ebp-10h]
  int v32; // [esp+18h] [ebp-Ch]
  int v33; // [esp+1Ch] [ebp-8h]
  int v34; // [esp+20h] [ebp-4h]

  v2 = a1; /*0x10f6a5*/
  v3 = *(_DWORD *)a2; /*0x10f6ab*/
  v34 = *(_DWORD *)(*(_DWORD *)a2 + 60); /*0x10f6b0*/
  v4 = *(_DWORD *)(a2 + 16); /*0x10f6b3*/
  v33 = v4; /*0x10f6b6*/
  if ( (a1 & 0xFF000000) == 0 ) /*0x10f6c0*/
    goto LABEL_21; /*0x10f6c0*/
  v2 = a1 & 0xFFFFFF; /*0x10f6c6*/
  if ( (a1 & 0x1000000) == 0 || v2 ) /*0x10f6d9*/
  {
    if ( ((a1 & 0x2000000) == 0 || (v4 & 0x200000) == 0) && (a1 & 0x1000000) == 0 ) /*0x10f7a7*/
      goto LABEL_21; /*0x10f7a7*/
    if ( (v4 & 0x80000) != 0 ) /*0x10f7b2*/
      goto LABEL_175; /*0x10f7b2*/
    if ( (*(_DWORD *)(a2 + 16) & 0x100000) == 0 ) /*0x10f7be*/
    {
      v2 = 256; /*0x10f7e4*/
      goto LABEL_21; /*0x10f7e4*/
    }
LABEL_19:
    putc(511, (FILE *)v3); /*0x10f7c0*/
    putc(256, (FILE *)v3); /*0x10f7d1*/
    v2 = a1 & 0xFFFEFF | 0x100; /*0x10f7d6*/
    goto LABEL_21; /*0x10f7df*/
  }
  if ( (v4 & 0x20000) != 0 ) /*0x10f6e5*/
    goto LABEL_175; /*0x10f6e5*/
  if ( (v4 & 0x40000) != 0 ) /*0x10f6f1*/
  {
    v5 = spltty(); /*0x10f6fc*/
    while ( getc((FILE *)(v3 + 12)) >= 0 ) /*0x10f70f*/
      ; /*0x10f704*/
    wakeup(v3); /*0x10f712*/
    wakeup(v3 + 24); /*0x10f71e*/
    *(_DWORD *)(v3 + 64) &= ~0x100u; /*0x10f723*/
    ((void (__cdecl *)(int, int))funcs_10DE95[11 * *(unsigned __int8 *)(v3 + 57)])(v3, 3); /*0x10f73e*/
    while ( getc((FILE *)(v3 + 24)) >= 0 ) /*0x10f74f*/
      ; /*0x10f744*/
    while ( getc((FILE *)v3) >= 0 ) /*0x10f75f*/
      ; /*0x10f754*/
    *(_BYTE *)(v3 + 75) = 0; /*0x10f761*/
    *(_BYTE *)(v3 + 76) = 0; /*0x10f765*/
    *(_DWORD *)(v3 + 64) &= 0xFF40FFFF; /*0x10f769*/
    splx(v5); /*0x10f771*/
    gsignal((_DWORD *)*(__int16 *)(v3 + 68), (char *)2); /*0x10f77b*/
    goto LABEL_175; /*0x10f77b*/
  }
  if ( (v4 & 0x100000) != 0 ) /*0x10f789*/
    goto LABEL_19; /*0x10f789*/
LABEL_21:
  if ( (*(_BYTE *)(v3 + 66) & 0x10) == 0 && (v34 & 0x8000020) == 0 && (v33 & 0x400000) != 0 ) /*0x10f801*/
    v2 &= ~0x80u; /*0x10f803*/
  v6 = *(_DWORD *)(v3 + 64); /*0x10f809*/
  if ( (v6 & 0x80000) != 0 ) /*0x10f811*/
  {
    v2 |= 0x100u; /*0x10f813*/
    *(_DWORD *)(v3 + 64) = v6 & 0xFFF7FFFF; /*0x10f81e*/
  }
  if ( (v2 & 0x100) == 0 /*0x10f849*/
    && (*(_BYTE *)(v3 + 66) & 0x40) == 0
    && ((*(int *)(v3 + 4 * (v2 >> 5) + 100) >> (v2 & 0x1F)) & 1) != 0 )
  {
    if ( (_UNKNOWN *)(v33 & 0x181000) == &unk_101000 && v2 == 255 ) /*0x10f864*/
    {
      putc(511, (FILE *)v3); /*0x10f86c*/
      v2 = 511; /*0x10f871*/
    }
    if ( (v33 & 0x10) != 0 && (_BYTE)v2 != 0xFF ) /*0x10f88a*/
    {
      if ( *(_BYTE *)(v3 + 90) == (_BYTE)v2 ) /*0x10f893*/
      {
        if ( (v34 & 8) != 0 ) /*0x10f89b*/
        {
          if ( (v34 & 0x40000) != 0 ) /*0x10f8a3*/
            ttyoutstr(asc_1DAF76, v3); /*0x10f8ab*/
          else
            ttyecho(v2, a2); /*0x10f8b9*/
        }
        *(_DWORD *)(v3 + 64) |= 0x80000u; /*0x10f8be*/
        goto LABEL_175; /*0x10f8c5*/
      }
      if ( *(_BYTE *)(v3 + 88) == (_BYTE)v2 ) /*0x10f8da*/
      {
        if ( (v34 & 0x800000) != 0 ) /*0x10f8e9*/
        {
LABEL_181:
          *(_DWORD *)(v3 + 60) &= ~0x800000u; /*0x110000*/
          return; /*0x110000*/
        }
        v32 = spltty(); /*0x10f8f4*/
        wakeup(v3 + 24); /*0x10f8fb*/
        *(_DWORD *)(v3 + 64) &= ~0x100u; /*0x10f900*/
        ((void (__cdecl *)(int, int))funcs_10DE95[11 * *(unsigned __int8 *)(v3 + 57)])(v3, 2); /*0x10f91b*/
        while ( getc((FILE *)(v3 + 24)) >= 0 ) /*0x10f92b*/
          ; /*0x10f920*/
        splx(v32); /*0x10f931*/
        ttyecho(v2, a2); /*0x10f93e*/
        if ( *(_DWORD *)(v3 + 12) + *(_DWORD *)v3 ) /*0x10f945*/
          ttyretype(a2); /*0x10f953*/
        *(_DWORD *)(v3 + 60) |= 0x800000u; /*0x10f958*/
        return; /*0x10f95f*/
      }
    }
    if ( (v33 & 8) != 0 && (_BYTE)v2 != 0xFF ) /*0x10f975*/
    {
      if ( *(_BYTE *)(v3 + 79) == (_BYTE)v2 || *(_BYTE *)(v3 + 80) == (_BYTE)v2 ) /*0x10f983*/
      {
        if ( v34 >= 0 ) /*0x10f98d*/
        {
          v31 = spltty(); /*0x10f998*/
          while ( getc((FILE *)(v3 + 12)) >= 0 ) /*0x10f9ab*/
            ; /*0x10f9a0*/
          wakeup(v3); /*0x10f9ae*/
          wakeup(v3 + 24); /*0x10f9ba*/
          *(_DWORD *)(v3 + 64) &= ~0x100u; /*0x10f9bf*/
          ((void (__cdecl *)(int, int))funcs_10DE95[11 * *(unsigned __int8 *)(v3 + 57)])(v3, 3); /*0x10f9da*/
          while ( getc((FILE *)(v3 + 24)) >= 0 ) /*0x10f9eb*/
            ; /*0x10f9e0*/
          while ( getc((FILE *)v3) >= 0 ) /*0x10f9fb*/
            ; /*0x10f9f0*/
          *(_BYTE *)(v3 + 75) = 0; /*0x10f9fd*/
          *(_BYTE *)(v3 + 76) = 0; /*0x10fa01*/
          *(_DWORD *)(v3 + 64) &= 0xFF40FFFF; /*0x10fa05*/
          splx(v31); /*0x10fa10*/
        }
        ttyecho(v2, a2); /*0x10fa1d*/
        v7 = 3; /*0x10fa25*/
        if ( *(_BYTE *)(v3 + 79) == (_BYTE)v2 ) /*0x10fa34*/
          v7 = 2; /*0x10fa36*/
        gsignal((_DWORD *)*(__int16 *)(v3 + 68), (char *)v7); /*0x10fa3c*/
        goto LABEL_175; /*0x10fa3c*/
      }
      if ( *(_BYTE *)(v3 + 85) == (_BYTE)v2 ) /*0x10fa4a*/
      {
        if ( v34 >= 0 ) /*0x10fa50*/
        {
          v30 = spltty(); /*0x10fa57*/
          while ( getc((FILE *)(v3 + 12)) >= 0 ) /*0x10fa6b*/
            ; /*0x10fa60*/
          wakeup(v3); /*0x10fa6e*/
          while ( getc((FILE *)v3) >= 0 ) /*0x10fa83*/
            ; /*0x10fa78*/
          *(_BYTE *)(v3 + 75) = 0; /*0x10fa85*/
          *(_BYTE *)(v3 + 76) = 0; /*0x10fa89*/
          *(_DWORD *)(v3 + 64) &= 0xFF40FFFF; /*0x10fa8d*/
          splx(v30); /*0x10fa98*/
        }
        ttyecho(v2, a2); /*0x10faa5*/
        gsignal((_DWORD *)*(__int16 *)(v3 + 68), v29); /*0x10fab1*/
        goto LABEL_175; /*0x10fab6*/
      }
    }
    if ( (v33 & 0x4000000) != 0 && (_BYTE)v2 != 0xFF ) /*0x10facc*/
    {
      if ( *(_BYTE *)(v3 + 82) == (_BYTE)v2 ) /*0x10fad1*/
      {
        v8 = *(_DWORD *)(v3 + 64); /*0x10fad3*/
        if ( (v8 & 0x100) == 0 ) /*0x10fad9*/
        {
          BYTE1(v8) |= 1u; /*0x10fadb*/
          *(_DWORD *)(v3 + 64) = v8; /*0x10fade*/
          ((void (__cdecl *)(int, _DWORD))funcs_10DE95[11 * *(unsigned __int8 *)(v3 + 57)])(v3, 0); /*0x10faf5*/
          return; /*0x10faf7*/
        }
        if ( *(_BYTE *)(v3 + 81) != (_BYTE)v2 ) /*0x10fb0a*/
          return; /*0x10fb0a*/
        goto LABEL_175; /*0x10fb0a*/
      }
      if ( *(_BYTE *)(v3 + 81) == (_BYTE)v2 ) /*0x10fb22*/
      {
LABEL_180:
        *(_DWORD *)(v3 + 64) &= ~0x100u; /*0x10fff9*/
        goto LABEL_181; /*0x10fff9*/
      }
    }
    if ( v2 == 13 ) /*0x10fb2b*/
    {
      if ( (v33 & 0x1000000) != 0 ) /*0x10fb36*/
        goto LABEL_175; /*0x10fb36*/
      if ( (v34 & 0x10) != 0 || (v33 & 0x2000000) != 0 ) /*0x10fb4a*/
        v2 = 10; /*0x10fb4c*/
    }
    else if ( v2 == 10 && (v33 & 0x800000) != 0 ) /*0x10fb62*/
    {
      v2 = 13; /*0x10fb64*/
    }
    if ( (v34 & 4) != 0 && v2 <= 127 ) /*0x10fb74*/
    {
      v9 = *(_DWORD *)(v3 + 64); /*0x10fb76*/
      if ( (v9 & 0x10000) != 0 ) /*0x10fb7f*/
      {
        v10 = unputc(v3); /*0x10fb86*/
        ttyrub(v10, a2); /*0x10fb8f*/
        v11 = maptab[v2]; /*0x10fb97*/
        if ( v11 ) /*0x10fb9f*/
          v2 = v11; /*0x10fba1*/
        v2 |= 0x100u; /*0x10fba4*/
        *(_DWORD *)(v3 + 64) &= 0xFFFCFFFF; /*0x10fbaa*/
        goto LABEL_92; /*0x10fbaa*/
      }
      if ( (unsigned int)(v2 - 65) > 0x19 ) /*0x10fbc2*/
      {
        if ( v2 == 92 ) /*0x10fbcf*/
          *(_DWORD *)(v3 + 64) = v9 | 0x10000; /*0x10fbd7*/
      }
      else
      {
        v2 += 32; /*0x10fbc4*/
      }
    }
    if ( (v34 & 0x22) != 0 ) /*0x10fbde*/
      goto LABEL_99; /*0x10fbde*/
    if ( (*(_BYTE *)(v3 + 66) & 2) != 0 ) /*0x10fc60*/
    {
      if ( (_BYTE)v2 == 0xFF ) /*0x10fc67*/
      {
LABEL_148:
        if ( *(_DWORD *)(v3 + 12) + *(_DWORD *)v3 > 1023 ) /*0x10fe9a*/
        {
          if ( (v33 & 0x8000000) != 0 && *(_DWORD *)(v3 + 24) < tthiwat[*(_BYTE *)(v3 + 74) & 0x1F] ) /*0x10feb8*/
            ttyoutput(7, v3); /*0x10febd*/
          DWORD2(v28) = *(__int16 *)(v3 + 56); /*0x10fec9*/
          DWORD1(v28) = aTtyDCanonInput; /*0x10feca*/
LABEL_153:
          LODWORD(v28) = 4; /*0x10fecf*/
          log(v28); /*0x10fed1*/
          goto LABEL_175; /*0x10fed6*/
        }
        if ( putc(v2, (FILE *)v3) >= 0 ) /*0x10fee8*/
        {
          if ( v2 == 10 || (v2 == *(unsigned __int8 *)(v3 + 83) || v2 == *(unsigned __int8 *)(v3 + 84)) && v2 != 255 ) /*0x10ff09*/
          {
            *(_BYTE *)(v3 + 75) = 0; /*0x10ff0b*/
            catq(v3, v3 + 12); /*0x10ff14*/
            ttwakeup(v3); /*0x10ff1a*/
          }
          else
          {
            v20 = *(_BYTE *)(v3 + 75); /*0x10ff24*/
            *(_BYTE *)(v3 + 75) = v20 + 1; /*0x10ff27*/
            if ( !v20 ) /*0x10ff2c*/
              *(_BYTE *)(v3 + 76) = *(_BYTE *)(v3 + 72); /*0x10ff31*/
          }
          v21 = *(_DWORD *)(v3 + 64); /*0x10ff34*/
          *(_DWORD *)(v3 + 64) = v21 & 0xFFFDFFFF; /*0x10ff3f*/
          if ( (v21 & 0x400000) == 0 ) /*0x10ff47*/
          {
            if ( (_BYTE)v2 != 0xFF && *(_BYTE *)(a2 + 20) == (_BYTE)v2 ) /*0x10ff5a*/
              *(_DWORD *)(v3 + 64) = v21 & 0xFFFDFFFF | 0x20000; /*0x10ff62*/
            v22 = *(_DWORD *)(v3 + 64); /*0x10ff65*/
            if ( (v22 & 0x40000) != 0 ) /*0x10ff6d*/
            {
              *(_DWORD *)(v3 + 64) = v22 & 0xFFFBFFFF; /*0x10ff74*/
              ttyoutput(47, v3); /*0x10ff7a*/
            }
            v23 = *(char *)(v3 + 72); /*0x10ff82*/
            ttyecho(v2, a2); /*0x10ff8b*/
            if ( (_BYTE)v2 != 0xFF && *(_BYTE *)(v3 + 83) == (_BYTE)v2 && (v34 & 8) != 0 ) /*0x10ffa5*/
            {
              v24 = *(char *)(v3 + 72) - v23; /*0x10ffad*/
              v25 = 2; /*0x10ffaf*/
              if ( v24 <= 2 ) /*0x10ffb7*/
                v25 = v24; /*0x10ffb9*/
              for ( i = v25; i > 0; --i ) /*0x10ffbf*/
                ttyoutput(8, v3); /*0x10ffc7*/
            }
          }
        }
        goto LABEL_175; /*0x10ffd2*/
      }
      if ( *(_BYTE *)(v3 + 77) == (_BYTE)v2 || *(_BYTE *)(v3 + 78) == (_BYTE)v2 ) /*0x10fc75*/
      {
        v12 = unputc(v3); /*0x10fc7c*/
        ttyrub(v12, a2); /*0x10fc85*/
        v2 |= 0x100u; /*0x10fc8a*/
        goto LABEL_148; /*0x10fc93*/
      }
    }
    if ( (_BYTE)v2 != 0xFF ) /*0x10fc9d*/
    {
      if ( *(_BYTE *)(v3 + 77) == (_BYTE)v2 ) /*0x10fca6*/
      {
        if ( *(_DWORD *)v3 ) /*0x10fca8*/
        {
          v13 = unputc(v3); /*0x10fcbe*/
          ttyrub(v13, a2); /*0x10fcc1*/
          if ( (v34 & 0x80000) != 0 && (v13 & 0x80u) != 0 ) /*0x10fcdc*/
          {
            if ( *(_DWORD *)v3 ) /*0x10fce2*/
            {
              v14 = unputc(v3); /*0x10fcec*/
              if ( (_BYTE)v14 != 0x8E ) /*0x10fcf8*/
                ttyrub(v14, a2); /*0x10fd03*/
            }
          }
        }
        goto LABEL_175; /*0x10fd08*/
      }
      if ( *(_BYTE *)(v3 + 78) == (_BYTE)v2 ) /*0x10fd1e*/
      {
        if ( (v33 & 4) != 0 && (v34 & 0x4000000) != 0 && *(_DWORD *)v3 == *(char *)(v3 + 75) ) /*0x10fd3f*/
        {
          while ( *(_DWORD *)v3 ) /*0x10fd3b*/
          {
            v15 = unputc(v3); /*0x10fd4d*/
            ttyrub(v15, a2); /*0x10fd56*/
          }
        }
        else
        {
          ttyecho(v2, a2); /*0x10fd6d*/
          if ( (v33 & 4) != 0 ) /*0x10fd7b*/
            ttyecho(10, a2); /*0x10fd83*/
          while ( getc((FILE *)v3) > 0 ) /*0x10fd97*/
            ; /*0x10fd8c*/
          *(_BYTE *)(v3 + 75) = 0; /*0x10fd99*/
        }
        *(_DWORD *)(v3 + 64) &= 0xFFC0FFFF; /*0x10fd9d*/
        goto LABEL_175; /*0x10fda4*/
      }
      if ( *(_BYTE *)(v3 + 89) == (_BYTE)v2 ) /*0x10fdba*/
      {
        while ( 1 ) /*0x10fdcd*/
        {
          v16 = unputc(v3); /*0x10fdcd*/
          if ( v16 != 32 && v16 != 9 ) /*0x10fddf*/
            break; /*0x10fddf*/
          ttyrub(v16, a2); /*0x10fde6*/
        }
        if ( v16 != -1 ) /*0x10fdf3*/
        {
          ttyrub(v16, a2); /*0x10fdfe*/
          v17 = unputc(v3); /*0x10fe04*/
          v18 = v17; /*0x10fe09*/
          if ( v17 != -1 ) /*0x10fe11*/
          {
            v19 = partab[(unsigned __int8)v17] & 0x40; /*0x10fe22*/
            while ( v18 != 32 && v18 != 9 && ((v33 & 0x20) == 0 || (partab[(unsigned __int8)v18] & 0x40) == v19) ) /*0x10fe3e*/
            {
              ttyrub(v18, a2); /*0x10fe45*/
              v18 = unputc(v3); /*0x10fe50*/
              if ( v18 == -1 ) /*0x10fe58*/
                goto LABEL_175; /*0x10fe58*/
            }
            putc(v18, (FILE *)v3); /*0x10fe6a*/
          }
        }
        goto LABEL_175; /*0x10fe6f*/
      }
      if ( *(_BYTE *)(v3 + 87) == (_BYTE)v2 ) /*0x10fe7e*/
      {
        ttyretype(a2); /*0x10fe84*/
        goto LABEL_175; /*0x10fe89*/
      }
    }
    goto LABEL_148; /*0x10fe7e*/
  }
LABEL_92:
  if ( (v34 & 0x22) == 0 ) /*0x10fbb5*/
    goto LABEL_148; /*0x10fbb5*/
LABEL_99:
  if ( *(int *)v3 > 1024 ) /*0x10fbe6*/
  {
    if ( *(_DWORD *)(v3 + 24) < tthiwat[*(_BYTE *)(v3 + 74) & 0x1F] && (v33 & 0x8000000) != 0 ) /*0x10fc04*/
      ttyoutput(7, v3); /*0x10fc09*/
    DWORD2(v28) = *(__int16 *)(v3 + 56); /*0x10fc15*/
    DWORD1(v28) = aTtyDCbreakInpu; /*0x10fc16*/
    goto LABEL_153; /*0x10fc1b*/
  }
  if ( putc(v2, (FILE *)v3) >= 0 ) /*0x10fc2c*/
  {
    if ( ttcheckwakeup(a2) ) /*0x10fc36*/
      ttwakeup(v3); /*0x10fc43*/
    ttyecho(v2, a2); /*0x10fc50*/
  }
LABEL_175:
  if ( (v33 & 0x10) != 0 ) /*0x10ffda*/
  {
    if ( (v34 & 0x40000000) == 0 ) /*0x10ffe5*/
      goto LABEL_180; /*0x10ffe5*/
    if ( (*(_BYTE *)(v3 + 65) & 1) == 0 ) /*0x10ffeb*/
      goto LABEL_180; /*0x10ffeb*/
    v27 = *(_BYTE *)(v3 + 82); /*0x10ffed*/
    if ( v27 != -1 && *(_BYTE *)(v3 + 81) == v27 ) /*0x10fff7*/
      goto LABEL_180; /*0x10fff7*/
  }
}
