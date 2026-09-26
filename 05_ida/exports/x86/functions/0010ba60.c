/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ba60. */
void __cdecl qsort(void *__base, size_t __nel, size_t __width, int (__cdecl *__compar)(const void *, const void *))
{
  char *v4; // edi
  char *v5; // ebx
  char *v6; // esi
  char *v7; // eax
  char *v8; // edi
  char *i; // edi
  char *v10; // edi
  int v11; // eax
  char *v12; // ecx
  unsigned int v13; // edi
  char *j; // ebx
  char *v15; // eax
  char *k; // esi
  char v17; // [esp+Ch] [ebp-Ch]
  char v18; // [esp+Ch] [ebp-Ch]
  char *v19; // [esp+10h] [ebp-8h]

  if ( (int)__nel > 1 ) /*0x10ba72*/
  {
    dword_1DAC08 = __width; /*0x10ba78*/
    dword_1DAC04 = (int (__cdecl *)(_DWORD, _DWORD))__compar; /*0x10ba81*/
    dword_1DAC0C = 4 * __width; /*0x10ba8e*/
    dword_1DAC10 = 6 * __width; /*0x10ba96*/
    if ( (int)__nel <= 3 ) /*0x10baa9*/
    {
      v4 = (char *)__base + __width * __nel; /*0x10bac4*/
    }
    else
    {
      sub_10BB88(__base, (char *)__base + __width * __nel); /*0x10bab0*/
      v4 = (char *)__base + dword_1DAC0C; /*0x10bab8*/
    }
    v5 = (char *)__base; /*0x10bac7*/
LABEL_7:
    v6 = v5; /*0x10badc*/
    while ( 1 ) /*0x10bade*/
    {
      v5 += dword_1DAC08; /*0x10bade*/
      if ( v5 >= v4 ) /*0x10bae6*/
        break; /*0x10bae6*/
      if ( dword_1DAC04(v6, v5) > 0 ) /*0x10bada*/
        goto LABEL_7; /*0x10bada*/
    }
    if ( __base != v6 ) /*0x10baeb*/
    {
      v7 = (char *)__base; /*0x10baed*/
      v8 = (char *)__base + dword_1DAC08; /*0x10baf2*/
      if ( __base < (char *)__base + dword_1DAC08 ) /*0x10bafa*/
      {
        do /*0x10bb0e*/
        {
          v17 = *v6; /*0x10bafe*/
          *v6++ = *v7; /*0x10bb03*/
          *v7++ = v17; /*0x10bb09*/
        }
        while ( v7 < v8 ); /*0x10bb0e*/
      }
    }
    for ( i = (char *)__base; ; i = v19 ) /*0x10bb10*/
    {
      v10 = &i[dword_1DAC08]; /*0x10bb70*/
      v12 = v10; /*0x10bb76*/
      if ( (char *)__base + __width * __nel <= v10 ) /*0x10bb7b*/
        break; /*0x10bb7b*/
      do /*0x10bb32*/
      {
        v10 -= dword_1DAC08; /*0x10bb19*/
        v19 = v12; /*0x10bb25*/
        v11 = dword_1DAC04(v10, v12); /*0x10bb28*/
        v12 = v19; /*0x10bb2d*/
      }
      while ( v11 > 0 ); /*0x10bb32*/
      v13 = (unsigned int)&v10[dword_1DAC08]; /*0x10bb39*/
      if ( (char *)v13 != v19 ) /*0x10bb3d*/
      {
        for ( j = &v19[dword_1DAC08 - 1]; j >= v19; --j ) /*0x10bb45*/
        {
          v18 = *j; /*0x10bb4a*/
          v15 = j; /*0x10bb4d*/
          for ( k = j; ; v15 = k ) /*0x10bb4f*/
          {
            k -= dword_1DAC08; /*0x10bb5a*/
            if ( (unsigned int)k < v13 ) /*0x10bb62*/
              break; /*0x10bb62*/
            *v15 = *k; /*0x10bb56*/
          }
          *v15 = v18; /*0x10bb67*/
        }
      }
    }
  }
}
