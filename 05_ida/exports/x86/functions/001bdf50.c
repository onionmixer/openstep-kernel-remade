/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bdf50. */
int __cdecl audio_scaleSamples(char *a1, _BYTE *a2, unsigned int a3, int a4, int a5, int a6, int a7)
{
  char *v7; // ebx
  _BYTE *v8; // ecx
  int v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // esi
  unsigned int v13; // eax
  __int16 *v14; // ebx
  _WORD *v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // esi
  int v18; // eax
  int v19; // esi
  int v20; // eax
  char *v21; // ebx
  _BYTE *v22; // ecx
  int v23; // eax
  _BYTE *v24; // ebx
  unsigned int v25; // esi
  int v26; // eax
  int v27; // esi
  int v28; // eax
  _BYTE *v29; // ebx
  int v30; // eax
  char *v32; // [esp+14h] [ebp-Ch]
  unsigned __int8 *v33; // [esp+14h] [ebp-Ch]
  int v34; // [esp+18h] [ebp-8h]
  int v35; // [esp+18h] [ebp-8h]
  int v36; // [esp+1Ch] [ebp-4h]
  int v37; // [esp+1Ch] [ebp-4h]

  v7 = a1; /*0x1bdf59*/
  v8 = a2; /*0x1bdf5c*/
  v9 = 0; /*0x1bdf65*/
  if ( a4 == 1 ) /*0x1bdf6a*/
  {
    v37 = a6 >> 8; /*0x1be11e*/
    v35 = a7 >> 8; /*0x1be127*/
    v32 = a1; /*0x1be12a*/
    v24 = a2; /*0x1be12d*/
    if ( a5 != 1 ) /*0x1be133*/
    {
      if ( a5 != 2 ) /*0x1be139*/
        return v9; /*0x1be139*/
      v27 = (a3 >> 1) - 1; /*0x1be1ae*/
      if ( !(a3 >> 1) ) /*0x1be1ac*/
        return v9; /*0x1be1b2*/
      while ( 1 ) /*0x1be1ca*/
      {
        v28 = (v37 * audio_muLaw[(unsigned __int8)*v32]) >> 7; /*0x1be1ca*/
        v33 = (unsigned __int8 *)(v32 + 1); /*0x1be1ce*/
        if ( v28 > 0x7FFF ) /*0x1be1d6*/
          break; /*0x1be1d6*/
        if ( v28 < -32768 ) /*0x1be1e5*/
        {
          *v24 = 0; /*0x1be1e7*/
          goto LABEL_66; /*0x1be1e7*/
        }
        *v24 = audio_shortToMulaw(v28); /*0x1be1f7*/
        v29 = v24 + 1; /*0x1be1f9*/
LABEL_68:
        v30 = (v35 * audio_muLaw[*v33]) >> 7; /*0x1be1fd*/
        v32 = (char *)(v33 + 1); /*0x1be213*/
        if ( v30 <= 0x7FFF ) /*0x1be21b*/
        {
          if ( v30 >= -32768 ) /*0x1be229*/
          {
            *v29 = audio_shortToMulaw(v30); /*0x1be23b*/
            v24 = v29 + 1; /*0x1be23d*/
            goto LABEL_74; /*0x1be23d*/
          }
          *v29 = 0; /*0x1be22b*/
        }
        else
        {
          *v29 = 0x80; /*0x1be21d*/
        }
        v24 = v29 + 1; /*0x1be22e*/
        ++v9; /*0x1be22f*/
LABEL_74:
        if ( --v27 == -1 ) /*0x1be245*/
          return v9; /*0x1be245*/
      }
      *v24 = 0x80; /*0x1be1d8*/
LABEL_66:
      v29 = v24 + 1; /*0x1be1ea*/
      ++v9; /*0x1be1eb*/
      goto LABEL_68; /*0x1be1ec*/
    }
    v25 = a3 - 1; /*0x1be152*/
    if ( !a3 ) /*0x1be156*/
      return v9; /*0x1be156*/
    while ( 1 ) /*0x1be16e*/
    {
      v26 = ((v35 + v37) / 2 * audio_muLaw[(unsigned __int8)*v32++]) >> 7; /*0x1be16e*/
      if ( v26 <= 0x7FFF ) /*0x1be17a*/
      {
        if ( v26 >= -32768 ) /*0x1be189*/
        {
          *v24++ = audio_shortToMulaw(v26); /*0x1be19b*/
          goto LABEL_59; /*0x1be19d*/
        }
        *v24 = 0; /*0x1be18b*/
      }
      else
      {
        *v24 = 0x80; /*0x1be17c*/
      }
      ++v24; /*0x1be18e*/
      ++v9; /*0x1be18f*/
LABEL_59:
      if ( --v25 == -1 ) /*0x1be1a5*/
        return v9; /*0x1be1a5*/
    }
  }
  if ( a4 > 1 ) /*0x1bdf70*/
  {
    if ( a4 != 3 ) /*0x1bdf7f*/
      goto LABEL_76; /*0x1bdf7f*/
    v36 = a6 >> 8; /*0x1be046*/
    v34 = a7 >> 8; /*0x1be04f*/
    if ( a5 != 1 ) /*0x1be056*/
    {
      if ( a5 != 2 ) /*0x1be05c*/
        return v9; /*0x1be05c*/
      v19 = (a3 >> 1) - 1; /*0x1be0b6*/
      if ( !(a3 >> 1) ) /*0x1be0b4*/
        return v9; /*0x1be0ba*/
      while ( 1 ) /*0x1be0c7*/
      {
        v20 = (v36 * *v7) >> 7; /*0x1be0c7*/
        v21 = v7 + 1; /*0x1be0ca*/
        if ( v20 > 127 ) /*0x1be0ce*/
          break; /*0x1be0ce*/
        if ( v20 < -128 ) /*0x1be0db*/
        {
          *v8 = 0x80; /*0x1be0dd*/
          goto LABEL_39; /*0x1be0dd*/
        }
        *v8 = v20; /*0x1be0e4*/
        v22 = v8 + 1; /*0x1be0e6*/
LABEL_41:
        v23 = (v34 * *v21) >> 7; /*0x1be0e7*/
        v7 = v21 + 1; /*0x1be0f1*/
        if ( v23 <= 127 ) /*0x1be0f5*/
        {
          if ( v23 >= -128 ) /*0x1be0ff*/
          {
            *v22 = v23; /*0x1be108*/
            v8 = v22 + 1; /*0x1be10a*/
            goto LABEL_47; /*0x1be10a*/
          }
          *v22 = 0x80; /*0x1be101*/
        }
        else
        {
          *v22 = 127; /*0x1be0f7*/
        }
        v8 = v22 + 1; /*0x1be104*/
        ++v9; /*0x1be105*/
LABEL_47:
        if ( --v19 == -1 ) /*0x1be10f*/
          return v9; /*0x1be10f*/
      }
      *v8 = 127; /*0x1be0d0*/
LABEL_39:
      v22 = v8 + 1; /*0x1be0e0*/
      ++v9; /*0x1be0e1*/
      goto LABEL_41; /*0x1be0e2*/
    }
    v17 = a3 - 1; /*0x1be076*/
    if ( !a3 ) /*0x1be07a*/
      return v9; /*0x1be07a*/
    while ( 1 ) /*0x1be087*/
    {
      v18 = ((v34 + v36) / 2 * *v7++) >> 7; /*0x1be087*/
      if ( v18 <= 127 ) /*0x1be08e*/
      {
        if ( v18 >= -128 ) /*0x1be09b*/
        {
          *v8++ = v18; /*0x1be0a4*/
          goto LABEL_32; /*0x1be0a6*/
        }
        *v8 = 0x80; /*0x1be09d*/
      }
      else
      {
        *v8 = 127; /*0x1be090*/
      }
      ++v8; /*0x1be0a0*/
      ++v9; /*0x1be0a1*/
LABEL_32:
      if ( --v17 == -1 ) /*0x1be0ab*/
        return v9; /*0x1be0ab*/
    }
  }
  if ( a4 )
  {
LABEL_76:
    IOLog((int)"Audio: unrecognized format %d in scaleSamples\n", a4);
    return v9; /*0x1be256*/
  }
  if ( a5 == 1 ) /*0x1bdf92*/
  {
    v10 = (a3 >> 1) - 1; /*0x1bdfb2*/
    if ( !(a3 >> 1) ) /*0x1bdfb6*/
      return v9; /*0x1bdfb6*/
    while ( 1 ) /*0x1bdfc3*/
    {
      v11 = ((a7 + a6) / 2 * *(__int16 *)v7) >> 15; /*0x1bdfc3*/
      v7 += 2; /*0x1bdfc6*/
      if ( v11 <= 0x7FFF ) /*0x1bdfce*/
      {
        if ( v11 >= -32768 ) /*0x1bdfdd*/
        {
          *(_WORD *)v8 = v11; /*0x1bdfec*/
          v8 += 2; /*0x1bdfef*/
          goto LABEL_17; /*0x1bdfef*/
        }
        *(_WORD *)v8 = 0x8000; /*0x1bdfdf*/
      }
      else
      {
        *(_WORD *)v8 = 0x7FFF; /*0x1bdfd0*/
      }
      v8 += 2; /*0x1bdfe4*/
      ++v9; /*0x1bdfe7*/
LABEL_17:
      if ( --v10 == -1 ) /*0x1bdff6*/
        return v9; /*0x1bdff6*/
    }
  }
  if ( a5 == 2 ) /*0x1bdf98*/
  {
    v12 = (a3 >> 2) - 1; /*0x1be002*/
    if ( a3 >> 2 ) /*0x1be000*/
    {
      do /*0x1be036*/
      {
        v13 = a6 * *(__int16 *)v7; /*0x1be00f*/
        v14 = (__int16 *)(v7 + 2); /*0x1be013*/
        *(_WORD *)v8 = v13 >> 15; /*0x1be019*/
        v15 = v8 + 2; /*0x1be01c*/
        v16 = a7 * *v14; /*0x1be022*/
        v7 = (char *)(v14 + 1); /*0x1be026*/
        *v15 = v16 >> 15; /*0x1be02c*/
        v8 = v15 + 1; /*0x1be02f*/
        --v12; /*0x1be032*/
      }
      while ( v12 != -1 ); /*0x1be036*/
    }
  }
  return v9; /*0x1be260*/
}
