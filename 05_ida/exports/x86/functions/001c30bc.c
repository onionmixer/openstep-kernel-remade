/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c30bc. */
id __cdecl -[IOFrameBufferDisplay moveCursor:frame:token:](
        IOFrameBufferDisplay *self,
        SEL a2,
        $9B414A52084CF78D000E95AF47DF0AD5 *a3,
        int a4,
        int a5)
{
  char v6; // cl
  unsigned int v7; // edx
  $514E7C50D28E54AB164B6500F83867A3 *v8; // eax
  __int16 *v9; // edi
  int v10; // ebx
  _WORD *v11; // ecx
  int v12; // ebx
  _WORD *v13; // edi
  __int16 v14; // dx
  __int16 v15; // ax
  $514E7C50D28E54AB164B6500F83867A3 *v16; // eax
  __int16 *v17; // edi
  int v18; // esi
  _BYTE *v19; // eax
  _BYTE *v20; // edi
  __int16 v21; // dx
  __int16 v22; // cx
  $514E7C50D28E54AB164B6500F83867A3 *v23; // edi
  _DWORD *v24; // eax
  _DWORD *v25; // ecx
  int v26; // edi
  _DWORD *v27; // eax
  int v28; // edx
  _DWORD *v29; // ebx
  int v30; // edx
  int v31; // ecx
  int v32; // edi
  _BYTE *v33; // edx
  char v34; // al
  unsigned int v35; // edx
  $514E7C50D28E54AB164B6500F83867A3 *v36; // eax
  __int16 *v37; // edi
  int v38; // ebx
  _WORD *v39; // ecx
  int v40; // ebx
  _WORD *v41; // edi
  __int16 v42; // dx
  __int16 v43; // ax
  $514E7C50D28E54AB164B6500F83867A3 *v44; // eax
  __int16 *v45; // edi
  int v46; // esi
  _BYTE *v47; // eax
  _BYTE *v48; // edi
  __int16 v49; // dx
  __int16 v50; // cx
  $514E7C50D28E54AB164B6500F83867A3 *v51; // edi
  _DWORD *v52; // eax
  _DWORD *v53; // ecx
  int v54; // edi
  _DWORD *v55; // eax
  int v56; // edx
  _BYTE *v57; // ecx
  _DWORD *v58; // edi
  int v59; // ecx
  unsigned int v60; // edx
  int v61; // ecx
  _DWORD *v62; // edi
  int v63; // ecx
  unsigned int v64; // edx
  int v65; // ecx
  int v66; // [esp+10h] [ebp-44h]
  int v67; // [esp+10h] [ebp-44h]
  int v68; // [esp+10h] [ebp-44h]
  int v69; // [esp+10h] [ebp-44h]
  int v70; // [esp+10h] [ebp-44h]
  int v71; // [esp+10h] [ebp-44h]
  int v72; // [esp+10h] [ebp-44h]
  int v73; // [esp+10h] [ebp-44h]
  int v74; // [esp+14h] [ebp-40h]
  int v75; // [esp+14h] [ebp-40h]
  int v76; // [esp+14h] [ebp-40h]
  int v77; // [esp+14h] [ebp-40h]
  int v78; // [esp+14h] [ebp-40h]
  int v79; // [esp+14h] [ebp-40h]
  int v80; // [esp+1Ch] [ebp-38h]
  int v81; // [esp+1Ch] [ebp-38h]
  unsigned __int16 v82; // [esp+30h] [ebp-24h]
  int v83; // [esp+30h] [ebp-24h]
  __int16 v84; // [esp+34h] [ebp-20h]
  int var2; // [esp+3Ch] [ebp-18h]
  int v86; // [esp+3Ch] [ebp-18h]
  volatile signed __int32 *priv; // [esp+50h] [ebp-4h]

  priv = (volatile signed __int32 *)self->priv; /*0x1c30d1*/
  if ( !ev_try_lock(priv + 1) ) /*0x1c30da*/
    return self; /*0x1c30e9*/
  *priv = a4; /*0x1c30f6*/
  *(($9B414A52084CF78D000E95AF47DF0AD5 *)priv + 7) = *a3; /*0x1c30fa*/
  v6 = *((_BYTE *)priv + 8); /*0x1c30fd*/
  *((_BYTE *)priv + 8) = v6 + 1; /*0x1c3104*/
  if ( !v6 ) /*0x1c3109*/
  {
    v7 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c3122*/
    if ( v7 > 3 ) /*0x1c3128*/
    {
      if ( v7 != 4 ) /*0x1c313f*/
        goto LABEL_8; /*0x1c313f*/
      v23 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c32a8*/
      v24 = self->priv; /*0x1c32aa*/
      v68 = v24[3]; /*0x1c32b3*/
      v76 = v24[4]; /*0x1c32b9*/
      var2 = v23->var2; /*0x1c32bf*/
      v25 = (char *)v23->var5 /*0x1c32eb*/
          + 4 * var2 * ((__int16)v76 - *((__int16 *)v24 + 26))
          + 4 * ((__int16)v68 - *((__int16 *)v24 + 24));
      v26 = (v68 >> 16) - (__int16)v68; /*0x1c32f6*/
      v86 = var2 - v26; /*0x1c32f8*/
      v27 = v24 + 1042; /*0x1c32fb*/
      v28 = (v76 >> 16) - (__int16)v76 - 1; /*0x1c330b*/
      if ( v76 >> 16 != (__int16)v76 ) /*0x1c330f*/
      {
        do /*0x1c3342*/
        {
          v69 = v26 - 1; /*0x1c331f*/
          if ( v26 ) /*0x1c3325*/
          {
            do /*0x1c3339*/
            {
              *v25++ = *v27++; /*0x1c332a*/
              --v69; /*0x1c3332*/
            }
            while ( v69 != -1 ); /*0x1c3339*/
          }
          v25 += v86; /*0x1c333b*/
          --v28; /*0x1c333e*/
        }
        while ( v28 != -1 ); /*0x1c3342*/
      }
    }
    else
    {
      if ( v7 != 1 ) /*0x1c312d*/
      {
LABEL_8:
        v8 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c3145*/
        v9 = (__int16 *)self->priv; /*0x1c3155*/
        v66 = *((_DWORD *)v9 + 3); /*0x1c315e*/
        v74 = *((_DWORD *)v9 + 4); /*0x1c3164*/
        v10 = v8->var2; /*0x1c3167*/
        v11 = (char *)v8->var5 + 2 * v10 * ((__int16)v74 - v9[26]) + 2 * ((__int16)v66 - v9[24]); /*0x1c318b*/
        v12 = v10 - (__int16)(HIWORD(v66) - v66); /*0x1c319f*/
        v13 = v9 + 1060; /*0x1c31a4*/
        v14 = HIWORD(v74) - v74 - 1; /*0x1c31b7*/
        if ( HIWORD(v74) != (_WORD)v74 ) /*0x1c31bd*/
        {
          do /*0x1c31ed*/
          {
            v15 = HIWORD(v66) - v66; /*0x1c31c8*/
            while ( --v15 != -1 ) /*0x1c31dc*/
              *v11++ = *v13++; /*0x1c31d3*/
            v11 += v12; /*0x1c31e4*/
            --v14; /*0x1c31e7*/
          }
          while ( v14 != -1 ); /*0x1c31ed*/
        }
        goto LABEL_24; /*0x1c31ed*/
      }
      v16 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c31ff*/
      v17 = (__int16 *)self->priv; /*0x1c3204*/
      v67 = *((_DWORD *)v17 + 3); /*0x1c320d*/
      v75 = *((_DWORD *)v17 + 4); /*0x1c3213*/
      v18 = v16->var2; /*0x1c3216*/
      v19 = (char *)v16->var5 + v18 * ((__int16)v75 - v17[26]) + (__int16)v67 - v17[24]; /*0x1c3237*/
      v20 = v17 + 1060; /*0x1c3250*/
      v21 = HIWORD(v75) - v75 - 1; /*0x1c3263*/
      if ( HIWORD(v75) != (_WORD)v75 ) /*0x1c3269*/
      {
        do /*0x1c328f*/
        {
          v22 = HIWORD(v67) - v67; /*0x1c3270*/
          while ( --v22 != -1 ) /*0x1c327e*/
            *v19++ = *v20++; /*0x1c327a*/
          v19 += v18 - (__int16)(HIWORD(v67) - v67); /*0x1c3286*/
          --v21; /*0x1c3289*/
        }
        while ( v21 != -1 ); /*0x1c328f*/
      }
    }
  }
LABEL_24:
  if ( *((_BYTE *)priv + 9) ) /*0x1c3347*/
  {
    *((_BYTE *)priv + 9) = 0; /*0x1c334e*/
    if ( *((_BYTE *)priv + 8) ) /*0x1c3352*/
      --*((_BYTE *)priv + 8); /*0x1c335e*/
  }
  if ( !*((_BYTE *)priv + 10) ) /*0x1c3367*/
    goto LABEL_66; /*0x1c3367*/
  v29 = self->priv; /*0x1c3375*/
  v30 = *v29; /*0x1c337e*/
  v31 = v29[*v29 + 14]; /*0x1c3380*/
  v82 = *((_WORD *)v29 + 14) - v31; /*0x1c338b*/
  LOWORD(v30) = v82 + 16; /*0x1c338f*/
  v83 = (v30 << 16) | v82; /*0x1c339e*/
  v84 = *((_WORD *)v29 + 15) - HIWORD(v31); /*0x1c33ab*/
  v32 = 0; /*0x1c33bf*/
  if ( (__int16)v83 < *((__int16 *)v29 + 11) && *((__int16 *)v29 + 10) < SHIWORD(v83) && v84 < *((__int16 *)v29 + 13) ) /*0x1c33e2*/
    v32 = *((_WORD *)v29 + 12) < (unsigned __int16)(v84 + 16); /*0x1c33f2*/
  if ( v32 == *((char *)v29 + 11) ) /*0x1c33fe*/
    goto LABEL_66; /*0x1c33fe*/
  *((_BYTE *)v29 + 11) = v32; /*0x1c3406*/
  if ( !*((_BYTE *)v29 + 11) ) /*0x1c340e*/
  {
    v57 = self->priv; /*0x1c366f*/
    if ( !v57[8] ) /*0x1c3675*/
      goto LABEL_66; /*0x1c3675*/
    if ( --v57[8] ) /*0x1c3688*/
      goto LABEL_66; /*0x1c368d*/
    v58 = self->priv; /*0x1c3693*/
    v59 = v58[*v58 + 14]; /*0x1c369b*/
    *((_WORD *)v58 + 16) = *((_WORD *)v58 + 14) - v59; /*0x1c36a6*/
    *((_WORD *)v58 + 17) = *((_WORD *)v58 + 16) + 16; /*0x1c36b2*/
    *((_WORD *)v58 + 18) = *((_WORD *)v58 + 15) - HIWORD(v59); /*0x1c36c0*/
    *((_WORD *)v58 + 19) = *((_WORD *)v58 + 18) + 16; /*0x1c36cc*/
    v60 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c36e0*/
    if ( v60 > 3 ) /*0x1c36e6*/
    {
      if ( v60 == 4 ) /*0x1c36f7*/
      {
        sub_1C2B20(self); /*0x1c3714*/
        goto LABEL_65; /*0x1c3714*/
      }
    }
    else if ( v60 == 1 ) /*0x1c36eb*/
    {
      sub_1C27B4(self); /*0x1c3708*/
      goto LABEL_65; /*0x1c370d*/
    }
    sub_1C2388(self); /*0x1c36fd*/
LABEL_65:
    v61 = v58[9]; /*0x1c3719*/
    v58[10] = v58[8]; /*0x1c3722*/
    v58[11] = v61; /*0x1c3725*/
    goto LABEL_66; /*0x1c3725*/
  }
  v33 = self->priv; /*0x1c3417*/
  v34 = v33[8]; /*0x1c341d*/
  v33[8] = v34 + 1; /*0x1c3424*/
  if ( v34 ) /*0x1c3429*/
    goto LABEL_66; /*0x1c3429*/
  v35 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c343f*/
  if ( v35 > 3 ) /*0x1c3445*/
  {
    if ( v35 != 4 ) /*0x1c345b*/
      goto LABEL_39; /*0x1c345b*/
    v51 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c35c4*/
    v52 = self->priv; /*0x1c35c6*/
    v72 = v52[3]; /*0x1c35cf*/
    v79 = v52[4]; /*0x1c35d5*/
    v80 = v51->var2; /*0x1c35db*/
    v53 = (char *)v51->var5 /*0x1c3607*/
        + 4 * v80 * ((__int16)v79 - *((__int16 *)v52 + 26))
        + 4 * ((__int16)v72 - *((__int16 *)v52 + 24));
    v54 = (v72 >> 16) - (__int16)v72; /*0x1c3612*/
    v81 = v80 - v54; /*0x1c3614*/
    v55 = v52 + 1042; /*0x1c3617*/
    v56 = (v79 >> 16) - (__int16)v79 - 1; /*0x1c3627*/
    if ( v79 >> 16 != (__int16)v79 ) /*0x1c362b*/
    {
      do /*0x1c3662*/
      {
        v73 = v54 - 1; /*0x1c363f*/
        if ( v54 ) /*0x1c3645*/
        {
          do /*0x1c3659*/
          {
            *v53++ = *v55++; /*0x1c364a*/
            --v73; /*0x1c3652*/
          }
          while ( v73 != -1 ); /*0x1c3659*/
        }
        v53 += v81; /*0x1c365b*/
        --v56; /*0x1c365e*/
      }
      while ( v56 != -1 ); /*0x1c3662*/
    }
  }
  else
  {
    if ( v35 != 1 ) /*0x1c344a*/
    {
LABEL_39:
      v36 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c3461*/
      v37 = (__int16 *)self->priv; /*0x1c3471*/
      v70 = *((_DWORD *)v37 + 3); /*0x1c347a*/
      v77 = *((_DWORD *)v37 + 4); /*0x1c3480*/
      v38 = v36->var2; /*0x1c3483*/
      v39 = (char *)v36->var5 + 2 * v38 * ((__int16)v77 - v37[26]) + 2 * ((__int16)v70 - v37[24]); /*0x1c34a7*/
      v40 = v38 - (__int16)(HIWORD(v70) - v70); /*0x1c34bb*/
      v41 = v37 + 1060; /*0x1c34c0*/
      v42 = HIWORD(v77) - v77 - 1; /*0x1c34d3*/
      if ( HIWORD(v77) != (_WORD)v77 ) /*0x1c34d9*/
      {
        do /*0x1c3509*/
        {
          v43 = HIWORD(v70) - v70; /*0x1c34e4*/
          while ( --v43 != -1 ) /*0x1c34f8*/
            *v39++ = *v41++; /*0x1c34ef*/
          v39 += v40; /*0x1c3500*/
          --v42; /*0x1c3503*/
        }
        while ( v42 != -1 ); /*0x1c3509*/
      }
      goto LABEL_66; /*0x1c3509*/
    }
    v44 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c351b*/
    v45 = (__int16 *)self->priv; /*0x1c3520*/
    v71 = *((_DWORD *)v45 + 3); /*0x1c3529*/
    v78 = *((_DWORD *)v45 + 4); /*0x1c352f*/
    v46 = v44->var2; /*0x1c3532*/
    v47 = (char *)v44->var5 + v46 * ((__int16)v78 - v45[26]) + (__int16)v71 - v45[24]; /*0x1c3553*/
    v48 = v45 + 1060; /*0x1c356c*/
    v49 = HIWORD(v78) - v78 - 1; /*0x1c357f*/
    if ( HIWORD(v78) != (_WORD)v78 ) /*0x1c3585*/
    {
      do /*0x1c35ab*/
      {
        v50 = HIWORD(v71) - v71; /*0x1c358c*/
        while ( --v50 != -1 ) /*0x1c359a*/
          *v47++ = *v48++; /*0x1c3596*/
        v47 += v46 - (__int16)(HIWORD(v71) - v71); /*0x1c35a2*/
        --v49; /*0x1c35a5*/
      }
      while ( v49 != -1 ); /*0x1c35ab*/
    }
  }
LABEL_66:
  if ( !*((_BYTE *)priv + 8) ) /*0x1c372b*/
    goto LABEL_76; /*0x1c372b*/
  if ( --*((_BYTE *)priv + 8) ) /*0x1c373e*/
    goto LABEL_76; /*0x1c3743*/
  v62 = self->priv; /*0x1c374c*/
  v63 = v62[*v62 + 14]; /*0x1c3754*/
  *((_WORD *)v62 + 16) = *((_WORD *)v62 + 14) - v63; /*0x1c375f*/
  *((_WORD *)v62 + 17) = *((_WORD *)v62 + 16) + 16; /*0x1c376b*/
  *((_WORD *)v62 + 18) = *((_WORD *)v62 + 15) - HIWORD(v63); /*0x1c3779*/
  *((_WORD *)v62 + 19) = *((_WORD *)v62 + 18) + 16; /*0x1c3785*/
  v64 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c3799*/
  if ( v64 > 3 ) /*0x1c379f*/
  {
    if ( v64 == 4 ) /*0x1c37b3*/
    {
      sub_1C2B20(self); /*0x1c37d0*/
      goto LABEL_75; /*0x1c37d0*/
    }
  }
  else if ( v64 == 1 ) /*0x1c37a4*/
  {
    sub_1C27B4(self); /*0x1c37c4*/
    goto LABEL_75; /*0x1c37c9*/
  }
  sub_1C2388(self); /*0x1c37b9*/
LABEL_75:
  v65 = v62[9]; /*0x1c37d5*/
  v62[10] = v62[8]; /*0x1c37de*/
  v62[11] = v65; /*0x1c37e1*/
LABEL_76:
  ev_unlock((_DWORD *)priv + 1); /*0x1c37e4*/
  return self; /*0x1c37f6*/
}
