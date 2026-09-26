/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x198098. */
char __cdecl sub_198098(int a1, char a2)
{
  char result; // al
  int v3; // ebx
  unsigned int v4; // ebx
  int kk; // ebx
  int v6; // ebx
  int mm; // ebx
  int v8; // ecx
  int nn; // ebx
  int i1; // ebx
  int i2; // ebx
  int v12; // edx
  int i3; // ebx
  unsigned __int8 v14; // bl
  int v15; // ebx
  int i7; // ebx
  int v17; // ebx
  int i; // ebx
  int v19; // ebx
  _BYTE *v20; // ebx
  int v21; // ebx
  unsigned __int8 v22; // al
  char *v23; // ebx
  unsigned __int8 v24; // al
  int v25; // ebx
  char v26; // bl
  _BYTE *v27; // ebx
  int v28; // [esp+18h] [ebp-60h]
  int v29; // [esp+30h] [ebp-48h]
  int v30; // [esp+30h] [ebp-48h]
  int v31; // [esp+30h] [ebp-48h]
  int v32; // [esp+30h] [ebp-48h]
  int j; // [esp+30h] [ebp-48h]
  int k; // [esp+30h] [ebp-48h]
  int v35; // [esp+30h] [ebp-48h]
  int v36; // [esp+30h] [ebp-48h]
  int i4; // [esp+34h] [ebp-44h]
  int i5; // [esp+34h] [ebp-44h]
  int m; // [esp+34h] [ebp-44h]
  int v40; // [esp+34h] [ebp-44h]
  int n; // [esp+34h] [ebp-44h]
  int ii; // [esp+34h] [ebp-44h]
  int v43; // [esp+38h] [ebp-40h]
  _BYTE *v44; // [esp+38h] [ebp-40h]
  unsigned __int8 v45; // [esp+38h] [ebp-40h]
  int v46; // [esp+38h] [ebp-40h]
  unsigned __int8 v47; // [esp+38h] [ebp-40h]
  int v48; // [esp+38h] [ebp-40h]
  int v49; // [esp+3Ch] [ebp-3Ch]
  _BYTE *v50; // [esp+3Ch] [ebp-3Ch]
  int v51; // [esp+3Ch] [ebp-3Ch]
  _BYTE *v52; // [esp+3Ch] [ebp-3Ch]
  int v53; // [esp+3Ch] [ebp-3Ch]
  _BYTE *v54; // [esp+3Ch] [ebp-3Ch]
  int v55; // [esp+44h] [ebp-34h]
  int v56; // [esp+44h] [ebp-34h]
  int i6; // [esp+44h] [ebp-34h]
  int v58; // [esp+44h] [ebp-34h]
  int v59; // [esp+44h] [ebp-34h]
  int jj; // [esp+44h] [ebp-34h]
  unsigned __int8 v61; // [esp+4Ch] [ebp-2Ch]
  unsigned __int8 v62; // [esp+50h] [ebp-28h]
  unsigned int v63; // [esp+54h] [ebp-24h]
  int v64; // [esp+58h] [ebp-20h]
  char *v65; // [esp+5Ch] [ebp-1Ch]
  unsigned __int8 v66; // [esp+60h] [ebp-18h]
  unsigned __int8 v67; // [esp+64h] [ebp-14h]
  int v68; // [esp+68h] [ebp-10h]
  unsigned __int8 v69; // [esp+6Ch] [ebp-Ch]
  unsigned __int8 v70; // [esp+70h] [ebp-8h]

  result = a2; /*0x1980a1*/
  v29 = 0; /*0x1980a7*/
  if ( *(_DWORD *)a1 == 1 || *(_DWORD *)a1 == 3 ) /*0x1980bb*/
    v29 = 1; /*0x1980bd*/
  if ( v29 ) /*0x1980c8*/
  {
    v3 = *(_DWORD *)(a1 + 244); /*0x1980d1*/
    switch ( v3 ) /*0x1980da*/
    {
      case 1: /*0x1980da*/
        if ( a2 == 91 ) /*0x198108*/
        {
          *(_DWORD *)(a1 + 244) = 2; /*0x19810d*/
          return result; /*0x198117*/
        }
        result = a1; /*0x19811c*/
        *(_DWORD *)(a1 + 244) = 0; /*0x19811f*/
        break;
      case 0: /*0x1980da*/
        if ( a2 == 27 ) /*0x1980ec*/
        {
          *(_DWORD *)(a1 + 244) = 1; /*0x1980f5*/
          return result; /*0x1980ff*/
        }
LABEL_58:
        sub_197CA0(a1); /*0x198594*/
        if ( a2 == 10 ) /*0x1985a4*/
        {
          *(_DWORD *)(a1 + 168) = 0; /*0x1985fb*/
          ++*(_DWORD *)(a1 + 164); /*0x198605*/
        }
        else
        {
          if ( a2 <= 10 ) /*0x1985a6*/
          {
            if ( a2 == 8 ) /*0x1985ac*/
            {
              v17 = *(_DWORD *)(a1 + 168); /*0x198613*/
              if ( v17 ) /*0x19861b*/
                *(_DWORD *)(a1 + 168) = v17 - 1; /*0x198622*/
              goto LABEL_87; /*0x198628*/
            }
            if ( a2 == 9 ) /*0x1985b2*/
            {
              v31 = 8 - *(_DWORD *)(a1 + 168) % 8; /*0x198658*/
              sub_197CA0(a1); /*0x19865f*/
              for ( i = 0; v31 > i; ++i ) /*0x19866b*/
                sub_198098(a1, 32); /*0x198676*/
              sub_197CA0(a1); /*0x198688*/
              goto LABEL_87; /*0x198690*/
            }
            goto LABEL_86; /*0x1985b2*/
          }
          if ( a2 == 13 ) /*0x1985c0*/
          {
            *(_DWORD *)(a1 + 168) = 0; /*0x1985e7*/
          }
          else
          {
            if ( a2 <= 13 ) /*0x1985c2*/
            {
              if ( a2 == 12 ) /*0x1985c8*/
              {
                *(_DWORD *)(a1 + 168) = 0; /*0x19869b*/
                *(_DWORD *)(a1 + 164) = 0; /*0x1986a5*/
                v28 = *(_DWORD *)(a1 + 140); /*0x1986b5*/
                v19 = *(_DWORD *)(a1 + 144); /*0x1986b8*/
                v32 = *(_DWORD *)(a1 + 160); /*0x1986c4*/
                v51 = *(_DWORD *)(a1 + 152) + v28; /*0x1986cd*/
                v68 = *(_DWORD *)(a1 + 16); /*0x1986d3*/
                v45 = *(_BYTE *)(a1 + 176); /*0x1986dc*/
                __outbyte(0x3CEu, 0); /*0x1986e6*/
                _InterlockedIncrement(&dword_1E8654); /*0x1986e7*/
                __outbyte(0x3CFu, v45); /*0x1986f6*/
                _InterlockedIncrement(&dword_1E8654); /*0x1986f7*/
                __outbyte(0x3CEu, 8u); /*0x198705*/
                _InterlockedIncrement(&dword_1E8654); /*0x198706*/
                v67 = byte_1E4685[v28 & 7]; /*0x198725*/
                v66 = byte_1E468D[v51 & 7]; /*0x198734*/
                v20 = (_BYTE *)((v28 >> 3) + *(_DWORD *)(a1 + 24) + v68 * v19); /*0x198741*/
                v46 = (v51 >> 3) - (v28 >> 3) - 1; /*0x198748*/
                if ( v51 >> 3 == v28 >> 3 ) /*0x19874e*/
                {
                  __outbyte(0x3CFu, v67 & byte_1E468D[v51 & 7]); /*0x19875a*/
                  _InterlockedIncrement(&dword_1E8654); /*0x19875b*/
                  for ( j = v32 - 1; j >= 0; --j ) /*0x198765*/
                  {
                    *v20 = -1; /*0x198771*/
                    v20 += v68; /*0x198774*/
                  }
                }
                else
                {
                  for ( k = v32 - 1; k >= 0; --k ) /*0x198783*/
                  {
                    __outbyte(0x3CFu, v67); /*0x198795*/
                    _InterlockedIncrement(&dword_1E8654); /*0x198796*/
                    *v20 = -1; /*0x19879d*/
                    v52 = v20 + 1; /*0x1987a3*/
                    __outbyte(0x3CFu, 0xFFu); /*0x1987a8*/
                    _InterlockedIncrement(&dword_1E8654); /*0x1987a9*/
                    for ( m = v46 - 1; m >= 0; --m ) /*0x1987b7*/
                      *v52++ = -1; /*0x1987bf*/
                    __outbyte(0x3CFu, v66); /*0x1987d3*/
                    _InterlockedIncrement(&dword_1E8654); /*0x1987d4*/
                    *v52 = -1; /*0x1987e6*/
                    v20 += v68; /*0x1987e9*/
                  }
                }
                __outbyte(0x3CFu, 0xFFu); /*0x1987f8*/
                _InterlockedIncrement(&dword_1E8654); /*0x1987f9*/
                goto LABEL_87; /*0x198800*/
              }
              goto LABEL_86; /*0x1985c8*/
            }
            if ( a2 != 127 ) /*0x1985d8*/
            {
LABEL_86:
              sub_197E58(a1, a2); /*0x198810*/
              goto LABEL_87; /*0x198819*/
            }
            ++*(_DWORD *)(a1 + 168); /*0x198807*/
          }
        }
LABEL_87:
        if ( *(_DWORD *)(a1 + 168) >= *(_DWORD *)(a1 + 148) ) /*0x198833*/
        {
          *(_DWORD *)(a1 + 168) = 0; /*0x198835*/
          ++*(_DWORD *)(a1 + 164); /*0x19883f*/
        }
        v21 = *(_DWORD *)(a1 + 156); /*0x198848*/
        if ( *(_DWORD *)(a1 + 164) >= v21 ) /*0x198854*/
        {
          *(_DWORD *)(a1 + 164) = v21 - 1; /*0x19885b*/
          __outbyte(0x3CEu, 5u); /*0x198868*/
          _InterlockedIncrement(&dword_1E8654); /*0x198869*/
          v22 = __inbyte(0x3CFu); /*0x198875*/
          __outbyte(0x3CEu, 5u); /*0x198885*/
          _InterlockedIncrement(&dword_1E8654); /*0x198886*/
          __outbyte(0x3CFu, v22 & 0xFC | 1); /*0x198894*/
          _InterlockedIncrement(&dword_1E8654); /*0x198895*/
          v35 = *(_DWORD *)(a1 + 16); /*0x1988ab*/
          v23 = (char *)((*(int *)(a1 + 140) >> 3) + *(_DWORD *)(a1 + 24) + v35 * (*(_DWORD *)(a1 + 144) + 12)); /*0x1988c2*/
          v65 = &v23[-12 * v35]; /*0x1988d2*/
          v58 = 12; /*0x1988d5*/
          v64 = *(_DWORD *)(a1 + 160); /*0x1988e2*/
          if ( v64 > 12 ) /*0x1988e8*/
          {
            v63 = *(int *)(a1 + 152) >> 3; /*0x1988f6*/
            do /*0x19891c*/
            {
              qmemcpy(v65, v23, v63); /*0x198908*/
              v23 += v35; /*0x19890a*/
              v65 += v35; /*0x198910*/
              ++v58; /*0x198913*/
            }
            while ( v58 < v64 ); /*0x19891c*/
          }
          __outbyte(0x3CEu, 5u); /*0x198925*/
          _InterlockedIncrement(&dword_1E8654); /*0x198926*/
          v24 = __inbyte(0x3CFu); /*0x198932*/
          __outbyte(0x3CEu, 5u); /*0x19893f*/
          _InterlockedIncrement(&dword_1E8654); /*0x198940*/
          __outbyte(0x3CFu, v24 & 0xFC); /*0x19894e*/
          _InterlockedIncrement(&dword_1E8654); /*0x19894f*/
          *(_DWORD *)(a1 + 168) = 0; /*0x198959*/
          v25 = *(_DWORD *)(a1 + 140); /*0x198963*/
          v53 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x19897e*/
          v59 = *(_DWORD *)(a1 + 152) + v25; /*0x198989*/
          v36 = *(_DWORD *)(a1 + 16); /*0x19898f*/
          v47 = *(_BYTE *)(a1 + 176); /*0x198998*/
          __outbyte(0x3CEu, 0); /*0x1989a2*/
          _InterlockedIncrement(&dword_1E8654); /*0x1989a3*/
          __outbyte(0x3CFu, v47); /*0x1989b2*/
          _InterlockedIncrement(&dword_1E8654); /*0x1989b3*/
          __outbyte(0x3CEu, 8u); /*0x1989c1*/
          _InterlockedIncrement(&dword_1E8654); /*0x1989c2*/
          v40 = v25 >> 3; /*0x1989ce*/
          v26 = byte_1E4685[v25 & 7]; /*0x1989da*/
          v62 = v26; /*0x1989e0*/
          v61 = byte_1E468D[v59 & 7]; /*0x1989ef*/
          v54 = (_BYTE *)(v40 + *(_DWORD *)(a1 + 24) + v36 * v53); /*0x198a01*/
          v48 = (v59 >> 3) - v40 - 1; /*0x198a0b*/
          if ( v59 >> 3 == v40 ) /*0x198a11*/
          {
            __outbyte(0x3CFu, v26 & v61); /*0x198a1d*/
            _InterlockedIncrement(&dword_1E8654); /*0x198a1e*/
            for ( n = 11; n >= 0; --n ) /*0x198a25*/
            {
              *v54 = -1; /*0x198a37*/
              v54 += v36; /*0x198a3f*/
            }
          }
          else
          {
            for ( ii = 11; ii >= 0; --ii ) /*0x198a4c*/
            {
              __outbyte(0x3CFu, v62); /*0x198a64*/
              _InterlockedIncrement(&dword_1E8654); /*0x198a65*/
              *v54 = -1; /*0x198a6f*/
              v27 = v54 + 1; /*0x198a75*/
              __outbyte(0x3CFu, 0xFFu); /*0x198a78*/
              _InterlockedIncrement(&dword_1E8654); /*0x198a79*/
              for ( jj = v48 - 1; jj >= 0; --jj ) /*0x198a87*/
                *v27++ = -1; /*0x198a8c*/
              __outbyte(0x3CFu, v61); /*0x198a9d*/
              _InterlockedIncrement(&dword_1E8654); /*0x198a9e*/
              *v27 = -1; /*0x198aaa*/
              v54 += v36; /*0x198ab0*/
            }
          }
          __outbyte(0x3CFu, 0xFFu); /*0x198abf*/
          _InterlockedIncrement(&dword_1E8654); /*0x198ac0*/
        }
        return sub_197CA0(a1); /*0x198acb*/
      case 2: /*0x1980da*/
        break;
      default:
        goto LABEL_58; /*0x1980e1*/
    }
    if ( (unsigned __int8)(a2 - 48) <= 9u ) /*0x198132*/
    {
      **(_BYTE **)(a1 + 252) = 10 * **(_BYTE **)(a1 + 252) + a2 - 48; /*0x19814b*/
      return result; /*0x19814d*/
    }
    if ( a2 != 59 ) /*0x198158*/
    {
      for ( kk = 0; kk <= 2; ++kk ) /*0x198180*/
      {
        if ( !*(_BYTE *)(kk + a1 + 248) ) /*0x198187*/
          *(_BYTE *)(kk + a1 + 248) = 1; /*0x198191*/
      }
      v6 = **(unsigned __int8 **)(a1 + 252); /*0x1981a8*/
      sub_197CA0(a1); /*0x1981af*/
      switch ( a2 ) /*0x1981cb*/
      {
        case 'A': /*0x1981cb*/
          for ( mm = v6 - 1; mm != -1; --mm ) /*0x19828c*/
          {
            v8 = *(_DWORD *)(a1 + 164); /*0x198297*/
            if ( v8 ) /*0x1982a2*/
              *(_DWORD *)(a1 + 164) = v8 - 1; /*0x1982a8*/
          }
          break; /*0x1982b2*/
        case 'B': /*0x1981cb*/
          for ( nn = v6 - 1; nn != -1; --nn ) /*0x1982c0*/
            ++*(_DWORD *)(a1 + 164); /*0x1982cb*/
          break; /*0x1982d5*/
        case 'C': /*0x1981cb*/
          for ( i1 = v6 - 1; i1 != -1; --i1 ) /*0x1982e0*/
            ++*(_DWORD *)(a1 + 168); /*0x1982eb*/
          break; /*0x1982f5*/
        case 'D': /*0x1981cb*/
          for ( i2 = v6 - 1; i2 != -1; --i2 ) /*0x198300*/
          {
            v12 = *(_DWORD *)(a1 + 168); /*0x19830b*/
            if ( v12 ) /*0x198316*/
              *(_DWORD *)(a1 + 168) = v12 - 1; /*0x19831c*/
          }
          break; /*0x198326*/
        case 'E': /*0x1981cb*/
          *(_DWORD *)(a1 + 168) = 0; /*0x198333*/
          for ( i3 = v6 - 1; i3 != -1; --i3 ) /*0x198341*/
            ++*(_DWORD *)(a1 + 164); /*0x19834b*/
          break; /*0x198355*/
        case 'H': /*0x1981cb*/
        case 'f': /*0x1981cb*/
          *(_DWORD *)(a1 + 168) = **(unsigned __int8 **)(a1 + 252) - 1; /*0x19836c*/
          v55 = *(_DWORD *)(a1 + 252); /*0x198378*/
          *(_DWORD *)(a1 + 252) = v55 - 1; /*0x19837c*/
          *(_DWORD *)(a1 + 164) = *(unsigned __int8 *)(v55 - 1) - 1; /*0x19838a*/
          --*(_DWORD *)(a1 + 252); /*0x198390*/
          break; /*0x198396*/
        case 'K': /*0x1981cb*/
          v43 = *(_DWORD *)(a1 + 144) + 12 * *(_DWORD *)(a1 + 164); /*0x1983c6*/
          v56 = *(_DWORD *)(a1 + 140) + 8 * *(_DWORD *)(a1 + 168); /*0x1983d2*/
          v49 = *(_DWORD *)(a1 + 140) + *(_DWORD *)(a1 + 152); /*0x1983e4*/
          v30 = *(_DWORD *)(a1 + 16); /*0x1983ea*/
          v14 = *(_BYTE *)(a1 + 176); /*0x1983ed*/
          __outbyte(0x3CEu, 0); /*0x1983fa*/
          _InterlockedIncrement(&dword_1E8654); /*0x1983fb*/
          __outbyte(0x3CFu, v14); /*0x198409*/
          _InterlockedIncrement(&dword_1E8654); /*0x19840a*/
          __outbyte(0x3CEu, 8u); /*0x198418*/
          _InterlockedIncrement(&dword_1E8654); /*0x198419*/
          v70 = byte_1E4685[v56 & 7]; /*0x19843b*/
          v69 = byte_1E468D[v49 & 7]; /*0x19844a*/
          v44 = (_BYTE *)((v56 >> 3) + *(_DWORD *)(a1 + 24) + v30 * v43); /*0x19845c*/
          v15 = (v49 >> 3) - (v56 >> 3) - 1; /*0x198462*/
          if ( v49 >> 3 == v56 >> 3 ) /*0x198466*/
          {
            __outbyte(0x3CFu, v70 & byte_1E468D[v49 & 7]); /*0x198472*/
            _InterlockedIncrement(&dword_1E8654); /*0x198473*/
            for ( i4 = 11; i4 >= 0; --i4 ) /*0x19847a*/
            {
              *v44 = -1; /*0x19848f*/
              v44 += v30; /*0x198497*/
            }
          }
          else
          {
            for ( i5 = 11; i5 >= 0; --i5 ) /*0x1984a4*/
            {
              __outbyte(0x3CFu, v70); /*0x1984bc*/
              _InterlockedIncrement(&dword_1E8654); /*0x1984bd*/
              *v44 = -1; /*0x1984c7*/
              v50 = v44 + 1; /*0x1984cb*/
              __outbyte(0x3CFu, 0xFFu); /*0x1984d0*/
              _InterlockedIncrement(&dword_1E8654); /*0x1984d1*/
              for ( i6 = v15 - 1; i6 >= 0; --i6 ) /*0x1984e0*/
                *v50++ = -1; /*0x1984e7*/
              __outbyte(0x3CFu, v69); /*0x1984fb*/
              _InterlockedIncrement(&dword_1E8654); /*0x1984fc*/
              *v50 = -1; /*0x19850e*/
              v44 += v30; /*0x198514*/
            }
          }
          __outbyte(0x3CFu, 0xFFu); /*0x198523*/
          _InterlockedIncrement(&dword_1E8654); /*0x198524*/
          break; /*0x19852b*/
        case 'm': /*0x1981cb*/
          *(_DWORD *)(a1 + 252) -= 2; /*0x198533*/
          if ( *(_DWORD *)(a1 + 176) == *(_DWORD *)(a1 + 180) ) /*0x198546*/
          {
            *(_DWORD *)(a1 + 176) = 3; /*0x198548*/
            *(_DWORD *)(a1 + 180) = 0; /*0x198552*/
          }
          break; /*0x198552*/
        default:
          break;
      }
      *(_DWORD *)(a1 + 252) = a1 + 249; /*0x19855c*/
      for ( i7 = 2; i7 >= 0; --i7 ) /*0x19856d*/
        *(_BYTE *)(i7 + a1 + 248) = 0; /*0x198577*/
      *(_DWORD *)(a1 + 244) = 0; /*0x198582*/
      goto LABEL_87; /*0x19858c*/
    }
    result = a1; /*0x198163*/
    v4 = *(_DWORD *)(a1 + 252); /*0x198166*/
    if ( v4 < a1 + 250 ) /*0x19816e*/
      *(_DWORD *)(a1 + 252) = v4 + 1; /*0x198175*/
  }
  return result; /*0x198ad3*/
}
