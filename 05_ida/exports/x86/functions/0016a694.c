/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a694. */
int *__cdecl zone_free_space_add(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // esi
  int *v5; // ebx
  int *i; // edx
  int *v7; // edx
  int v8; // eax
  int v9; // ebx
  int *v10; // eax
  int *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // esi
  unsigned int v15; // eax
  int *v17; // [esp+Ch] [ebp-10h]
  signed int v18; // [esp+10h] [ebp-Ch]
  int **v19; // [esp+14h] [ebp-8h]
  unsigned int v20; // [esp+18h] [ebp-4h]

  v4 = a1; /*0x16a69d*/
  v5 = (int *)a3; /*0x16a6a0*/
  if ( !a1 ) /*0x16a6a5*/
    v4 = &_zone_default_space; /*0x16a6a7*/
  v17 = v4 + 2; /*0x16a6af*/
  for ( i = (int *)v4[2]; ; i = (int *)*i ) /*0x16a6b2*/
  {
    if ( !i ) /*0x16a6c8*/
      goto LABEL_9; /*0x16a6c8*/
    if ( (unsigned int)i >= a3 || (int *)((char *)i + i[1]) == (int *)a3 ) /*0x16a6bf*/
      break; /*0x16a6bf*/
    v17 = i; /*0x16a6c1*/
  }
  v20 = i[1]; /*0x16a6d5*/
  if ( (unsigned int)i + v20 < a3 ) /*0x16a6de*/
  {
LABEL_9:
    if ( (unsigned int)(a4 - a2) <= 0xF ) /*0x16a6e9*/
      return v5; /*0x16a6e9*/
    if ( i ) /*0x16a6f1*/
      v17 = i; /*0x16a6f3*/
    v7 = (int *)(a3 + a2); /*0x16a6f9*/
    v7[1] = a4 - a2; /*0x16a6fb*/
    v8 = *v17; /*0x16a701*/
    *v7 = *v17; /*0x16a703*/
    if ( v8 ) /*0x16a707*/
      *(_DWORD *)(v8 + 8) = v7; /*0x16a709*/
    v7[2] = (int)v17; /*0x16a70f*/
    *v17 = (int)v7; /*0x16a712*/
    ++v4[3]; /*0x16a714*/
    goto LABEL_31; /*0x16a717*/
  }
  if ( (int *)((char *)i + v20) != (int *)a3 ) /*0x16a71e*/
    return v5; /*0x16a71e*/
  v9 = v4[6]; /*0x16a727*/
  v18 = v20 >> v4[4]; /*0x16a731*/
  if ( v18 > v9 ) /*0x16a736*/
    v18 = v4[6]; /*0x16a738*/
  v19 = (int **)(v4[5] + 16 * v18 - 16); /*0x16a747*/
  if ( *v19 == i ) /*0x16a74d*/
  {
    if ( v18 >= v9 ) /*0x16a752*/
    {
      v11 = (int *)*i; /*0x16a774*/
      if ( *i ) /*0x16a774*/
      {
        do /*0x16a789*/
        {
          if ( (unsigned int)v11[1] >= v4[1] ) /*0x16a783*/
            break; /*0x16a783*/
          v11 = (int *)*v11; /*0x16a785*/
        }
        while ( v11 ); /*0x16a789*/
      }
      *v19 = v11; /*0x16a78e*/
    }
    else
    {
      v10 = (int *)*i; /*0x16a754*/
      if ( *i ) /*0x16a754*/
      {
        do /*0x16a769*/
        {
          if ( v10[1] == v20 ) /*0x16a763*/
            break; /*0x16a763*/
          v10 = (int *)*v10; /*0x16a765*/
        }
        while ( v10 ); /*0x16a769*/
      }
      *v19 = v10; /*0x16a76e*/
    }
  }
  v5 = i; /*0x16a790*/
  v7 = (int *)((char *)i + a2); /*0x16a795*/
  v7[1] = v5[1] + a4 - a2; /*0x16a7a0*/
  v12 = *v5; /*0x16a7a3*/
  *v7 = *v5; /*0x16a7a5*/
  if ( v12 ) /*0x16a7a9*/
    *(_DWORD *)(v12 + 8) = v7; /*0x16a7ab*/
  v7[2] = (int)v17; /*0x16a7b1*/
  *v17 = (int)v7; /*0x16a7b4*/
LABEL_31:
  v13 = (unsigned int)v7[1] >> v4[4]; /*0x16a7b6*/
  if ( v4[6] < v13 ) /*0x16a7cb*/
    v13 = v4[6]; /*0x16a7cd*/
  v14 = 16 * v13 + v4[5]; /*0x16a7d6*/
  v15 = *(_DWORD *)(v14 - 16); /*0x16a7d8*/
  if ( !v15 || (unsigned int)v7 < v15 ) /*0x16a7e1*/
    *(_DWORD *)(v14 - 16) = v7; /*0x16a7e3*/
  return v5; /*0x16a7eb*/
}
