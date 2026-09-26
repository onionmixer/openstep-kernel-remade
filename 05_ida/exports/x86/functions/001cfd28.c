/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cfd28. */
int __cdecl sub_1CFD28(int a1)
{
  int result; // eax
  int v2; // edx
  int v3; // ebx
  int *v4; // edi
  int v5; // esi
  _DWORD *v6; // eax
  void (__cdecl *v7)(int, char *); // eax
  int v8; // edi
  int v9; // ebx
  Class Class; // esi
  int v11; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]

  v13 = *(_DWORD *)(a1 + 8); /*0x1cfd37*/
  result = *(_DWORD *)(a1 + 4); /*0x1cfd3a*/
  for ( i = result; v13; i += 16 ) /*0x1cfd42*/
  {
    v2 = *(_DWORD *)(i + 12); /*0x1cfd4b*/
    v11 = v2; /*0x1cfd4e*/
    if ( v2 ) /*0x1cfd53*/
    {
      v3 = *(unsigned __int16 *)(v2 + 8); /*0x1cfd59*/
      v4 = (int *)(v2 + 12); /*0x1cfd5f*/
      if ( *(_WORD *)(v2 + 8) ) /*0x1cfd59*/
      {
        do /*0x1cfda6*/
        {
          v5 = *v4; /*0x1cfd68*/
          v6 = *(_DWORD **)(*(_DWORD *)*v4 + 28); /*0x1cfd6c*/
          if ( v6 ) /*0x1cfd71*/
          {
            for ( ; *v6; v6 = (_DWORD *)*v6 ) /*0x1cfd73*/
              ; /*0x1cfd78*/
            v7 = (void (__cdecl *)(int, char *))class_lookupMethodInMethodList((int)v6, (int)aLoad); /*0x1cfd87*/
            if ( v7 ) /*0x1cfd91*/
              v7(v5, aLoad); /*0x1cfd9b*/
          }
          --v3; /*0x1cfda0*/
          ++v4; /*0x1cfda1*/
        }
        while ( v3 ); /*0x1cfda6*/
      }
      v8 = *(unsigned __int16 *)(v11 + 10); /*0x1cfdab*/
      result = *(unsigned __int16 *)(v11 + 8); /*0x1cfdaf*/
      v9 = v11 + 4 * result + 12; /*0x1cfdb3*/
      if ( *(_WORD *)(v11 + 10) ) /*0x1cfdab*/
      {
        do /*0x1cfdfc*/
        {
          Class = objc_getClass(*(const char **)(*(_DWORD *)v9 + 4)); /*0x1cfdc7*/
          result = *(_DWORD *)(*(_DWORD *)v9 + 12); /*0x1cfdcb*/
          if ( result ) /*0x1cfdd3*/
          {
            result = class_lookupMethodInMethodList(result, (int)aLoad); /*0x1cfddd*/
            if ( result ) /*0x1cfde7*/
              result = ((int (__cdecl *)(Class, char *))result)(Class, aLoad); /*0x1cfdf1*/
          }
          --v8; /*0x1cfdf6*/
          v9 += 4; /*0x1cfdf7*/
        }
        while ( v8 ); /*0x1cfdfc*/
      }
    }
    --v13; /*0x1cfdfe*/
  }
  return result; /*0x1cfe12*/
}
