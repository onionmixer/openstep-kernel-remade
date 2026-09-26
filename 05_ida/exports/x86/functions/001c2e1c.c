/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2e1c. */
id __cdecl -[IOFrameBufferDisplay hideCursor:](IOFrameBufferDisplay *self, SEL a2, int a3)
{
  _BYTE *priv; // edx
  char v5; // al
  unsigned int v6; // edx
  $514E7C50D28E54AB164B6500F83867A3 *v7; // eax
  __int16 *v8; // edi
  int v9; // ebx
  _WORD *v10; // ecx
  int v11; // ebx
  _WORD *v12; // edi
  __int16 v13; // dx
  __int16 v14; // ax
  $514E7C50D28E54AB164B6500F83867A3 *v15; // eax
  __int16 *v16; // edi
  int v17; // ebx
  _BYTE *v18; // eax
  _BYTE *v19; // edi
  __int16 v20; // dx
  __int16 v21; // cx
  $514E7C50D28E54AB164B6500F83867A3 *v22; // edi
  _DWORD *v23; // eax
  _DWORD *v24; // ecx
  int v25; // edi
  _DWORD *v26; // eax
  int v27; // edx
  int v28; // [esp+Ch] [ebp-20h]
  int v29; // [esp+Ch] [ebp-20h]
  int v30; // [esp+Ch] [ebp-20h]
  int v31; // [esp+Ch] [ebp-20h]
  int v32; // [esp+10h] [ebp-1Ch]
  int v33; // [esp+10h] [ebp-1Ch]
  int v34; // [esp+10h] [ebp-1Ch]
  int var2; // [esp+18h] [ebp-14h]
  int v36; // [esp+18h] [ebp-14h]

  if ( !ev_try_lock((volatile signed __int32 *)self->priv + 1) ) /*0x1c2e32*/
    return self; /*0x1c2e41*/
  priv = self->priv; /*0x1c2e4b*/
  v5 = priv[8]; /*0x1c2e51*/
  priv[8] = v5 + 1; /*0x1c2e58*/
  if ( !v5 ) /*0x1c2e5d*/
  {
    v6 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 6); /*0x1c2e76*/
    if ( v6 > 3 ) /*0x1c2e7c*/
    {
      if ( v6 == 4 ) /*0x1c2e93*/
      {
        v22 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c2ffc*/
        v23 = self->priv; /*0x1c2ffe*/
        v30 = v23[3]; /*0x1c3007*/
        v34 = v23[4]; /*0x1c300d*/
        var2 = v22->var2; /*0x1c3013*/
        v24 = (char *)v22->var5 /*0x1c3043*/
            + 4 * var2 * ((__int16)v34 - *((__int16 *)v23 + 26))
            + 4 * ((__int16)v30 - *((__int16 *)v23 + 24));
        v25 = (v30 >> 16) - (__int16)v30; /*0x1c304e*/
        v36 = var2 - v25; /*0x1c3050*/
        v26 = v23 + 1042; /*0x1c3053*/
        v27 = (v34 >> 16) - (__int16)v34 - 1; /*0x1c3064*/
        if ( v34 >> 16 != (__int16)v34 ) /*0x1c3068*/
        {
          do /*0x1c3099*/
          {
            v31 = v25 - 1; /*0x1c3077*/
            if ( v25 ) /*0x1c307d*/
            {
              do /*0x1c3091*/
              {
                *v24++ = *v26++; /*0x1c3082*/
                --v31; /*0x1c308a*/
              }
              while ( v31 != -1 ); /*0x1c3091*/
            }
            v24 += v36; /*0x1c3093*/
            --v27; /*0x1c3095*/
          }
          while ( v27 != -1 ); /*0x1c3099*/
        }
        goto LABEL_24; /*0x1c3099*/
      }
    }
    else if ( v6 == 1 ) /*0x1c2e81*/
    {
      v15 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c2f53*/
      v16 = (__int16 *)self->priv; /*0x1c2f58*/
      v29 = *((_DWORD *)v16 + 3); /*0x1c2f61*/
      v33 = *((_DWORD *)v16 + 4); /*0x1c2f67*/
      v17 = v15->var2; /*0x1c2f6a*/
      v18 = (char *)v15->var5 + v17 * ((__int16)v33 - v16[26]) + (__int16)v29 - v16[24]; /*0x1c2f8b*/
      v19 = v16 + 1060; /*0x1c2fa4*/
      v20 = HIWORD(v33) - v33 - 1; /*0x1c2fb7*/
      if ( HIWORD(v33) != (_WORD)v33 ) /*0x1c2fbd*/
      {
        do /*0x1c2fe3*/
        {
          v21 = HIWORD(v29) - v29; /*0x1c2fc4*/
          while ( --v21 != -1 ) /*0x1c2fd2*/
            *v18++ = *v19++; /*0x1c2fce*/
          v18 += v17 - (__int16)(HIWORD(v29) - v29); /*0x1c2fda*/
          --v20; /*0x1c2fdd*/
        }
        while ( v20 != -1 ); /*0x1c2fe3*/
      }
      goto LABEL_24; /*0x1c2fe3*/
    }
    v7 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c2ea4*/
    v8 = (__int16 *)self->priv; /*0x1c2ea9*/
    v28 = *((_DWORD *)v8 + 3); /*0x1c2eb2*/
    v32 = *((_DWORD *)v8 + 4); /*0x1c2eb8*/
    v9 = v7->var2; /*0x1c2ebb*/
    v10 = (char *)v7->var5 + 2 * v9 * ((__int16)v32 - v8[26]) + 2 * ((__int16)v28 - v8[24]); /*0x1c2edf*/
    v11 = v9 - (__int16)(HIWORD(v28) - v28); /*0x1c2ef3*/
    v12 = v8 + 1060; /*0x1c2ef8*/
    v13 = HIWORD(v32) - v32 - 1; /*0x1c2f0b*/
    if ( HIWORD(v32) != (_WORD)v32 ) /*0x1c2f11*/
    {
      do /*0x1c2f40*/
      {
        v14 = HIWORD(v28) - v28; /*0x1c2f1c*/
        while ( --v14 != -1 ) /*0x1c2f30*/
          *v10++ = *v12++; /*0x1c2f27*/
        v10 += v11; /*0x1c2f38*/
        --v13; /*0x1c2f3a*/
      }
      while ( v13 != -1 ); /*0x1c2f40*/
    }
  }
LABEL_24:
  ev_unlock((_DWORD *)self->priv + 1); /*0x1c309b*/
  return self; /*0x1c30b3*/
}
