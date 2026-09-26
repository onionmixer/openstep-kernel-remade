/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc2f8. */
int __cdecl NXMapGet(_DWORD *a1, int a2)
{
  unsigned int v2; // eax
  int *v3; // esi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // eax
  int *v8; // esi
  int v9; // eax
  int v10; // ebx
  unsigned int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]
  int v14; // [esp+1Ch] [ebp-4h]

  v13 = a1[3]; /*0x1cc307*/
  v2 = (*(int (__cdecl **)(_DWORD *, int))*a1)(a1, a2); /*0x1cc313*/
  v12 = (v2 + 65521 * (HIWORD(v2) ^ (unsigned __int16)v2)) % a1[2]; /*0x1cc332*/
  v3 = (int *)(v13 + 8 * v12); /*0x1cc33b*/
  if ( *v3 != -1 ) /*0x1cc341*/
  {
    ++dword_1E5580; /*0x1cc347*/
    if ( a2 == *v3 ) /*0x1cc352*/
      v4 = 1; /*0x1cc368*/
    else
      v4 = (*(int (__cdecl **)(_DWORD *, int, int))(*a1 + 4))(a1, *v3, a2); /*0x1cc35f*/
    if ( v4 ) /*0x1cc36f*/
    {
      v14 = v3[1]; /*0x1cc374*/
      ++dword_1E5584; /*0x1cc377*/
      v5 = *v3; /*0x1cc37d*/
      goto LABEL_18; /*0x1cc37f*/
    }
    v6 = v12; /*0x1cc384*/
    while ( 1 ) /*0x1cc388*/
    {
      v7 = v6 + 1; /*0x1cc388*/
      v6 = 0; /*0x1cc38b*/
      if ( a1[2] > v7 ) /*0x1cc390*/
        v6 = v7; /*0x1cc392*/
      if ( v12 == v6 ) /*0x1cc397*/
        break; /*0x1cc397*/
      ++dword_1E5588; /*0x1cc399*/
      v8 = (int *)(v13 + 8 * v6); /*0x1cc3a2*/
      if ( *v8 == -1 ) /*0x1cc3a8*/
        break; /*0x1cc3a8*/
      if ( *v8 == a2 ) /*0x1cc3b4*/
        v9 = 1; /*0x1cc3c8*/
      else
        v9 = (*(int (__cdecl **)(_DWORD *, int, int))(*a1 + 4))(a1, *v8, a2); /*0x1cc3be*/
      if ( v9 ) /*0x1cc3cf*/
      {
        v14 = v8[1]; /*0x1cc3d4*/
        v5 = *v8; /*0x1cc3d7*/
        goto LABEL_18; /*0x1cc3d9*/
      }
    }
  }
  v5 = -1; /*0x1cc3dc*/
LABEL_18:
  v10 = 0; /*0x1cc3e1*/
  if ( v5 != -1 ) /*0x1cc3e6*/
    return v14; /*0x1cc3e8*/
  return v10; /*0x1cc3f0*/
}
