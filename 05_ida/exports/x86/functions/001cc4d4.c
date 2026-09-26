/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc4d4. */
int __cdecl NXMapInsert(_DWORD *a1, int a2, int a3)
{
  unsigned int v3; // eax
  int v4; // eax
  int result; // eax
  unsigned int v6; // ecx
  int v7; // ebx
  int v8; // esi
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // [esp+14h] [ebp-1Ch]
  unsigned int v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-14h]
  _DWORD *v15; // [esp+24h] [ebp-Ch]
  _DWORD *v16; // [esp+24h] [ebp-Ch]
  int *v17; // [esp+24h] [ebp-Ch]
  unsigned int v18; // [esp+28h] [ebp-8h]
  int v19; // [esp+2Ch] [ebp-4h]

  while ( 1 )
  {
    v19 = a1[3]; /*0x1cc4e3*/
    v3 = (*(int (__cdecl **)(_DWORD *, int))*a1)(a1, a2); /*0x1cc4fb*/
    v18 = (65521 * (HIWORD(v3) ^ (unsigned __int16)v3) + v3) % a1[2]; /*0x1cc51d*/
    v15 = (_DWORD *)(v19 + 8 * v18); /*0x1cc529*/
    if ( a2 == -1 )
    {
      _NXLogError("*** NXMapInsert: invalid key: -1\n");
      return 0; /*0x1cc6de*/
    }
    ++dword_1E5594; /*0x1cc53c*/
    if ( *v15 == -1 ) /*0x1cc548*/
    {
      ++dword_1E5598; /*0x1cc54a*/
      *v15 = a2; /*0x1cc553*/
      v15[1] = a3; /*0x1cc558*/
      ++a1[1]; /*0x1cc55e*/
      return 0; /*0x1cc561*/
    }
    if ( a2 == *v15 ) /*0x1cc570*/
      v4 = 1; /*0x1cc590*/
    else
      v4 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v15, a2); /*0x1cc589*/
    if ( v4 ) /*0x1cc597*/
    {
      result = v15[1]; /*0x1cc59c*/
      ++dword_1E5598; /*0x1cc59f*/
      if ( a3 != result ) /*0x1cc5a8*/
        v15[1] = a3; /*0x1cc5b1*/
      return result; /*0x1cc5b4*/
    }
    if ( a1[2] != a1[1] ) /*0x1cc5c8*/
      break; /*0x1cc5c8*/
    sub_1CC3F8(a1); /*0x1cc5cb*/
  }
  v11 = v18; /*0x1cc5db*/
  do
  {
    v6 = 0; /*0x1cc5e4*/
    if ( a1[2] > v11 + 1 ) /*0x1cc5ec*/
      v6 = v11 + 1; /*0x1cc5ee*/
    v11 = v6; /*0x1cc5f0*/
    if ( v6 == v18 )
    {
      _NXLogError("**** NXMapInsert: bug\n");
      return 0; /*0x1cc6d9*/
    }
    ++dword_1E559C; /*0x1cc5fe*/
    v16 = (_DWORD *)(v19 + 8 * v6); /*0x1cc60d*/
    if ( *v16 == -1 ) /*0x1cc613*/
    {
      v7 = a2; /*0x1cc615*/
      v8 = a3; /*0x1cc618*/
      v12 = v18; /*0x1cc61e*/
      do /*0x1cc660*/
      {
        v17 = (int *)(v19 + 8 * v12); /*0x1cc631*/
        v13 = *v17; /*0x1cc636*/
        v14 = v17[1]; /*0x1cc63c*/
        *v17 = v7; /*0x1cc63f*/
        v17[1] = v8; /*0x1cc641*/
        v7 = v13; /*0x1cc644*/
        v8 = v14; /*0x1cc647*/
        v9 = 0; /*0x1cc64e*/
        if ( a1[2] > v12 + 1 ) /*0x1cc656*/
          v9 = v12 + 1; /*0x1cc658*/
        v12 = v9; /*0x1cc65a*/
      }
      while ( v13 != -1 ); /*0x1cc660*/
      ++a1[1]; /*0x1cc665*/
      if ( 4 * a1[1] > (unsigned int)(3 * a1[2]) ) /*0x1cc67d*/
        sub_1CC3F8(a1); /*0x1cc683*/
      return 0; /*0x1cc688*/
    }
    if ( a2 == *v16 ) /*0x1cc694*/
      v10 = 1; /*0x1cc6b4*/
    else
      v10 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v16, a2); /*0x1cc6ad*/
  }
  while ( !v10 );
  result = v16[1]; /*0x1cc6c4*/
  if ( a3 != result ) /*0x1cc6ca*/
    v16[1] = a3; /*0x1cc6cf*/
  return result; /*0x1cc6e3*/
}
