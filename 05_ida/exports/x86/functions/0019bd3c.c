/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19bd3c. */
int __cdecl sub_19BD3C(_DWORD *a1, char a2)
{
  int result; // eax
  int v3; // edi
  unsigned int v4; // edx
  char v5; // cl
  int v6; // edi
  char v7; // dl
  _WORD *v8; // ecx
  int v9; // edi
  char v10; // dl
  int v11; // ecx
  int v12; // edi
  char v13; // dl
  __int16 v14; // [esp+10h] [ebp-Ch]
  char *v15; // [esp+14h] [ebp-8h]

  result = (int)sub_19BBE0(a1); /*0x19bd52*/
  if ( a2 > 31 ) /*0x19bd60*/
  {
    v15 = &aEreIlComputerA[12 * a2]; /*0x19bd73*/
    v3 = 8 * a1[42] + a1[35]; /*0x19bd89*/
    result = a1[36] + 12 * a1[41]; /*0x19bd9a*/
    v4 = a1[7]; /*0x19bd9d*/
    if ( v4 > 3 ) /*0x19bda3*/
    {
      if ( v4 == 4 ) /*0x19bdbb*/
      {
        v11 = a1[45]; /*0x19bf27*/
        result = a1[6] + a1[4] * result + 4 * v3; /*0x19bf34*/
        v12 = 12; /*0x19bf37*/
        do /*0x19bf8a*/
        {
          v13 = *v15++; /*0x19bf3f*/
          if ( v13 < 0 ) /*0x19bf47*/
            *(_DWORD *)result = v11; /*0x19bf49*/
          if ( (v13 & 0x40) != 0 ) /*0x19bf4e*/
            *(_DWORD *)(result + 4) = v11; /*0x19bf50*/
          if ( (v13 & 0x20) != 0 ) /*0x19bf56*/
            *(_DWORD *)(result + 8) = v11; /*0x19bf58*/
          if ( (v13 & 0x10) != 0 ) /*0x19bf5e*/
            *(_DWORD *)(result + 12) = v11; /*0x19bf60*/
          if ( (v13 & 8) != 0 ) /*0x19bf66*/
            *(_DWORD *)(result + 16) = v11; /*0x19bf68*/
          if ( (v13 & 4) != 0 ) /*0x19bf6e*/
            *(_DWORD *)(result + 20) = v11; /*0x19bf70*/
          if ( (v13 & 2) != 0 ) /*0x19bf76*/
            *(_DWORD *)(result + 24) = v11; /*0x19bf78*/
          if ( (v13 & 1) != 0 ) /*0x19bf7e*/
            *(_DWORD *)(result + 28) = v11; /*0x19bf80*/
          result += a1[4]; /*0x19bf86*/
          --v12; /*0x19bf89*/
        }
        while ( v12 ); /*0x19bf8a*/
      }
    }
    else if ( v4 >= 2 ) /*0x19bda8*/
    {
      v14 = *((_WORD *)a1 + 90); /*0x19be42*/
      result = a1[6] + a1[4] * result; /*0x19be77*/
      v8 = (_WORD *)(result + 2 * v3); /*0x19be7a*/
      v9 = 12; /*0x19bea0*/
      do /*0x19bf1e*/
      {
        v10 = *v15++; /*0x19beab*/
        if ( v10 < 0 ) /*0x19beb3*/
          *v8 = v14; /*0x19beb9*/
        if ( (v10 & 0x40) != 0 ) /*0x19bebf*/
          v8[1] = v14; /*0x19bec5*/
        if ( (v10 & 0x20) != 0 ) /*0x19becc*/
          v8[2] = v14; /*0x19bed2*/
        if ( (v10 & 0x10) != 0 ) /*0x19bed9*/
          v8[3] = v14; /*0x19bedf*/
        if ( (v10 & 8) != 0 ) /*0x19bee6*/
          v8[4] = v14; /*0x19beec*/
        if ( (v10 & 4) != 0 ) /*0x19bef3*/
          v8[5] = v14; /*0x19bef9*/
        if ( (v10 & 2) != 0 ) /*0x19bf00*/
          v8[6] = v14; /*0x19bf06*/
        if ( (v10 & 1) != 0 ) /*0x19bf0d*/
          v8[7] = v14; /*0x19bf13*/
        v8 = (_WORD *)((char *)v8 + a1[4]); /*0x19bf1a*/
        --v9; /*0x19bf1d*/
      }
      while ( v9 ); /*0x19bf1e*/
    }
    else if ( v4 == 1 ) /*0x19bdb1*/
    {
      v5 = *((_BYTE *)a1 + 180); /*0x19bdcb*/
      result = v3 + a1[6] + a1[4] * result; /*0x19bdd8*/
      v6 = 12; /*0x19bdda*/
      do /*0x19be2e*/
      {
        v7 = *v15++; /*0x19bde3*/
        if ( v7 < 0 ) /*0x19bdeb*/
          *(_BYTE *)result = v5; /*0x19bded*/
        if ( (v7 & 0x40) != 0 ) /*0x19bdf2*/
          *(_BYTE *)(result + 1) = v5; /*0x19bdf4*/
        if ( (v7 & 0x20) != 0 ) /*0x19bdfa*/
          *(_BYTE *)(result + 2) = v5; /*0x19bdfc*/
        if ( (v7 & 0x10) != 0 ) /*0x19be02*/
          *(_BYTE *)(result + 3) = v5; /*0x19be04*/
        if ( (v7 & 8) != 0 ) /*0x19be0a*/
          *(_BYTE *)(result + 4) = v5; /*0x19be0c*/
        if ( (v7 & 4) != 0 ) /*0x19be12*/
          *(_BYTE *)(result + 5) = v5; /*0x19be14*/
        if ( (v7 & 2) != 0 ) /*0x19be1a*/
          *(_BYTE *)(result + 6) = v5; /*0x19be1c*/
        if ( (v7 & 1) != 0 ) /*0x19be22*/
          *(_BYTE *)(result + 7) = v5; /*0x19be24*/
        result += a1[4]; /*0x19be2a*/
        --v6; /*0x19be2d*/
      }
      while ( v6 ); /*0x19be2e*/
    }
    ++a1[42]; /*0x19bf8f*/
  }
  return result; /*0x19bf98*/
}
