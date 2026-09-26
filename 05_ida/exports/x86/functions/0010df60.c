/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10df60. */
int __cdecl ttioctl(FILE *a1, int a2, int *a3, char a4)
{
  _BYTE *v4; // edi
  __int16 v5; // dx
  int ur_high; // esi
  int base_low; // esi
  int v8; // ebx
  int v10; // edi
  int v11; // edx
  int v12; // edx
  int v13; // ebx
  int (__cdecl *v14)(void *, char *, int); // edx
  int v15; // eax
  int v16; // ebx
  int v17; // ebx
  int (__cdecl *read)(void *, char *, int); // edx
  _DWORD *v19; // edi
  int ur_low; // edi
  int v21; // edi
  _DWORD *v22; // ebx
  _DWORD *posix_proc; // eax
  int v24; // edx
  int v25; // ebx
  int v26; // edx
  int v27; // eax
  int v28; // edx
  int ur; // eax
  int v30; // edi
  int v31; // ebx
  FILE *v32; // [esp+Ch] [ebp-34h]
  int v33; // [esp+Ch] [ebp-34h]
  unsigned int v34; // [esp+Ch] [ebp-34h]
  FILE *v35; // [esp+Ch] [ebp-34h]
  FILE *v36; // [esp+Ch] [ebp-34h]
  int v37; // [esp+14h] [ebp-2Ch]
  int v38; // [esp+1Ch] [ebp-24h]
  int v39; // [esp+20h] [ebp-20h]
  int v40; // [esp+24h] [ebp-1Ch]
  int v41; // [esp+28h] [ebp-18h]
  int v42; // [esp+28h] [ebp-18h]
  int v43; // [esp+28h] [ebp-18h]
  int v44; // [esp+28h] [ebp-18h]
  int v45; // [esp+28h] [ebp-18h]
  int extra_low; // [esp+2Ch] [ebp-14h]
  int v47; // [esp+30h] [ebp-10h]
  unsigned __int8 *v48; // [esp+34h] [ebp-Ch]
  unsigned __int8 *p; // [esp+34h] [ebp-Ch]
  __sbuf v50; // [esp+38h] [ebp-8h]
  __sbuf v51; // [esp+38h] [ebp-8h]

  v47 = ttynty(a1); /*0x10df75*/
  extra_low = SLOWORD(a1->_extra); /*0x10df7c*/
  if ( a2 != -2147060719 ) /*0x10df88*/
  {
    if ( a2 > -2147060719 ) /*0x10df8e*/
    {
      if ( a2 != 536900702 ) /*0x10e00e*/
      {
        if ( a2 > 536900702 ) /*0x10e010*/
        {
          if ( a2 < 536900718 || a2 > 536900719 && (a2 > 536900731 || a2 < 536900730) ) /*0x10e05e*/
            goto LABEL_36; /*0x10e05e*/
        }
        else if ( a2 != -2146929561 ) /*0x10e018*/
        {
          if ( a2 > -2146929561 ) /*0x10e01a*/
          {
            if ( a2 > -2145094634 || a2 < -2145094636 ) /*0x10e03a*/
              goto LABEL_36; /*0x10e03a*/
          }
          else if ( a2 != -2147060619 ) /*0x10e022*/
          {
            goto LABEL_36; /*0x10e022*/
          }
        }
      }
    }
    else if ( a2 != -2147191690 ) /*0x10df96*/
    {
      if ( a2 > -2147191690 ) /*0x10df9c*/
      {
        if ( a2 < -2147191683 || a2 > -2147191681 && (a2 > -2147060726 || a2 < -2147060727) ) /*0x10dffe*/
          goto LABEL_36; /*0x10dffe*/
      }
      else if ( a2 != -2147191807 ) /*0x10dfa4*/
      {
        if ( a2 > -2147191807 ) /*0x10dfaa*/
        {
          if ( a2 != -2147191792 ) /*0x10dfc6*/
            goto LABEL_36; /*0x10dfc6*/
        }
        else if ( a2 != -2147388302 ) /*0x10dfb2*/
        {
          goto LABEL_36; /*0x10dfb2*/
        }
      }
    }
  }
  while ( 1 ) /*0x10e083*/
  {
    v4 = *(_BYTE **)active_u; /*0x10e083*/
    v5 = *(_WORD *)(*(_DWORD *)active_u + 46); /*0x10e088*/
    if ( LOWORD(a1->_lb._base) == v5 /*0x10e0aa*/
      || *(FILE **)(active_u + 360) != a1
      || (v4[41] & 0x10) != 0
      || (v4[34] & 0x20) != 0
      || (v4[30] & 0x20) != 0 )
    {
      break; /*0x10e0aa*/
    }
    gsignal((_DWORD *)v5, (char *)0x16); /*0x10e06a*/
    sleep((unsigned int)&lbolt); /*0x10e076*/
  }
LABEL_36:
  if ( a2 == 536900610 ) /*0x10e0b2*/
  {
    v42 = spltty(); /*0x10e3c5*/
    *(_DWORD *)a1->_ubuf |= 0x200u; /*0x10e3c8*/
LABEL_134:
    v10 = v42; /*0x10e539*/
LABEL_135:
    splx(v10); /*0x10e53c*/
    return 0; /*0x10e542*/
  }
  if ( a2 <= 536900610 ) /*0x10e0b8*/
  {
    if ( a2 == -2147191682 ) /*0x10e0c4*/
    {
      a1->_ur &= ~(*a3 << 16); /*0x10e84e*/
    }
    else
    {
      if ( a2 <= -2147191682 ) /*0x10e0ca*/
      {
        if ( a2 == -2147191807 ) /*0x10e0d2*/
        {
          v8 = *a3; /*0x10e2eb*/
          if ( nldisp <= (unsigned int)*a3 || (char *)*(&linesw + 12 * v8) == (char *)nodev ) /*0x10e308*/
            return 6; /*0x10e30f*/
          if ( v8 == SHIBYTE(a1->_lb._base) ) /*0x10e31a*/
            return 0; /*0x10e31a*/
          v41 = spltty(); /*0x10e325*/
          (*(&off_1DAFEC + 12 * SHIBYTE(a1->_lb._base)))(a1); /*0x10e339*/
          a1[1]._write = nullptr; /*0x10e33b*/
          v32 = (FILE *)(*(&linesw + 12 * v8))(extra_low, a1); /*0x10e355*/
          if ( v32 ) /*0x10e35d*/
          {
            a1[1]._write = nullptr; /*0x10e35f*/
            (*(&linesw + 12 * SHIBYTE(a1->_lb._base)))(extra_low, a1); /*0x10e37b*/
            splx(v41); /*0x10e381*/
            return (int)v32; /*0x10e389*/
          }
          HIBYTE(a1->_lb._base) = v8; /*0x10e390*/
          goto LABEL_237; /*0x10e393*/
        }
        if ( a2 <= -2147191807 ) /*0x10e0d8*/
        {
          if ( a2 == -2147195267 ) /*0x10e0e0*/
          {
            v41 = spltty(); /*0x10e7c5*/
            if ( *a3 ) /*0x10e7cb*/
              *(_DWORD *)a1->_ubuf |= 0x4000u; /*0x10e7d0*/
            else
              *(_DWORD *)a1->_ubuf &= ~0x4000u; /*0x10e7dc*/
          }
          else
          {
            if ( a2 <= -2147195267 ) /*0x10e0e6*/
            {
              if ( a2 != -2147388302 ) /*0x10e0ee*/
                return -1; /*0x10ec81*/
              if ( !*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x10e555*/
                goto LABEL_140; /*0x10e555*/
              if ( (a4 & 1) != 0 ) /*0x10e55d*/
              {
                if ( *(FILE **)(active_u + 360) != a1 ) /*0x10e569*/
                  return 13; /*0x10e570*/
LABEL_140:
                v45 = spltty(); /*0x10e578*/
                (*(&off_1DAFFC + 12 * SHIBYTE(a1->_lb._base)))(*(unsigned __int8 *)a3, a1); /*0x10e598*/
                splx(v45); /*0x10e59a*/
                return 0; /*0x10e59a*/
              }
              return 1; /*0x10e947*/
            }
            if ( a2 != -2147195266 ) /*0x10e102*/
              return -1; /*0x10e102*/
            v41 = spltty(); /*0x10e79d*/
            if ( *a3 ) /*0x10e7a3*/
              *(_DWORD *)a1->_ubuf |= 0x2000u; /*0x10e7a8*/
            else
              *(_DWORD *)a1->_ubuf &= ~0x2000u; /*0x10e7b4*/
          }
LABEL_237:
          splx(v41); /*0x10ec1a*/
          return 0; /*0x10ec23*/
        }
        if ( a2 != -2147191690 ) /*0x10e116*/
        {
          if ( a2 <= -2147191690 ) /*0x10e11c*/
          {
            if ( a2 != -2147191792 ) /*0x10e124*/
              return -1; /*0x10e124*/
            if ( *a3 ) /*0x10e3d9*/
              v33 = *a3 & 3; /*0x10e3ec*/
            else
              v33 = 3; /*0x10e3e0*/
            v40 = spltty(); /*0x10e3f5*/
            if ( (v33 & 1) != 0 ) /*0x10e401*/
            {
              while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10e413*/
                ; /*0x10e408*/
              wakeup((int)a1); /*0x10e416*/
            }
            if ( (v33 & 2) != 0 ) /*0x10e424*/
            {
              wakeup((int)&a1->_lbfsize); /*0x10e42a*/
              *(_DWORD *)a1->_ubuf &= ~0x100u; /*0x10e42f*/
              ((void (__cdecl *)(FILE *, int))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, v33); /*0x10e452*/
              while ( getc((FILE *)&a1->_lbfsize) >= 0 ) /*0x10e463*/
                ; /*0x10e458*/
            }
            if ( (v33 & 1) != 0 ) /*0x10e46b*/
            {
              while ( getc(a1) >= 0 ) /*0x10e47b*/
                ; /*0x10e470*/
              HIBYTE(a1->_lb._size) = 0; /*0x10e47d*/
              LOBYTE(a1->_blksize) = 0; /*0x10e481*/
              *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10e485*/
            }
            v10 = v40; /*0x10e48c*/
            goto LABEL_135; /*0x10e48f*/
          }
          if ( a2 != -2147191683 ) /*0x10e136*/
            return -1; /*0x10e136*/
          ur_low = LOWORD(a1->_ur); /*0x10e874*/
          a1->_ur = ur_low; /*0x10e878*/
          a1->_ur = ur_low | (*a3 << 16); /*0x10e885*/
          v19 = (_DWORD *)v47; /*0x10e888*/
          *(_DWORD *)(v47 + 16) = 472193564; /*0x10e88b*/
          *(_BYTE *)(v47 + 20) = 92; /*0x10e892*/
          *(_BYTE *)(v47 + 21) = 1; /*0x10e896*/
          *(_BYTE *)(v47 + 22) = 0; /*0x10e89a*/
LABEL_179:
          ttysetspec(v19); /*0x10e89e*/
          return 0; /*0x10e8a4*/
        }
        v21 = *(_DWORD *)active_u; /*0x10e8c2*/
        v38 = *(_DWORD *)active_u; /*0x10e8c4*/
        v35 = (FILE *)*a3; /*0x10e8cc*/
        if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0 ) /*0x10e8d3*/
        {
          if ( !*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) || (a4 & 1) != 0 ) /*0x10e940*/
          {
            LOWORD(a1->_lb._base) = (_WORD)v35; /*0x10e950*/
            return 0; /*0x10e954*/
          }
          return 1; /*0x10e940*/
        }
        v22 = pgfind(*a3); /*0x10e8db*/
        posix_proc = get_posix_proc(*(__int16 *)(v21 + 48)); /*0x10e8e2*/
        if ( (int)v35 <= 0 || !v22 ) /*0x10e8ef*/
          return 22; /*0x10e8f6*/
        v24 = *(_DWORD *)(posix_proc[4] + 8); /*0x10e8ff*/
        if ( *(_DWORD *)(v47 + 8) == v24 && (*(_BYTE *)(v38 + 43) & 0x40) != 0 ) /*0x10e915*/
        {
          if ( v22[2] == v24 ) /*0x10e91a*/
          {
            *(_DWORD *)(v47 + 12) = v22; /*0x10e91f*/
            LOWORD(a1->_lb._base) = *((_WORD *)v22 + 6); /*0x10e926*/
            return 0; /*0x10e92a*/
          }
          return 1; /*0x10e91a*/
        }
        return 25; /*0x10e993*/
      }
      if ( a2 == -2147060719 ) /*0x10e14a*/
      {
        bcopy(a3, (char *)&a1->_blksize + 3, 6u); /*0x10e7fe*/
        v19 = (_DWORD *)v47; /*0x10e803*/
        goto LABEL_179; /*0x10e806*/
      }
      if ( a2 > -2147060719 ) /*0x10e150*/
      {
        if ( a2 == -2146929561 ) /*0x10e182*/
        {
          if ( bcmp(&a1[1]._r, a3, 8u) ) /*0x10e9b2*/
          {
            a1[1]._r = *a3; /*0x10e9c7*/
            a1[1]._w = a3[1]; /*0x10e9cd*/
            gsignal((_DWORD *)SLOWORD(a1->_lb._base), (char *)0x1C); /*0x10e9d7*/
          }
          return 0; /*0x10e9dc*/
        }
        if ( a2 > -2146929561 ) /*0x10e188*/
        {
          if ( a2 > -2145094634 || a2 < -2145094636 ) /*0x10e1ae*/
            return -1; /*0x10e1ae*/
          v41 = spltty(); /*0x10ea53*/
          if ( !*((_BYTE *)a3 + 33) ) /*0x10ea56*/
            *((_BYTE *)a3 + 33) = *((_BYTE *)a3 + 34); /*0x10ea61*/
          if ( (unsigned int)(a2 + 2145094635) <= 1 ) /*0x10ea6d*/
          {
            v36 = (FILE *)spltty(); /*0x10ea78*/
            while ( (a1->_lbfsize || (*(_DWORD *)a1->_ubuf & 0x2000020) != 0) /*0x10ea94*/
                 && ((a1->_ubuf[0] & 0x10) != 0 || *(__int16 *)(ttynty(a1) + 16) < 0) )
            {
              ((void (__cdecl *)(FILE *))a1->_read)(a1); /*0x10ea9a*/
              a1->_ubuf[0] |= 0x40u; /*0x10ea9c*/
              sleep((unsigned int)&a1->_lbfsize); /*0x10eaa6*/
            }
            splx(v36); /*0x10eac1*/
            if ( a2 == -2145094634 ) /*0x10eacf*/
            {
              v37 = spltty(); /*0x10ead6*/
              while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10eaee*/
                ; /*0x10eae0*/
              wakeup((int)a1); /*0x10eaf1*/
              while ( getc(a1) >= 0 ) /*0x10eb07*/
                ; /*0x10eafc*/
              HIBYTE(a1->_lb._size) = 0; /*0x10eb09*/
              LOBYTE(a1->_blksize) = 0; /*0x10eb0d*/
              *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10eb11*/
              splx(v37); /*0x10eb1c*/
            }
          }
          v27 = a3[2]; /*0x10eb27*/
          if ( (v27 & 1) == 0 ) /*0x10eb2c*/
          {
            v28 = *(_DWORD *)a1->_ubuf; /*0x10eb2e*/
            if ( (v28 & 0x10) == 0 && *(__int16 *)(v47 + 16) < 0 && (v27 & 0x8000u) == 0 ) /*0x10eb43*/
            {
              LOBYTE(v28) = v28 & 0xF9 | 2; /*0x10eb48*/
              *(_DWORD *)a1->_ubuf = v28; /*0x10eb4b*/
              ttwakeup(a1); /*0x10eb4f*/
            }
          }
          ur = a1->_ur; /*0x10eb57*/
          v30 = ((unsigned int)a3[3] >> 5) & 1; /*0x10eb6e*/
          if ( a2 != -2145094634 && v30 != ((ur & 0x22) == 0) ) /*0x10eb7e*/
          {
            if ( v30 ) /*0x10eb82*/
            {
              a1->_ur = ur | 0x20000000; /*0x10eb89*/
              ttwakeup(a1); /*0x10eb8d*/
            }
            else
            {
              catq(a1, &a1->_flags); /*0x10eb9d*/
              p = a1->_p; /*0x10eba4*/
              v51 = *(__sbuf *)&a1->_r; /*0x10ebaa*/
              a1->_p = *(unsigned __int8 **)&a1->_flags; /*0x10ebb6*/
              *(__sbuf *)&a1->_r = a1->_bf; /*0x10ebbb*/
              *(_DWORD *)&a1->_flags = p; /*0x10ebc7*/
              a1->_bf = v51; /*0x10ebcd*/
            }
          }
          if ( !v30 && (*(_DWORD *)(v47 + 20) & 0xFFFF00) != (a3[6] & 0xFFFF00) ) /*0x10ebf9*/
            ttwakeup(a1); /*0x10ebfc*/
          ttsettermios(v47, a3); /*0x10ec0c*/
          ttysetspec((_DWORD *)v47); /*0x10ec15*/
          goto LABEL_237; /*0x10ec15*/
        }
        if ( a2 != -2147060619 ) /*0x10e190*/
          return -1; /*0x10e190*/
        bcopy(a3, (char *)&a1->_offset + 5, 6u); /*0x10e816*/
        v19 = (_DWORD *)v47; /*0x10e81b*/
        goto LABEL_179; /*0x10e81e*/
      }
      if ( a2 != -2147191681 ) /*0x10e158*/
      {
        if ( a2 > -2147060726 || a2 < -2147060727 ) /*0x10e170*/
          return -1; /*0x10e170*/
        BYTE1(a1->_blksize) = *((_BYTE *)a3 + 2); /*0x10e5a6*/
        BYTE2(a1->_blksize) = *((_BYTE *)a3 + 3); /*0x10e5af*/
        BYTE1(a1->_lb._size) = *(_BYTE *)a3; /*0x10e5b7*/
        BYTE2(a1->_lb._size) = *((_BYTE *)a3 + 1); /*0x10e5c0*/
        v34 = a1->_ur & 0xFFFF0000 | *((unsigned __int16 *)a3 + 2); /*0x10e5d5*/
        v41 = spltty(); /*0x10e5dd*/
        v15 = a1->_ur; /*0x10e5e0*/
        if ( (v15 & 0x20) != 0 || (v34 & 0x20) != 0 || a2 == -2147060727 ) /*0x10e5f8*/
        {
          v16 = spltty(); /*0x10e603*/
          while ( (a1->_lbfsize || (*(_DWORD *)a1->_ubuf & 0x2000020) != 0) /*0x10e61c*/
               && ((a1->_ubuf[0] & 0x10) != 0 || *(__int16 *)(ttynty(a1) + 16) < 0) )
          {
            ((void (__cdecl *)(FILE *))a1->_read)(a1); /*0x10e622*/
            a1->_ubuf[0] |= 0x40u; /*0x10e624*/
            sleep((unsigned int)&a1->_lbfsize); /*0x10e62e*/
          }
          splx(v16); /*0x10e646*/
          v39 = spltty(); /*0x10e653*/
          while ( getc((FILE *)&a1->_flags) >= 0 ) /*0x10e667*/
            ; /*0x10e65c*/
          wakeup((int)a1); /*0x10e66a*/
          while ( getc(a1) >= 0 ) /*0x10e67f*/
            ; /*0x10e674*/
          HIBYTE(a1->_lb._size) = 0; /*0x10e681*/
          LOBYTE(a1->_blksize) = 0; /*0x10e685*/
          *(_DWORD *)a1->_ubuf &= 0xFF40FFFF; /*0x10e689*/
          splx(v39); /*0x10e694*/
        }
        else if ( (a1->_ur & 2) != (v34 & 2) ) /*0x10e6a9*/
        {
          if ( (v34 & 2) != 0 ) /*0x10e6ad*/
          {
            catq(a1, &a1->_flags); /*0x10e6b4*/
            v48 = a1->_p; /*0x10e6bb*/
            v50 = *(__sbuf *)&a1->_r; /*0x10e6c1*/
            a1->_p = *(unsigned __int8 **)&a1->_flags; /*0x10e6cd*/
            *(__sbuf *)&a1->_r = a1->_bf; /*0x10e6d2*/
            *(_DWORD *)&a1->_flags = v48; /*0x10e6de*/
            a1->_bf = v50; /*0x10e6e4*/
          }
          else
          {
            a1->_ur = v15 | 0x20000000; /*0x10e6f9*/
            v34 |= 0x20000000u; /*0x10e6fc*/
            ttwakeup(a1); /*0x10e704*/
          }
        }
        a1->_ur = v34; /*0x10e70f*/
        *(_DWORD *)(v47 + 16) = 472193564; /*0x10e715*/
        *(_BYTE *)(v47 + 20) = 92; /*0x10e71c*/
        *(_BYTE *)(v47 + 21) = 1; /*0x10e720*/
        *(_BYTE *)(v47 + 22) = 0; /*0x10e724*/
        ttysetspec((_DWORD *)v47); /*0x10e729*/
        if ( (a1->_ur & 0x20) != 0 ) /*0x10e735*/
        {
          *(_DWORD *)a1->_ubuf &= ~0x100u; /*0x10e73b*/
          v17 = spltty(); /*0x10e747*/
          if ( (*(_DWORD *)a1->_ubuf & 0x4000121) == 0 ) /*0x10e750*/
          {
            read = a1->_read; /*0x10e752*/
            if ( read ) /*0x10e757*/
              ((void (__cdecl *)(FILE *))read)(a1); /*0x10e75a*/
          }
          splx(v17); /*0x10e760*/
        }
        goto LABEL_237; /*0x10e768*/
      }
      a1->_ur |= *a3 << 16; /*0x10e83c*/
    }
    *(_DWORD *)(v47 + 16) = 472193564; /*0x10e854*/
    *(_BYTE *)(v47 + 20) = 92; /*0x10e85b*/
    *(_BYTE *)(v47 + 21) = 1; /*0x10e85f*/
    *(_BYTE *)(v47 + 22) = 0; /*0x10e863*/
    ttysetspec((_DWORD *)v47); /*0x10e868*/
    return 0; /*0x10e86d*/
  }
  if ( a2 == 1074033760 ) /*0x10e1c2*/
  {
    ur_high = *(_DWORD *)a1->_ubuf; /*0x10e2d4*/
    goto LABEL_181; /*0x10e2d7*/
  }
  if ( a2 > 1074033760 ) /*0x10e1c8*/
  {
    if ( a2 == 1074164744 ) /*0x10e256*/
    {
      *(_BYTE *)a3 = BYTE1(a1->_lb._size); /*0x10e776*/
      *((_BYTE *)a3 + 1) = BYTE2(a1->_lb._size); /*0x10e77b*/
      *((_BYTE *)a3 + 2) = BYTE1(a1->_blksize); /*0x10e781*/
      *((_BYTE *)a3 + 3) = BYTE2(a1->_blksize); /*0x10e787*/
      *((_WORD *)a3 + 2) = a1->_ur; /*0x10e78e*/
      return 0; /*0x10e792*/
    }
    if ( a2 > 1074164744 ) /*0x10e25c*/
    {
      if ( a2 == 1074164852 ) /*0x10e29a*/
      {
        bcopy((char *)&a1->_offset + 5, a3, 6u); /*0x10e82a*/
      }
      else if ( a2 > 1074164852 ) /*0x10e2a0*/
      {
        if ( a2 == 1074295912 ) /*0x10e2ba*/
        {
          *a3 = a1[1]._r; /*0x10e9ea*/
          a3[1] = a1[1]._w; /*0x10e9ef*/
        }
        else
        {
          if ( a2 != 1076130835 ) /*0x10e2c6*/
            return -1; /*0x10e2c6*/
          ttgettermios(v47, a3); /*0x10ea3c*/
        }
      }
      else
      {
        if ( a2 != 1074164754 ) /*0x10e2a8*/
          return -1; /*0x10e2a8*/
        bcopy((char *)&a1->_blksize + 3, a3, 6u); /*0x10e7f1*/
      }
      return 0; /*0x10e7f1*/
    }
    if ( a2 == 1074033783 ) /*0x10e264*/
    {
      v25 = *(_DWORD *)active_u; /*0x10e962*/
      if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x10e968*/
      {
        v26 = *(_DWORD *)(get_posix_proc(*(__int16 *)(v25 + 48))[4] + 8); /*0x10e977*/
        if ( *(_DWORD *)(v47 + 8) != v26 || (*(_BYTE *)(v25 + 43) & 0x40) == 0 || !*(_DWORD *)(v26 + 8) ) /*0x10e988*/
          return 25; /*0x10e98c*/
      }
      base_low = SLOWORD(a1->_lb._base); /*0x10e998*/
      goto LABEL_200; /*0x10e998*/
    }
    if ( a2 <= 1074033783 ) /*0x10e26a*/
    {
      if ( a2 != 1074033779 ) /*0x10e272*/
        return -1; /*0x10e272*/
      base_low = a1->_lbfsize; /*0x10e4b0*/
      goto LABEL_200; /*0x10e4b3*/
    }
    if ( a2 != 1074033788 ) /*0x10e286*/
      return -1; /*0x10e286*/
    ur_high = HIWORD(a1->_ur); /*0x10e8ac*/
LABEL_181:
    *a3 = ur_high; /*0x10e8b0*/
    return 0; /*0x10e8b5*/
  }
  if ( a2 == 536900712 ) /*0x10e1d4*/
  {
    if ( a1 != &cons ) /*0x10e9fe*/
      (*(&funcs_10EA24 + 11 * *(unsigned __int8 *)(cons_tp + 57)))(*(__int16 *)(cons_tp + 56), 536898312, 0, 0); /*0x10ea24*/
    cons_tp = (int)a1; /*0x10ea26*/
    return 0; /*0x10ea2c*/
  }
  if ( a2 > 536900712 ) /*0x10e1da*/
  {
    if ( a2 == 536900719 ) /*0x10e216*/
    {
      v41 = spltty(); /*0x10e4bd*/
      v11 = *(_DWORD *)a1->_ubuf; /*0x10e4c0*/
      if ( (v11 & 0x100) == 0 ) /*0x10e4c6*/
      {
        BYTE1(v11) |= 1u; /*0x10e4cc*/
        *(_DWORD *)a1->_ubuf = v11; /*0x10e4cf*/
        ((void (__cdecl *)(FILE *, _DWORD))funcs_10DE95[11 * BYTE1(a1->_extra)])(a1, 0); /*0x10e4e6*/
      }
      goto LABEL_237; /*0x10e4eb*/
    }
    if ( a2 <= 536900719 ) /*0x10e21c*/
    {
      if ( a2 != 536900718 ) /*0x10e224*/
        return -1; /*0x10e224*/
      v42 = spltty(); /*0x10e4f5*/
      v12 = *(_DWORD *)a1->_ubuf; /*0x10e4f8*/
      if ( (v12 & 0x100) != 0 || (a1->_ur & 0x800000) != 0 ) /*0x10e504*/
      {
        BYTE1(v12) &= ~1u; /*0x10e506*/
        *(_DWORD *)a1->_ubuf = v12; /*0x10e509*/
        a1->_ur &= ~0x800000u; /*0x10e50c*/
        v13 = spltty(); /*0x10e518*/
        if ( (*(_DWORD *)a1->_ubuf & 0x4000121) == 0 ) /*0x10e521*/
        {
          v14 = a1->_read; /*0x10e523*/
          if ( v14 ) /*0x10e528*/
            ((void (__cdecl *)(FILE *))v14)(a1); /*0x10e52b*/
        }
        splx(v13); /*0x10e531*/
      }
      goto LABEL_134; /*0x10e531*/
    }
    if ( a2 == 1074030207 ) /*0x10e236*/
    {
      v44 = spltty(); /*0x10e499*/
      *a3 = ttnread(v47); /*0x10e4a8*/
      splx(v44); /*0x10e4aa*/
      return 0; /*0x10e4aa*/
    }
    if ( a2 != 1074033664 ) /*0x10e242*/
      return -1; /*0x10e242*/
    base_low = SHIBYTE(a1->_lb._base); /*0x10e2dc*/
LABEL_200:
    *a3 = base_low; /*0x10e99c*/
    return 0; /*0x10e9a1*/
  }
  if ( a2 == 536900622 ) /*0x10e1e2*/
  {
    v43 = spltty(); /*0x10e3b1*/
    *(_DWORD *)a1->_ubuf &= ~0x80u; /*0x10e3b4*/
    splx(v43); /*0x10e3bb*/
  }
  else
  {
    if ( a2 <= 536900622 ) /*0x10e1e8*/
    {
      if ( a2 != 536900621 ) /*0x10e1f0*/
        return -1; /*0x10e1f0*/
      v42 = spltty(); /*0x10e39d*/
      a1->_ubuf[0] |= 0x80u; /*0x10e3a0*/
      goto LABEL_134; /*0x10e3a4*/
    }
    if ( a2 != 536900702 ) /*0x10e202*/
      return -1; /*0x10e202*/
    v31 = spltty(); /*0x10ec2d*/
    while ( (a1->_lbfsize || (*(_DWORD *)a1->_ubuf & 0x2000020) != 0) /*0x10ec48*/
         && ((a1->_ubuf[0] & 0x10) != 0 || *(__int16 *)(ttynty(a1) + 16) < 0) )
    {
      ((void (__cdecl *)(FILE *))a1->_read)(a1); /*0x10ec4e*/
      a1->_ubuf[0] |= 0x40u; /*0x10ec50*/
      sleep((unsigned int)&a1->_lbfsize); /*0x10ec5a*/
    }
    splx(v31); /*0x10ec72*/
  }
  return 0; /*0x10ec89*/
}
