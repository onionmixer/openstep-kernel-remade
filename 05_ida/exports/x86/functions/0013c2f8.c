/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c2f8. */
int __cdecl hashalloc(int a1, int a2, int a3, int a4, int (__cdecl *a5)(int, int, int, int))
{
  int v5; // esi
  int result; // eax
  int v7; // edx
  int i; // ebx
  int v9; // edx
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+Ch] [ebp-8h]

  v5 = *(_DWORD *)(a1 + 80); /*0x13c30a*/
  result = a5(a1, a2, a3, a4); /*0x13c31d*/
  v7 = a2; /*0x13c324*/
  if ( !result ) /*0x13c329*/
  {
    for ( i = 1; ; i *= 2 ) /*0x13c334*/
    {
      v11 = *(_DWORD *)(v5 + 44); /*0x13c362*/
      if ( i >= v11 ) /*0x13c367*/
        break; /*0x13c367*/
      v9 = i + v7; /*0x13c33c*/
      if ( v9 >= v11 ) /*0x13c340*/
        v9 -= v11; /*0x13c342*/
      v15 = v9; /*0x13c34c*/
      v10 = a5(a1, v9, 0, a4); /*0x13c354*/
      v7 = v15; /*0x13c359*/
      if ( v10 ) /*0x13c35e*/
        return v10; /*0x13c35e*/
    }
    v12 = (a2 + 2) % *(_DWORD *)(v5 + 44); /*0x13c372*/
    v13 = 2; /*0x13c375*/
    if ( *(int *)(v5 + 44) > 2 ) /*0x13c37d*/
    {
      while ( 1 ) /*0x13c388*/
      {
        v16 = v12; /*0x13c388*/
        v10 = a5(a1, v12, 0, a4); /*0x13c390*/
        if ( v10 ) /*0x13c39a*/
          break; /*0x13c39a*/
        v12 = v16 + 1; /*0x13c39c*/
        v14 = *(_DWORD *)(v5 + 44); /*0x13c39d*/
        if ( v16 + 1 == v14 ) /*0x13c3a2*/
          v12 = 0; /*0x13c3a4*/
        if ( ++v13 >= v14 ) /*0x13c3a9*/
          return 0; /*0x13c3a9*/
      }
      return v10; /*0x13c332*/
    }
    return 0; /*0x13c3ab*/
  }
  return result; /*0x13c3b0*/
}
