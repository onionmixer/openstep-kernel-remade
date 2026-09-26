/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c3800. */
id __cdecl -[IOFrameBufferDisplay showCursor:frame:token:](
        IOFrameBufferDisplay *self,
        SEL a2,
        $9B414A52084CF78D000E95AF47DF0AD5 *a3,
        int a4,
        int a5)
{
  _DWORD *v6; // edi
  int v7; // edx
  int v8; // ecx
  _BYTE *v9; // edx
  char v10; // al
  unsigned int v11; // edx
  $514E7C50D28E54AB164B6500F83867A3 *v12; // eax
  __int16 *v13; // edi
  int v14; // ebx
  _WORD *v15; // ecx
  int v16; // ebx
  _WORD *v17; // edi
  __int16 v18; // dx
  __int16 v19; // ax
  $514E7C50D28E54AB164B6500F83867A3 *v20; // eax
  __int16 *v21; // edi
  int v22; // esi
  _BYTE *v23; // eax
  _BYTE *v24; // edi
  __int16 v25; // dx
  __int16 v26; // cx
  $514E7C50D28E54AB164B6500F83867A3 *v27; // edi
  _DWORD *v28; // eax
  _DWORD *v29; // ecx
  int v30; // edi
  _DWORD *v31; // eax
  int v32; // edx
  _BYTE *v33; // ecx
  _DWORD *v34; // edi
  int v35; // ecx
  unsigned int v36; // edx
  int v37; // ecx
  _BYTE *v38; // ecx
  _DWORD *v39; // edi
  int v40; // ecx
  unsigned int v41; // edx
  int v42; // ecx
  unsigned __int16 v43; // [esp+10h] [ebp-28h]
  int v44; // [esp+10h] [ebp-28h]
  int v45; // [esp+10h] [ebp-28h]
  int v46; // [esp+10h] [ebp-28h]
  int v47; // [esp+10h] [ebp-28h]
  int v48; // [esp+10h] [ebp-28h]
  __int16 v49; // [esp+14h] [ebp-24h]
  int v50; // [esp+14h] [ebp-24h]
  int v51; // [esp+14h] [ebp-24h]
  int v52; // [esp+14h] [ebp-24h]
  int var2; // [esp+1Ch] [ebp-1Ch]
  int v54; // [esp+1Ch] [ebp-1Ch]
  int v55; // [esp+30h] [ebp-8h]
  volatile signed __int32 *priv; // [esp+34h] [ebp-4h]

  priv = (volatile signed __int32 *)self->priv; /*0x1c3815*/
  if ( !ev_try_lock(priv + 1) ) /*0x1c381e*/
    return self; /*0x1c382d*/
  *priv = a4; /*0x1c383a*/
  *(($9B414A52084CF78D000E95AF47DF0AD5 *)priv + 7) = *a3; /*0x1c383e*/
  if ( !*((_BYTE *)priv + 10) ) /*0x1c3841*/
    goto LABEL_42; /*0x1c3841*/
  v6 = self->priv; /*0x1c384f*/
  v7 = *v6; /*0x1c3855*/
  v8 = v6[*v6 + 14]; /*0x1c3857*/
  v43 = *((_WORD *)v6 + 14) - v8; /*0x1c3862*/
  LOWORD(v7) = v43 + 16; /*0x1c3866*/
  v44 = (v7 << 16) | v43; /*0x1c3875*/
  v49 = *((_WORD *)v6 + 15) - HIWORD(v8); /*0x1c3882*/
  v55 = 0; /*0x1c3896*/
  if ( (__int16)v44 < *((__int16 *)v6 + 11) && *((__int16 *)v6 + 10) < SHIWORD(v44) && v49 < *((__int16 *)v6 + 13) ) /*0x1c38be*/
    v55 = *((_WORD *)v6 + 12) < (unsigned __int16)(v49 + 16); /*0x1c38ce*/
  if ( v55 == *((char *)v6 + 11) ) /*0x1c38da*/
    goto LABEL_42; /*0x1c38da*/
  *((_BYTE *)v6 + 11) = v55; /*0x1c38e3*/
  if ( !*((_BYTE *)v6 + 11) ) /*0x1c38eb*/
  {
    v33 = self->priv; /*0x1c3b4b*/
    if ( !v33[8] ) /*0x1c3b51*/
      goto LABEL_42; /*0x1c3b51*/
    if ( --v33[8] ) /*0x1c3b64*/
      goto LABEL_42; /*0x1c3b69*/
    v34 = self->priv; /*0x1c3b6f*/
    v35 = v34[*v34 + 14]; /*0x1c3b77*/
    *((_WORD *)v34 + 16) = *((_WORD *)v34 + 14) - v35; /*0x1c3b82*/
    *((_WORD *)v34 + 17) = *((_WORD *)v34 + 16) + 16; /*0x1c3b8e*/
    *((_WORD *)v34 + 18) = *((_WORD *)v34 + 15) - HIWORD(v35); /*0x1c3b9c*/
    *((_WORD *)v34 + 19) = *((_WORD *)v34 + 18) + 16; /*0x1c3ba8*/
    v36 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c3bbc*/
    if ( v36 > 3 ) /*0x1c3bc2*/
    {
      if ( v36 == 4 ) /*0x1c3bd3*/
      {
        sub_1C2B20(self); /*0x1c3bf0*/
        goto LABEL_41; /*0x1c3bf0*/
      }
    }
    else if ( v36 == 1 ) /*0x1c3bc7*/
    {
      sub_1C27B4(self); /*0x1c3be4*/
      goto LABEL_41; /*0x1c3be9*/
    }
    sub_1C2388(self); /*0x1c3bd9*/
LABEL_41:
    v37 = v34[9]; /*0x1c3bf5*/
    v34[10] = v34[8]; /*0x1c3bfe*/
    v34[11] = v37; /*0x1c3c01*/
    goto LABEL_42; /*0x1c3c01*/
  }
  v9 = self->priv; /*0x1c38f4*/
  v10 = v9[8]; /*0x1c38fa*/
  v9[8] = v10 + 1; /*0x1c3901*/
  if ( v10 ) /*0x1c3906*/
    goto LABEL_42; /*0x1c3906*/
  v11 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c391c*/
  if ( v11 > 3 ) /*0x1c3922*/
  {
    if ( v11 != 4 ) /*0x1c3937*/
      goto LABEL_15; /*0x1c3937*/
    v27 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c3aa0*/
    v28 = self->priv; /*0x1c3aa2*/
    v47 = v28[3]; /*0x1c3aab*/
    v52 = v28[4]; /*0x1c3ab1*/
    var2 = v27->var2; /*0x1c3ab7*/
    v29 = (char *)v27->var5 /*0x1c3ae3*/
        + 4 * var2 * ((__int16)v52 - *((__int16 *)v28 + 26))
        + 4 * ((__int16)v47 - *((__int16 *)v28 + 24));
    v30 = (v47 >> 16) - (__int16)v47; /*0x1c3aee*/
    v54 = var2 - v30; /*0x1c3af0*/
    v31 = v28 + 1042; /*0x1c3af3*/
    v32 = (v52 >> 16) - (__int16)v52 - 1; /*0x1c3b03*/
    if ( v52 >> 16 != (__int16)v52 ) /*0x1c3b07*/
    {
      do /*0x1c3b3e*/
      {
        v48 = v30 - 1; /*0x1c3b1b*/
        if ( v30 ) /*0x1c3b21*/
        {
          do /*0x1c3b35*/
          {
            *v29++ = *v31++; /*0x1c3b26*/
            --v48; /*0x1c3b2e*/
          }
          while ( v48 != -1 ); /*0x1c3b35*/
        }
        v29 += v54; /*0x1c3b37*/
        --v32; /*0x1c3b3a*/
      }
      while ( v32 != -1 ); /*0x1c3b3e*/
    }
  }
  else
  {
    if ( v11 != 1 ) /*0x1c3927*/
    {
LABEL_15:
      v12 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c393d*/
      v13 = (__int16 *)self->priv; /*0x1c394d*/
      v45 = *((_DWORD *)v13 + 3); /*0x1c3956*/
      v50 = *((_DWORD *)v13 + 4); /*0x1c395c*/
      v14 = v12->var2; /*0x1c395f*/
      v15 = (char *)v12->var5 + 2 * v14 * ((__int16)v50 - v13[26]) + 2 * ((__int16)v45 - v13[24]); /*0x1c3983*/
      v16 = v14 - (__int16)(HIWORD(v45) - v45); /*0x1c3997*/
      v17 = v13 + 1060; /*0x1c399c*/
      v18 = HIWORD(v50) - v50 - 1; /*0x1c39af*/
      if ( HIWORD(v50) != (_WORD)v50 ) /*0x1c39b5*/
      {
        do /*0x1c39e5*/
        {
          v19 = HIWORD(v45) - v45; /*0x1c39c0*/
          while ( --v19 != -1 ) /*0x1c39d4*/
            *v15++ = *v17++; /*0x1c39cb*/
          v15 += v16; /*0x1c39dc*/
          --v18; /*0x1c39df*/
        }
        while ( v18 != -1 ); /*0x1c39e5*/
      }
      goto LABEL_42; /*0x1c39e5*/
    }
    v20 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c39f7*/
    v21 = (__int16 *)self->priv; /*0x1c39fc*/
    v46 = *((_DWORD *)v21 + 3); /*0x1c3a05*/
    v51 = *((_DWORD *)v21 + 4); /*0x1c3a0b*/
    v22 = v20->var2; /*0x1c3a0e*/
    v23 = (char *)v20->var5 + v22 * ((__int16)v51 - v21[26]) + (__int16)v46 - v21[24]; /*0x1c3a2f*/
    v24 = v21 + 1060; /*0x1c3a48*/
    v25 = HIWORD(v51) - v51 - 1; /*0x1c3a5b*/
    if ( HIWORD(v51) != (_WORD)v51 ) /*0x1c3a61*/
    {
      do /*0x1c3a87*/
      {
        v26 = HIWORD(v46) - v46; /*0x1c3a68*/
        while ( --v26 != -1 ) /*0x1c3a76*/
          *v23++ = *v24++; /*0x1c3a72*/
        v23 += v22 - (__int16)(HIWORD(v46) - v46); /*0x1c3a7e*/
        --v25; /*0x1c3a81*/
      }
      while ( v25 != -1 ); /*0x1c3a87*/
    }
  }
LABEL_42:
  v38 = self->priv; /*0x1c3c04*/
  if ( !v38[8] ) /*0x1c3c0d*/
    goto LABEL_52; /*0x1c3c0d*/
  if ( --v38[8] ) /*0x1c3c20*/
    goto LABEL_52; /*0x1c3c25*/
  v39 = self->priv; /*0x1c3c2b*/
  v40 = v39[*v39 + 14]; /*0x1c3c33*/
  *((_WORD *)v39 + 16) = *((_WORD *)v39 + 14) - v40; /*0x1c3c3e*/
  *((_WORD *)v39 + 17) = *((_WORD *)v39 + 16) + 16; /*0x1c3c4a*/
  *((_WORD *)v39 + 18) = *((_WORD *)v39 + 15) - HIWORD(v40); /*0x1c3c58*/
  *((_WORD *)v39 + 19) = *((_WORD *)v39 + 18) + 16; /*0x1c3c64*/
  v41 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c3c78*/
  if ( v41 > 3 ) /*0x1c3c7e*/
  {
    if ( v41 == 4 ) /*0x1c3c8f*/
    {
      sub_1C2B20(self); /*0x1c3cac*/
      goto LABEL_51; /*0x1c3cac*/
    }
  }
  else if ( v41 == 1 ) /*0x1c3c83*/
  {
    sub_1C27B4(self); /*0x1c3ca0*/
    goto LABEL_51; /*0x1c3ca5*/
  }
  sub_1C2388(self); /*0x1c3c95*/
LABEL_51:
  v42 = v39[9]; /*0x1c3cb1*/
  v39[10] = v39[8]; /*0x1c3cba*/
  v39[11] = v42; /*0x1c3cbd*/
LABEL_52:
  ev_unlock((_DWORD *)priv + 1); /*0x1c3cc0*/
  return self; /*0x1c3cd2*/
}
