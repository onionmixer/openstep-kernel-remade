/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19372c. */
char sigreturn()
{
  int v0; // eax
  int v1; // ebx
  int v2; // eax
  _BOOL4 v3; // ecx
  _BOOL4 v4; // ecx
  _BOOL4 v5; // ecx
  _BOOL4 v6; // ecx
  int v7; // esi
  int *v8; // eax
  int v9; // ecx
  unsigned int v10; // edx
  thread_act_t v12; // [esp+Ch] [ebp-50h]
  unsigned int *v13; // [esp+10h] [ebp-4Ch]
  _DWORD v14[10]; // [esp+14h] [ebp-48h] BYREF
  int v15; // [esp+3Ch] [ebp-20h]
  int v16; // [esp+40h] [ebp-1Ch]
  int v17; // [esp+44h] [ebp-18h]
  int v18; // [esp+48h] [ebp-14h]
  int v19; // [esp+4Ch] [ebp-10h]
  int v20; // [esp+50h] [ebp-Ch]
  int v21; // [esp+54h] [ebp-8h]
  int v22; // [esp+58h] [ebp-4h]

  v13 = *(unsigned int **)(dword_1E875C + 36); /*0x19373d*/
  v12 = active_threads; /*0x193746*/
  v0 = *(_DWORD *)(*(_DWORD *)(active_threads + 40) + 112); /*0x19374c*/
  if ( v0 ) /*0x193751*/
    v1 = v0 + 132; /*0x193753*/
  else
    v1 = thread_user_state(active_threads); /*0x193768*/
  v2 = copyin(*v13, (unsigned int)v14, 72); /*0x193776*/
  if ( v2 ) /*0x19377d*/
    return v2; /*0x19377d*/
  if ( (v16 & 0x20000) != 0 ) /*0x193787*/
    goto LABEL_40; /*0x193787*/
  LOBYTE(v2) = v18; /*0x19378d*/
  if ( !v18 ) /*0x193796*/
    return v2; /*0x193796*/
  if ( (v18 & 4) != 0 ) /*0x19379f*/
  {
    LOBYTE(v2) = v18 & 3; /*0x1937a3*/
    if ( (v18 & 3) != 3 ) /*0x1937a7*/
      return v2; /*0x1937a7*/
  }
  else
  {
    LOWORD(v2) = (unsigned __int16)v18 >> 3; /*0x1937b2*/
    if ( (unsigned __int16)((unsigned __int16)v18 >> 3) > 0x1Fu ) /*0x1937bc*/
      return v2; /*0x1937bc*/
    LOBYTE(v2) = v18 & 3; /*0x1937c4*/
    if ( (v18 & 3) != 3 ) /*0x1937c8*/
      return v2; /*0x1937c8*/
    LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v18 >> 3) + 5) & 0x60; /*0x1937d7*/
    if ( (_BYTE)v2 != 96 ) /*0x1937db*/
      return v2; /*0x1937db*/
  }
  if ( !v19 || (v19 & 4) != 0 ) /*0x1937ef*/
    goto LABEL_55; /*0x1937ef*/
  LOWORD(v2) = (unsigned __int16)v19 >> 3; /*0x1937f3*/
  v3 = 0; /*0x1937fa*/
  if ( (unsigned __int16)((unsigned __int16)v19 >> 3) <= 0x1Fu ) /*0x1937ff*/
  {
    LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v19 >> 3) + 5) & 0x60; /*0x19380a*/
    v3 = (_BYTE)v2 == 96; /*0x193810*/
  }
  if ( v3 ) /*0x193813*/
  {
LABEL_55:
    if ( !v20 || (v20 & 4) != 0 ) /*0x193827*/
      goto LABEL_56; /*0x193827*/
    LOWORD(v2) = (unsigned __int16)v20 >> 3; /*0x19382b*/
    v4 = 0; /*0x193832*/
    if ( (unsigned __int16)((unsigned __int16)v20 >> 3) <= 0x1Fu ) /*0x193837*/
    {
      LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v20 >> 3) + 5) & 0x60; /*0x193842*/
      v4 = (_BYTE)v2 == 96; /*0x193848*/
    }
    if ( v4 ) /*0x19384b*/
    {
LABEL_56:
      if ( !v21 || (v21 & 4) != 0 ) /*0x19385f*/
        goto LABEL_57; /*0x19385f*/
      LOWORD(v2) = (unsigned __int16)v21 >> 3; /*0x193863*/
      v5 = 0; /*0x19386a*/
      if ( (unsigned __int16)((unsigned __int16)v21 >> 3) <= 0x1Fu ) /*0x19386f*/
      {
        LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v21 >> 3) + 5) & 0x60; /*0x19387a*/
        v5 = (_BYTE)v2 == 96; /*0x193880*/
      }
      if ( v5 ) /*0x193883*/
      {
LABEL_57:
        if ( !v22 || (v22 & 4) != 0 ) /*0x193897*/
          goto LABEL_58; /*0x193897*/
        LOWORD(v2) = (unsigned __int16)v22 >> 3; /*0x19389b*/
        v6 = 0; /*0x1938a2*/
        if ( (unsigned __int16)((unsigned __int16)v22 >> 3) <= 0x1Fu ) /*0x1938a7*/
        {
          LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v22 >> 3) + 5) & 0x60; /*0x1938b2*/
          v6 = (_BYTE)v2 == 96; /*0x1938b8*/
        }
        if ( v6 ) /*0x1938bb*/
        {
LABEL_58:
          LOBYTE(v2) = v15; /*0x1938c1*/
          if ( v15 ) /*0x1938ca*/
          {
            if ( (v15 & 4) != 0 ) /*0x1938d3*/
            {
              LOBYTE(v2) = v15 & 3; /*0x1938d7*/
              if ( (v15 & 3) != 3 ) /*0x1938db*/
                return v2; /*0x1938db*/
            }
            else
            {
              LOWORD(v2) = (unsigned __int16)v15 >> 3; /*0x1938e6*/
              if ( (unsigned __int16)((unsigned __int16)v15 >> 3) > 0x1Fu ) /*0x1938f0*/
                return v2; /*0x1938f0*/
              LOBYTE(v2) = v15 & 3; /*0x1938f8*/
              if ( (v15 & 3) != 3 ) /*0x1938fc*/
                return v2; /*0x1938fc*/
              LOBYTE(v2) = *((_BYTE *)gdt + 8 * ((unsigned __int16)v15 >> 3) + 5) & 0x60; /*0x19390b*/
              if ( (_BYTE)v2 != 96 ) /*0x19390f*/
                return v2; /*0x19390f*/
            }
LABEL_40:
            *(_BYTE *)(dword_1E875C + 105) = 1; /*0x193915*/
            *(_DWORD *)(active_u + 332) = v14[0] & 1; /*0x193929*/
            *(_DWORD *)(*(_DWORD *)active_u + 28) = v14[1] & 0xFFFAFEFF; /*0x19393f*/
            *(_DWORD *)(v1 + 44) = v14[2]; /*0x193945*/
            *(_DWORD *)(v1 + 32) = v14[3]; /*0x19394b*/
            *(_DWORD *)(v1 + 40) = v14[4]; /*0x193951*/
            *(_DWORD *)(v1 + 36) = v14[5]; /*0x193957*/
            *(_DWORD *)(v1 + 16) = v14[6]; /*0x19395d*/
            *(_DWORD *)(v1 + 20) = v14[7]; /*0x193963*/
            *(_DWORD *)(v1 + 24) = v14[8]; /*0x193969*/
            *(_DWORD *)(v1 + 68) = v14[9]; /*0x19396f*/
            *(_WORD *)(v1 + 72) = v15; /*0x193976*/
            v7 = v16; /*0x19397a*/
            *(_DWORD *)(v1 + 64) = v16; /*0x19397d*/
            v2 = v7 & 0x50DD5 | 0x202; /*0x193987*/
            *(_DWORD *)(v1 + 64) = v2; /*0x19398c*/
            *(_DWORD *)(v1 + 56) = v17; /*0x193992*/
            *(_WORD *)(v1 + 60) = v18; /*0x193999*/
            if ( (v16 & 0x20000) != 0 ) /*0x1939a1*/
            {
              *(_WORD *)(v1 + 12) = 0; /*0x1939a3*/
              *(_WORD *)(v1 + 8) = 0; /*0x1939a9*/
              *(_WORD *)(v1 + 4) = 0; /*0x1939af*/
              *(_WORD *)v1 = 0; /*0x1939b5*/
              *(_WORD *)(v1 + 80) = v19; /*0x1939be*/
              *(_WORD *)(v1 + 76) = v20; /*0x1939c6*/
              *(_WORD *)(v1 + 84) = v21; /*0x1939ce*/
              *(_WORD *)(v1 + 88) = v22; /*0x1939d6*/
              *(_DWORD *)(v1 + 64) |= 0x20000u; /*0x1939da*/
            }
            else
            {
              *(_WORD *)(v1 + 12) = v19; /*0x1939e8*/
              *(_WORD *)(v1 + 8) = v20; /*0x1939f0*/
              *(_WORD *)(v1 + 4) = v21; /*0x1939f8*/
              *(_WORD *)v1 = v22; /*0x193a00*/
            }
            if ( (v14[0] & 2) != 0 ) /*0x193a07*/
            {
              v8 = *(int **)(*(_DWORD *)(v12 + 40) + 236); /*0x193a0f*/
              v9 = 0; /*0x193a15*/
              if ( v8 ) /*0x193a19*/
                v9 = *v8; /*0x193a1b*/
              if ( v9 && (v10 = *(_DWORD *)(v9 + 132), v10 <= 7) ) /*0x193a2a*/
                v2 = v9 + 132 * v10 + 136; /*0x193a33*/
              else
                v2 = 0; /*0x193a3c*/
              if ( v2 ) /*0x193a40*/
                *(_DWORD *)(v2 + 72) = 1; /*0x193a42*/
            }
          }
        }
      }
    }
  }
  return v2; /*0x193a4c*/
}
