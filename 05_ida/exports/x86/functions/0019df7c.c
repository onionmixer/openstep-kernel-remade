/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19df7c. */
void __cdecl sub_19DF7C(int a1, unsigned int a2, int a3, int a4, const char *a5)
{
  unsigned int *v5; // ebx
  unsigned int v6; // eax
  int i; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edx
  _BYTE *v11; // edx
  int v12; // eax
  _WORD *v13; // edx
  int v14; // eax
  unsigned int *v15; // edx
  int v16; // eax
  int v17; // [esp+Ch] [ebp-8h]

  v5 = *(unsigned int **)(a1 + 28); /*0x19df88*/
  v6 = v5[7]; /*0x19df8b*/
  if ( v6 == 2 ) /*0x19df91*/
  {
    v5[43] = 22015; /*0x19e034*/
    v5[44] = 0xFFFF; /*0x19e03e*/
    v5[45] = 15; /*0x19e048*/
    v5[46] = 21855; /*0x19e052*/
    v5[47] = 43695; /*0x19e05c*/
  }
  else if ( v6 > 2 ) /*0x19df97*/
  {
    if ( v6 == 3 ) /*0x19dfa7*/
    {
      v5[43] = 10591; /*0x19e068*/
      v5[44] = 31710; /*0x19e072*/
      v5[45] = 0; /*0x19e07c*/
      v5[46] = 10570; /*0x19e086*/
      v5[47] = 21140; /*0x19e090*/
    }
    else if ( v6 == 4 ) /*0x19dfb0*/
    {
      v5[43] = -11184641; /*0x19e09c*/
      v5[44] = -1; /*0x19e0a6*/
      v5[45] = -16777216; /*0x19e0b0*/
      v5[46] = -11184811; /*0x19e0ba*/
      v5[47] = -5592406; /*0x19e0c4*/
    }
  }
  else if ( v6 == 1 ) /*0x19df9c*/
  {
    if ( v5[8] == 1 ) /*0x19dfc0*/
    {
      v5[43] = 85; /*0x19dfc2*/
      v5[44] = 255; /*0x19dfcc*/
      v5[45] = 0; /*0x19dfd6*/
      v5[46] = 85; /*0x19dfe0*/
      v5[47] = 170; /*0x19dfea*/
    }
    else
    {
      v5[43] = 99; /*0x19dffc*/
      v5[44] = 239; /*0x19e006*/
      v5[45] = 0; /*0x19e010*/
      v5[46] = 245; /*0x19e01a*/
      v5[47] = 250; /*0x19e024*/
    }
  }
  v5[54] = 0; /*0x19e0ce*/
  for ( i = 2; i >= 0; --i ) /*0x19e0d8*/
    *((_BYTE *)v5 + i + 220) = 0; /*0x19e0e0*/
  v5[56] = (unsigned int)v5 + 221; /*0x19e0f1*/
  if ( a3 && *v5 != 3 ) /*0x19e104*/
  {
    v8 = v5[43]; /*0x19e10a*/
    v17 = v5[2] * v5[3]; /*0x19e117*/
    v9 = v5[7]; /*0x19e11a*/
    if ( v9 > 3 ) /*0x19e120*/
    {
      if ( v9 != 4 ) /*0x19e133*/
        goto LABEL_23; /*0x19e133*/
    }
    else if ( !v9 ) /*0x19e125*/
    {
LABEL_23:
      panic(aFbconsolePixel); /*0x19e13c*/
    }
    v10 = v5[7]; /*0x19e152*/
    if ( v10 > 3 ) /*0x19e158*/
    {
      if ( v10 != 4 ) /*0x19e16b*/
LABEL_39:
        panic(aFbconsoleFillB); /*0x19e1b4*/
      v15 = (unsigned int *)v5[6]; /*0x19e19c*/
      v16 = v17 - 1; /*0x19e19e*/
      if ( v17 ) /*0x19e1a2*/
      {
        do /*0x19e1ad*/
        {
          *v15++ = v8; /*0x19e1a4*/
          --v16; /*0x19e1a9*/
        }
        while ( v16 != -1 ); /*0x19e1ad*/
      }
    }
    else if ( v10 >= 2 ) /*0x19e15d*/
    {
      v13 = (_WORD *)v5[6]; /*0x19e184*/
      v14 = v17 - 1; /*0x19e186*/
      if ( v17 ) /*0x19e18a*/
      {
        do /*0x19e196*/
        {
          *v13++ = v8; /*0x19e18c*/
          --v14; /*0x19e192*/
        }
        while ( v14 != -1 ); /*0x19e196*/
      }
    }
    else
    {
      if ( v10 != 1 ) /*0x19e162*/
        goto LABEL_39; /*0x19e162*/
      v11 = (_BYTE *)v5[6]; /*0x19e170*/
      v12 = v17 - 1; /*0x19e172*/
      if ( v17 ) /*0x19e176*/
      {
        do /*0x19e17f*/
        {
          *v11++ = v8; /*0x19e178*/
          --v12; /*0x19e17b*/
        }
        while ( v12 != -1 ); /*0x19e17f*/
      }
    }
  }
  *v5 = a2; /*0x19e1c4*/
  if ( a2 != 2 ) /*0x19e1c9*/
  {
    if ( a2 > 2 ) /*0x19e1cb*/
    {
      if ( a2 != 3 ) /*0x19e1d8*/
LABEL_48:
        panic(aFbconsoleFbini); /*0x19e228*/
      sub_19D254(v5, 320, 200, a5, a4, 1); /*0x19e221*/
    }
    else
    {
      if ( a2 != 1 ) /*0x19e1d0*/
        goto LABEL_48; /*0x19e1d0*/
      sub_19D254(v5, (int)(3 * v5[1]) / 4, (int)(3 * v5[2]) / 4, a5, a4, 0); /*0x19e208*/
    }
  }
}
