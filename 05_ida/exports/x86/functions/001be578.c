/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be578. */
int __cdecl audio_mix(__int16 *a1, _BYTE *a2, size_t a3, int a4, int a5)
{
  __int16 *v5; // ebx
  _BYTE *v6; // ecx
  _BYTE *v8; // edi
  _BYTE *v9; // ebx
  size_t v10; // ecx
  size_t v11; // esi
  int v12; // eax
  size_t v13; // esi
  int v14; // eax
  unsigned __int8 *v15; // edi
  _BYTE *v16; // ebx
  size_t v17; // esi
  int v18; // eax
  int v19; // [esp+Ch] [ebp-4h]

  v5 = a1; /*0x1be581*/
  v6 = a2; /*0x1be584*/
  v19 = 0; /*0x1be58d*/
  if ( !a3 ) /*0x1be596*/
    return 0; /*0x1be59a*/
  if ( a5 ) /*0x1be5a4*/
  {
    if ( a4 == 3 ) /*0x1be5a9*/
    {
      v8 = a1; /*0x1be5ab*/
      v9 = a2; /*0x1be5ad*/
      v10 = a3 - 1; /*0x1be5af*/
      do /*0x1be5cf*/
      {
        *v9++ = *v8 & 0x7F | *v8 ^ 0x80; /*0x1be5c7*/
        ++v8; /*0x1be5ca*/
        --v10; /*0x1be5cb*/
      }
      while ( v10 != -1 ); /*0x1be5cf*/
    }
    else
    {
      bcopy(a1, a2, a3); /*0x1be5db*/
    }
    return v19; /*0x1be5cf*/
  }
  if ( a4 == 1 ) /*0x1be5eb*/
  {
    v15 = (unsigned __int8 *)a1; /*0x1be6a8*/
    v16 = a2; /*0x1be6aa*/
    v17 = a3 - 1; /*0x1be6ac*/
    while ( 1 ) /*0x1be6ca*/
    {
      v18 = audio_muLaw[(unsigned __int8)*v16] + audio_muLaw[*v15++]; /*0x1be6ca*/
      if ( v18 <= 0x7FFF ) /*0x1be6d2*/
      {
        if ( v18 >= -32768 ) /*0x1be6e1*/
        {
          *v16++ = audio_shortToMulaw(v18); /*0x1be6f3*/
          goto LABEL_40; /*0x1be6f5*/
        }
        *v16 = 0; /*0x1be6e3*/
      }
      else
      {
        *v16 = 0x80; /*0x1be6d4*/
      }
      ++v16; /*0x1be6e6*/
      ++v19; /*0x1be6e7*/
LABEL_40:
      if ( --v17 == -1 ) /*0x1be6fd*/
        return v19; /*0x1be6fd*/
    }
  }
  if ( a4 > 1 ) /*0x1be5f1*/
  {
    if ( a4 != 3 ) /*0x1be5ff*/
      goto LABEL_42; /*0x1be5ff*/
    v13 = a3 - 1; /*0x1be658*/
    while ( 1 ) /*0x1be675*/
    {
      v14 = (char)(*v6 & 0x7F | *v6 ^ 0x80) + *(char *)v5; /*0x1be675*/
      v5 = (__int16 *)((char *)v5 + 1); /*0x1be677*/
      if ( v14 <= 127 ) /*0x1be67b*/
      {
        if ( v14 >= -128 ) /*0x1be687*/
        {
          *v6++ = v14 & 0x7F | v14 ^ 0x80; /*0x1be69d*/
          goto LABEL_31; /*0x1be69f*/
        }
        *v6 = 0; /*0x1be689*/
      }
      else
      {
        *v6 = -1; /*0x1be67d*/
      }
      ++v6; /*0x1be68c*/
      ++v19; /*0x1be68d*/
LABEL_31:
      if ( --v13 == -1 ) /*0x1be6a4*/
        return v19; /*0x1be6a4*/
    }
  }
  if ( a4 )
  {
LABEL_42:
    IOLog((int)"Audio: unrecognized format %d in mix\n", a4);
    return v19; /*0x1be70a*/
  }
  v11 = (a3 >> 1) - 1; /*0x1be60a*/
  if ( a3 >> 1 ) /*0x1be608*/
  {
    do /*0x1be61a*/
    {
      v12 = *(__int16 *)v6 + *v5++; /*0x1be61a*/
      if ( v12 <= 0x7FFF ) /*0x1be624*/
      {
        if ( v12 >= -32768 ) /*0x1be635*/
        {
          *(_WORD *)v6 = v12; /*0x1be644*/
          v6 += 2; /*0x1be647*/
          goto LABEL_22; /*0x1be647*/
        }
        *(_WORD *)v6 = 0x8000; /*0x1be637*/
      }
      else
      {
        *(_WORD *)v6 = 0x7FFF; /*0x1be626*/
      }
      v6 += 2; /*0x1be63c*/
      ++v19; /*0x1be63f*/
LABEL_22:
      --v11; /*0x1be64a*/
    }
    while ( v11 != -1 ); /*0x1be61a*/
  }
  return v19; /*0x1be715*/
}
