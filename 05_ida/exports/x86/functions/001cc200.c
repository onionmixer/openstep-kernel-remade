/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc200. */
int __cdecl NXMapMember(_DWORD *a1, int a2, _DWORD *a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // esi
  int v5; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  unsigned int v11; // [esp+14h] [ebp-8h]
  int v12; // [esp+18h] [ebp-4h]

  v12 = a1[3]; /*0x1cc20f*/
  v3 = (*(int (__cdecl **)(_DWORD *, int))*a1)(a1, a2); /*0x1cc21b*/
  v11 = (v3 + 65521 * (HIWORD(v3) ^ (unsigned __int16)v3)) % a1[2]; /*0x1cc23a*/
  v4 = (_DWORD *)(v12 + 8 * v11); /*0x1cc243*/
  if ( *v4 != -1 ) /*0x1cc249*/
  {
    ++dword_1E5580; /*0x1cc24f*/
    if ( a2 == *v4 ) /*0x1cc25a*/
      v5 = 1; /*0x1cc270*/
    else
      v5 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v4, a2); /*0x1cc267*/
    if ( v5 ) /*0x1cc277*/
    {
      *a3 = v4[1]; /*0x1cc27f*/
      ++dword_1E5584; /*0x1cc281*/
      return *v4; /*0x1cc289*/
    }
    v7 = v11; /*0x1cc28c*/
    while ( 1 ) /*0x1cc290*/
    {
      v8 = v7 + 1; /*0x1cc290*/
      v7 = 0; /*0x1cc293*/
      if ( a1[2] > v8 ) /*0x1cc298*/
        v7 = v8; /*0x1cc29a*/
      if ( v11 == v7 ) /*0x1cc29f*/
        break; /*0x1cc29f*/
      ++dword_1E5588; /*0x1cc2a1*/
      v9 = (_DWORD *)(v12 + 8 * v7); /*0x1cc2aa*/
      if ( *v9 == -1 ) /*0x1cc2b0*/
        break; /*0x1cc2b0*/
      if ( *v9 == a2 ) /*0x1cc2bc*/
        v10 = 1; /*0x1cc2d0*/
      else
        v10 = (*(int (__cdecl **)(_DWORD *, _DWORD, int))(*a1 + 4))(a1, *v9, a2); /*0x1cc2c6*/
      if ( v10 ) /*0x1cc2d7*/
      {
        *a3 = v9[1]; /*0x1cc2df*/
        return *v9; /*0x1cc2e3*/
      }
    }
  }
  return -1; /*0x1cc2f0*/
}
