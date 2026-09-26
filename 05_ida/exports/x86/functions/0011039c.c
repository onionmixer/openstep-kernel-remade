/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11039c. */
int __cdecl ttread(FILE *a1, _DWORD *a2)
{
  int v2; // edi
  int v3; // eax
  int v5; // eax
  int v6; // ebx
  _DWORD *posix_proc; // edx
  int v8; // edx
  _DWORD *v9; // edi
  __int16 v10; // ax
  int v11; // edi
  int v12; // edx
  int v13; // ebx
  unsigned __int8 *p; // eax
  int v15; // eax
  int i; // edi
  int v17; // eax
  int v18; // ebx
  int v19; // edi
  char v20; // dl
  int v21; // edi
  int v22; // ebx
  int (__cdecl *read)(void *, char *, int); // eax
  unsigned __int8 *v24; // [esp+Ch] [ebp-3Ch]
  int v25; // [esp+10h] [ebp-38h]
  int v26; // [esp+14h] [ebp-34h]
  int ur; // [esp+18h] [ebp-30h]
  FILE *p_flags; // [esp+1Ch] [ebp-2Ch]
  int v29; // [esp+20h] [ebp-28h]
  _DWORD v30[2]; // [esp+24h] [ebp-24h] BYREF
  _DWORD v31[2]; // [esp+2Ch] [ebp-1Ch] BYREF
  int v32; // [esp+34h] [ebp-14h] BYREF
  int v33; // [esp+38h] [ebp-10h]
  _DWORD v34[3]; // [esp+3Ch] [ebp-Ch] BYREF

  v29 = ttynty(a1); /*0x1103ae*/
  v26 = 0; /*0x1103b1*/
LABEL_2:
  v25 = 0; /*0x1103bb*/
  while ( 1 ) /*0x110493*/
  {
    while ( 1 ) /*0x1103c5*/
    {
      ur = a1->_ur; /*0x1103c5*/
      v2 = spltty(); /*0x1103cd*/
      if ( (ur & 0x20000000) != 0 ) /*0x1103d8*/
      {
        a1->_ur &= ~0x20000000u; /*0x1103da*/
        *(_DWORD *)a1->_ubuf |= 0x100000u; /*0x1103e1*/
        v34[0] = a1->_p; /*0x1103ea*/
        v34[1] = a1->_r; /*0x1103f0*/
        v34[2] = a1->_w; /*0x1103f6*/
        a1->_p = nullptr; /*0x1103f9*/
        a1->_w = 0; /*0x1103ff*/
        a1->_r = 0; /*0x110406*/
        while ( 1 ) /*0x110411*/
        {
          v3 = getc((FILE *)v34); /*0x110411*/
          if ( v3 < 0 ) /*0x11041b*/
            break; /*0x11041b*/
          ttyinput(v3, a1); /*0x11041f*/
        }
        *(_DWORD *)a1->_ubuf &= ~0x100000u; /*0x11042c*/
      }
      splx(v2); /*0x110434*/
      while ( 1 ) /*0x110477*/
      {
        v5 = *(_DWORD *)a1->_ubuf; /*0x110477*/
        if ( (v5 & 0x10) != 0 || *(__int16 *)(v29 + 16) < 0 ) /*0x110486*/
          break; /*0x110486*/
        if ( (v5 & 0x8000u) == 0 ) /*0x110443*/
          return 5; /*0x110443*/
        if ( (v5 & 0x2000) != 0 ) /*0x11044c*/
          goto LABEL_11; /*0x11044c*/
        sleep((unsigned int)a1); /*0x11046f*/
      }
      v6 = *(_DWORD *)active_u; /*0x11048d*/
      if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x110493*/
        break; /*0x110493*/
      if ( *(FILE **)(active_u + 360) != a1 ) /*0x1104e2*/
        goto LABEL_32; /*0x1104e2*/
      v10 = *(_WORD *)(v6 + 46); /*0x1104e4*/
      if ( LOWORD(a1->_lb._base) == v10 ) /*0x1104ec*/
        goto LABEL_32; /*0x1104ec*/
      if ( (*(_BYTE *)(v6 + 34) & 0x10) != 0 || (*(_BYTE *)(v6 + 30) & 0x10) != 0 || (*(_BYTE *)(v6 + 41) & 0x10) != 0 ) /*0x1104fe*/
        return 5; /*0x110505*/
      gsignal((_DWORD *)v10, (char *)0x15); /*0x110510*/
LABEL_31:
      sleep((unsigned int)&lbolt); /*0x110515*/
    }
    posix_proc = get_posix_proc(*(__int16 *)(v6 + 48)); /*0x11049f*/
    if ( *(FILE **)(active_u + 360) == a1 ) /*0x1104af*/
    {
      v8 = posix_proc[4]; /*0x1104b1*/
      v9 = *(_DWORD **)(v8 + 12); /*0x1104b8*/
      if ( v9 != (_DWORD *)SLOWORD(a1->_lb._base) ) /*0x1104bd*/
      {
        if ( (*(_BYTE *)(v6 + 34) & 0x10) != 0 /*0x1104d5*/
          || (*(_BYTE *)(v6 + 30) & 0x10) != 0
          || !*(_DWORD *)(v8 + 16)
          || (*(_BYTE *)(v6 + 41) & 0x10) != 0 )
        {
          return 5; /*0x1104d5*/
        }
        gsignal(v9, (char *)0x15); /*0x1104da*/
        goto LABEL_31; /*0x1104da*/
      }
    }
LABEL_32:
    v11 = spltty(); /*0x110531*/
    if ( (ur & 0x22) != 0 ) /*0x110537*/
    {
      v12 = *(unsigned __int8 *)(v29 + 21); /*0x110540*/
      p_flags = a1; /*0x110548*/
      if ( *(_BYTE *)(v29 + 22) ) /*0x110544*/
      {
        v13 = 100000 * *(unsigned __int8 *)(v29 + 22); /*0x11056d*/
        if ( *(_BYTE *)(v29 + 21) ) /*0x110540*/
        {
          p = a1->_p; /*0x110574*/
          if ( (int)a1->_p <= 0 ) /*0x110578*/
            goto LABEL_52; /*0x110578*/
          if ( (int)p >= v12 ) /*0x110580*/
            goto LABEL_62; /*0x110580*/
          if ( v25 ) /*0x11058a*/
          {
            if ( (int)v24 >= (int)p ) /*0x1105a3*/
            {
              getthetime(v31); /*0x1105b4*/
              v13 -= v31[1] - v33 + 1000000 * (v31[0] - v32); /*0x1105db*/
            }
            else
            {
              getthetime(&v32); /*0x1105a9*/
            }
          }
          else
          {
            v25 = 1; /*0x11058c*/
            getthetime(&v32); /*0x110597*/
          }
          v24 = a1->_p; /*0x1105e5*/
        }
        else
        {
          if ( (int)a1->_p > 0 ) /*0x1105ef*/
            goto LABEL_62; /*0x1105ef*/
          if ( v25 ) /*0x1105f9*/
          {
            getthetime(v30); /*0x110614*/
            v13 -= v30[1] - v33 + 1000000 * (v30[0] - v32); /*0x11063b*/
          }
          else
          {
            v25 = 1; /*0x1105fb*/
            getthetime(&v32); /*0x110606*/
          }
        }
        if ( v13 <= 0 ) /*0x110642*/
          goto LABEL_62; /*0x110642*/
        untimeout((int)wakeup, (int)a1); /*0x110669*/
        timeout((int)wakeup); /*0x110678*/
      }
      else if ( (int)a1->_p >= v12 ) /*0x110551*/
      {
        goto LABEL_62; /*0x110551*/
      }
    }
    else
    {
      p_flags = (FILE *)&a1->_flags; /*0x110687*/
      if ( *(int *)&a1->_flags > 0 ) /*0x11068e*/
      {
LABEL_62:
        splx(v11); /*0x1106f8*/
        for ( i = 1; ; i = 0 ) /*0x1106fe*/
        {
          v17 = getc(p_flags); /*0x11070c*/
          v18 = v17; /*0x110711*/
          if ( v17 < 0 ) /*0x110718*/
            break; /*0x110718*/
          if ( (_BYTE)v17 != 0xFF ) /*0x110721*/
          {
            if ( BYTE6(a1->_offset) == (_BYTE)v17 && (ur & 0x20) == 0 && (*(_BYTE *)(v29 + 16) & 8) != 0 ) /*0x110735*/
            {
              gsignal((_DWORD *)SLOWORD(a1->_lb._base), (char *)0x12); /*0x11073e*/
              if ( i ) /*0x110748*/
              {
                sleep((unsigned int)a1); /*0x11074d*/
                goto LABEL_2; /*0x110755*/
              }
              break; /*0x110748*/
            }
            if ( (_BYTE)v17 != 0xFF && BYTE3(a1->_offset) == (_BYTE)v17 && (ur & 0x22) == 0 ) /*0x11076a*/
              break; /*0x11076a*/
          }
          v26 = ureadc(v17, a2); /*0x110776*/
          if ( v26 /*0x1107aa*/
            || !a2[5]
            || (ur & 0x22) == 0 && (v18 == 10 || (v18 == BYTE3(a1->_offset) || v18 == BYTE4(a1->_offset)) && v18 != 255) )
          {
            break; /*0x1107aa*/
          }
        }
        if ( (int)a1->_p <= 203 ) /*0x1107ba*/
        {
          v19 = spltty(); /*0x1107c1*/
          *(_DWORD *)a1->_ubuf &= ~0x800000u; /*0x1107c3*/
          splx(v19); /*0x1107cb*/
          if ( (*(_DWORD *)a1->_ubuf & 0x1000400) == 0x400 ) /*0x1107e0*/
          {
            v20 = BYTE1(a1->_offset); /*0x1107e2*/
            if ( v20 != -1 && !putc(v20, (FILE *)&a1->_lbfsize) ) /*0x1107f2*/
            {
              v21 = spltty(); /*0x110803*/
              *(_DWORD *)a1->_ubuf &= ~0x400u; /*0x110805*/
              splx(v21); /*0x11080d*/
              v22 = spltty(); /*0x11081a*/
              if ( (*(_DWORD *)a1->_ubuf & 0x4000121) == 0 ) /*0x110823*/
              {
                read = a1->_read; /*0x110825*/
                if ( read ) /*0x11082a*/
                  ((void (__cdecl *)(FILE *))read)(a1); /*0x11082d*/
              }
              splx(v22); /*0x110833*/
            }
          }
        }
        return v26; /*0x110838*/
      }
    }
LABEL_52:
    v15 = 0; /*0x110690*/
    if ( (a1->_ubuf[0] & 0x10) != 0 || *(__int16 *)(v29 + 16) < 0 ) /*0x1106a0*/
      v15 = 1; /*0x1106a2*/
    if ( !v15 && (a1->_ubuf[0] & 4) != 0 ) /*0x1106af*/
    {
      splx(v11); /*0x1106b2*/
      return 0; /*0x1106b9*/
    }
    if ( (a1->_ubuf[1] & 0x20) != 0 ) /*0x1106c4*/
      break; /*0x1106c4*/
    sleep((unsigned int)a1); /*0x1106e3*/
    splx(v11); /*0x1106e9*/
  }
  splx(v11); /*0x1106c7*/
LABEL_11:
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x110459*/
    return 11; /*0x1106d4*/
  else
    return 35; /*0x11045f*/
}
