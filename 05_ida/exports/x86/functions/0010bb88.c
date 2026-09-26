/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bb88. */
char __cdecl sub_10BB88(_BYTE *a1, _BYTE *a2)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax
  _BYTE *v5; // esi
  int v6; // eax
  _BYTE *v7; // ebx
  _BYTE *v8; // edi
  _BYTE *v9; // ecx
  _BYTE *v10; // esi
  _BYTE *v11; // ebx
  _BYTE *v12; // edi
  _BYTE *v13; // ecx
  _BYTE *v14; // esi
  int v15; // ecx
  int v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+10h] [ebp-14h]
  _BYTE *v20; // [esp+20h] [ebp-4h]

  v2 = a2 - a1; /*0x10bb94*/
  do /*0x10bd36*/
  {
    v3 = (v2 / dword_1DAC08) >> 1; /*0x10bba3*/
    LOBYTE(v4) = v3 * dword_1DAC08; /*0x10bbad*/
    v5 = &a1[v3 * dword_1DAC08]; /*0x10bbb3*/
    v20 = v5; /*0x10bbb5*/
    if ( dword_1DAC10 <= v2 ) /*0x10bbbe*/
    {
      v6 = dword_1DAC04(a1, &a1[v3 * dword_1DAC08]); /*0x10bbca*/
      v7 = v5; /*0x10bbd1*/
      if ( v6 > 0 ) /*0x10bbd5*/
        v7 = a1; /*0x10bbd7*/
      v8 = &a2[-dword_1DAC08]; /*0x10bbdd*/
      v4 = dword_1DAC04(v7, &a2[-dword_1DAC08]); /*0x10bbea*/
      if ( v4 > 0 ) /*0x10bbf1*/
      {
        v9 = a1; /*0x10bbf3*/
        if ( v7 == a1 ) /*0x10bbf8*/
          v9 = v5; /*0x10bbfa*/
        v7 = v9; /*0x10bbfc*/
        v4 = dword_1DAC04(v9, v8); /*0x10bc05*/
        if ( v4 < 0 ) /*0x10bc0c*/
          v7 = v8; /*0x10bc0e*/
      }
      if ( v7 != v5 ) /*0x10bc12*/
      {
        v18 = dword_1DAC08; /*0x10bc1a*/
        do /*0x10bc30*/
        {
          LOBYTE(v4) = *v5; /*0x10bc20*/
          *v5++ = *v7; /*0x10bc27*/
          *v7++ = v4; /*0x10bc2a*/
          --v18; /*0x10bc2d*/
        }
        while ( v18 ); /*0x10bc30*/
      }
    }
    v10 = a1; /*0x10bc32*/
    v11 = &a2[-dword_1DAC08]; /*0x10bc38*/
    while ( 2 ) /*0x10bc5f*/
    {
      while ( v20 > v10 ) /*0x10bc5f*/
      {
        v4 = dword_1DAC04(v10, v20); /*0x10bc4b*/
        if ( v4 > 0 ) /*0x10bc54*/
          break; /*0x10bc54*/
        v10 += dword_1DAC08; /*0x10bc56*/
      }
      while ( v20 < v11 ) /*0x10bc9d*/
      {
        v4 = dword_1DAC04(v20, v11); /*0x10bc6f*/
        if ( v4 > 0 ) /*0x10bc78*/
        {
          v12 = &v10[dword_1DAC08]; /*0x10bc84*/
          v13 = v11; /*0x10bc8b*/
          if ( v20 == v10 ) /*0x10bc89*/
            v20 = v11; /*0x10bcd6*/
          else
            v11 -= dword_1DAC08; /*0x10bc8d*/
          goto LABEL_25; /*0x10bc8f*/
        }
        v11 -= dword_1DAC08; /*0x10bc94*/
      }
      if ( v20 != v10 ) /*0x10bca2*/
      {
        v13 = v20; /*0x10bca4*/
        v20 = v10; /*0x10bca7*/
        v12 = v10; /*0x10bcaa*/
        v11 -= dword_1DAC08; /*0x10bcac*/
LABEL_25:
        v19 = dword_1DAC08; /*0x10bcb2*/
        do /*0x10bccc*/
        {
          LOBYTE(v4) = *v10; /*0x10bcbc*/
          *v10++ = *v13; /*0x10bcc3*/
          *v13++ = v4; /*0x10bcc6*/
          --v19; /*0x10bcc9*/
        }
        while ( v19 ); /*0x10bccc*/
        v10 = v12; /*0x10bcce*/
        continue; /*0x10bcd0*/
      }
      break;
    }
    v14 = &v20[dword_1DAC08]; /*0x10bce1*/
    v2 = v20 - a1; /*0x10bce9*/
    v15 = a2 - &v20[dword_1DAC08]; /*0x10bcef*/
    if ( v20 - a1 > v15 ) /*0x10bcf3*/
    {
      if ( dword_1DAC0C <= v15 ) /*0x10bd1e*/
        LOBYTE(v4) = sub_10BB88(&v20[dword_1DAC08], a2); /*0x10bd25*/
      a2 = v20; /*0x10bd2d*/
    }
    else
    {
      if ( dword_1DAC0C <= v2 ) /*0x10bcfb*/
      {
        v17 = a2 - &v20[dword_1DAC08]; /*0x10bd02*/
        LOBYTE(v4) = sub_10BB88(a1, v20); /*0x10bd05*/
        v15 = v17; /*0x10bd0d*/
      }
      a1 = v14; /*0x10bd10*/
      v2 = v15; /*0x10bd13*/
    }
  }
  while ( dword_1DAC0C <= v2 ); /*0x10bd36*/
  return v4; /*0x10bd3f*/
}
