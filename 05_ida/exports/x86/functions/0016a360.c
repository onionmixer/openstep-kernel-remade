/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a360. */
_DWORD *__cdecl sub_16A360(_DWORD *a1, unsigned int a2)
{
  int v2; // ebx
  _DWORD *result; // eax
  unsigned int v4; // esi
  signed int v5; // edx
  _DWORD *v6; // eax
  int v7; // ebx
  signed int v8; // edx
  int *v9; // esi
  _DWORD *v10; // edx
  _DWORD *v11; // eax
  int v12; // [esp+Ch] [ebp-8h]
  _DWORD *v13; // [esp+10h] [ebp-4h]

  v2 = a1[2]; /*0x16a36c*/
  if ( !v2 ) /*0x16a371*/
    return nullptr; /*0x16a375*/
  v4 = *(_DWORD *)(v2 + 4); /*0x16a37c*/
  if ( a2 <= v4 ) /*0x16a382*/
  {
    v12 = a1[6]; /*0x16a38a*/
    v5 = v4 >> a1[4]; /*0x16a391*/
    if ( v12 < v5 ) /*0x16a396*/
      v5 = a1[6]; /*0x16a398*/
    v13 = (_DWORD *)(a1[5] + 16 * v5 - 16); /*0x16a3a6*/
    if ( *v13 == v2 ) /*0x16a3ac*/
    {
      if ( v12 <= v5 ) /*0x16a3b5*/
      {
        v6 = *(_DWORD **)v2; /*0x16a3d0*/
        if ( *(_DWORD *)v2 ) /*0x16a3d0*/
        {
          do /*0x16a3e5*/
          {
            if ( v6[1] >= a1[1] ) /*0x16a3df*/
              break; /*0x16a3df*/
            v6 = (_DWORD *)*v6; /*0x16a3e1*/
          }
          while ( v6 ); /*0x16a3e5*/
        }
      }
      else
      {
        v6 = *(_DWORD **)v2; /*0x16a3b7*/
        if ( *(_DWORD *)v2 ) /*0x16a3b7*/
        {
          do /*0x16a3c9*/
          {
            if ( v6[1] == v4 ) /*0x16a3c3*/
              break; /*0x16a3c3*/
            v6 = (_DWORD *)*v6; /*0x16a3c5*/
          }
          while ( v6 ); /*0x16a3c9*/
        }
      }
      *v13 = v6; /*0x16a3ea*/
    }
    return (_DWORD *)v2; /*0x16a3ec*/
  }
  v7 = a1[6]; /*0x16a3f7*/
  v8 = a2 >> a1[4]; /*0x16a3ff*/
  if ( v8 > v7 ) /*0x16a403*/
    v8 = a1[6]; /*0x16a405*/
  v9 = (int *)(a1[5] + 16 * v8 - 16); /*0x16a40f*/
  if ( v8 < v7 ) /*0x16a414*/
  {
    while ( 1 ) /*0x16a418*/
    {
      v2 = *v9; /*0x16a418*/
      if ( *v9 ) /*0x16a418*/
        break; /*0x16a418*/
      ++v8; /*0x16a438*/
      v9 += 4; /*0x16a439*/
      if ( a1[6] <= v8 ) /*0x16a43f*/
        goto LABEL_25; /*0x16a43f*/
    }
    v10 = *(_DWORD **)v2; /*0x16a41e*/
    if ( *(_DWORD *)v2 ) /*0x16a41e*/
    {
      do /*0x16a431*/
      {
        if ( v10[1] == *(_DWORD *)(v2 + 4) ) /*0x16a42b*/
          break; /*0x16a42b*/
        v10 = (_DWORD *)*v10; /*0x16a42d*/
      }
      while ( v10 ); /*0x16a431*/
    }
    *v9 = (int)v10; /*0x16a433*/
    return (_DWORD *)v2; /*0x16a435*/
  }
LABEL_25:
  v2 = *v9; /*0x16a441*/
  if ( !*v9 ) /*0x16a445*/
    return (_DWORD *)v2; /*0x16a481*/
  if ( *(_DWORD *)(v2 + 4) >= a2 ) /*0x16a44d*/
  {
    v11 = *(_DWORD **)v2; /*0x16a468*/
    if ( *(_DWORD *)v2 ) /*0x16a468*/
    {
      do /*0x16a47d*/
      {
        if ( v11[1] >= a1[1] ) /*0x16a477*/
          break; /*0x16a477*/
        v11 = (_DWORD *)*v11; /*0x16a479*/
      }
      while ( v11 ); /*0x16a47d*/
    }
    *v9 = (int)v11; /*0x16a47f*/
    return (_DWORD *)v2; /*0x16a47f*/
  }
  result = *(_DWORD **)v2; /*0x16a44f*/
  if ( *(_DWORD *)v2 ) /*0x16a44f*/
  {
    do /*0x16a464*/
    {
      if ( result[1] >= a2 ) /*0x16a45e*/
        break; /*0x16a45e*/
      result = (_DWORD *)*result; /*0x16a460*/
    }
    while ( result ); /*0x16a464*/
  }
  return result; /*0x16a486*/
}
