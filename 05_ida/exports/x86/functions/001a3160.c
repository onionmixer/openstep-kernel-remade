/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3160. */
int __cdecl sub_1A3160(int a1, int a2, int a3, int a4, int a5)
{
  int *v5; // eax
  int v6; // ecx
  unsigned int v7; // edx
  int v8; // eax
  int *v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // ecx
  int *v16; // eax
  int v17; // edx
  unsigned int v18; // eax
  int v19; // ebx
  unsigned __int16 v20; // ax
  int v21; // ecx
  int *v22; // eax
  int v23; // edx
  unsigned int v24; // eax
  int v25; // ebx
  int v26; // edx
  int v27; // eax
  int v28; // ebx
  int v29; // ebx
  unsigned __int16 v30; // ax
  int v31; // ecx
  int *v32; // eax
  int v33; // edx
  unsigned int v34; // eax
  int v35; // ebx
  int v36; // edx
  int v37; // ebx
  int v38; // edi
  int v39; // eax
  int v40; // ebx
  unsigned __int16 v41; // ax
  int v42; // ecx
  int *v43; // eax
  int v44; // edx
  unsigned int v45; // eax
  int v46; // ebx
  int v47; // edx
  int v48; // ebx
  int v50; // edx
  int v51; // [esp+Ch] [ebp-4Ch]
  int v52; // [esp+Ch] [ebp-4Ch]
  int v53; // [esp+Ch] [ebp-4Ch]
  unsigned __int16 *v54; // [esp+10h] [ebp-48h]
  unsigned __int16 *v55; // [esp+10h] [ebp-48h]
  unsigned __int16 *v56; // [esp+10h] [ebp-48h]
  int v57; // [esp+14h] [ebp-44h]
  int v58; // [esp+18h] [ebp-40h]
  unsigned __int16 v59; // [esp+1Eh] [ebp-3Ah]
  unsigned int v60; // [esp+20h] [ebp-38h]
  _DWORD v61[2]; // [esp+24h] [ebp-34h] BYREF
  __int16 v62; // [esp+2Ch] [ebp-2Ch]
  int v63; // [esp+30h] [ebp-28h]
  unsigned int v64; // [esp+34h] [ebp-24h]
  unsigned int v65; // [esp+38h] [ebp-20h]
  int v66; // [esp+3Ch] [ebp-1Ch] BYREF
  __int16 v67; // [esp+40h] [ebp-18h]
  int v68; // [esp+44h] [ebp-14h]
  unsigned int v69; // [esp+48h] [ebp-10h]
  unsigned int v70; // [esp+4Ch] [ebp-Ch]
  unsigned int v71; // [esp+50h] [ebp-8h]
  unsigned int v72; // [esp+54h] [ebp-4h]

  v5 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a316f*/
  v6 = 0; /*0x1a3175*/
  if ( v5 ) /*0x1a3179*/
    v6 = *v5; /*0x1a317b*/
  if ( v6 ) /*0x1a317f*/
  {
    v7 = *(_DWORD *)(v6 + 132); /*0x1a3181*/
    if ( v7 > 7 ) /*0x1a318a*/
      v8 = 0; /*0x1a319c*/
    else
      v8 = v6 + 132 * v7 + 136; /*0x1a3193*/
    v58 = v8; /*0x1a319e*/
  }
  else
  {
    v58 = 0; /*0x1a31a4*/
  }
  v9 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a31b1*/
  v10 = 0; /*0x1a31b7*/
  if ( v9 ) /*0x1a31bb*/
    v10 = *v9; /*0x1a31bd*/
  v11 = 8 * a3; /*0x1a31c2*/
  if ( *(_DWORD *)(v10 + 52) <= (unsigned int)(8 * a3) ) /*0x1a31cc*/
    return 0; /*0x1a31cc*/
  v12 = *(_DWORD *)(v10 + 48); /*0x1a31d2*/
  *(_DWORD *)(a1 + 116) = &loc_1A3200; /*0x1a31da*/
  v71 = __readfsdword(v11 + v12); /*0x1a31e4*/
  v72 = __readfsdword(v11 + v12 + 4); /*0x1a31eb*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a31f1*/
  v13 = BYTE1(v72) & 0x1F; /*0x1a3217*/
  if ( v13 == 7 ) /*0x1a321d*/
  {
    v14 = 0; /*0x1a3260*/
LABEL_23:
    v57 = 0; /*0x1a3262*/
    goto LABEL_24; /*0x1a3262*/
  }
  if ( (BYTE1(v72) & 0x1Fu) > 7 ) /*0x1a321f*/
  {
    if ( v13 == 14 ) /*0x1a322f*/
    {
      v14 = 1; /*0x1a323c*/
      v57 = 1; /*0x1a3241*/
      goto LABEL_24; /*0x1a3248*/
    }
    if ( v13 != 15 ) /*0x1a3234*/
      return 0; /*0x1a3234*/
    v14 = 1; /*0x1a324c*/
    goto LABEL_23; /*0x1a3251*/
  }
  if ( v13 != 6 ) /*0x1a3224*/
    return 0; /*0x1a3224*/
  v14 = 0; /*0x1a3254*/
  v57 = 1; /*0x1a3256*/
LABEL_24:
  if ( (v72 & 0x8000) == 0 || (v71 & 0x40000) == 0 ) /*0x1a3279*/
    return 0; /*0x1a3279*/
  v15 = HIWORD(v71) >> 3; /*0x1a3283*/
  v16 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a328c*/
  v17 = 0; /*0x1a3292*/
  if ( v16 ) /*0x1a3296*/
    v17 = *v16; /*0x1a3298*/
  if ( *(_DWORD *)(v17 + 60) <= (unsigned int)(8 * v15) ) /*0x1a32a4*/
    return 0; /*0x1a32a4*/
  v18 = *(_DWORD *)(v17 + 56) + 8 * v15; /*0x1a32b0*/
  *(_DWORD *)(a1 + 116) = &loc_1A32DC; /*0x1a32b6*/
  v69 = __readfsdword(v18); /*0x1a32c0*/
  v70 = __readfsdword(v18 + 4); /*0x1a32c7*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a32cd*/
  if ( (BYTE1(v70) & 0x18) != 0x18 || (v70 & 0x8000) == 0 ) /*0x1a3303*/
    return 0; /*0x1a3303*/
  if ( a5 || a3 <= 7 || a3 == 16 || a3 > 17 ) /*0x1a331f*/
  {
    if ( v14 ) /*0x1a3327*/
    {
      v19 = *(_DWORD *)(v58 + 104); /*0x1a3330*/
      v20 = *(_WORD *)(a2 + 72); /*0x1a3336*/
      if ( (v20 & 4) == 0 ) /*0x1a333c*/
        return 0; /*0x1a333c*/
      v21 = v20 >> 3; /*0x1a3346*/
      v22 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a334f*/
      v23 = 0; /*0x1a3355*/
      if ( v22 ) /*0x1a3359*/
        v23 = *v22; /*0x1a335b*/
      if ( *(_DWORD *)(v23 + 60) <= (unsigned int)(8 * v21) ) /*0x1a3367*/
        return 0; /*0x1a3367*/
      v24 = *(_DWORD *)(v23 + 56) + 8 * v21; /*0x1a3370*/
      *(_DWORD *)(a1 + 116) = &loc_1A339C; /*0x1a3376*/
      v64 = __readfsdword(v24); /*0x1a3380*/
      v65 = __readfsdword(v24 + 4); /*0x1a3387*/
      *(_DWORD *)(a1 + 116) = 0; /*0x1a338d*/
      v66 = *(_DWORD *)(a2 + 56); /*0x1a33b6*/
      v67 = *(_WORD *)(a2 + 60); /*0x1a33c0*/
      v68 = *(_DWORD *)(a2 + 64); /*0x1a33ca*/
      if ( v19 ) /*0x1a33cf*/
        v68 |= 0x200u; /*0x1a33d1*/
      else
        v68 &= ~0x200u; /*0x1a33dc*/
      v25 = *(_DWORD *)(a2 + 68) - 12; /*0x1a33e9*/
      v54 = (unsigned __int16 *)&v66; /*0x1a33ef*/
      v51 = 12; /*0x1a33f2*/
      LOBYTE(v23) = HIBYTE(v65); /*0x1a3404*/
      v26 = ((unsigned __int8)v65 << 16) | HIWORD(v64) | (v23 << 24); /*0x1a340c*/
      v27 = 0xFFFF; /*0x1a340e*/
      if ( (v65 & 0x400000) != 0 ) /*0x1a3417*/
        v27 = -1; /*0x1a3419*/
      *(_DWORD *)(a1 + 116) = &loc_1A3450; /*0x1a3421*/
      do /*0x1a3440*/
      {
        v28 = v27 & v25; /*0x1a3428*/
        __writefsword(v28 + v26, *v54++); /*0x1a3430*/
        v25 = v28 + 2; /*0x1a3439*/
        v51 -= 2; /*0x1a343c*/
      }
      while ( v51 ); /*0x1a3440*/
      *(_DWORD *)(a1 + 116) = 0; /*0x1a3445*/
      if ( (v65 & 0x400000) != 0 ) /*0x1a3464*/
      {
        *(_DWORD *)(a2 + 68) -= 12; /*0x1a3469*/
      }
      else
      {
        v27 = (unsigned __int16)(*(_WORD *)(a2 + 68) - 12); /*0x1a347f*/
        *(_DWORD *)(a2 + 68) = v27; /*0x1a3484*/
      }
      goto LABEL_82; /*0x1a346d*/
    }
    v29 = *(_DWORD *)(v58 + 104); /*0x1a348f*/
    v30 = *(_WORD *)(a2 + 72); /*0x1a3495*/
    if ( (v30 & 4) == 0 ) /*0x1a349b*/
      return 0; /*0x1a349b*/
    v31 = v30 >> 3; /*0x1a34a5*/
    v32 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a34ae*/
    v33 = 0; /*0x1a34b4*/
    if ( v32 ) /*0x1a34b8*/
      v33 = *v32; /*0x1a34ba*/
    if ( *(_DWORD *)(v33 + 60) <= (unsigned int)(8 * v31) ) /*0x1a34c6*/
      return 0; /*0x1a34c6*/
    v34 = *(_DWORD *)(v33 + 56) + 8 * v31; /*0x1a34d0*/
    *(_DWORD *)(a1 + 116) = &loc_1A34FC; /*0x1a34d6*/
    v64 = __readfsdword(v34); /*0x1a34e0*/
    v65 = __readfsdword(v34 + 4); /*0x1a34e7*/
    *(_DWORD *)(a1 + 116) = 0; /*0x1a34ed*/
    LOWORD(v66) = *(_WORD *)(a2 + 56); /*0x1a3517*/
    HIWORD(v66) = *(_WORD *)(a2 + 60); /*0x1a3522*/
    v67 = *(_WORD *)(a2 + 64); /*0x1a352d*/
    if ( v29 ) /*0x1a3533*/
      v67 |= 0x200u; /*0x1a3535*/
    else
      v67 &= ~0x200u; /*0x1a3540*/
    v35 = *(_DWORD *)(a2 + 68) - 6; /*0x1a354c*/
    v55 = (unsigned __int16 *)&v66; /*0x1a3552*/
    v52 = 6; /*0x1a3555*/
    LOBYTE(v33) = HIBYTE(v65); /*0x1a3567*/
    v36 = ((unsigned __int8)v65 << 16) | HIWORD(v64) | (v33 << 24); /*0x1a356f*/
    v27 = 0xFFFF; /*0x1a3571*/
    if ( (v65 & 0x400000) != 0 ) /*0x1a357a*/
      v27 = -1; /*0x1a357c*/
    *(_DWORD *)(a1 + 116) = &loc_1A35B4; /*0x1a3584*/
    do /*0x1a35a4*/
    {
      v37 = v27 & v35; /*0x1a358c*/
      __writefsword(v37 + v36, *v55++); /*0x1a3594*/
      v35 = v37 + 2; /*0x1a359d*/
      v52 -= 2; /*0x1a35a0*/
    }
    while ( v52 ); /*0x1a35a4*/
    *(_DWORD *)(a1 + 116) = 0; /*0x1a35a9*/
    if ( (v65 & 0x400000) != 0 ) /*0x1a35c8*/
    {
      *(_DWORD *)(a2 + 68) -= 6; /*0x1a35cd*/
      goto LABEL_82; /*0x1a35d1*/
    }
    v38 = a2; /*0x1a35d8*/
    LOWORD(v39) = *(_WORD *)(a2 + 68) - 6; /*0x1a35df*/
LABEL_79:
    v27 = (unsigned __int16)v39; /*0x1a373f*/
    *(_DWORD *)(v38 + 68) = (unsigned __int16)v39; /*0x1a3744*/
    goto LABEL_82; /*0x1a3747*/
  }
  if ( v14 ) /*0x1a35ea*/
  {
    v40 = *(_DWORD *)(v58 + 104); /*0x1a35f3*/
    v41 = *(_WORD *)(a2 + 72); /*0x1a35f9*/
    if ( (v41 & 4) == 0 ) /*0x1a35ff*/
      return 0; /*0x1a35ff*/
    v42 = v41 >> 3; /*0x1a3609*/
    v43 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a3612*/
    v44 = 0; /*0x1a3618*/
    if ( v43 ) /*0x1a361c*/
      v44 = *v43; /*0x1a361e*/
    if ( *(_DWORD *)(v44 + 60) <= (unsigned int)(8 * v42) ) /*0x1a362a*/
      return 0; /*0x1a362a*/
    v45 = *(_DWORD *)(v44 + 56) + 8 * v42; /*0x1a3634*/
    *(_DWORD *)(a1 + 116) = &loc_1A3660; /*0x1a363a*/
    v59 = __readfsdword(v45) >> 16; /*0x1a3644*/
    v60 = __readfsdword(v45 + 4); /*0x1a364b*/
    *(_DWORD *)(a1 + 116) = 0; /*0x1a3651*/
    v61[0] = a4; /*0x1a3677*/
    v61[1] = *(_DWORD *)(a2 + 56); /*0x1a3680*/
    v62 = *(_WORD *)(a2 + 60); /*0x1a368a*/
    v63 = *(_DWORD *)(a2 + 64); /*0x1a3694*/
    if ( v40 ) /*0x1a3699*/
      v63 |= 0x200u; /*0x1a369b*/
    else
      v63 &= ~0x200u; /*0x1a36a4*/
    v46 = *(_DWORD *)(a2 + 68) - 16; /*0x1a36b1*/
    v56 = (unsigned __int16 *)v61; /*0x1a36b7*/
    v53 = 16; /*0x1a36ba*/
    LOBYTE(v44) = HIBYTE(v60); /*0x1a36cc*/
    v47 = ((unsigned __int8)v60 << 16) | v59 | (v44 << 24); /*0x1a36d4*/
    v27 = 0xFFFF; /*0x1a36d6*/
    if ( (v60 & 0x400000) != 0 ) /*0x1a36df*/
      v27 = -1; /*0x1a36e1*/
    *(_DWORD *)(a1 + 116) = &loc_1A3718; /*0x1a36e9*/
    do /*0x1a3708*/
    {
      v48 = v27 & v46; /*0x1a36f0*/
      __writefsword(v48 + v47, *v56++); /*0x1a36f8*/
      v46 = v48 + 2; /*0x1a3701*/
      v53 -= 2; /*0x1a3704*/
    }
    while ( v53 ); /*0x1a3708*/
    *(_DWORD *)(a1 + 116) = 0; /*0x1a370d*/
    if ( (v60 & 0x400000) != 0 ) /*0x1a3728*/
    {
      *(_DWORD *)(a2 + 68) -= 16; /*0x1a372d*/
      goto LABEL_82; /*0x1a3731*/
    }
    v38 = a2; /*0x1a3734*/
    LOWORD(v39) = *(_WORD *)(a2 + 68) - 16; /*0x1a373b*/
    goto LABEL_79; /*0x1a373b*/
  }
  v27 = sub_1A2FC8(a1, a2, *(_DWORD *)(v58 + 104), a4); /*0x1a375f*/
  if ( !v27 ) /*0x1a3766*/
    return 0; /*0x1a376a*/
LABEL_82:
  v50 = *(_DWORD *)(v58 + 128) & 1; /*0x1a376c*/
  LOWORD(v27) = HIWORD(v72); /*0x1a3778*/
  *(_DWORD *)(a2 + 56) = (v27 << 16) | (unsigned __int16)v71; /*0x1a3788*/
  *(_WORD *)(a2 + 60) = HIWORD(v71); /*0x1a378f*/
  if ( !v50 ) /*0x1a3795*/
    *(_DWORD *)(a2 + 64) &= ~0x100u; /*0x1a3797*/
  if ( v57 ) /*0x1a37a2*/
    *(_DWORD *)(v58 + 104) = 0; /*0x1a37a7*/
  return 1; /*0x1a37b6*/
}
